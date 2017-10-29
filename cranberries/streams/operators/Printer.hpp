/**
 * API for Git.io
 *
 * These codes are licensed under CC0.
 * http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */

#ifndef CRANBERRIES_STREAMS_OPERATORS_PRINTER_HPP
#define CRANBERRIES_STREAMS_OPERATORS_PRINTER_HPP
#include <string>
#include <iostream>
#include <type_traits>
#include <utility>
#include "../utility.hpp"

namespace cranberries {
namespace streams {
namespace operators {

  template < bool B >
  class Printer
    : cranberries_magic::EagerOperationModuleBase
  {
  public:
    Printer( std::ostream& os, std::string delim ) noexcept
      : os_{ os }, delim_{ delim }
    {}

    template <
      typename Stream
    >
    inline
    void
    operator()
    (
      Stream&& stream_
    )
      noexcept(false)
    {
      CRANBERRIES_STREAM_EMPTY_ERROR_THROW_IF( stream_.empty() );
      auto&& iter = stream_.begin();
      os_ << *iter;
      ++iter;
      for (; iter != stream_.end(); ++iter)
        os_ << delim_ << *iter;
      if (B) os_ << std::endl;
    }

  
    std::ostream& os_; // defalut is std::cout
  private:
    std::string delim_; // defalut is ", "
  };


  template < bool B >
  class FormatPrinter
    : cranberries_magic::EagerOperationModuleBase
  {
  public:
    FormatPrinter( const char* fmt, const char* delim ) noexcept
      : fmt_{ fmt }
      , delim_{ delim }
    {}

    template <
      typename Stream
    >
    inline
    void
    operator()
    (
      Stream&& stream_
    )
      noexcept(false)
    {
      CRANBERRIES_STREAM_EMPTY_ERROR_THROW_IF( stream_.empty() );
      auto&& iter = stream_.begin();
      printf(fmt_, *iter);
      ++iter;
      for (; iter != stream_.end(); ++iter){
        printf( "%s", delim_ );
        printf( fmt_, *iter );
      }
      if (B) printf("\n");
    }

  private:
    const char* fmt_;
    const char* delim_;
  };


} // ! namespace operators
} // ! namespace stream
} // ! namespace cranberries
#endif