export module Math.Vector4i;
export import Math.Impl.Vector4;

export namespace mathon {
    using Vector4i = impl::Vector<4, int, false>;
    using Point4i  = impl::Vector<4, int, true>;
};