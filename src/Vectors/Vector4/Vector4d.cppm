export module Math.Vector4d;
export import Math.Impl.Vector4;

export namespace mathon {
    using Vector4d = impl::Vector<4, double, false>;
    using Point4d  = impl::Vector<4, double, true>;
    
};