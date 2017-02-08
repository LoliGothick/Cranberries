#ifndef CRANBERRIES_STREAMS_OPERATORS_CHUNK_FOR_EACH_HPP
#define CRANBERRIES_STREAMS_OPERATORS_CHUNK_FOR_EACH_HPP
#include <type_traits>
#include <utility>
#include "../utility.hpp"

namespace cranberries {
namespace streams {
namespace operators {

  template <
    size_t N,
    typename Func
  >
  class ChunkForEach
    : private cranberries_magic::EagerOperationModuleBase
  {
  public:
    ChunkForEach() = default;
    ChunkForEach(ChunkForEach const&) = default;
    ChunkForEach(ChunkForEach&&) = default;
    ChunkForEach(Func func) : func_{ std::forward<Func>(func) } {}
    ~ChunkForEach() = default;

    template <
      typename Stream
    >
    decltype(auto)
    operator()(Stream&& stream_) {
      apply(stream_, std::make_index_sequence<N>());
      return std::forward<Stream>(stream_);
    }

  private:
    template < typename Range, size_t ...I >
    void apply(Range&& range_, std::index_sequence<I...>) {
      auto len = range_.size();
      for (size_t i{}; i < len / N*N; i += N) func_(range_[i + I]...);
    }

    Func func_;
  };

}
}
}


#endif
