#include "stdafx.h"
#include "../../cranberries/experimental/ranges.hpp"

int main() {
  using namespace cranberries::experimental::ranges;

  create::generate_canonical()
    | lazy::take(4)
    | action::write_line();

  create::range(1, 10)
    | lazy::take(4)
    | action::write_line();

  create::iterate(1, [](auto v) { return v * 2; })
    | lazy::take(5)
    | action::write_line();

  std::vector<std::string> v{ "a", "b", "c", "dummy" };

  v | lazy::take(3)
    | action::write_line();

  getchar();
}