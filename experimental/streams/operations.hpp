#ifndef CRANBERRIES_STREAMS_OPERATIONS_HPP
#define CRANBERRIES_STREAMS_OPERATIONS_HPP
#include <utility>
#include <string>
#include <type_traits>
#include "forward.hpp"
#include "cranberries_magic/tag.hpp"


namespace cranberries {
namespace streams {

  //----------------------//
  // Intermediate process //
  //----------------------//


  inline operators::Splitter split(std::string s) noexcept { return{ s }; }

  inline namespace lazy {


    template < std::size_t N > operators::ChunkProxy<N> chunk() { return {}; }

    template <
      typename Pred
    >
    inline
    operators::Filter<Pred>
    filtered
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    inline operators::Sort<> sorted() noexcept { return{}; }
    inline operators::Sort<> sorted(size_t first, size_t last) noexcept { return{ first, last }; }

    inline operators::StableSort<> stable_sorted() noexcept { return{}; }

    inline operators::PartialSort<> partial_sorted(size_t n) noexcept { return{ n }; }

    inline operators::NthElement<> nth_elemented(size_t n) noexcept { return{ n }; }

    template <
      typename Pred
    >
    inline
    operators::Sort<Pred>
    sorted
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::StableSort<Pred>
    stable_sorted
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::StableSort<Pred>
    partial_sorted
    (
      size_t n,
      Pred&& pred
    )
      noexcept
    {
      return{ n, std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::NthElement<Pred>
    nth_elemented
    (
      size_t n,
      Pred&& pred
    )
      noexcept
    {
      return{ n, std::forward<Pred>(pred) };
    }

    template < typename G >
    inline operators::RadixSort<G, opt::ascending> ascending_radix_sorted(G&& get_key) noexcept { return{ std::forward<G>(get_key) }; }

    template < typename G >
    inline operators::RadixSort<G, opt::ascending> ascending_radix_sorted(size_t first, size_t last, G&& get_key) noexcept { return{ first, last, std::forward<G>(get_key) }; }

    inline operators::RadixSort<cranberries_magic::defaulted_t, opt::ascending> ascending_radix_sorted() noexcept { return{}; }

    inline operators::RadixSort<cranberries_magic::defaulted_t, opt::ascending> ascending_radix_sorted(size_t first, size_t last) noexcept { return{ first, last }; }

    template < typename G >
    inline operators::RadixSort<G, opt::descending> descending_radix_sorted(G&& get_key) noexcept { return{ std::forward<G>(get_key) }; }

    template < typename G >
    inline operators::RadixSort<G, opt::descending> descending_radix_sorted(size_t first, size_t last, G&& get_key) noexcept { return{ first, last, std::forward<G>(get_key) }; }

    inline operators::RadixSort<cranberries_magic::defaulted_t, opt::descending> descending_radix_sorted() noexcept { return{}; }

    inline operators::RadixSort<cranberries_magic::defaulted_t, opt::descending> descending_radix_sorted(size_t first, size_t last) noexcept { return{ first, last }; }

    inline operators::DistinctProxy distinctly() noexcept { return{}; }

    inline operators::Drop dropped(std::size_t n)  noexcept { return{ n }; }

    inline operators::Take taken(std::size_t n) noexcept { return{ n }; }

    template < typename To >
    inline operators::MapToProxy<To> transformed_to() noexcept { return{}; }


    template <
      typename UnaryFunc
    >
    inline
    operators::Peek<UnaryFunc>
    peeked
    (
      UnaryFunc&& func
    )
      noexcept
    {
      return{ std::forward<UnaryFunc>(func) };
    }


    template <
      typename UnaryFunc
    >
    inline
    operators::TransformProxy<UnaryFunc>
    transformed
    (
      UnaryFunc&& func
    )
      noexcept
    {
      return{ std::forward<UnaryFunc>(func) };
    }

    inline operators::UniqueProxy uniquely() noexcept { return{}; }

    inline operators::Reverse reversed() noexcept { return{}; }

    template < typename Engine = std::mt19937 >
    inline operators::Shuffle<Engine> shuffled(Engine&& engine_ = Engine{}) { return{ std::forward<Engine>(engine_) }; }

    template < typename ElemType >
    inline operators::Replace<ElemType> replaced(ElemType&& old_value, ElemType&& new_value) { return{ std::forward<ElemType>(old_value), std::forward<ElemType>(new_value) }; }

    template < typename UnaryOp, typename New >
    inline operators::ReplaceIf<UnaryOp, New> replaced_if(UnaryOp&& op, New&& new_value) { return{ std::forward<UnaryOp>(op), std::forward<New>(new_value) }; }

    template < typename Range >
    inline operators::SetUnion<Range> set_union(Range&& range) { return{ std::forward<Range>(range) }; }

    template < typename Range >
    inline operators::SetIntersection<Range> set_intersection(Range&& range) { return{ std::forward<Range>(range) }; }

    template < typename Range >
    inline operators::SetDiff<Range> set_difference(Range&& range) { return{ std::forward<Range>(range) }; }

    template < typename Range >
    inline operators::SetSymmetricDiff<Range> set_symmetric_difference(Range&& range) { return{ std::forward<Range>(range) }; }

    inline operators::SummaryStatProxy summary_stat() noexcept { return{}; }

    template <
      typename Stream,
      enabler_t<
        disjunction_v<cranberries_magic::is_infinite_stream<Stream>, is_range<Stream>>
      > = nullptr
    >
    inline
    operators::Merge<Stream>
    merged
    (
      Stream&& stream_
    )
      noexcept
    {
      return{ std::forward<Stream>(stream_) };
    }

    template <
      typename Range,
      enabler_t<
        disjunction_v<cranberries_magic::is_stream<Range>, is_range<Range>>
      > = nullptr
    >
    inline
    operators::Join<Range>
    joined(
      Range&& range_
    )
      noexcept
    {
      return{ std::forward<Range>(range_) };
    }


    inline operators::FlatProxy flatten() noexcept { return{}; }

    inline operators::FlatAllProxy all_flatten() noexcept { return{}; }

    inline operators::Stride strided(size_t step) noexcept { return{ step }; }

    inline operators::Slice sliced(size_t low, size_t up) noexcept { return{ low,up }; }

    template < typename UnaryOp >
    inline operators::FlatMap<UnaryOp> flat_transformed(UnaryOp&& op) noexcept { return{ std::forward<UnaryOp>(op) }; }

    template <
      typename Pred
    >
    inline
    operators::TakeWhile<Pred>
    taken_while
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::DropWhile<Pred>
    dropped_while
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }
  }

  inline namespace eager {

    inline operators::Repetition repeat(size_t times = 1) noexcept { return{ times }; }

    inline operators::Run run() noexcept { return{}; }

    inline operators::Fopen fopen(std::string path) { return { path }; }

    inline operators::ReadLine read_line() { return{}; }

    inline
    operators::ReadByte<cranberries_magic::defaulted_t, cranberries_magic::defaulted_t>
    read_byte() { return {}; }

    template <
      typename MaxSize
    >
    inline
    operators::ReadByte<cranberries_magic::defaulted_t, MaxSize>
    read_byte(MaxSize max_size) { return { max_size }; }

    template <
      typename Ate
    >
    inline
    operators::ReadByte<Ate, cranberries_magic::defaulted_t>
    read_n_byte(Ate ate) { return { ate }; }

    template <
      typename Ate,
      typename MaxSize
    >
    inline
    operators::ReadByte<Ate, MaxSize>
    read_n_byte(Ate ate, MaxSize max_size) { return { ate, max_size }; }

    inline operators::Write write() noexcept { return {}; }

    inline operators::WriteLine write_line() noexcept { return{}; }

    inline operators::WriteLine write_line(std::string delim) noexcept { return { delim }; }
    
    inline
    operators::Printer<false>
    print_to
    (
      std::ostream& os = std::cout, // default output std::cout
      std::string delim = ", " // default delimiter ", "
    ) {
      return{ os, delim };
    }

    inline
    operators::FormatPrinter<false>
    printf_to
    (
      const char* fmt,
      const char* delim = ", "
    ) {
      return{ fmt, delim };
    }
    
    inline
    operators::FormatPrinter<true>
    printfln_to
    (
      const char* fmt,
      const char* delim = ", "
    ) {
      return{ fmt, delim };
    }


    inline
    operators::Printer<true>
    println_to
    (
      std::ostream& os = std::cout, // default output std::cout
      std::string delim = ", " // default delimiter ", "
    ) {
      return{ os, delim };
    }

    inline
    operators::Printer<true>
    println_to
    (
      std::ostream&& os,
      std::string delim = ", " // default delimiter ", "
    ) {
      return{ os, delim };
    }


    template <
      typename Pred
    >
    inline
    operators::AllOf<Pred>
    all_of
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::AnyOf<Pred>
    any_of
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename Pred
    >
    inline
    operators::NoneOf<Pred>
    none_of
    (
      Pred&& pred
    )
      noexcept
    {
      return{ std::forward<Pred>(pred) };
    }

    template <
      typename InitialType,
      typename BinaryOp
    >
    inline
    operators::Accumulate<
      InitialType,
      BinaryOp
    >
    accumulate
    (
      InitialType init,
      BinaryOp&& op
    )
      noexcept
    {
      return{ init, std::forward<BinaryOp>(op) };
    }

    template <
      typename InitialType
    >
    inline
    operators::Accumulate<
      InitialType,
      cranberries_magic::defaulted_t
    >
    accumulate
    (
      InitialType init
    )
      noexcept
    {
      return{ init };
    }

    template < typename Target >
    inline operators::Count<Target> count(Target v) noexcept { return{ v }; }

    template < typename Pred >
    inline operators::CountIf<Pred> count_if(Pred&& pred_) noexcept { return{ pred_ }; }

    inline operators::Accumulate<cranberries_magic::defaulted_t, cranberries_magic::defaulted_t> accumulate() noexcept { return{}; }

    inline operators::Accumulate<cranberries_magic::defaulted_t, cranberries_magic::defaulted_t> sum() noexcept { return{}; }

    template < typename Pred >
    inline operators::SumIf<Pred> sum_if(Pred&& pred_) noexcept { return{ std::forward<Pred>(pred_) }; }

    inline operators::Product product() noexcept { return{}; }

    inline operators::Average average() noexcept { return{}; }

    inline operators::Median median() noexcept { return{}; }

    inline operators::Mode mode() noexcept { return{}; }

    template <
      template <class T, class Allocator = std::allocator<T>> class Seeq = std::vector,
      typename Keygen
    >
    inline operators::GrouingBy<opt::ordered, Seeq, Keygen> grouping_by(Keygen&& keygen) { return{ std::forward<Keygen>(keygen) }; }

    template <
      template <class T, class Allocator = std::allocator<T>> class Seeq = std::vector,
      typename Keygen
    >
    inline operators::PartitioningBy<opt::unordered, Seeq, Keygen> grouping_by_hash(Keygen&& pred) { return{ std::forward<Keygen>(pred) }; }

    template <
      template <class T, class Allocator = std::allocator<T>> class Seeq = std::vector,
      typename Pred
    >
    inline operators::PartitioningBy<opt::ordered, Seeq, Pred> partitioning_by(Pred&& pred) { return{ std::forward<Pred>(pred) }; }

    template <
      template <class T, class Allocator = std::allocator<T>> class Seeq = std::vector,
      typename Pred
    >
    inline operators::PartitioningBy<opt::unordered, Seeq, Pred> partitioning_by_hash(Pred&& pred) { return{ std::forward<Pred>(pred) }; }

    inline operators::MapToProxy<std::string> to_string() noexcept { return{}; }

    template <
      typename BinaryFunc
    >
    inline
    operators::AdjacentForEach<BinaryFunc>
    adjacent_for_each
    (
       BinaryFunc&& f
    )
      noexcept
    {
      return{ std::forward<BinaryFunc>(f) };
    }

    template <
      typename UnaryFunc
    >
    inline
    operators::ForEach<UnaryFunc>
    for_each
    (
      UnaryFunc&& func
    )
      noexcept
    {
      return{ std::forward<UnaryFunc>(func) };
    }

    template <
      size_t N,
      typename Func
    >
    inline
    operators::ChunkForEach<N,Func>
    chunk_for_each
    (
      Func&& func
    )
      noexcept
    {
      return{ std::forward<Func>(func) };
    }


  }

  //----------------------//
  // Operation Assistants //
  //----------------------//

  inline namespace lazy {

    template <
      typename Func
    >
    inline
    operators::Iinvoker<Func>
    invoked(
      Func&& f
    )
      noexcept
    {
      return { std::forward<Func>(f) };
    }
  }




} // ! namespace stream
} // ! namespace cranberries

#endif