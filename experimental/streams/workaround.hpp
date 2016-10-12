#ifndef CRANBERRIES_STREAMS_WORKAROUND_HPP
#define CRANBERRIES_STREAMS_WORKAROUND_HPP

namespace cranberries {
namespace streams {
namespace workaround {

  template < bool B >
  struct expand_left {
    template < typename Stream, typename Elem >
    static void loop( Stream&& stream_, Elem&& elem_ ) noexcept {
      for (auto&& e : elem_)
        expand_left <
        is_range_v<decltype(e)>
        >::loop( std::forward<Stream>( stream_ ), std::forward<decltype(e)>( e ) );
    }
  };
  template < >
  struct expand_left<false> {
    template < typename Stream, typename Elem >
    static void loop( Stream&& stream_, Elem&& elem_ ) noexcept {
      stream_.emplace_back( elem_ );
    }
  };

  template < bool B >
  struct expand_right {
    template < typename Stream, typename Elem >
    static void loop( Stream&& stream_, Elem&& elem_ ) noexcept {
      using std::crbegin; using std::crend;
      for (auto&& iter = crbegin(elem_); iter != crend(elem_); ++iter )
        expand_right <
        is_range_v<decltype(*iter)>
        >::loop( std::forward<Stream>( stream_ ), *iter );
    }
  };
  template < >
  struct expand_right<false> {
    template < typename Stream, typename Elem >
    static void loop( Stream&& stream_, Elem&& elem_ ) noexcept {
      stream_.emplace_back( elem_ );
    }
  };



  template <
    bool IsStream
  >
    struct for_msvc
  {
    template <
      typename Stream,
      typename Range
    >
    static
    void
    invoke
    (
      Stream&& stream_,
      Range&& proj_
    )
      noexcept
    {
      stream_.insert( stream_.end(), proj_.rbegin(), proj_.rend() );
    }
  };

  template < >
  struct for_msvc<true>
  {
    template <
      typename Stream,
      typename Range
    >
    static
    void
    invoke
    (
      Stream&& stream_,
      Range&& proj_
    )
      noexcept
    {
      proj_.eval();
      stream_.insert( stream_.end(), proj_.rbegin(), proj_.rend() );
    }
  };



}
}
}
#endif