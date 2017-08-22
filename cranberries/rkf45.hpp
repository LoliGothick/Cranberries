/**
 * API for Git.io
 *
 * These codes are licensed under CC0.
 * http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */

#ifndef CRANBERRIES_RKF45_HPP
#define CRANBERRIES_RKF45_HPP
#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <cmath>
#include <algorithm>
#include "common/exception.hpp"
#include "type_traits.hpp"
#include "array_vectorized_utility.hpp"

namespace cranberries {

  // RKF45 Solver Class
  template < typename System >
  class RKF45ForDifferentialEquationOfFirstOrder {
    // Differential equation 
    // the equation must be formed
    //   dx/dt = f(t,x)
    System f;


    // a : minimum value of t
    // b : maximum value of t
    // tol : tolerance(allowable error)
    // h_min : minimum step size
    // h_max : maximum step size
    long double a,b,tol,h_min,h_max;

    // For a variable system
    long double check(long double state) noexcept {
      return state;
    }

    // For variadic system
    // It returns maximum error in witch variables
    template < class State >
    enabler_t<is_range_v<State>,long double>
    check(State&& state) noexcept {
      return *std::max_element(std::begin(state), std::end(state));
    }

  public:
    RKF45ForDifferentialEquationOfFirstOrder(System f) noexcept : f{ f } {}

    // init({ a, b, alpha, tol, h_min, h_max })
    // a : minimum value of t
    // b : maximum value of t
    // tol : tolerance(allowable error)
    // h_min : minimum step size
    // h_max : maximum step size
    auto& init(generate_tuple_t<long double,5> params) {
      std::tie(a, b, tol, h_min, h_max) = params;
      return *this;
    }

    // set_integrate_range({ a, b })
    // a : minimum value of t
    // b : maximum value of t
    auto& set_integrate_range(generate_tuple_t<long double, 2> params) {
      std::tie(a, b) = params;
      return *this;
    }

    // set_tolerance(tol)
    // tol : tolerance(allowable error)
    auto& set_tolerance(long double param) {
      tol = param;
      return *this;
    }

    // set_step_size_range({ h_min, h_max })
    // h_min : minimum step size
    // h_max : maximum step size
    auto& set_step_size_range(generate_tuple_t<long double, 2> params) {
      std::tie(h_min, h_max) = params;
      return *this;
    }

    // For test
    template < typename State >
    bool integrate(State alpha) noexcept {
      return integrate(alpha, [](auto t, auto x) { std::cout << t << " " << x << '\n'; });
    }

    // Solve Equation With Observer
    template < typename State, typename Observer >
    bool integrate(State alpha, Observer&& ob ) noexcept {
      /// step 0:
      // declarations
      State k1{}, k2{}, k3{}, k4{}, k5{}, k6{};
      long double R{}, sigma{};
      /// step 1:
      // initialization
      auto t = a;
      auto x = alpha;
      auto h = h_min;

      // update function
      auto update = [&] {
        using namespace array_vectorized_util;
        /// step 3:
        // 
        k1 = h*f(t, x);
        k2 = h*f(t + 0.25L*h, x + 0.25L*k1);
        k3 = h*f(t + 3.0L / 8.0L*h, (3.0L*k1 + 9.0L*k2) / 32.0L);
        k4 = h*f(t + 12.0L / 13.0L*h, x + (1932.0L*k1 - 7200.0L*k2 + 7296.0L*k3) / 2197.0L);
        k5 = h*f(t + h, x + 439.0L / 216.0L*k1 - 8.0L*k2 + 3680.0L / 513.0L*k3 - 845.0L / 4104 * k4);
        k6 = h*f(t + 0.5L*h, x - 8.0L / 27.0L*k1 + 2.0L*k2 - 3544.0L / 2565.0L*k3 + 1859.0L / 4104.0L*k4 - 11.0L / 40.0L*k5);
        /// step 4:
        t += h;
        /// step 5:
        x += 25.0L / 216.0L*k1 + 1408.0L / 2565.0L*k3 + 2197.0L / 4101.0L*k4 - k5 / 5.0L;
        // output
        ob(t, x);
      };

      /// step 2:
      // main loop
      while (true) {
        update();
        /// step 6:
        // (maximum) difference of order 4 and order 5
        R = check([&] { 
          using namespace array_vectorized_util;
          return array_vectorized_util::abs(k1 / 360.0L - 128.0L / 4275.0L*k3 - 2197.0L / 75240.0L*k4 + k5 / 50.0L + 2.0L / 55.0L*k6);
        }());
        sigma = 0.84L*std::sqrt(std::sqrt(tol / R));
        /// step 7:
        // step size control
        h = sigma <= 0.1L ? 0.1L*h :
            sigma >= 4.0L ? 4.0L*h :
            sigma*h;
        /// step 8:
        if (h_max < h) h = h_max;
        
        if (b <= t) break;
        if (b < t + h && t < b) goto LAST;

        if (h < h_min) goto FAILURE;
      }

      return true;


    LAST:
      t = b - h;
      update();
      return true;


    FAILURE:
      return false;
    }
  };

  // RKF45 Solver Class for Second Order
  // Equation Form : d^2y/dt^2 = b(dy/dt) + cy = f(t)
  //
  // Let
  // dy/dt = z
  // d^2y/dt^2 = dz/dt
  // 
  // dz/dt = f(t)-cy-bz
  // 
  // Let
  // dy/dt = f1(t,y,z)
  // dz/dt = f2(t,y,z)
  //
  // Let
  // Increment of y against h : k
  // Increment of z against h : l
  //
  // t[i+1] = t[i] + h
  // y[i]   = y[i] + k
  // z[i]   = z[i] + l
  template < class System1, class System2 >
  class RKF45ForDifferentialEquationOfSecondOrder {
    // Differential equation 
    // the equation must be formed
    //   dx/dt = f(t,y,z)
    System1 f1;
    System2 f2;


    // a : minimum value of t
    // b : maximum value of t
    // tol : tolerance(allowable error)
    // h_min : minimum step size
    // h_max : maximum step size
    long double a, b, tol, h_min, h_max;

    // For a variable system
    long double check(long double state) noexcept {
      return state;
    }

    // For variadic system
    // It returns maximum error in witch variables
    template < class State >
    enabler_t<is_range_v<State>, long double>
      check(State&& state) noexcept {
      return *std::max_element(std::begin(state), std::end(state));
    }

  public:
    RKF45ForDifferentialEquationOfSecondOrder(System1 f, System2 g) noexcept : f1{ f }, f2{ g } {}

    // init({ a, b, alpha, tol, h_min, h_max })
    // a : minimum value of t
    // b : maximum value of t
    // tol : tolerance(allowable error)
    // h_min : minimum step size
    // h_max : maximum step size
    auto& init(generate_tuple_t<long double, 5> params) {
      std::tie(a, b, tol, h_min, h_max) = params;
      return *this;
    }

    // set_integrate_range({ a, b })
    // a : minimum value of t
    // b : maximum value of t
    auto& set_integrate_range(generate_tuple_t<long double, 2> params) {
      std::tie(a, b) = params;
      return *this;
    }

    // set_tolerance(tol)
    // tol : tolerance(allowable error)
    auto& set_tolerance(long double param) {
      tol = param;
      return *this;
    }

    // set_step_size_range({ h_min, h_max })
    // h_min : minimum step size
    // h_max : maximum step size
    auto& set_step_size_range(generate_tuple_t<long double, 2> params) {
      std::tie(h_min, h_max) = params;
      return *this;
    }

    // Solve Equation With Observer
    template < typename State, typename Observer >
    bool integrate(State y0, State z0, Observer&& ob) noexcept {
      /// step 0:
      // dy = k
      // dz = l
      State k1{}, k2{}, k3{}, k4{}, k5{}, k6{};
      State l1{}, l2{}, l3{}, l4{}, l5{}, l6{};
      long double R{}, sigma{};
      /// step 1:
      // initialization
      auto t = 0.01L;
      State y{}, z{};
      std::tie(y,z) = std::tie(y0,z0);
      auto h = h_min;

      // update function
      auto update = [&] {
        using namespace array_vectorized_util;
        /// step 3:
        // 
        k1 = h*f1(t, y, z);
        k2 = h*f1(t + 0.25L*h, y + 0.25L*k1, z + 0.25L*k1);
        k3 = h*f1(t + 3.0L / 8.0L*h, (3.0L*k1 + 9.0L*k2) / 32.0L, (3.0L*k1 + 9.0L*k2) / 32.0L);
        k4 = h*f1(t + 12.0L / 13.0L*h, y + (1932.0L*k1 - 7200.0L*k2 + 7296.0L*k3) / 2197.0L, z + (1932.0L*k1 - 7200.0L*k2 + 7296.0L*k3) / 2197.0L);
        k5 = h*f1(t + h, y + 439.0L / 216.0L*k1 - 8.0L*k2 + 3680.0L / 513.0L*k3 - 845.0L / 4104 * k4, z + 439.0L / 216.0L*k1 - 8.0L*k2 + 3680.0L / 513.0L*k3 - 845.0L / 4104 * k4);
        k6 = h*f1(t + 0.5L*h, y - 8.0L / 27.0L*k1 + 2.0L*k2 - 3544.0L / 2565.0L*k3 + 1859.0L / 4104.0L*k4 - 11.0L / 40.0L*k5, z - 8.0L / 27.0L*k1 + 2.0L*k2 - 3544.0L / 2565.0L*k3 + 1859.0L / 4104.0L*k4 - 11.0L / 40.0L*k5);

        l1 = h*f2(t, y, z);
        l2 = h*f2(t + 0.25L*h, y + 0.25L*l1, z + 0.25L*l1);
        l3 = h*f2(t + 3.0L / 8.0L*h, (3.0L*l1 + 9.0L*l2) / 32.0L, (3.0L*l1 + 9.0L*l2) / 32.0L);
        l4 = h*f2(t + 12.0L / 13.0L*h, y + (1932.0L*l1 - 7200.0L*l2 + 7296.0L*l3) / 2197.0L, z + (1932.0L*l1 - 7200.0L*l2 + 7296.0L*l3) / 2197.0L);
        l5 = h*f2(t + h, y + 439.0L / 216.0L*l1 - 8.0L*l2 + 3680.0L / 513.0L*l3 - 845.0L / 4104 * l4, z + 439.0L / 216.0L*l1 - 8.0L*l2 + 3680.0L / 513.0L*l3 - 845.0L / 4104 * l4);
        l6 = h*f2(t + 0.5L*h, y - 8.0L / 27.0L*l1 + 2.0L*l2 - 3544.0L / 2565.0L*l3 + 1859.0L / 4104.0L*l4 - 11.0L / 40.0L*l5, z - 8.0L / 27.0L*l1 + 2.0L*l2 - 3544.0L / 2565.0L*l3 + 1859.0L / 4104.0L*l4 - 11.0L / 40.0L*l5);

        /// step 4:
        t += h;
        /// step 5:
        y += 25.0L / 216.0L*k1 + 1408.0L / 2565.0L*k3 + 2197.0L / 4101.0L*k4 - k5 / 5.0L;
        z += 25.0L / 216.0L*l1 + 1408.0L / 2565.0L*l3 + 2197.0L / 4101.0L*l4 - l5 / 5.0L;
        // output
        ob(t, y);
      };

      /// step 2:
      // main loop
      while (true) {
        update();
        /// step 6:
        // (maximum) difference of order 4 and order 5
        R = check([&] {
          using namespace array_vectorized_util;
          return std::max(
            array_vectorized_util::abs(k1 / 360.0L - 128.0L / 4275.0L*k3 - 2197.0L / 75240.0L*k4 + k5 / 50.0L + 2.0L / 55.0L*k6),
            array_vectorized_util::abs(l1 / 360.0L - 128.0L / 4275.0L*l3 - 2197.0L / 75240.0L*l4 + l5 / 50.0L + 2.0L / 55.0L*l6)
            );
        }());
        sigma = 0.84L*std::sqrt(std::sqrt(tol / R));
        /// step 7:
        std::cout << h << "\n";
        // step size control
        h = sigma <= 0.1L ? 0.1L*h :
          sigma >= 4.0L ? 4.0L*h :
          sigma*h;
        /// step 8:
        if (h_max < h) h = h_max;

        if (b <= t) break;
        if (b < t + h && t < b) goto LAST;

        if (h < h_min) goto FAILURE;
      }

      return true;


    LAST:
      t = b - h;
      update();
      return true;


    FAILURE:
      return false;
    }
  };

  // Builder function
  template < class System >
  RKF45ForDifferentialEquationOfFirstOrder<System> make_rkf45_solver_for_first_order(System&& f) noexcept {
    return { std::forward<System>(f) };
  }


  // Builder function
  template < class System1, class System2 >
  RKF45ForDifferentialEquationOfSecondOrder<System1,System2> make_rkf45_solver_for_second_order(System1&& f, System2&& g) noexcept {
    return { std::forward<System1>(f), std::forward<System2>(g) };
  }
} // ! namespace cranberries

#endif