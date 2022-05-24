export module Math.Vector4f;
export import Math.Impl.Vector4;

export namespace mathon {
    using Vector4f = impl::Vector<4, float, false>;
    using Point4f  = impl::Vector<4, float, true>;
};