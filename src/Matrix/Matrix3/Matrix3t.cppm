export module Math.Matrix3;

export import Math.Matrix3f;
export import Math.Matrix3d;
export import Math.Matrix3i;

export namespace mathon {
    template < typename T >
        using Matrix3 = impl::Matrix< 3, T >;
};