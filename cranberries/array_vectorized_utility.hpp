#ifndef CRANBERRIES_ARRAY_VECTORIZED_UTILITY_HPP
#define CRANBERRIES_ARRAY_VECTORIZED_UTILITY_HPP
#include <array>
#include <algorithm>
#include <cmath>
#include <numeric>

namespace cranberries {
  namespace array_vectorized_util {

    template < typename T, size_t N >
    constexpr std::array<T, N>& operator+=(std::array<T, N>& vec1, std::array<T, N> const& vec2) {
      for (size_t i{}; i < N; ++i) vec1[i] += vec2[i];
      return vec1;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator+(std::array<T, N> const& vec1, std::array<T, N> const& vec2) {
      std::array<T, N> result{};
      for (size_t i{}; i < N; ++i) result[i] = vec1[i] + vec2[i];
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator+=(std::array<T, N>& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e += s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator+=(std::array<T, N>&& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e += s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator+(std::array<T, N> const& vec, typename std::array<T, N>::value_type s) {
      return std::array<T, N>{vec} += s;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator+(typename std::array<T, N>::value_type s, std::array<T, N> const& vec) {
      return std::array<T, N>{vec} += s;
    }

    template < typename T, size_t N >
    constexpr std::array<T, N>& operator-=(std::array<T, N>& vec1, std::array<T, N> const& vec2) {
      for (size_t i{}; i < N; ++i) vec1[i] -= vec2[i];
      return vec1;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator-(std::array<T, N> const& vec1, std::array<T, N> const& vec2) {
      std::array<T, N> result{};
      for (size_t i{}; i < N; ++i) result[i] = vec1[i] - vec2[i];
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator-=(std::array<T, N>& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e -= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator-=(std::array<T, N>&& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e -= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator-(std::array<T, N> const& vec, typename std::array<T, N>::value_type s) {
      return std::array<T, N>{vec} -= s;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator-(typename std::array<T, N>::value_type s, std::array<T, N> const& vec) {
      return std::array<T, N>{vec} -= s;
    }

    template < typename T, size_t N >
    constexpr std::array<T, N>& operator*=(std::array<T, N>& vec1, std::array<T, N> const& vec2) {
      for (size_t i{}; i < N; ++i) vec1[i] *= vec2[i];
      return vec1;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator*(std::array<T, N> const& vec1, std::array<T, N> const& vec2) {
      std::array<T, N> result{};
      for (size_t i{}; i < N; ++i) result[i] = vec1[i] * vec2[i];
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator*=(std::array<T, N>& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e *= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator*=(std::array<T, N>&& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e *= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator*(std::array<T, N> const& vec, typename std::array<T, N>::value_type s) {
      auto result = vec;
      for (auto& e : result) e *= s;
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator*(typename std::array<T, N>::value_type s, std::array<T, N> const& vec) {
      auto result = vec;
      for (auto& e : result) e *= s;
      return result;
    }

    template < typename T, size_t N >
    constexpr std::array<T, N>& operator/=(std::array<T, N>& vec1, std::array<T, N> const& vec2) {
      for (size_t i{}; i < N; ++i) vec1[i] /= vec2[i];
      return vec1;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator/(std::array<T, N> const& vec1, std::array<T, N> const& vec2) {
      std::array<T, N> result{};
      for (size_t i{}; i < N; ++i) result[i] = vec1[i] / vec2[i];
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator/=(std::array<T, N>& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e /= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N>& operator/=(std::array<T, N>&& vec, typename std::array<T, N>::value_type s) {
      for (auto& e : vec) e /= s;
      return vec;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator/(std::array<T, N> const& vec, typename std::array<T, N>::value_type s) {
      auto result = vec;
      for (auto& e : result) e /= s;
      return result;
    }
    template < typename T, size_t N >
    constexpr std::array<T, N> operator/(typename std::array<T, N>::value_type s, std::array<T, N> const& vec) {
      auto result = vec;
      for (auto& e : result) e /= s;
      return result;
    }

    using std::abs;

    template < typename T, size_t N >
    constexpr std::array<T, N> abs(std::array<T, N> const& vec) {
      using std::abs;
      auto result = vec;
      for (auto& e : result) e = abs(e);
      return result;
    }

    template < typename T, size_t N >
    constexpr T norm(std::array<T, N> const& vec) {
      using std::sqrt;
      return sqrt( std::accumulate(std::begin(vec), std::end(vec), T{}, [](auto x) { return x*x; }) );
    }

  }
}

#endif