#ifndef CRANBRIIES_INTERVAL_LIB_COMPARE_TOTAL_ORDER_HPP
#define CRANBRIIES_INTERVAL_LIB_COMPARE_TOTAL_ORDER_HPP

#include <type_traits>
#include <utility>
#include "../interval.hpp"
#include "explicit.hpp"

namespace cranberries {

template <typename T, typename U>
constexpr auto operator<(T &&x, U &&y) -> decltype(total_less(x, y)) {
  return total_less(std::forward<T>(x), std::forward<U>(y));
}
template <typename T, typename U>
constexpr auto operator<=(T &&x, U &&y) -> decltype(total_less_or_equal(x, y)) {
  return total_less_or_equal(std::forward<T>(x), std::forward<U>(y));
}
template <typename T, typename U>
constexpr auto operator>(T &&x, U &&y) -> decltype(total_greater(x, y)) {
  return total_greater(std::forward<T>(x), std::forward<U>(y));
}
template <typename T, typename U>
constexpr auto operator>=(T &&x, U &&y)
    -> decltype(total_greater_or_equal(x, y)) {
  return total_greater_or_equal(std::forward<T>(x), std::forward<U>(y));
}
template <typename T, typename U>
constexpr auto operator==(T &&x, U &&y) -> decltype(total_equal(x, y)) {
  return total_equal(std::forward<T>(x), std::forward<U>(y));
}
template <typename T, typename U>
constexpr auto operator!=(T &&x, U &&y) -> decltype(total_equal(x, y)) {
  return !total_equal(std::forward<T>(x), std::forward<U>(y));
}
}  // namespace cranberries
#endif