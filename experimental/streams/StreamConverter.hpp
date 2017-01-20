#ifndef CRANBERRIES_STREAMS_STREAM_CONVERTER_HPP
#define CRANBERRIES_STREAMS_STREAM_CONVERTER_HPP
#include <utility>
#include "cranberries_magic/tag.hpp"

namespace cranberries {
namespace streams {
namespace cranberries_magic {

    //----------------------------//
    // stream to Range Converters //
    //----------------------------//


    // Converter temporary proxy object
    // Convert stream to any container
    template < class Stream >
    class ImplicitStreamConverter
    {
      Stream stream_;
    public:
      ImplicitStreamConverter(Stream stream) noexcept
        : stream_{ std::forward<Stream>(stream) }
      {}

      template < typename Target >
      inline operator Target() const noexcept(false) {
        return stream_. template convert<Target>();
      }
    };

    // Implicit convert traits
    struct ImplicitStreamConvertInvoker {
      template < typename Stream >
      static constexpr auto invoke(Stream&& stream) noexcept {
        return ImplicitStreamConverter<Stream>(std::forward<Stream>(stream));
      }
    };

    // Explicit convert traits
    template < class Target >
    struct ExplicitStreamConverter {
      template < typename Stream >
      static constexpr auto convert(Stream&& stream) {
        return Target{ stream.begin(), stream.end() };
      }
    };


    struct ConvertAny {};

    template <
      template<
        class T,
        class Allocator = std::allocator<T>
      >
      class Cont
    >
    struct ConvertTo
    {
      template < typename T >
      using type = Cont<T>;
    };




} // ! namespace cranberries_magic

inline namespace eager {
  constexpr cranberries_magic::ConvertAny convert{};

  template < template<class, class> class Target >
  constexpr auto convert_to = cranberries_magic::ConvertTo<Target>{};
}

} // ! namespace stream
} // ! namespace cranberries

#endif