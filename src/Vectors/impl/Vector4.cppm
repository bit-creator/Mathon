export module Math.Impl.Vector4;
export import Math.Impl.Vector3;
export import Math.Impl.Vector2;
export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier;

import <memory>;
import <concepts>;
import <cmath>;

template < typename T>
using vector = mathon::impl::Vector<4, T>;

template < typename T>
using vector2 = mathon::impl::Vector<2, T>;

template < typename T>
using vector3 = mathon::impl::Vector<3, T>;

namespace mathon::impl::operators { struct impl; };

export namespace mathon::impl {
template <
    no_cvref T
> class Vector<4, T> {
template <
    LenghtT l,
    no_cvref U
> friend class Vector;
public:
using value_type = T;
using vector     = vector<value_type>;
using vector2    = vector2<value_type>;
using vector3    = vector3<value_type>;
using reference  = vector&;

public:
    constexpr static inline LenghtT dimensions = 4;

private:
    value_type                               _x;
    value_type                               _y;
    value_type                               _z;
    value_type                               _w;

public:
// DESTRUCTOR
    constexpr ~Vector() noexcept(nt_d<T>) =default;

//  CONSTRUCTORS
    constexpr Vector() noexcept(nt_c<T>);

    constexpr explicit Vector(T val) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_, T z_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_, T z_, T w_) noexcept(nt_cc<T>);

    constexpr Vector(suitable_vector<vector> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector3> auto&& vec) noexcept(nt_cc<T>);

    constexpr Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector2> auto&& vec, T z_, T w_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(T x_, same_dim_vector<vector2> auto&& vec, T w_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);

    constexpr Vector(same_dim_vector<vector3> auto&& vec, T w_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, same_dim_vector<vector3> auto&& vec) noexcept(nt_cc<T>);
    
    constexpr Vector(same_dim_vector<vector2> auto&& vec1, same_dim_vector<vector2> auto&& vec2) noexcept(nt_cc<T>);

    constexpr reference
    operator =(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

    constexpr reference
    operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

    constexpr reference
    operator =(same_dim_vector<vector3> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);



//  GETTERS
    constexpr T x() const;
    constexpr T y() const;
    constexpr T z() const;
    constexpr T w() const;

    constexpr vector2 xx() const;
    constexpr vector2 xy() const;
    constexpr vector2 xz() const;
    constexpr vector2 xw() const;
    constexpr vector2 yx() const;
    constexpr vector2 yy() const;
    constexpr vector2 yz() const;
    constexpr vector2 yw() const;
    constexpr vector2 zx() const;
    constexpr vector2 zy() const;
    constexpr vector2 zz() const;
    constexpr vector2 zw() const;
    constexpr vector2 wx() const;
    constexpr vector2 wy() const;
    constexpr vector2 wz() const;
    constexpr vector2 ww() const;

    constexpr vector3 xxx() const;
    constexpr vector3 xxy() const;
    constexpr vector3 xxz() const;
    constexpr vector3 xxw() const;
    constexpr vector3 xyx() const;
    constexpr vector3 xyy() const;
    constexpr vector3 xyz() const;
    constexpr vector3 xyw() const;
    constexpr vector3 xzx() const;
    constexpr vector3 xzy() const;
    constexpr vector3 xzz() const;
    constexpr vector3 xzw() const;
    constexpr vector3 xwx() const;
    constexpr vector3 xwy() const;
    constexpr vector3 xwz() const;
    constexpr vector3 xww() const;
    constexpr vector3 yxx() const;
    constexpr vector3 yxy() const;
    constexpr vector3 yxz() const;
    constexpr vector3 yxw() const;
    constexpr vector3 yyx() const;
    constexpr vector3 yyy() const;
    constexpr vector3 yyz() const;
    constexpr vector3 yyw() const;
    constexpr vector3 yzx() const;
    constexpr vector3 yzy() const;
    constexpr vector3 yzz() const;
    constexpr vector3 yzw() const;
    constexpr vector3 ywx() const;
    constexpr vector3 ywy() const;
    constexpr vector3 ywz() const;
    constexpr vector3 yww() const;
    constexpr vector3 zxx() const;
    constexpr vector3 zxy() const;
    constexpr vector3 zxz() const;
    constexpr vector3 zxw() const;
    constexpr vector3 zyx() const;
    constexpr vector3 zyy() const;
    constexpr vector3 zyz() const;
    constexpr vector3 zyw() const;
    constexpr vector3 zzx() const;
    constexpr vector3 zzy() const;
    constexpr vector3 zzz() const;
    constexpr vector3 zzw() const;
    constexpr vector3 zwx() const;
    constexpr vector3 zwy() const;
    constexpr vector3 zwz() const;
    constexpr vector3 zww() const;
    constexpr vector3 wxx() const;
    constexpr vector3 wxy() const;
    constexpr vector3 wxz() const;
    constexpr vector3 wxw() const;
    constexpr vector3 wyx() const;
    constexpr vector3 wyy() const;
    constexpr vector3 wyz() const;
    constexpr vector3 wyw() const;
    constexpr vector3 wzx() const;
    constexpr vector3 wzy() const;
    constexpr vector3 wzz() const;
    constexpr vector3 wzw() const;
    constexpr vector3 wwx() const;
    constexpr vector3 wwy() const;
    constexpr vector3 wwz() const;
    constexpr vector3 www() const;

    constexpr vector xxxx() const;
    constexpr vector xxxy() const;
    constexpr vector xxxz() const;
    constexpr vector xxxw() const;
    constexpr vector xxyx() const;
    constexpr vector xxyy() const;
    constexpr vector xxyz() const;
    constexpr vector xxyw() const;
    constexpr vector xxzx() const;
    constexpr vector xxzy() const;
    constexpr vector xxzz() const;
    constexpr vector xxzw() const;
    constexpr vector xxwx() const;
    constexpr vector xxwy() const;
    constexpr vector xxwz() const;
    constexpr vector xxww() const;
    constexpr vector xyxx() const;
    constexpr vector xyxy() const;
    constexpr vector xyxz() const;
    constexpr vector xyxw() const;
    constexpr vector xyyx() const;
    constexpr vector xyyy() const;
    constexpr vector xyyz() const;
    constexpr vector xyyw() const;
    constexpr vector xyzx() const;
    constexpr vector xyzy() const;
    constexpr vector xyzz() const;
    constexpr vector xyzw() const;
    constexpr vector xywx() const;
    constexpr vector xywy() const;
    constexpr vector xywz() const;
    constexpr vector xyww() const;
    constexpr vector xzxx() const;
    constexpr vector xzxy() const;
    constexpr vector xzxz() const;
    constexpr vector xzxw() const;
    constexpr vector xzyx() const;
    constexpr vector xzyy() const;
    constexpr vector xzyz() const;
    constexpr vector xzyw() const;
    constexpr vector xzzx() const;
    constexpr vector xzzy() const;
    constexpr vector xzzz() const;
    constexpr vector xzzw() const;
    constexpr vector xzwx() const;
    constexpr vector xzwy() const;
    constexpr vector xzwz() const;
    constexpr vector xzww() const;
    constexpr vector xwxx() const;
    constexpr vector xwxy() const;
    constexpr vector xwxz() const;
    constexpr vector xwxw() const;
    constexpr vector xwyx() const;
    constexpr vector xwyy() const;
    constexpr vector xwyz() const;
    constexpr vector xwyw() const;
    constexpr vector xwzx() const;
    constexpr vector xwzy() const;
    constexpr vector xwzz() const;
    constexpr vector xwzw() const;
    constexpr vector xwwx() const;
    constexpr vector xwwy() const;
    constexpr vector xwwz() const;
    constexpr vector xwww() const;
    constexpr vector yxxx() const;
    constexpr vector yxxy() const;
    constexpr vector yxxz() const;
    constexpr vector yxxw() const;
    constexpr vector yxyx() const;
    constexpr vector yxyy() const;
    constexpr vector yxyz() const;
    constexpr vector yxyw() const;
    constexpr vector yxzx() const;
    constexpr vector yxzy() const;
    constexpr vector yxzz() const;
    constexpr vector yxzw() const;
    constexpr vector yxwx() const;
    constexpr vector yxwy() const;
    constexpr vector yxwz() const;
    constexpr vector yxww() const;
    constexpr vector yyxx() const;
    constexpr vector yyxy() const;
    constexpr vector yyxz() const;
    constexpr vector yyxw() const;
    constexpr vector yyyx() const;
    constexpr vector yyyy() const;
    constexpr vector yyyz() const;
    constexpr vector yyyw() const;
    constexpr vector yyzx() const;
    constexpr vector yyzy() const;
    constexpr vector yyzz() const;
    constexpr vector yyzw() const;
    constexpr vector yywx() const;
    constexpr vector yywy() const;
    constexpr vector yywz() const;
    constexpr vector yyww() const;
    constexpr vector yzxx() const;
    constexpr vector yzxy() const;
    constexpr vector yzxz() const;
    constexpr vector yzxw() const;
    constexpr vector yzyx() const;
    constexpr vector yzyy() const;
    constexpr vector yzyz() const;
    constexpr vector yzyw() const;
    constexpr vector yzzx() const;
    constexpr vector yzzy() const;
    constexpr vector yzzz() const;
    constexpr vector yzzw() const;
    constexpr vector yzwx() const;
    constexpr vector yzwy() const;
    constexpr vector yzwz() const;
    constexpr vector yzww() const;
    constexpr vector ywxx() const;
    constexpr vector ywxy() const;
    constexpr vector ywxz() const;
    constexpr vector ywxw() const;
    constexpr vector ywyx() const;
    constexpr vector ywyy() const;
    constexpr vector ywyz() const;
    constexpr vector ywyw() const;
    constexpr vector ywzx() const;
    constexpr vector ywzy() const;
    constexpr vector ywzz() const;
    constexpr vector ywzw() const;
    constexpr vector ywwx() const;
    constexpr vector ywwy() const;
    constexpr vector ywwz() const;
    constexpr vector ywww() const;
    constexpr vector zxxx() const;
    constexpr vector zxxy() const;
    constexpr vector zxxz() const;
    constexpr vector zxxw() const;
    constexpr vector zxyx() const;
    constexpr vector zxyy() const;
    constexpr vector zxyz() const;
    constexpr vector zxyw() const;
    constexpr vector zxzx() const;
    constexpr vector zxzy() const;
    constexpr vector zxzz() const;
    constexpr vector zxzw() const;
    constexpr vector zxwx() const;
    constexpr vector zxwy() const;
    constexpr vector zxwz() const;
    constexpr vector zxww() const;
    constexpr vector zyxx() const;
    constexpr vector zyxy() const;
    constexpr vector zyxz() const;
    constexpr vector zyxw() const;
    constexpr vector zyyx() const;
    constexpr vector zyyy() const;
    constexpr vector zyyz() const;
    constexpr vector zyyw() const;
    constexpr vector zyzx() const;
    constexpr vector zyzy() const;
    constexpr vector zyzz() const;
    constexpr vector zyzw() const;
    constexpr vector zywx() const;
    constexpr vector zywy() const;
    constexpr vector zywz() const;
    constexpr vector zyww() const;
    constexpr vector zzxx() const;
    constexpr vector zzxy() const;
    constexpr vector zzxz() const;
    constexpr vector zzxw() const;
    constexpr vector zzyx() const;
    constexpr vector zzyy() const;
    constexpr vector zzyz() const;
    constexpr vector zzyw() const;
    constexpr vector zzzx() const;
    constexpr vector zzzy() const;
    constexpr vector zzzz() const;
    constexpr vector zzzw() const;
    constexpr vector zzwx() const;
    constexpr vector zzwy() const;
    constexpr vector zzwz() const;
    constexpr vector zzww() const;
    constexpr vector zwxx() const;
    constexpr vector zwxy() const;
    constexpr vector zwxz() const;
    constexpr vector zwxw() const;
    constexpr vector zwyx() const;
    constexpr vector zwyy() const;
    constexpr vector zwyz() const;
    constexpr vector zwyw() const;
    constexpr vector zwzx() const;
    constexpr vector zwzy() const;
    constexpr vector zwzz() const;
    constexpr vector zwzw() const;
    constexpr vector zwwx() const;
    constexpr vector zwwy() const;
    constexpr vector zwwz() const;
    constexpr vector zwww() const;
    constexpr vector wxxx() const;
    constexpr vector wxxy() const;
    constexpr vector wxxz() const;
    constexpr vector wxxw() const;
    constexpr vector wxyx() const;
    constexpr vector wxyy() const;
    constexpr vector wxyz() const;
    constexpr vector wxyw() const;
    constexpr vector wxzx() const;
    constexpr vector wxzy() const;
    constexpr vector wxzz() const;
    constexpr vector wxzw() const;
    constexpr vector wxwx() const;
    constexpr vector wxwy() const;
    constexpr vector wxwz() const;
    constexpr vector wxww() const;
    constexpr vector wyxx() const;
    constexpr vector wyxy() const;
    constexpr vector wyxz() const;
    constexpr vector wyxw() const;
    constexpr vector wyyx() const;
    constexpr vector wyyy() const;
    constexpr vector wyyz() const;
    constexpr vector wyyw() const;
    constexpr vector wyzx() const;
    constexpr vector wyzy() const;
    constexpr vector wyzz() const;
    constexpr vector wyzw() const;
    constexpr vector wywx() const;
    constexpr vector wywy() const;
    constexpr vector wywz() const;
    constexpr vector wyww() const;
    constexpr vector wzxx() const;
    constexpr vector wzxy() const;
    constexpr vector wzxz() const;
    constexpr vector wzxw() const;
    constexpr vector wzyx() const;
    constexpr vector wzyy() const;
    constexpr vector wzyz() const;
    constexpr vector wzyw() const;
    constexpr vector wzzx() const;
    constexpr vector wzzy() const;
    constexpr vector wzzz() const;
    constexpr vector wzzw() const;
    constexpr vector wzwx() const;
    constexpr vector wzwy() const;
    constexpr vector wzwz() const;
    constexpr vector wzww() const;
    constexpr vector wwxx() const;
    constexpr vector wwxy() const;
    constexpr vector wwxz() const;
    constexpr vector wwxw() const;
    constexpr vector wwyx() const;
    constexpr vector wwyy() const;
    constexpr vector wwyz() const;
    constexpr vector wwyw() const;
    constexpr vector wwzx() const;
    constexpr vector wwzy() const;
    constexpr vector wwzz() const;
    constexpr vector wwzw() const;
    constexpr vector wwwx() const;
    constexpr vector wwwy() const;
    constexpr vector wwwz() const;
    constexpr vector wwww() const;

        //  SETTERS
    constexpr void x(T x_);
    constexpr void y(T y_);
    constexpr void z(T z_);
    constexpr void w(T w_);
    constexpr void xy(T a, T b);
    constexpr void xz(T a, T b);
    constexpr void xw(T a, T b);
    constexpr void yz(T a, T b);
    constexpr void yw(T a, T b);
    constexpr void zw(T a, T b);
    constexpr void xyz(T a, T b, T c);
    constexpr void xyw(T a, T b, T c);
    constexpr void xzw(T a, T b, T c);
    constexpr void yzw(T a, T b, T c);
    constexpr void xyzw(T x_, T y_, T z_, T w_);
    constexpr void xy(suitable_vector<vector2> auto&& v);
    constexpr void xz(suitable_vector<vector2> auto&& v);
    constexpr void xw(suitable_vector<vector2> auto&& v);
    constexpr void yz(suitable_vector<vector2> auto&& v);
    constexpr void yw(suitable_vector<vector2> auto&& v);
    constexpr void zw(suitable_vector<vector2> auto&& v);
    constexpr void xyz(suitable_vector<vector3> auto&& v);
    constexpr void xyw(suitable_vector<vector3> auto&& v);
    constexpr void xzw(suitable_vector<vector3> auto&& v);
    constexpr void yzw(suitable_vector<vector3> auto&& v);
    constexpr void xyw(same_dim_vector<vector2> auto&& v, T a);
    constexpr void xzw(same_dim_vector<vector2> auto&& v, T a);
    constexpr void xyz(same_dim_vector<vector2> auto&& v, T a);
    constexpr void yzw(same_dim_vector<vector2> auto&& v, T a);
    constexpr void xyz(T a, same_dim_vector<vector2> auto&& v);
    constexpr void xyw(T a, same_dim_vector<vector2> auto&& v);
    constexpr void xzw(T a, same_dim_vector<vector2> auto&& v);
    constexpr void yzw(T a, same_dim_vector<vector2> auto&& v);
    constexpr void xyzw(suitable_vector<vector> auto&& v);
    constexpr void xyzw(same_dim_vector<vector3> auto&& v, T a);
    constexpr void xyzw(T a, same_dim_vector<vector3> auto&& v);
    constexpr void xyzw(same_dim_vector<vector2> auto&& v, T a, T b);
    constexpr void xyzw(T a, same_dim_vector<vector2> auto&& v, T b);
    constexpr void xyzw(T a, T b, same_dim_vector<vector2> auto&& v);
    constexpr void xyzw(same_dim_vector<vector2> auto&& v, same_dim_vector<vector2> auto&& o);

// OPERATORS
    friend struct operators::impl;

// LOGICAL
    constexpr bool is_normalize()                        const noexcept;
    constexpr bool colinear_to(vector_4 auto&& vec)      const noexcept;
    constexpr bool orthogonal_to(vector_4 auto&& vec)    const noexcept;
    constexpr bool codirectional_to(vector_4 auto&& vec) const noexcept;

// MODIFIER
    constexpr void normalize() noexcept;

// INFO
    constexpr auto   length() const noexcept;
    constexpr double cos_angle(vector_4 auto&& vec) const noexcept;
}; // Vector<4, T>

template < no_cvref T > constexpr 
vector<T>::Vector() noexcept(nt_c<T>)
    : Vector(T(), T(), T(), T()) {
}

template < no_cvref T > constexpr
vector<T>::Vector(T val) noexcept(nt_cc<T>)
    : Vector(val, val, val, val) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_) noexcept(nt_cc<T>)
    : Vector(x_, y_, T(), T()) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_, T z_) noexcept(nt_cc<T>)
    : Vector(x_, y_, z_, T()) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_, T z_, T w_) noexcept(nt_cc<T>)
    : _x(x_), _y(y_), _z(z_), _w(w_) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(suitable_vector<vector> auto&& vec) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y, vec._z, vec._w) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector3> auto&& vec) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y, vec._z) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y, z_) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector2> auto&& vec, T z_, T w_) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y, z_, w_) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : Vector(x_, vec._x, vec._y) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, same_dim_vector<vector2> auto&& vec, T w_) noexcept(nt_cc<T>)
    : Vector(x_, vec._x, vec._y, w_) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : Vector(x_, y_, vec._x, vec._y) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector3> auto&& vec, T w_) noexcept(nt_cc<T>)
    : Vector(vec._x, vec._y, vec._z, w_) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, same_dim_vector<vector3> auto&& vec) noexcept(nt_cc<T>)  
    : Vector(x_, vec._x, vec._y, vec._z) {
}

template < no_cvref T > constexpr 
vector<T>::Vector(same_dim_vector<vector2> auto&& vec1, same_dim_vector<vector2> auto&& vec2) noexcept(nt_cc<T>)
    : Vector(vec1._x, vec1._y, vec2._x, vec2._y) {
}


template < no_cvref T > constexpr vector<T>& 
vector<T>::operator =(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
        if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = std::forward<share_category<decltype(vec), T>>(vec._z);
    _w = std::forward<share_category<decltype(vec), T>>(vec._w);

    return *this;
}

template < no_cvref T > constexpr vector<T>& 
vector<T>::operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
        if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = T();
    _w = T();

    return *this;
}

template < no_cvref T > constexpr vector<T>& 
vector<T>::operator =(same_dim_vector<vector3> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
        if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = std::forward<share_category<decltype(vec), T>>(vec._z);
    _w = T();

    return *this;
}


template < no_cvref T > constexpr void
vector<T>::x(T x_) {
    _x = x_;
}

template < no_cvref T > constexpr void 
vector<T>::y(T y_) {
    _y = y_;
}

template < no_cvref T > constexpr void 
vector<T>::z(T z_) {
    _z = z_;
}

template < no_cvref T > constexpr void 
vector<T>::w(T w_) {
    _w = w_;
}

template < no_cvref T > constexpr void 
vector<T>::xy(T a, T b) {
    _x = a;
    _y = b;
}

template < no_cvref T > constexpr void 
vector<T>::xz(T a, T b) {
    _x = a;
    _z = b;
}

template < no_cvref T > constexpr void 
vector<T>::xw(T a, T b) {
    _x = a;
    _w = b;
}

template < no_cvref T > constexpr void 
vector<T>::yz(T a, T b) {
    _y = a;
    _z = b;
}

template < no_cvref T > constexpr void 
vector<T>::yw(T a, T b) {
    _y = a;
    _w = b;
}

template < no_cvref T > constexpr void 
vector<T>::zw(T a, T b) {
    _z = a;
    _w = b;
}

template < no_cvref T > constexpr void 
vector<T>::xyz(T a, T b, T c) {
    _x = a;
    _y = b;
    _z = c;
}

template < no_cvref T > constexpr void 
vector<T>::xyw(T a, T b, T c) {
    _x = a;
    _y = b;
    _w = c;
}

template < no_cvref T > constexpr void 
vector<T>::xzw(T a, T b, T c) {
    _x = a;
    _z = b;
    _w = c;
}

template < no_cvref T > constexpr void 
vector<T>::yzw(T a, T b, T c) {
    _y = a;
    _z = b;
    _w = c;
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(T x_, T y_, T z_, T w_) {
    _x = x_;
    _y = y_;
    _z = z_;
    _w = w_;
}

template < no_cvref T > constexpr void 
vector<T>::xy(suitable_vector<vector2> auto&& v) {
    _x = v.x();
    _y = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xz(suitable_vector<vector2> auto&& v) {
    _x = v.x();
    _z = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xw(suitable_vector<vector2> auto&& v) {
    _x = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void
vector<T>::yz(suitable_vector<vector2> auto&& v) {
    _y = v.x();
    _z = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::yw(suitable_vector<vector2> auto&& v) {
    _y = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::zw(suitable_vector<vector2> auto&& v) {
    _z = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xyz(suitable_vector<vector3> auto&& v) {
    _x = v.x();
    _y = v.y();
    _z = v.z();
}

template < no_cvref T > constexpr void 
vector<T>::xyw(suitable_vector<vector3> auto&& v) {
    _x = v.x();
    _y = v.y();
    _w = v.z();
}

template < no_cvref T > constexpr void 
vector<T>::xzw(suitable_vector<vector3> auto&& v) {
    _x = v.x();
    _z = v.y();
    _w = v.z();
}

template < no_cvref T > constexpr void 
vector<T>::yzw(suitable_vector<vector3> auto&& v) {
    _y = v.x();
    _z = v.y();
    _w = v.z();
}

template < no_cvref T > constexpr void 
vector<T>::xyz(same_dim_vector<vector2> auto&& v, T a) {
    _x = v.x();
    _y = v.y();
    _z = a;
}

template < no_cvref T > constexpr void 
vector<T>::xyw(same_dim_vector<vector2> auto&& v, T a) {
    _x = v.x();
    _y = v.y();
    _w = a;
}

template < no_cvref T > constexpr void 
vector<T>::xzw(same_dim_vector<vector2> auto&& v, T a) {
    _x = v.x();
    _z = v.y();
    _w = a;
}

template < no_cvref T > constexpr void 
vector<T>::yzw(same_dim_vector<vector2> auto&& v, T a) {
    _y = v.x();
    _z = v.y();
    _w = a;
}

template < no_cvref T > constexpr void 
vector<T>::xyz(T a, same_dim_vector<vector2> auto&& v) {
    _x = a;
    _y = v.x();
    _z = v.y();
    }

template < no_cvref T > constexpr void 
vector<T>::xyw(T a, same_dim_vector<vector2> auto&& v) {
    _x = a;
    _y = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xzw(T a, same_dim_vector<vector2> auto&& v) {
    _x = a;
    _z = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::yzw(T a, same_dim_vector<vector2> auto&& v) {
    _y = a;
    _z = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(suitable_vector<vector> auto&& v) {
    _x = v.x();
    _y = v.y();
    _z = v.z();
    _w = v.w();
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(same_dim_vector<vector3> auto&& v, T a) {
    _x = v.x();
    _y = v.y();
    _z = v.z();
    _w = a;
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(T a, same_dim_vector<vector3> auto&& v) {
    _x = a;
    _y = v.x();
    _z = v.y();
    _w = v.z();
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(same_dim_vector<vector2> auto&& v, T a, T b) {
    _x = v.x();
    _y = v.y();
    _z = a;
    _w = b;
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(T a, same_dim_vector<vector2> auto&& v, T b) {
    _x = a;
    _y = v.x();
    _z = v.y();
    _w = b;
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(T a, T b, same_dim_vector<vector2> auto&& v) {
    _x = a;
    _y = b;
    _z = v.x();
    _w = v.y();
}

template < no_cvref T > constexpr void 
vector<T>::xyzw(same_dim_vector<vector2> auto&& v, same_dim_vector<vector2> auto&& o) {
    _x = v.x();
    _y = v.y();
    _z = o.x();
    _w = o.y();
}


template < no_cvref T > constexpr T
vector<T>::x() const {
    return _x;
}

template < no_cvref T > constexpr T
vector<T>::y() const {
    return _y;
}

template < no_cvref T > constexpr T
vector<T>::z() const {
    return _z;
}

template < no_cvref T > constexpr T
vector<T>::w() const {
    return _w;
}

template < no_cvref T > constexpr vector2<T>
vector<T>::xx() const {
    return { _x, _x };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::xy() const {
    return { _x, _y };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::xz() const {
    return { _x, _z };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::xw() const {
    return { _x, _w };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::yx() const {
    return { _y, _x };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::yy() const {
    return { _y, _y };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::yz() const {
    return { _y, _z };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::yw() const {
    return { _y, _w };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::zx() const {
    return { _z, _x };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::zy() const {
    return { _z, _y };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::zz() const {
    return { _z, _z };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::zw() const {
    return { _z, _w };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::wx() const {
    return { _w, _x };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::wy() const {
    return { _w, _y };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::wz() const {
    return { _w, _z };
}

template < no_cvref T > constexpr vector2<T>
vector<T>::ww() const {
    return { _w, _w };
}


template < no_cvref T > constexpr vector3<T>
vector<T>::xxx() const {
    return { _x, _x, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xxy() const {
    return { _x, _x, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xxz() const {
    return { _x, _x, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xxw() const {
    return { _x, _x, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xyx() const {
    return { _x, _y, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xyy() const {
    return { _x, _y, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xyz() const {
    return { _x, _y, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xyw() const {
    return { _x, _y, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xzx() const {
    return { _x, _z, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xzy() const {
    return { _x, _z, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xzz() const {
    return { _x, _z, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xzw() const {
    return { _x, _z, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xwx() const {
    return { _x, _w, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xwy() const {
    return { _x, _w, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xwz() const {
    return { _x, _w, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::xww() const {
    return { _x, _w, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yxx() const {
    return { _y, _x, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yxy() const {
    return { _y, _x, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yxz() const {
    return { _y, _x, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yxw() const {
    return { _y, _x, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yyx() const {
    return { _y, _y, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yyy() const {
    return { _y, _y, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yyz() const {
    return { _y, _y, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yyw() const {
    return { _y, _y, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yzx() const {
    return { _y, _z, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yzy() const {
    return { _y, _z, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yzz() const {
    return { _y, _z, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yzw() const {
    return { _y, _z, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::ywx() const {
    return { _y, _w, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::ywy() const {
    return { _y, _w, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::ywz() const {
    return { _y, _w, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::yww() const {
    return { _y, _w, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zxx() const {
    return { _z, _x, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zxy() const {
    return { _z, _x, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zxz() const {
    return { _z, _x, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zxw() const {
    return { _z, _x, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zyx() const {
    return { _z, _y, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zyy() const {
    return { _z, _y, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zyz() const {
    return { _z, _y, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zyw() const {
    return { _z, _y, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zzx() const {
    return { _z, _z, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zzy() const {
    return { _z, _z, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zzz() const {
    return { _z, _z, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zzw() const {
    return { _z, _z, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zwx() const {
    return { _z, _w, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zwy() const {
    return { _z, _w, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zwz() const {
    return { _z, _w, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::zww() const {
    return { _z, _w, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wxx() const {
    return { _w, _x, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wxy() const {
    return { _w, _x, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wxz() const {
    return { _w, _x, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wxw() const {
    return { _w, _x, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wyx() const {
    return { _w, _y, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wyy() const {
    return { _w, _y, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wyz() const {
    return { _w, _y, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wyw() const {
    return { _w, _y, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wzx() const {
    return { _w, _z, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wzy() const {
    return { _w, _z, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wzz() const {
    return { _w, _z, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wzw() const {
    return { _w, _z, _w };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wwx() const {
    return { _w, _w, _x };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wwy() const {
    return { _w, _w, _y };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::wwz() const {
    return { _w, _w, _z };
}

template < no_cvref T > constexpr vector3<T>
vector<T>::www() const {
    return { _w, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxxx() const {
    return { _x, _x, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxxy() const {
    return { _x, _x, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxxz() const {
    return { _x, _x, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxxw() const {
    return { _x, _x, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxyx() const {
    return { _x, _x, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxyy() const {
    return { _x, _x, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxyz() const {
    return { _x, _x, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxyw() const {
    return { _x, _x, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxzx() const {
    return { _x, _x, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxzy() const {
    return { _x, _x, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxzz() const {
    return { _x, _x, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxzw() const {
    return { _x, _x, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxwx() const {
    return { _x, _x, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxwy() const {
    return { _x, _x, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxwz() const {
    return { _x, _x, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxww() const {
    return { _x, _x, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyxx() const {
    return { _x, _y, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyxy() const {
    return { _x, _y, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyxz() const {
    return { _x, _y, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyxw() const {
    return { _x, _y, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyyx() const {
    return { _x, _y, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyyy() const {
    return { _x, _y, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyyz() const {
    return { _x, _y, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyyw() const {
    return { _x, _y, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyzx() const {
    return { _x, _y, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyzy() const {
    return { _x, _y, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyzz() const {
    return { _x, _y, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyzw() const {
    return { _x, _y, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xywx() const {
    return { _x, _y, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xywy() const {
    return { _x, _y, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xywz() const {
    return { _x, _y, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyww() const {
    return { _x, _y, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzxx() const {
    return { _x, _z, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzxy() const {
    return { _x, _z, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzxz() const {
    return { _x, _z, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzxw() const {
    return { _x, _z, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzyx() const {
    return { _x, _z, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzyy() const {
    return { _x, _z, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzyz() const {
    return { _x, _z, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzyw() const {
    return { _x, _z, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzzx() const {
    return { _x, _z, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzzy() const {
    return { _x, _z, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzzz() const {
    return { _x, _z, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzzw() const {
    return { _x, _z, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzwx() const {
    return { _x, _z, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzwy() const {
    return { _x, _z, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzwz() const {
    return { _x, _z, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzww() const {
    return { _x, _z, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwxx() const {
    return { _x, _w, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwxy() const {
    return { _x, _w, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwxz() const {
    return { _x, _w, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwxw() const {
    return { _x, _w, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwyx() const {
    return { _x, _w, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwyy() const {
    return { _x, _w, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwyz() const {
    return { _x, _w, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwyw() const {
    return { _x, _w, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwzx() const {
    return { _x, _w, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwzy() const {
    return { _x, _w, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwzz() const {
    return { _x, _w, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwzw() const {
    return { _x, _w, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwwx() const {
    return { _x, _w, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwwy() const {
    return { _x, _w, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwwz() const {
    return { _x, _w, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xwww() const {
    return { _x, _w, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxxx() const {
    return { _y, _x, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxxy() const {
    return { _y, _x, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxxz() const {
    return { _y, _x, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxxw() const {
    return { _y, _x, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxyx() const {
    return { _y, _x, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxyy() const {
    return { _y, _x, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxyz() const {
    return { _y, _x, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxyw() const {
    return { _y, _x, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxzx() const {
    return { _y, _x, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxzy() const {
    return { _y, _x, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxzz() const {
    return { _y, _x, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxzw() const {
    return { _y, _x, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxwx() const {
    return { _y, _x, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxwy() const {
    return { _y, _x, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxwz() const {
    return { _y, _x, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxww() const {
    return { _y, _x, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyxx() const {
    return { _y, _y, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyxy() const {
    return { _y, _y, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyxz() const {
    return { _y, _y, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyxw() const {
    return { _y, _y, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyyx() const {
    return { _y, _y, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyyy() const {
    return { _y, _y, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyyz() const {
    return { _y, _y, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyyw() const {
    return { _y, _y, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyzx() const {
    return { _y, _y, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyzy() const {
    return { _y, _y, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyzz() const {
    return { _y, _y, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyzw() const {
    return { _y, _y, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yywx() const {
    return { _y, _y, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yywy() const {
    return { _y, _y, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yywz() const {
    return { _y, _y, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyww() const {
    return { _y, _y, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzxx() const {
    return { _y, _z, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzxy() const {
    return { _y, _z, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzxz() const {
    return { _y, _z, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzxw() const {
    return { _y, _z, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzyx() const {
    return { _y, _z, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzyy() const {
    return { _y, _z, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzyz() const {
    return { _y, _z, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzyw() const {
    return { _y, _z, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzzx() const {
    return { _y, _z, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzzy() const {
    return { _y, _z, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzzz() const {
    return { _y, _z, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzzw() const {
    return { _y, _z, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzwx() const {
    return { _y, _z, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzwy() const {
    return { _y, _z, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzwz() const {
    return { _y, _z, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzww() const {
    return { _y, _z, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywxx() const {
    return { _y, _w, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywxy() const {
    return { _y, _w, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywxz() const {
    return { _y, _w, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywxw() const {
    return { _y, _w, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywyx() const {
    return { _y, _w, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywyy() const {
    return { _y, _w, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywyz() const {
    return { _y, _w, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywyw() const {
    return { _y, _w, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywzx() const {
    return { _y, _w, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywzy() const {
    return { _y, _w, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywzz() const {
    return { _y, _w, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywzw() const {
    return { _y, _w, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywwx() const {
    return { _y, _w, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywwy() const {
    return { _y, _w, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywwz() const {
    return { _y, _w, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::ywww() const {
    return { _y, _w, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxxx() const {
    return { _z, _x, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxxy() const {
    return { _z, _x, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxxz() const {
    return { _z, _x, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxxw() const {
    return { _z, _x, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxyx() const {
    return { _z, _x, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxyy() const {
    return { _z, _x, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxyz() const {
    return { _z, _x, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxyw() const {
    return { _z, _x, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxzx() const {
    return { _z, _x, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxzy() const {
    return { _z, _x, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxzz() const {
    return { _z, _x, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxzw() const {
    return { _z, _x, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxwx() const {
    return { _z, _x, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxwy() const {
    return { _z, _x, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxwz() const {
    return { _z, _x, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxww() const {
    return { _z, _x, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyxx() const {
    return { _z, _y, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyxy() const {
    return { _z, _y, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyxz() const {
    return { _z, _y, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyxw() const {
    return { _z, _y, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyyx() const {
    return { _z, _y, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyyy() const {
    return { _z, _y, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyyz() const {
    return { _z, _y, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyyw() const {
    return { _z, _y, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyzx() const {
    return { _z, _y, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyzy() const {
    return { _z, _y, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyzz() const {
    return { _z, _y, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyzw() const {
    return { _z, _y, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zywx() const {
    return { _z, _y, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zywy() const {
    return { _z, _y, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zywz() const {
    return { _z, _y, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyww() const {
    return { _z, _y, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzxx() const {
    return { _z, _z, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzxy() const {
    return { _z, _z, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzxz() const {
    return { _z, _z, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzxw() const {
    return { _z, _z, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzyx() const {
    return { _z, _z, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzyy() const {
    return { _z, _z, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzyz() const {
    return { _z, _z, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzyw() const {
    return { _z, _z, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzzx() const {
    return { _z, _z, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzzy() const {
    return { _z, _z, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzzz() const {
    return { _z, _z, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzzw() const {
    return { _z, _z, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzwx() const {
    return { _z, _z, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzwy() const {
    return { _z, _z, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzwz() const {
    return { _z, _z, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzww() const {
    return { _z, _z, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwxx() const {
    return { _z, _w, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwxy() const {
    return { _z, _w, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwxz() const {
    return { _z, _w, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwxw() const {
    return { _z, _w, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwyx() const {
    return { _z, _w, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwyy() const {
    return { _z, _w, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwyz() const {
    return { _z, _w, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwyw() const {
    return { _z, _w, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwzx() const {
    return { _z, _w, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwzy() const {
    return { _z, _w, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwzz() const {
    return { _z, _w, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwzw() const {
    return { _z, _w, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwwx() const {
    return { _z, _w, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwwy() const {
    return { _z, _w, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwwz() const {
    return { _z, _w, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zwww() const {
    return { _z, _w, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxxx() const {
    return { _w, _x, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxxy() const {
    return { _w, _x, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxxz() const {
    return { _w, _x, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxxw() const {
    return { _w, _x, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxyx() const {
    return { _w, _x, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxyy() const {
    return { _w, _x, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxyz() const {
    return { _w, _x, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxyw() const {
    return { _w, _x, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxzx() const {
    return { _w, _x, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxzy() const {
    return { _w, _x, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxzz() const {
    return { _w, _x, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxzw() const {
    return { _w, _x, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxwx() const {
    return { _w, _x, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxwy() const {
    return { _w, _x, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxwz() const {
    return { _w, _x, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wxww() const {
    return { _w, _x, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyxx() const {
    return { _w, _y, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyxy() const {
    return { _w, _y, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyxz() const {
    return { _w, _y, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyxw() const {
    return { _w, _y, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyyx() const {
    return { _w, _y, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyyy() const {
    return { _w, _y, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyyz() const {
    return { _w, _y, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyyw() const {
    return { _w, _y, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyzx() const {
    return { _w, _y, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyzy() const {
    return { _w, _y, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyzz() const {
    return { _w, _y, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyzw() const {
    return { _w, _y, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wywx() const {
    return { _w, _y, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wywy() const {
    return { _w, _y, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wywz() const {
    return { _w, _y, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wyww() const {
    return { _w, _y, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzxx() const {
    return { _w, _z, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzxy() const {
    return { _w, _z, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzxz() const {
    return { _w, _z, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzxw() const {
    return { _w, _z, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzyx() const {
    return { _w, _z, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzyy() const {
    return { _w, _z, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzyz() const {
    return { _w, _z, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzyw() const {
    return { _w, _z, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzzx() const {
    return { _w, _z, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzzy() const {
    return { _w, _z, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzzz() const {
    return { _w, _z, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzzw() const {
    return { _w, _z, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzwx() const {
    return { _w, _z, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzwy() const {
    return { _w, _z, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzwz() const {
    return { _w, _z, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wzww() const {
    return { _w, _z, _w, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwxx() const {
    return { _w, _w, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwxy() const {
    return { _w, _w, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwxz() const {
    return { _w, _w, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwxw() const {
    return { _w, _w, _x, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwyx() const {
    return { _w, _w, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwyy() const {
    return { _w, _w, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwyz() const {
    return { _w, _w, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwyw() const {
    return { _w, _w, _y, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwzx() const {
    return { _w, _w, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwzy() const {
    return { _w, _w, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwzz() const {
    return { _w, _w, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwzw() const {
    return { _w, _w, _z, _w };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwwx() const {
    return { _w, _w, _w, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwwy() const {
    return { _w, _w, _w, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwwz() const {
    return { _w, _w, _w, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::wwww() const {
    return { _w, _w, _w, _w };
}

template < no_cvref T > constexpr bool
vector<T>::colinear_to(vector_4 auto&& rhs) const noexcept {
    if((!_x && !rhs._x && _y && rhs._y) 
    || (!_y && !rhs._y && _x && rhs._x)) return true;
    if (!(_x && rhs._x) || !(_y && rhs._y)) return false;
    if ((_x > rhs._x && _y < rhs._y) || (_x < rhs._x && _y > rhs._y)) return false;
    if (_x > rhs._x) return _x / rhs._x == _y / rhs._y || _x / rhs._x == -(_y / rhs._y);
    else return rhs._x / _x == rhs._y / _y || rhs._x / _x == -(rhs._y / _y);
}

template < no_cvref T > constexpr bool
vector<T>::is_normalize() const noexcept {
    if constexpr (std::floating_point<T> || std::integral<T>)
        if (_x > 1.0 || _y > 1.0 || _z > 1.0) return false;
    return abs(length() - static_cast<T>(1.0)) < HelperData::eps;
}

template < no_cvref T > constexpr bool
vector<T>::orthogonal_to(vector_4 auto&& vec) const noexcept {
    return !(*this * vec);
}

template < no_cvref T > constexpr bool 
vector<T>::codirectional_to(vector_4 auto&& vec) const noexcept {
    return colinear_to(vec)? vec._x / _x == vec._y / _y == vec._z / _z: false;
}

template < no_cvref T > constexpr void
vector<T>::normalize() noexcept {
    _x == 0 && _y == 0 && _z == 0? *this = {0, 0, 0}:
    _x == 0 && _y == 0 ?           *this = {0, 0, 1}:
    _y == 0 && _z == 0 ?           *this = {1, 0, 0}:
    _x == 0 && _z == 0 ?           *this = {0, 1, 0}:
    *this = *this / length();
}

template < no_cvref T > constexpr auto
vector<T>::length() const noexcept {
    return  _x == 0 &&
            _y == 0 &&
            _z == 0? 0:
            _x == 0 && _y == 0? _z:
            _y == 0 && _z == 0? _x:
            _x == 0 && _z == 0? _y:
            sqrt (
                _x == 0? _y * _y + _z * _z:
                _y == 0? _x * _x + _z * _z:
                _z == 0? _y * _y + _x * _x:
                _x * _x + _y * _y + _z * _z
            );
}

template < no_cvref T > constexpr double    
vector<T>::cos_angle(vector_4 auto&& vec) const noexcept {
    return  is_normalize()?
            vec.is_normalize()?
            (*this * vec):
            (*this * vec) / vec.length():
            vec.is_normalize()?
            (*this * vec) / length():
            (*this * vec) / (length() * vec.length());   
}

}; // mathon::impl