export module Math.Vector2;

export import Math.Vector2f;
export import Math.Vector2d;
export import Math.Vector2i;

export namespace mathon {
    template < typename T >
        using Vector2 = impl::Vector< 2, T >;
};
