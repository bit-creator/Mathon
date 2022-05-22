export module Math.Impl.Utilites;

// export import std;
import <type_traits>;
import <concepts>;

export namespace mathon::impl {
    using LenghtT = int;

    template<typename Tp> concept no_cvref = std::same_as<Tp, std::remove_cvref_t<Tp>>;

    template< typename U, typename T>
    concept pure_same_as = std::same_as<std::remove_cvref_t<U>, std::remove_cvref_t<T>>;

    template<typename Tp, typename Up> 
    concept no_cvref_convertible_to = 
        no_cvref<Tp> &&  no_cvref<Up> 
        &&  std::convertible_to<Tp, Up>;

    template<typename Tp> concept nt_c = std::is_nothrow_constructible_v<Tp>;
    template<typename Tp> concept nt_d = std::is_nothrow_destructible_v<Tp>;
    
    template<typename Tp> concept nt_cc = std::is_nothrow_copy_constructible_v<Tp>;
    template<typename Tp> concept nt_mc = std::is_nothrow_move_constructible_v<Tp>;
    
    template<typename Tp> concept nt_ca = std::is_nothrow_copy_assignable_v<Tp>;
    template<typename Tp> concept nt_ma = std::is_nothrow_move_assignable_v<Tp>;

    template<LenghtT len, LenghtT min> concept not_less_then = len >= min;
    template<LenghtT len, LenghtT req> concept equal         = len == req;

    template <
        typename T
    > concept has_value_type = std::same_as <
        typename std::remove_cvref_t<T>::value_type,
        typename std::remove_cvref_t<T>::value_type    
    >;
    
    template <
        typename T
    > concept has_dimensions = std::integral <
        decltype(std::remove_cvref_t<T>::dimensions)
    >;

    template < has_value_type T >
    using value_type = typename std::remove_cvref_t<T>::value_type;

    template < has_value_type T, has_value_type U >
    using common_value_type = std::remove_cvref_t<std::common_type_t<value_type<T>, value_type<U>>>;

    template < has_dimensions T > 
    constexpr inline LenghtT dimensions = std::remove_cvref_t<T>::dimensions;

    struct HelperData {
        constexpr static inline float eps = 0.00001;
    };
};

export namespace mathon::impl::operators {
    template < bool modify, typename T >
    struct return_type_impl {  };
    
    template < typename T >
    struct return_type_impl<false, T> { using type = T; };
    
    template < typename T >
    struct return_type_impl<true, T> { using type = void; };
    
    template < bool modify, typename T >
    using return_type = typename return_type_impl<modify, T>::type;
};