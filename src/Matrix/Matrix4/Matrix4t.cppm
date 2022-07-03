export module Math.Matrix4;

export import Math.Matrix4f;
export import Math.Matrix4d;
export import Math.Matrix4i;

export namespace mathon {
    template < typename T >
        using Matrix4 = impl::Matrix< 4, T >;
};