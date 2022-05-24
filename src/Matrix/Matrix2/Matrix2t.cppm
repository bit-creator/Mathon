export module Math.Matrix2;

export import Math.Matrix2f;
export import Math.Matrix2d;
export import Math.Matrix2i;

export namespace mathon {
    template < typename T >
        using Matrix2 = impl::Matrix< 2, T >;
};