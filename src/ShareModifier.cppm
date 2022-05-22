export module Math.Impl.ShareModifier;

import <type_traits>;

export namespace mathon::impl {
    template < typename T >
    using without_modifier = T;

    template < typename T >
    using rvalue = T&&;

    template < typename T >
    using lvalue = const T&;

    template < typename T >
    using const_value = const T;

    template < typename T >
    using volatile_value = volatile T;

    template < typename T >
    using ref_value = T&;

    template < typename T >
    using rvalue_ref_value = T&&;

    template < 
        typename T,
        template < typename >
            typename... Modifiers
    > struct set_modifier_impl {  };

    template < typename T >
    struct set_modifier_impl<T> {
        using type = T;
    };
    
    template < 
        typename T,
        template < typename >
            typename Mod,
        template < typename >
            typename... Modifiers
    > struct set_modifier_impl<T, Mod, Modifiers...>:
        public set_modifier_impl<Mod<T>, Modifiers...> {  };

    template < 
        typename T,
        template < typename >
            typename... Modifiers
    > using set_modifier = typename set_modifier_impl<T, Modifiers...>::type;

    // share value category
    template < typename From, typename To > 
    struct share_category_impl: 
        public set_modifier_impl < To, without_modifier > {  };

    template < typename From, typename To >
    struct share_category_impl < lvalue<From>, To >:
        public set_modifier_impl < To, lvalue > {  };

    template < typename From, typename To >
    struct share_category_impl < rvalue < From >, To >:
        public set_modifier_impl < To, rvalue >{  };

    template < typename From, typename To >
    using share_category = typename share_category_impl<From, To>::type;

    // share const property
    template < typename From, typename To >
    struct share_const_impl:
        public set_modifier_impl < To, without_modifier > {  };

    template < typename From, typename To >
    struct share_const_impl < const_value<From>, To >:
        public set_modifier_impl < To, const_value > {  };

    template < typename From, typename To >
    using share_const = typename share_const_impl < From, To >::type;

    // share volatile property
    template < typename From, typename To >
    struct share_volatile_impl:
        public set_modifier_impl < To, without_modifier > {  };

    template < typename From, typename To >
    struct share_volatile_impl < volatile_value<From>, To >:
        public set_modifier_impl < To, volatile_value > {  };

    template < typename From, typename To >
    using share_volatile = typename share_volatile_impl < From, To >::type;

    // share const volatile
    template < typename From, typename To >
    using share_cv = share_const < From, share_volatile < From, To > >;

    // share references
    template < typename From, typename To > 
    struct share_ref_impl:
        public set_modifier_impl < To, without_modifier > {  };

    template < typename From, typename To >
    struct share_ref_impl < From&, To >:
        public set_modifier_impl < std::remove_reference_t<To>, ref_value > {  };

    template < typename From, typename To >
    struct share_ref_impl < From&&, To >:
        public set_modifier_impl < std::remove_reference_t<To>, rvalue_ref_value > {  };

    template < typename From, typename To >
    using share_ref = typename share_ref_impl<From, To>::type;

    // share cv reference
    template < typename From, typename To >
    using share_cvref = share_cv < From, share_ref < From, To > >;
}; // mathon::impl
