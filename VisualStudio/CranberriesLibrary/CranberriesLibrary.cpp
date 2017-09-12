#include <iostream>
#include <cranberries/experimental/ranges.hpp>
#include <cranberries/unit_test/unit_test.hpp>
#include <cranberries/func_util.hpp>
#include <initializer_list>
#include <chrono>

int main() {
  using namespace cranberries::experimental::ranges;
  using clock = std::chrono::high_resolution_clock;
  using cranberries::make_finally;
  using namespace cranberries::func_util;

  auto println = [](auto&& head, auto&&... tail) {
    std::cout << head;
    (void)std::initializer_list<int>{ (void(std::cout << " " << tail),0)... };
    std::cout << std::endl;
  };

  auto are_equal
    = [](auto a, auto b) -> cranberries::expected<bool> {
    if (a == b) return true;
    else return cranberries::make_unexpected("not equal");
  };

  println <<= are_equal(1, 2)
    .map_or(1, [](auto v) { return v; })
    .value();

  auto p = [](std::string s) {std::cout << "\n" << s << "\n"; };

  // Fibonacci numbers
  p("[ iterate -> take ] // Fibonacci numbers");
  create::iterate(1, [prev = 0](int v)mutable{
    return make_finally([&] {prev = v; }), prev + v;
  })
    | view::take(7)                 // [1,1,2,3,5,8,13]
    | action::write_line();

  p("[ generate -> transform -> take ] // tick");
  create::generate([lap = clock::now()]()mutable->std::chrono::duration<double, std::milli>{
    auto tmp = clock::now();
    return make_finally([&] {lap = tmp; }), tmp - lap;
  })
    | view::transform([](auto duration) { return std::to_string(duration.count()) + "[ms]"; })
    | view::take(7)
    | action::write_line();

  p("[ range ]");
  create::range(1, 5)               // [1,5) = [1,2,3,4]
    | action::write_line();

  p("[ cyclic -> take ]");
  view::cyclic(create::range(1, 5)) // [1,2,3,4,1,2,4,1,...]
    | view::take(5)                 // [1,2,3,4,1]
    | action::write_line();

  p("[ cyclic(range) -> reverse -> take -> reverse ]");
  view::cyclic(create::range(1, 5)) // [1,2,3,4,1,2,4,1,...]
    | action::reverse()             // [4,3,2,1,4,3,2,1,...]
    | view::take(5)                 // [4,3,2,1,4]
    | action::reverse()             // [4,1,2,3,4]
    | action::write_line();

  p("[ cyclic(range) -> take -> concat(range) -> distinct -> reverse ]");
  view::cyclic(create::range(1, 5))    // [1,2,3,4,1,2,4,1,...]
    | view::take(7)                    // [1,2,3,4,1,2,3]
    | view::concat(create::range(1, 6)) // [1,2,3,4,1,2,3,1,2,3,4,5]
    | action::distinct()               // [1,2,3,4,5]
    | action::reverse()                // [5,4,3,2,1]
    | action::write_line();

  p("[ range -> zip_with ]");
  create::range(1, 4)
    | view::zip_with(std::vector<std::string>{"one", "two", "three"})
    | action::peek([](auto tup) { std::cout << "[" << std::get<0>(tup) << "," << std::get<1>(tup) << "] "; });
  std::cout << std::endl;

  p("[ range -> take_while -> drop ]");
  create::range(1, 20)                            // [1,2,3,...,19]
    | view::take_while([](auto i) {return i < 8; }) // [1,2,3,4,5,6,7]
    | view::drop(4)                               // [5,6,7]
    | action::write_line();

  p("[ range -> take_while -> drop_while ]");
  create::range(1, 20)                            // [1,2,3,...,19]
    | view::take_while([](auto i) {return i < 8; }) // [1,2,3,4,5,6,7]
    | view::drop_while([](auto i) {return i < 5; }) // [5,6,7]
    | action::write_line();

  p("[ range -> transform_with_index ]");
  create::range(1, 6)
    | view::transform_with_index([](size_t i, auto e) { return e*i; })
    | action::write_line();


  getchar();
}