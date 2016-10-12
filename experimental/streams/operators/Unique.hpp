#ifndef CRANBERRIES_STREAMS_OPERATORS_UNIQUE_HPP
#define CRANBERRIES_STREAMS_OPERATORS_UNIQUE_HPP
#include <utility>
#include <type_traits>
#include <algorithm>
#include "..\utility.hpp"

namespace cranberries {
namespace streams {
namespace operators {

  struct UniqueProxy{};

  // Intermidiate Operation
  template <
    typename T
  >
  class Unique
    : private detail::IntermidiateStreamOperatorBase
    , private detail::StreamFilterBase
  {
  public:

    Unique() = default;

    template <
      typename Stream
    >
    inline
    decltype(auto)
    operator()
    (
      Stream&& stream_
    )
      noexcept(false)
    {
      CRANBERRIES_STREAM_EMPTY_ERROR_THROW_IF( stream_.empty() );
      auto&& source = stream_.get();
      source.erase( std::unique( source.begin(), source.end() ), source.end() );
      return std::forward<Stream>(stream_);
    }

    template <
      typename T
    >
    bool
    operator[]
    (
      T&& arg
    )
      noexcept
    {
      once( arg );
      if ( arg == prev ) {
        return true;
      }
      prev = arg;
      return false;
    }

    void once( T const& a ) {
      prev = a + 1;
      once_flag = false;
    }

  private:
    T prev;
    bool once_flag = true;
  };


} // ! namespace operators
} // ! namespace stream
} // ! namespace cranberries

#endif