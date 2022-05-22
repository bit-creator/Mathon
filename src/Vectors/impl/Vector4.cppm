export module Math.Impl.Vector4;
export import Math.Impl.Vector3;
export import Math.Impl.Vector2;
export import Math.Impl.Signatures;

export namespace mathon::impl {
    template < typename T > 
        class Vector<4, T> {
        private:
            using L = LenghtT;

        private:
            T                   _x;
            T                   _y;
            T                   _z;
            T                   _w;

        public:
        // DESTRUCTOR
            constexpr ~Vector() =default;

        //  CONSTRUCTORS
                          constexpr Vector()                       : _x(   ), _y(   ), _z(   ), _w(   ) {  }
            explicit      constexpr Vector(T val)                  : _x(val), _y(val), _z(val), _w(val) {  }
                          constexpr Vector(T x_, T y_)             : _x(x_ ), _y(y_ ), _z(   ), _w(   ) {  }
                          constexpr Vector(T x_, T y_, T z_)       : _x(x_ ), _y(y_ ), _z(z_ ), _w(   ) {  }
                          constexpr Vector(T x_, T y_, T z_, T w_) : _x(x_ ), _y(y_ ), _z(z_ ), _w(w_ ) {  }

            constexpr Vector(Vector<2, T> v)                 : _x(v.x()), _y(v.y()), _z(     ), _w(     ) {  }
            constexpr Vector(Vector<3, T> v)                 : _x(v.x()), _y(v.y()), _z(v.z()), _w(     ) {  }
            constexpr Vector(Vector<4, T> const& v)          : _x(v.x()), _y(v.y()), _z(v.z()), _w(v.w()) {  }
            constexpr Vector(Vector<3, T> v, T a)            : _x(v.x()), _y(v.y()), _z(v.z()), _w(a    ) {  }
            constexpr Vector(T a, Vector<3, T> v)            : _x(a    ), _y(v.x()), _z(v.y()), _w(v.z()) {  }
            constexpr Vector(Vector<2, T> v, T a, T b)       : _x(v.x()), _y(v.y()), _z(a    ), _w(b    ) {  }
            constexpr Vector(T a, Vector<2, T> v, T b)       : _x(a    ), _y(v.x()), _z(v.y()), _w(b    ) {  }
            constexpr Vector(T a, T b, Vector<2, T> v)       : _x(a    ), _y(b    ), _z(v.x()), _w(v.y()) {  }
            constexpr Vector(Vector<2, T> v, Vector<2, T> o) : _x(v.x()), _y(v.y()), _z(o.x()), _w(o.y()) {  }


        // ASSIGMENTS
            template<L l> constexpr Vector<3, T>& operator =(Vector<l, T> vec) { 
                if(&vec == this) return *this;
                if constexpr (l == 4) xyzw(vec);
                if constexpr (l == 3) xyz(vec); 
                if constexpr (l == 2) xy(vec);
                return *this; 
            }

        //  GETTERS
            constexpr T x() const { return _x; }
            constexpr T y() const { return _y; }
            constexpr T z() const { return _z; }
            constexpr T w() const { return _w; }

            constexpr Vector<2, T> xx() const { return { _x, _x }; }
            constexpr Vector<2, T> xy() const { return { _x, _y }; }
            constexpr Vector<2, T> xz() const { return { _x, _z }; }
            constexpr Vector<2, T> xw() const { return { _x, _w }; }
            constexpr Vector<2, T> yx() const { return { _y, _x }; }
            constexpr Vector<2, T> yy() const { return { _y, _y }; }
            constexpr Vector<2, T> yz() const { return { _y, _z }; }
            constexpr Vector<2, T> yw() const { return { _y, _w }; }
            constexpr Vector<2, T> zx() const { return { _z, _x }; }
            constexpr Vector<2, T> zy() const { return { _z, _y }; }
            constexpr Vector<2, T> zz() const { return { _z, _z }; }
            constexpr Vector<2, T> zw() const { return { _z, _w }; }
            constexpr Vector<2, T> wx() const { return { _w, _x }; }
            constexpr Vector<2, T> wy() const { return { _w, _y }; }
            constexpr Vector<2, T> wz() const { return { _w, _z }; }
            constexpr Vector<2, T> ww() const { return { _w, _w }; }

            constexpr Vector<3, T> xxx() const { return { _x, _x, _x }; }
            constexpr Vector<3, T> xxy() const { return { _x, _x, _y }; }
            constexpr Vector<3, T> xxz() const { return { _x, _x, _z }; }
            constexpr Vector<3, T> xxw() const { return { _x, _x, _w }; }
            constexpr Vector<3, T> xyx() const { return { _x, _y, _x }; }
            constexpr Vector<3, T> xyy() const { return { _x, _y, _y }; }
            constexpr Vector<3, T> xyz() const { return { _x, _y, _z }; }
            constexpr Vector<3, T> xyw() const { return { _x, _y, _w }; }
            constexpr Vector<3, T> xzx() const { return { _x, _z, _x }; }
            constexpr Vector<3, T> xzy() const { return { _x, _z, _y }; }
            constexpr Vector<3, T> xzz() const { return { _x, _z, _z }; }
            constexpr Vector<3, T> xzw() const { return { _x, _z, _w }; }
            constexpr Vector<3, T> xwx() const { return { _x, _w, _x }; }
            constexpr Vector<3, T> xwy() const { return { _x, _w, _y }; }
            constexpr Vector<3, T> xwz() const { return { _x, _w, _z }; }
            constexpr Vector<3, T> xww() const { return { _x, _w, _w }; }
            constexpr Vector<3, T> yxx() const { return { _y, _x, _x }; }
            constexpr Vector<3, T> yxy() const { return { _y, _x, _y }; }
            constexpr Vector<3, T> yxz() const { return { _y, _x, _z }; }
            constexpr Vector<3, T> yxw() const { return { _y, _x, _w }; }
            constexpr Vector<3, T> yyx() const { return { _y, _y, _x }; }
            constexpr Vector<3, T> yyy() const { return { _y, _y, _y }; }
            constexpr Vector<3, T> yyz() const { return { _y, _y, _z }; }
            constexpr Vector<3, T> yyw() const { return { _y, _y, _w }; }
            constexpr Vector<3, T> yzx() const { return { _y, _z, _x }; }
            constexpr Vector<3, T> yzy() const { return { _y, _z, _y }; }
            constexpr Vector<3, T> yzz() const { return { _y, _z, _z }; }
            constexpr Vector<3, T> yzw() const { return { _y, _z, _w }; }
            constexpr Vector<3, T> ywx() const { return { _y, _w, _x }; }
            constexpr Vector<3, T> ywy() const { return { _y, _w, _y }; }
            constexpr Vector<3, T> ywz() const { return { _y, _w, _z }; }
            constexpr Vector<3, T> yww() const { return { _y, _w, _w }; }
            constexpr Vector<3, T> zxx() const { return { _z, _x, _x }; }
            constexpr Vector<3, T> zxy() const { return { _z, _x, _y }; }
            constexpr Vector<3, T> zxz() const { return { _z, _x, _z }; }
            constexpr Vector<3, T> zxw() const { return { _z, _x, _w }; }
            constexpr Vector<3, T> zyx() const { return { _z, _y, _x }; }
            constexpr Vector<3, T> zyy() const { return { _z, _y, _y }; }
            constexpr Vector<3, T> zyz() const { return { _z, _y, _z }; }
            constexpr Vector<3, T> zyw() const { return { _z, _y, _w }; }
            constexpr Vector<3, T> zzx() const { return { _z, _z, _x }; }
            constexpr Vector<3, T> zzy() const { return { _z, _z, _y }; }
            constexpr Vector<3, T> zzz() const { return { _z, _z, _z }; }
            constexpr Vector<3, T> zzw() const { return { _z, _z, _w }; }
            constexpr Vector<3, T> zwx() const { return { _z, _w, _x }; }
            constexpr Vector<3, T> zwy() const { return { _z, _w, _y }; }
            constexpr Vector<3, T> zwz() const { return { _z, _w, _z }; }
            constexpr Vector<3, T> zww() const { return { _z, _w, _w }; }
            constexpr Vector<3, T> wxx() const { return { _w, _x, _x }; }
            constexpr Vector<3, T> wxy() const { return { _w, _x, _y }; }
            constexpr Vector<3, T> wxz() const { return { _w, _x, _z }; }
            constexpr Vector<3, T> wxw() const { return { _w, _x, _w }; }
            constexpr Vector<3, T> wyx() const { return { _w, _y, _x }; }
            constexpr Vector<3, T> wyy() const { return { _w, _y, _y }; }
            constexpr Vector<3, T> wyz() const { return { _w, _y, _z }; }
            constexpr Vector<3, T> wyw() const { return { _w, _y, _w }; }
            constexpr Vector<3, T> wzx() const { return { _w, _z, _x }; }
            constexpr Vector<3, T> wzy() const { return { _w, _z, _y }; }
            constexpr Vector<3, T> wzz() const { return { _w, _z, _z }; }
            constexpr Vector<3, T> wzw() const { return { _w, _z, _w }; }
            constexpr Vector<3, T> wwx() const { return { _w, _w, _x }; }
            constexpr Vector<3, T> wwy() const { return { _w, _w, _y }; }
            constexpr Vector<3, T> wwz() const { return { _w, _w, _z }; }
            constexpr Vector<3, T> www() const { return { _w, _w, _w }; }

            constexpr Vector<4, T> xxxx() const { return { _x, _x, _x, _x }; }
            constexpr Vector<4, T> xxxy() const { return { _x, _x, _x, _y }; }
            constexpr Vector<4, T> xxxz() const { return { _x, _x, _x, _z }; }
            constexpr Vector<4, T> xxxw() const { return { _x, _x, _x, _w }; }
            constexpr Vector<4, T> xxyx() const { return { _x, _x, _y, _x }; }
            constexpr Vector<4, T> xxyy() const { return { _x, _x, _y, _y }; }
            constexpr Vector<4, T> xxyz() const { return { _x, _x, _y, _z }; }
            constexpr Vector<4, T> xxyw() const { return { _x, _x, _y, _w }; }
            constexpr Vector<4, T> xxzx() const { return { _x, _x, _z, _x }; }
            constexpr Vector<4, T> xxzy() const { return { _x, _x, _z, _y }; }
            constexpr Vector<4, T> xxzz() const { return { _x, _x, _z, _z }; }
            constexpr Vector<4, T> xxzw() const { return { _x, _x, _z, _w }; }
            constexpr Vector<4, T> xxwx() const { return { _x, _x, _w, _x }; }
            constexpr Vector<4, T> xxwy() const { return { _x, _x, _w, _y }; }
            constexpr Vector<4, T> xxwz() const { return { _x, _x, _w, _z }; }
            constexpr Vector<4, T> xxww() const { return { _x, _x, _w, _w }; }
            constexpr Vector<4, T> xyxx() const { return { _x, _y, _x, _x }; }
            constexpr Vector<4, T> xyxy() const { return { _x, _y, _x, _y }; }
            constexpr Vector<4, T> xyxz() const { return { _x, _y, _x, _z }; }
            constexpr Vector<4, T> xyxw() const { return { _x, _y, _x, _w }; }
            constexpr Vector<4, T> xyyx() const { return { _x, _y, _y, _x }; }
            constexpr Vector<4, T> xyyy() const { return { _x, _y, _y, _y }; }
            constexpr Vector<4, T> xyyz() const { return { _x, _y, _y, _z }; }
            constexpr Vector<4, T> xyyw() const { return { _x, _y, _y, _w }; }
            constexpr Vector<4, T> xyzx() const { return { _x, _y, _z, _x }; }
            constexpr Vector<4, T> xyzy() const { return { _x, _y, _z, _y }; }
            constexpr Vector<4, T> xyzz() const { return { _x, _y, _z, _z }; }
            constexpr Vector<4, T> xyzw() const { return { _x, _y, _z, _w }; }
            constexpr Vector<4, T> xywx() const { return { _x, _y, _w, _x }; }
            constexpr Vector<4, T> xywy() const { return { _x, _y, _w, _y }; }
            constexpr Vector<4, T> xywz() const { return { _x, _y, _w, _z }; }
            constexpr Vector<4, T> xyww() const { return { _x, _y, _w, _w }; }
            constexpr Vector<4, T> xzxx() const { return { _x, _z, _x, _x }; }
            constexpr Vector<4, T> xzxy() const { return { _x, _z, _x, _y }; }
            constexpr Vector<4, T> xzxz() const { return { _x, _z, _x, _z }; }
            constexpr Vector<4, T> xzxw() const { return { _x, _z, _x, _w }; }
            constexpr Vector<4, T> xzyx() const { return { _x, _z, _y, _x }; }
            constexpr Vector<4, T> xzyy() const { return { _x, _z, _y, _y }; }
            constexpr Vector<4, T> xzyz() const { return { _x, _z, _y, _z }; }
            constexpr Vector<4, T> xzyw() const { return { _x, _z, _y, _w }; }
            constexpr Vector<4, T> xzzx() const { return { _x, _z, _z, _x }; }
            constexpr Vector<4, T> xzzy() const { return { _x, _z, _z, _y }; }
            constexpr Vector<4, T> xzzz() const { return { _x, _z, _z, _z }; }
            constexpr Vector<4, T> xzzw() const { return { _x, _z, _z, _w }; }
            constexpr Vector<4, T> xzwx() const { return { _x, _z, _w, _x }; }
            constexpr Vector<4, T> xzwy() const { return { _x, _z, _w, _y }; }
            constexpr Vector<4, T> xzwz() const { return { _x, _z, _w, _z }; }
            constexpr Vector<4, T> xzww() const { return { _x, _z, _w, _w }; }
            constexpr Vector<4, T> xwxx() const { return { _x, _w, _x, _x }; }
            constexpr Vector<4, T> xwxy() const { return { _x, _w, _x, _y }; }
            constexpr Vector<4, T> xwxz() const { return { _x, _w, _x, _z }; }
            constexpr Vector<4, T> xwxw() const { return { _x, _w, _x, _w }; }
            constexpr Vector<4, T> xwyx() const { return { _x, _w, _y, _x }; }
            constexpr Vector<4, T> xwyy() const { return { _x, _w, _y, _y }; }
            constexpr Vector<4, T> xwyz() const { return { _x, _w, _y, _z }; }
            constexpr Vector<4, T> xwyw() const { return { _x, _w, _y, _w }; }
            constexpr Vector<4, T> xwzx() const { return { _x, _w, _z, _x }; }
            constexpr Vector<4, T> xwzy() const { return { _x, _w, _z, _y }; }
            constexpr Vector<4, T> xwzz() const { return { _x, _w, _z, _z }; }
            constexpr Vector<4, T> xwzw() const { return { _x, _w, _z, _w }; }
            constexpr Vector<4, T> xwwx() const { return { _x, _w, _w, _x }; }
            constexpr Vector<4, T> xwwy() const { return { _x, _w, _w, _y }; }
            constexpr Vector<4, T> xwwz() const { return { _x, _w, _w, _z }; }
            constexpr Vector<4, T> xwww() const { return { _x, _w, _w, _w }; }
            constexpr Vector<4, T> yxxx() const { return { _y, _x, _x, _x }; }
            constexpr Vector<4, T> yxxy() const { return { _y, _x, _x, _y }; }
            constexpr Vector<4, T> yxxz() const { return { _y, _x, _x, _z }; }
            constexpr Vector<4, T> yxxw() const { return { _y, _x, _x, _w }; }
            constexpr Vector<4, T> yxyx() const { return { _y, _x, _y, _x }; }
            constexpr Vector<4, T> yxyy() const { return { _y, _x, _y, _y }; }
            constexpr Vector<4, T> yxyz() const { return { _y, _x, _y, _z }; }
            constexpr Vector<4, T> yxyw() const { return { _y, _x, _y, _w }; }
            constexpr Vector<4, T> yxzx() const { return { _y, _x, _z, _x }; }
            constexpr Vector<4, T> yxzy() const { return { _y, _x, _z, _y }; }
            constexpr Vector<4, T> yxzz() const { return { _y, _x, _z, _z }; }
            constexpr Vector<4, T> yxzw() const { return { _y, _x, _z, _w }; }
            constexpr Vector<4, T> yxwx() const { return { _y, _x, _w, _x }; }
            constexpr Vector<4, T> yxwy() const { return { _y, _x, _w, _y }; }
            constexpr Vector<4, T> yxwz() const { return { _y, _x, _w, _z }; }
            constexpr Vector<4, T> yxww() const { return { _y, _x, _w, _w }; }
            constexpr Vector<4, T> yyxx() const { return { _y, _y, _x, _x }; }
            constexpr Vector<4, T> yyxy() const { return { _y, _y, _x, _y }; }
            constexpr Vector<4, T> yyxz() const { return { _y, _y, _x, _z }; }
            constexpr Vector<4, T> yyxw() const { return { _y, _y, _x, _w }; }
            constexpr Vector<4, T> yyyx() const { return { _y, _y, _y, _x }; }
            constexpr Vector<4, T> yyyy() const { return { _y, _y, _y, _y }; }
            constexpr Vector<4, T> yyyz() const { return { _y, _y, _y, _z }; }
            constexpr Vector<4, T> yyyw() const { return { _y, _y, _y, _w }; }
            constexpr Vector<4, T> yyzx() const { return { _y, _y, _z, _x }; }
            constexpr Vector<4, T> yyzy() const { return { _y, _y, _z, _y }; }
            constexpr Vector<4, T> yyzz() const { return { _y, _y, _z, _z }; }
            constexpr Vector<4, T> yyzw() const { return { _y, _y, _z, _w }; }
            constexpr Vector<4, T> yywx() const { return { _y, _y, _w, _x }; }
            constexpr Vector<4, T> yywy() const { return { _y, _y, _w, _y }; }
            constexpr Vector<4, T> yywz() const { return { _y, _y, _w, _z }; }
            constexpr Vector<4, T> yyww() const { return { _y, _y, _w, _w }; }
            constexpr Vector<4, T> yzxx() const { return { _y, _z, _x, _x }; }
            constexpr Vector<4, T> yzxy() const { return { _y, _z, _x, _y }; }
            constexpr Vector<4, T> yzxz() const { return { _y, _z, _x, _z }; }
            constexpr Vector<4, T> yzxw() const { return { _y, _z, _x, _w }; }
            constexpr Vector<4, T> yzyx() const { return { _y, _z, _y, _x }; }
            constexpr Vector<4, T> yzyy() const { return { _y, _z, _y, _y }; }
            constexpr Vector<4, T> yzyz() const { return { _y, _z, _y, _z }; }
            constexpr Vector<4, T> yzyw() const { return { _y, _z, _y, _w }; }
            constexpr Vector<4, T> yzzx() const { return { _y, _z, _z, _x }; }
            constexpr Vector<4, T> yzzy() const { return { _y, _z, _z, _y }; }
            constexpr Vector<4, T> yzzz() const { return { _y, _z, _z, _z }; }
            constexpr Vector<4, T> yzzw() const { return { _y, _z, _z, _w }; }
            constexpr Vector<4, T> yzwx() const { return { _y, _z, _w, _x }; }
            constexpr Vector<4, T> yzwy() const { return { _y, _z, _w, _y }; }
            constexpr Vector<4, T> yzwz() const { return { _y, _z, _w, _z }; }
            constexpr Vector<4, T> yzww() const { return { _y, _z, _w, _w }; }
            constexpr Vector<4, T> ywxx() const { return { _y, _w, _x, _x }; }
            constexpr Vector<4, T> ywxy() const { return { _y, _w, _x, _y }; }
            constexpr Vector<4, T> ywxz() const { return { _y, _w, _x, _z }; }
            constexpr Vector<4, T> ywxw() const { return { _y, _w, _x, _w }; }
            constexpr Vector<4, T> ywyx() const { return { _y, _w, _y, _x }; }
            constexpr Vector<4, T> ywyy() const { return { _y, _w, _y, _y }; }
            constexpr Vector<4, T> ywyz() const { return { _y, _w, _y, _z }; }
            constexpr Vector<4, T> ywyw() const { return { _y, _w, _y, _w }; }
            constexpr Vector<4, T> ywzx() const { return { _y, _w, _z, _x }; }
            constexpr Vector<4, T> ywzy() const { return { _y, _w, _z, _y }; }
            constexpr Vector<4, T> ywzz() const { return { _y, _w, _z, _z }; }
            constexpr Vector<4, T> ywzw() const { return { _y, _w, _z, _w }; }
            constexpr Vector<4, T> ywwx() const { return { _y, _w, _w, _x }; }
            constexpr Vector<4, T> ywwy() const { return { _y, _w, _w, _y }; }
            constexpr Vector<4, T> ywwz() const { return { _y, _w, _w, _z }; }
            constexpr Vector<4, T> ywww() const { return { _y, _w, _w, _w }; }
            constexpr Vector<4, T> zxxx() const { return { _z, _x, _x, _x }; }
            constexpr Vector<4, T> zxxy() const { return { _z, _x, _x, _y }; }
            constexpr Vector<4, T> zxxz() const { return { _z, _x, _x, _z }; }
            constexpr Vector<4, T> zxxw() const { return { _z, _x, _x, _w }; }
            constexpr Vector<4, T> zxyx() const { return { _z, _x, _y, _x }; }
            constexpr Vector<4, T> zxyy() const { return { _z, _x, _y, _y }; }
            constexpr Vector<4, T> zxyz() const { return { _z, _x, _y, _z }; }
            constexpr Vector<4, T> zxyw() const { return { _z, _x, _y, _w }; }
            constexpr Vector<4, T> zxzx() const { return { _z, _x, _z, _x }; }
            constexpr Vector<4, T> zxzy() const { return { _z, _x, _z, _y }; }
            constexpr Vector<4, T> zxzz() const { return { _z, _x, _z, _z }; }
            constexpr Vector<4, T> zxzw() const { return { _z, _x, _z, _w }; }
            constexpr Vector<4, T> zxwx() const { return { _z, _x, _w, _x }; }
            constexpr Vector<4, T> zxwy() const { return { _z, _x, _w, _y }; }
            constexpr Vector<4, T> zxwz() const { return { _z, _x, _w, _z }; }
            constexpr Vector<4, T> zxww() const { return { _z, _x, _w, _w }; }
            constexpr Vector<4, T> zyxx() const { return { _z, _y, _x, _x }; }
            constexpr Vector<4, T> zyxy() const { return { _z, _y, _x, _y }; }
            constexpr Vector<4, T> zyxz() const { return { _z, _y, _x, _z }; }
            constexpr Vector<4, T> zyxw() const { return { _z, _y, _x, _w }; }
            constexpr Vector<4, T> zyyx() const { return { _z, _y, _y, _x }; }
            constexpr Vector<4, T> zyyy() const { return { _z, _y, _y, _y }; }
            constexpr Vector<4, T> zyyz() const { return { _z, _y, _y, _z }; }
            constexpr Vector<4, T> zyyw() const { return { _z, _y, _y, _w }; }
            constexpr Vector<4, T> zyzx() const { return { _z, _y, _z, _x }; }
            constexpr Vector<4, T> zyzy() const { return { _z, _y, _z, _y }; }
            constexpr Vector<4, T> zyzz() const { return { _z, _y, _z, _z }; }
            constexpr Vector<4, T> zyzw() const { return { _z, _y, _z, _w }; }
            constexpr Vector<4, T> zywx() const { return { _z, _y, _w, _x }; }
            constexpr Vector<4, T> zywy() const { return { _z, _y, _w, _y }; }
            constexpr Vector<4, T> zywz() const { return { _z, _y, _w, _z }; }
            constexpr Vector<4, T> zyww() const { return { _z, _y, _w, _w }; }
            constexpr Vector<4, T> zzxx() const { return { _z, _z, _x, _x }; }
            constexpr Vector<4, T> zzxy() const { return { _z, _z, _x, _y }; }
            constexpr Vector<4, T> zzxz() const { return { _z, _z, _x, _z }; }
            constexpr Vector<4, T> zzxw() const { return { _z, _z, _x, _w }; }
            constexpr Vector<4, T> zzyx() const { return { _z, _z, _y, _x }; }
            constexpr Vector<4, T> zzyy() const { return { _z, _z, _y, _y }; }
            constexpr Vector<4, T> zzyz() const { return { _z, _z, _y, _z }; }
            constexpr Vector<4, T> zzyw() const { return { _z, _z, _y, _w }; }
            constexpr Vector<4, T> zzzx() const { return { _z, _z, _z, _x }; }
            constexpr Vector<4, T> zzzy() const { return { _z, _z, _z, _y }; }
            constexpr Vector<4, T> zzzz() const { return { _z, _z, _z, _z }; }
            constexpr Vector<4, T> zzzw() const { return { _z, _z, _z, _w }; }
            constexpr Vector<4, T> zzwx() const { return { _z, _z, _w, _x }; }
            constexpr Vector<4, T> zzwy() const { return { _z, _z, _w, _y }; }
            constexpr Vector<4, T> zzwz() const { return { _z, _z, _w, _z }; }
            constexpr Vector<4, T> zzww() const { return { _z, _z, _w, _w }; }
            constexpr Vector<4, T> zwxx() const { return { _z, _w, _x, _x }; }
            constexpr Vector<4, T> zwxy() const { return { _z, _w, _x, _y }; }
            constexpr Vector<4, T> zwxz() const { return { _z, _w, _x, _z }; }
            constexpr Vector<4, T> zwxw() const { return { _z, _w, _x, _w }; }
            constexpr Vector<4, T> zwyx() const { return { _z, _w, _y, _x }; }
            constexpr Vector<4, T> zwyy() const { return { _z, _w, _y, _y }; }
            constexpr Vector<4, T> zwyz() const { return { _z, _w, _y, _z }; }
            constexpr Vector<4, T> zwyw() const { return { _z, _w, _y, _w }; }
            constexpr Vector<4, T> zwzx() const { return { _z, _w, _z, _x }; }
            constexpr Vector<4, T> zwzy() const { return { _z, _w, _z, _y }; }
            constexpr Vector<4, T> zwzz() const { return { _z, _w, _z, _z }; }
            constexpr Vector<4, T> zwzw() const { return { _z, _w, _z, _w }; }
            constexpr Vector<4, T> zwwx() const { return { _z, _w, _w, _x }; }
            constexpr Vector<4, T> zwwy() const { return { _z, _w, _w, _y }; }
            constexpr Vector<4, T> zwwz() const { return { _z, _w, _w, _z }; }
            constexpr Vector<4, T> zwww() const { return { _z, _w, _w, _w }; }
            constexpr Vector<4, T> wxxx() const { return { _w, _x, _x, _x }; }
            constexpr Vector<4, T> wxxy() const { return { _w, _x, _x, _y }; }
            constexpr Vector<4, T> wxxz() const { return { _w, _x, _x, _z }; }
            constexpr Vector<4, T> wxxw() const { return { _w, _x, _x, _w }; }
            constexpr Vector<4, T> wxyx() const { return { _w, _x, _y, _x }; }
            constexpr Vector<4, T> wxyy() const { return { _w, _x, _y, _y }; }
            constexpr Vector<4, T> wxyz() const { return { _w, _x, _y, _z }; }
            constexpr Vector<4, T> wxyw() const { return { _w, _x, _y, _w }; }
            constexpr Vector<4, T> wxzx() const { return { _w, _x, _z, _x }; }
            constexpr Vector<4, T> wxzy() const { return { _w, _x, _z, _y }; }
            constexpr Vector<4, T> wxzz() const { return { _w, _x, _z, _z }; }
            constexpr Vector<4, T> wxzw() const { return { _w, _x, _z, _w }; }
            constexpr Vector<4, T> wxwx() const { return { _w, _x, _w, _x }; }
            constexpr Vector<4, T> wxwy() const { return { _w, _x, _w, _y }; }
            constexpr Vector<4, T> wxwz() const { return { _w, _x, _w, _z }; }
            constexpr Vector<4, T> wxww() const { return { _w, _x, _w, _w }; }
            constexpr Vector<4, T> wyxx() const { return { _w, _y, _x, _x }; }
            constexpr Vector<4, T> wyxy() const { return { _w, _y, _x, _y }; }
            constexpr Vector<4, T> wyxz() const { return { _w, _y, _x, _z }; }
            constexpr Vector<4, T> wyxw() const { return { _w, _y, _x, _w }; }
            constexpr Vector<4, T> wyyx() const { return { _w, _y, _y, _x }; }
            constexpr Vector<4, T> wyyy() const { return { _w, _y, _y, _y }; }
            constexpr Vector<4, T> wyyz() const { return { _w, _y, _y, _z }; }
            constexpr Vector<4, T> wyyw() const { return { _w, _y, _y, _w }; }
            constexpr Vector<4, T> wyzx() const { return { _w, _y, _z, _x }; }
            constexpr Vector<4, T> wyzy() const { return { _w, _y, _z, _y }; }
            constexpr Vector<4, T> wyzz() const { return { _w, _y, _z, _z }; }
            constexpr Vector<4, T> wyzw() const { return { _w, _y, _z, _w }; }
            constexpr Vector<4, T> wywx() const { return { _w, _y, _w, _x }; }
            constexpr Vector<4, T> wywy() const { return { _w, _y, _w, _y }; }
            constexpr Vector<4, T> wywz() const { return { _w, _y, _w, _z }; }
            constexpr Vector<4, T> wyww() const { return { _w, _y, _w, _w }; }
            constexpr Vector<4, T> wzxx() const { return { _w, _z, _x, _x }; }
            constexpr Vector<4, T> wzxy() const { return { _w, _z, _x, _y }; }
            constexpr Vector<4, T> wzxz() const { return { _w, _z, _x, _z }; }
            constexpr Vector<4, T> wzxw() const { return { _w, _z, _x, _w }; }
            constexpr Vector<4, T> wzyx() const { return { _w, _z, _y, _x }; }
            constexpr Vector<4, T> wzyy() const { return { _w, _z, _y, _y }; }
            constexpr Vector<4, T> wzyz() const { return { _w, _z, _y, _z }; }
            constexpr Vector<4, T> wzyw() const { return { _w, _z, _y, _w }; }
            constexpr Vector<4, T> wzzx() const { return { _w, _z, _z, _x }; }
            constexpr Vector<4, T> wzzy() const { return { _w, _z, _z, _y }; }
            constexpr Vector<4, T> wzzz() const { return { _w, _z, _z, _z }; }
            constexpr Vector<4, T> wzzw() const { return { _w, _z, _z, _w }; }
            constexpr Vector<4, T> wzwx() const { return { _w, _z, _w, _x }; }
            constexpr Vector<4, T> wzwy() const { return { _w, _z, _w, _y }; }
            constexpr Vector<4, T> wzwz() const { return { _w, _z, _w, _z }; }
            constexpr Vector<4, T> wzww() const { return { _w, _z, _w, _w }; }
            constexpr Vector<4, T> wwxx() const { return { _w, _w, _x, _x }; }
            constexpr Vector<4, T> wwxy() const { return { _w, _w, _x, _y }; }
            constexpr Vector<4, T> wwxz() const { return { _w, _w, _x, _z }; }
            constexpr Vector<4, T> wwxw() const { return { _w, _w, _x, _w }; }
            constexpr Vector<4, T> wwyx() const { return { _w, _w, _y, _x }; }
            constexpr Vector<4, T> wwyy() const { return { _w, _w, _y, _y }; }
            constexpr Vector<4, T> wwyz() const { return { _w, _w, _y, _z }; }
            constexpr Vector<4, T> wwyw() const { return { _w, _w, _y, _w }; }
            constexpr Vector<4, T> wwzx() const { return { _w, _w, _z, _x }; }
            constexpr Vector<4, T> wwzy() const { return { _w, _w, _z, _y }; }
            constexpr Vector<4, T> wwzz() const { return { _w, _w, _z, _z }; }
            constexpr Vector<4, T> wwzw() const { return { _w, _w, _z, _w }; }
            constexpr Vector<4, T> wwwx() const { return { _w, _w, _w, _x }; }
            constexpr Vector<4, T> wwwy() const { return { _w, _w, _w, _y }; }
            constexpr Vector<4, T> wwwz() const { return { _w, _w, _w, _z }; }
            constexpr Vector<4, T> wwww() const { return { _w, _w, _w, _w }; }

        //  SETTERS
            constexpr void x(T x_) { _x = x_; }
            constexpr void y(T y_) { _y = y_; }
            constexpr void z(T z_) { _z = z_; }
            constexpr void w(T w_) { _w = w_; }

            constexpr void xy(T a, T b) { _x = a; _y = b; }
            constexpr void xz(T a, T b) { _x = a; _z = b; }
            constexpr void xw(T a, T b) { _x = a; _w = b; }
            constexpr void yz(T a, T b) { _y = a; _z = b; }
            constexpr void yw(T a, T b) { _y = a; _w = b; }
            constexpr void zw(T a, T b) { _z = a; _w = b; }

            constexpr void xyz(T a, T b, T c) { _x = a; _y = b; _z = c; }
            constexpr void xyw(T a, T b, T c) { _x = a; _y = b; _w = c; }
            constexpr void xzw(T a, T b, T c) { _x = a; _z = b; _w = c; }
            constexpr void yzw(T a, T b, T c) { _y = a; _z = b; _w = c; }

            constexpr void xyzw(T x_, T y_, T z_, T w_) { _x = x_; _y = y_; _z = z_; _w = w_; };
            
            template<L l> constexpr void xy(Vector<l, T> v) { static_assert(l >= 2); _x = v.x(); _y = v.y(); }
            template<L l> constexpr void xz(Vector<l, T> v) { static_assert(l >= 2); _x = v.x(); _z = v.y(); }
            template<L l> constexpr void xw(Vector<l, T> v) { static_assert(l >= 2); _x = v.x(); _w = v.y(); }
            template<L l> constexpr void yz(Vector<l, T> v) { static_assert(l >= 2); _y = v.x(); _z = v.y(); }
            template<L l> constexpr void yw(Vector<l, T> v) { static_assert(l >= 2); _y = v.x(); _w = v.y(); }
            template<L l> constexpr void zw(Vector<l, T> v) { static_assert(l >= 2); _z = v.x(); _w = v.y(); }

            template<L l> constexpr void xyz(Vector<l, T> v) { static_assert(l >= 3); _x = v.x(); _y = v.y(); _z = v.z(); }
            template<L l> constexpr void xyw(Vector<l, T> v) { static_assert(l >= 3); _x = v.x(); _y = v.y(); _w = v.z(); }
            template<L l> constexpr void xzw(Vector<l, T> v) { static_assert(l >= 3); _x = v.x(); _z = v.y(); _w = v.z(); }
            template<L l> constexpr void yzw(Vector<l, T> v) { static_assert(l >= 3); _y = v.x(); _z = v.y(); _w = v.z(); }

            constexpr void xyz(Vector<2, T> v, T a) { _x = v.x(); _y = v.y(); _z = a; }
            constexpr void xyw(Vector<2, T> v, T a) { _x = v.x(); _y = v.y(); _w = a; }
            constexpr void xzw(Vector<2, T> v, T a) { _x = v.x(); _z = v.y(); _w = a; }
            constexpr void yzw(Vector<2, T> v, T a) { _y = v.x(); _z = v.y(); _w = a; }

            constexpr void xyz(T a, Vector<2, T> v) { _x = a; _y = v.x(); _z = v.y(); }
            constexpr void xyw(T a, Vector<2, T> v) { _x = a; _y = v.x(); _w = v.y(); }
            constexpr void xzw(T a, Vector<2, T> v) { _x = a; _z = v.x(); _w = v.y(); }
            constexpr void yzw(T a, Vector<2, T> v) { _y = a; _z = v.x(); _w = v.y(); }

            constexpr void xyzw(Vector<4, T> v) { _x = v.x(); _y = v.y(); _z = v.z(); _w = v.w(); }

            constexpr void xyzw(Vector<3, T> v, T a) { _x = v.x(); _y = v.y(); _z = v.z(); _w = a; }
            constexpr void xyzw(T a, Vector<3, T> v) { _x = a; _y = v.x(); _z = v.y(); _w = v.z(); }

            constexpr void xyzw(Vector<2, T> v, T a, T b) { _x = v.x(); _y = v.y(); _z = a; _w = b; }
            constexpr void xyzw(T a, Vector<2, T> v, T b) { _x = a; _y = v.x(); _z = v.y(); _w = b; }
            constexpr void xyzw(T a, T b, Vector<2, T> v) { _x = a; _y = b; _z = v.x(); _w = v.y(); }

            constexpr void xyzw(Vector<2, T> v, Vector<2, T> o) { _x = v.x(); _y = v.y(); _z = o.x(); _w = o.y(); }
        };
};