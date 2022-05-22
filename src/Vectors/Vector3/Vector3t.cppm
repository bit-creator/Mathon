export module Math.Vector3;

export import Math.Vector3f;
export import Math.Vector3d;
export import Math.Vector3i;

export namespace mathon {
    template < typename T >
        using Vector3 = impl::Vector< 3, T >;
};