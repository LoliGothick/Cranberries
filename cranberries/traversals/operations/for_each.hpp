#ifndef CRANBERRIES_RANGES_OPERATIONS_FOR_EACH_HPP
#define CRANBERRIES_RANGES_OPERATIONS_FOR_EACH_HPP
#include <iostream>
#include <type_traits>
#include "../../utility/utility.hpp"
#include "../detail/sentinel_iterator.hpp"
#include "../detail/tags.hpp"

namespace cranberries {
inline namespace experimental {
namespace traversals {

template <class F>
class ForEach : private tag::adaptor_tag, private tag::action_tag {
  F f;

 public:
  template <class _F>
  ForEach(_F &&_f) noexcept : f{std::forward<_F>(_f)} {}

  template <class Traversable>
  using requires = typename concepts::iterable::template requires<Traversable>;

  template <class Traversable>
  decltype(auto) operator()(Traversable &&traversal) {
    for (auto &&elem : traversal) f(elem);
    return std::forward<Traversable>(traversal);
  }
};

namespace operation {
template <class F>
inline ForEach<F> for_each(F &&f) noexcept {
  return ForEach<F>{std::forward<F>(f)};
}
}  // namespace operation

}  // namespace traversals
}  // namespace experimental
}  // namespace cranberries
#endif  // !CRANBERRIES_RANGES_OPERATIONS_FOR_EACH_HPP
