#ifndef CRANBERRIES_RANGES_ACTION_ADAPTORS_CONVERTER_HPP
#define CRANBERRIES_RANGES_ACTION_ADAPTORS_CONVERTER_HPP
#include <iostream>
#include <type_traits>
#include "../../common/concepts.hpp"
#include "../../utility/utility.hpp"
#include "../detail/sentinel_iterator.hpp"
#include "../detail/tags.hpp"

namespace cranberries {
inline namespace experimental {
namespace traversals {

template <template <class T, class A = std::allocator<T>> class Container>
class Converter : private tag::adaptor_tag, private tag::action_tag {
 public:
  Converter() = default;

  template <class Range>
  using requires = typename concepts::iterable::template requires<Range>;

  template <class Range>
  decltype(auto) operator()(Range &&traversal) {
    Container<typename std::decay_t<Range>::value_type> ret{};
    for (auto const &e : traversal) ret.emplace_back(e);
    return ret;
  }
};

namespace operation {
template <template <class, class> class Target>
Converter<Target> convert() noexcept {
  return {};
}
}  // namespace operation

}  // namespace traversals
}  // namespace experimental
}  // namespace cranberries
#endif  // !CRANBERRIES_RANGES_ACTION_ADAPTORS_WRITELINE_HPP
