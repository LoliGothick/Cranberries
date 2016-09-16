#ifndef CRANBERRIES_STREAMS_OPERATORS_SILCE_HPP
#define CRANBERRIES_STREAMS_OPERATORS_SLICE_HPP
#include <utility>
#include "..\detail\tag.hpp"
#include "..\utility.hpp"

namespace cranberries {
namespace streams {
namespace operators {

  // Intermidiate Operation
  class Slice
    : private detail::IntermidiateStreamOperatorBase
  {
  public:
    Slice( size_t l, size_t u ) : low_{ l }, up_{ u }, i{ 1 } {}

    Slice() = default;
    Slice( Slice const& ) = default;
    Slice( Slice&& ) = default;
    Slice& operator=( Slice const& ) = default;
    Slice& operator=(Slice&&) = default;

    template <
      typename Stream
    >
    decltype(auto)
    operator()
    (
      Stream&& stream_
    ) {
      CRANBERRIES_STREAM_EMPTY_ERROR_THROW_IF( stream_.empty() );
      auto&& src = stream_.get();
      for ( auto&& iter = src.begin(); iter != src.end(); ++i ) {
        if ( i < low_ || up_ < i ) iter = src.erase( iter );
        else { ++iter; }
      }
      return std::forward<Stream>( stream_ );
    }

    template <
      typename T
    >
    bool
    operator[]
    (
      T&& // no use
    )
      noexcept
    {
      return i++ < low_ || up_ < i;
    }

    size_t low() const { return low_; }
    size_t up() const { return up_; }

  private:
    size_t i;
    size_t low_;
    size_t up_;
  };


} // ! namespace operators
} // ! namespace stream
} // ! namespace cranberries

#endif
