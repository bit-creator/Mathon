export module Math.Vector4;

export import Math.Vector4f;
export import Math.Vector4d;
export import Math.Vector4i;

export namespace mathon {
    template < typename T >
        using Vector4 = impl::Vector< 4, T >;
};
