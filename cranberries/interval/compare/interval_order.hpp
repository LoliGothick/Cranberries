#ifndef CRANBRIIES_INTERVAL_LIB_COMPARE_INTERVAL_ORDER_HPP
#define CRANBRIIES_INTERVAL_LIB_COMPARE_INTERVAL_ORDER_HPP

#include "../interval.hpp"
#include "explicit.hpp"

namespace cranberries {
namespace interval_lib {
namespace compare {
namespace interval_ordering_policy
{
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>& x, interval<R>& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>& x, interval<R> const& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>& x, interval<R>&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>& x, interval<R> const&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const& x, interval<R>& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const& x, interval<R> const& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const& x, interval<R>&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const& x, interval<R> const&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>&& x, interval<R>& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>&& x, interval<R> const& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>&& x, interval<R>&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>&& x, interval<R> const&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const&& x, interval<R>& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const&& x, interval<R> const& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const&& x, interval<R>&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const&& x, interval<R> const&& y )
  {
    return interval_less( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>& x, R&& y )
  {
    return interval_less( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const& x, R&& y )
  {
    return interval_less( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L>&& x, R&& y )
  {
    return interval_less( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( interval<L> const&& x, R&& y )
  {
    return interval_less( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( L&& x, interval<R>& y )
  {
    return interval_less( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( L&& x, interval<R> const& y )
  {
    return interval_less( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( L&& x, interval<R>&& y )
  {
    return interval_less( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<( L&& x, interval<R> const&& y )
  {
    return interval_less( std::forward<L>( x ), y );
  }

  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>& x, interval<R>& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>& x, interval<R> const& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>& x, interval<R>&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>& x, interval<R> const&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const& x, interval<R>& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const& x, interval<R> const& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const& x, interval<R>&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const& x, interval<R> const&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>&& x, interval<R>& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>&& x, interval<R> const& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>&& x, interval<R>&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>&& x, interval<R> const&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const&& x, interval<R>& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const&& x, interval<R> const& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const&& x, interval<R>&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const&& x, interval<R> const&& y )
  {
    return interval_less_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>& x, R&& y )
  {
    return interval_less_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const& x, R&& y )
  {
    return interval_less_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L>&& x, R&& y )
  {
    return interval_less_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( interval<L> const&& x, R&& y )
  {
    return interval_less_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( L&& x, interval<R>& y )
  {
    return interval_less_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( L&& x, interval<R> const& y )
  {
    return interval_less_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( L&& x, interval<R>&& y )
  {
    return interval_less_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator<=( L&& x, interval<R> const&& y )
  {
    return interval_less_or_equal( std::forward<L>( x ), y );
  }


  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>& x, interval<R>& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>& x, interval<R> const& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>& x, interval<R>&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>& x, interval<R> const&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const& x, interval<R>& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const& x, interval<R> const& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const& x, interval<R>&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const& x, interval<R> const&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>&& x, interval<R>& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>&& x, interval<R> const& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>&& x, interval<R>&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>&& x, interval<R> const&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const&& x, interval<R>& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const&& x, interval<R> const& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const&& x, interval<R>&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const&& x, interval<R> const&& y )
  {
    return interval_greater( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>& x, R&& y )
  {
    return interval_greater( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const& x, R&& y )
  {
    return interval_greater( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L>&& x, R&& y )
  {
    return interval_greater( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( interval<L> const&& x, R&& y )
  {
    return interval_greater( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( L&& x, interval<R>& y )
  {
    return interval_greater( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( L&& x, interval<R> const& y )
  {
    return interval_greater( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( L&& x, interval<R>&& y )
  {
    return interval_greater( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>( L&& x, interval<R> const&& y )
  {
    return interval_greater( std::forward<L>( x ), y );
  }


  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>& x, interval<R>& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>& x, interval<R> const& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>& x, interval<R>&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>& x, interval<R> const&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const& x, interval<R>& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const& x, interval<R> const& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const& x, interval<R>&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const& x, interval<R> const&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>&& x, interval<R>& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>&& x, interval<R> const& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>&& x, interval<R>&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>&& x, interval<R> const&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const&& x, interval<R>& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const&& x, interval<R> const& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const&& x, interval<R>&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const&& x, interval<R> const&& y )
  {
    return interval_greater_or_equal( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>& x, R&& y )
  {
    return interval_greater_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const& x, R&& y )
  {
    return interval_greater_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L>&& x, R&& y )
  {
    return interval_greater_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( interval<L> const&& x, R&& y )
  {
    return interval_greater_or_equal( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( L&& x, interval<R>& y )
  {
    return interval_greater_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( L&& x, interval<R> const& y )
  {
    return interval_greater_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( L&& x, interval<R>&& y )
  {
    return interval_greater_or_equal( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator>=( L&& x, interval<R> const&& y )
  {
    return interval_greater_or_equal( std::forward<L>( x ), y );
  }


  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>& x, interval<R>& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>& x, interval<R> const& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>& x, interval<R>&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>& x, interval<R> const&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const& x, interval<R>& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const& x, interval<R> const& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const& x, interval<R>&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const& x, interval<R> const&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>&& x, interval<R>& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>&& x, interval<R> const& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>&& x, interval<R>&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>&& x, interval<R> const&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const&& x, interval<R>& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const&& x, interval<R> const& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const&& x, interval<R>&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const&& x, interval<R> const&& y )
  {
    return interval_unordered( x, y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>& x, R&& y )
  {
    return interval_unordered( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const& x, R&& y )
  {
    return interval_unordered( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L>&& x, R&& y )
  {
    return interval_unordered( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( interval<L> const&& x, R&& y )
  {
    return interval_unordered( x, std::forward<R>( y ) );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( L&& x, interval<R>& y )
  {
    return interval_unordered( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( L&& x, interval<R> const& y )
  {
    return interval_unordered( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( L&& x, interval<R>&& y )
  {
    return interval_unordered( std::forward<L>( x ), y );
  }
  template < typename L, typename R >
  inline constexpr bool operator!=( L&& x, interval<R> const&& y )
  {
    return interval_unordered( std::forward<L>( x ), y );
  }

} // ! interval_oder
} // ! compare
} // ! interval_lib
} // ! cranberries
#endif