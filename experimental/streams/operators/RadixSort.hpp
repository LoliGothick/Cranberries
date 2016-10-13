#ifndef CRANBERRIES_STREAMS_OPERATORS_RADIX_SORT_HPP
#define CRANBERRIES_STREAMS_OPERATORS_RADIX_SORT_HPP
#include <utility>
#include <type_traits>
#include "..\stream_error.hpp"
#include "..\utility.hpp"
#include "..\algorithm\radix_sort.hpp"
#include "..\detail\tag.hpp"

namespace cranberries {
namespace streams {
namespace operators {

  template <
    typename G,
    bool B
  >
  class RadixSort
    : private detail::IntermidiateStreamOperatorBase
  {
  public:
    RadixSort( G get_key ) noexcept
      : get_key{ std::forward<G>( get_key ) }
      , first{}
      , last{}
    {}
    RadixSort( size_t first, size_t last, G get_key ) noexcept
      : get_key{ std::forward<G>( get_key ) }
      , first{ first }
      , last{ last }
    {}

    template <
      typename Stream,
      typename E = typename std::decay_t<Stream>::element_type
    >
    inline
    decltype(auto)
    operator()
    (
      Stream&& stream_
    )
      noexcept
    {
      if (B && first == last)
        cranberries::ascending_radix_sort( stream_.begin(), stream_.end(), std::forward<G>(get_key) );
      else if ( B )
        cranberries::ascending_radix_sort( stream_.begin() + first - 1, stream_.begin() + last, std::forward<G>( get_key ) );
      else if ( !B && first == last )
        cranberries::descending_radix_sort( stream_.begin(), stream_.end(), std::forward<G>( get_key ) );
      else
        cranberries::descending_radix_sort( stream_.begin() + first - 1, stream_.begin() + last, std::forward<G>( get_key ) );

      return std::forward<Stream>( stream_ );
    }
  private:
    G get_key;
    size_t first;
    size_t last;
  };

  template <
    bool B
  >
  class RadixSort<detail::defaulted_t,B>
    : private detail::IntermidiateStreamOperatorBase
  {
  public:
    RadixSort( size_t first, size_t last ) noexcept
      : first{ first }
      , last{ last }
    {}

    RadixSort() noexcept : RadixSort{ 0,0 } {}

    template <
      typename Stream,
      typename E = typename std::decay_t<Stream>::element_type
    >
    inline
    decltype(auto)
    operator()
    (
      Stream&& stream_
    )
      noexcept
    {
      if (B && first == last)
        cranberries::ascending_radix_sort( stream_.begin(), stream_.end() );
      else if (B)
        cranberries::ascending_radix_sort( stream_.begin() + first - 1, stream_.begin() + last );
      else if (!B && first == last)
        cranberries::descending_radix_sort( stream_.begin(), stream_.end() );
      else
        cranberries::descending_radix_sort( stream_.begin() + first - 1, stream_.begin() + last );

      return std::forward<Stream>( stream_ );
    }

  private:
    size_t first{};
    size_t last{};
  };


} // ! namespace operators
} // ! namespace stream
} // ! namespace cranberries
#endif