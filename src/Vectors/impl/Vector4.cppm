export module Math.Impl.Vector4;
export import Math.Impl.Vector3;
export import Math.Impl.Vector2;
export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier;

import <memory>;
import <concepts>;
import <cmath>;

template < typename T, bool b>
using vector = mathon::impl::Vector<4, T, b>;

template < typename T>
using vector2 = mathon::impl::Vector<2, T>;

template < typename T>
using vector3 = mathon::impl::Vector<3, T>;

namespace mathon::impl::operators { struct impl; };

// !!! its only wrapper for Vector3 if you want use homogeneous coordinates
// last value fixed from constructor, if you want change Vector interpretation to
// Point interpretation use a direct cast

export namespace mathon::impl {
template <
    no_cvref T,
    bool is_point_val
> class Vector<4, T, is_point_val> {
template <
    LenghtT l,
    no_cvref U,
    bool is_p
> friend class Vector;
public:
using value_type = T;
using vector     = vector<value_type, is_point_val>;
using vector2    = vector2<value_type>;
using vector3    = vector3<value_type>;
using reference  = vector&;

public:
    constexpr static inline LenghtT dimensions = 4;

private:
    value_type                               _x;
    value_type                               _y;
    value_type                               _z;
    const value_type                         _w = T(is_point_val);

public:
// DESTRUCTOR
    constexpr ~Vector() noexcept(nt_d<T>) =default;

//  CONSTRUCTORS
    constexpr Vector() noexcept(nt_c<T>);

    constexpr explicit Vector(T val) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_, T z_) noexcept(nt_cc<T>);

    constexpr Vector(suitable_vector<vector3> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);

    constexpr Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);
    
    constexpr reference
    operator =(suitable_vector<vector3> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

    constexpr reference
    operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

//  GETTERS
    constexpr value_type x() const noexcept(nt_c<T>);
    constexpr value_type y() const noexcept(nt_c<T>);
    constexpr value_type z() const noexcept(nt_c<T>);
    constexpr value_type w() const noexcept(nt_c<T>);

    constexpr bool is_point() const noexcept(nt_c<T>);; // same to w();

    constexpr vector2 xy() const noexcept(nt_c<vector2>);
    constexpr vector2 yx() const noexcept(nt_c<vector2>);
    constexpr vector2 zx() const noexcept(nt_c<vector2>);
    constexpr vector2 zy() const noexcept(nt_c<vector2>);
    constexpr vector2 xz() const noexcept(nt_c<vector2>);
    constexpr vector2 yz() const noexcept(nt_c<vector2>);
    constexpr vector2 xx() const noexcept(nt_c<vector2>);
    constexpr vector2 yy() const noexcept(nt_c<vector2>);
    constexpr vector2 zz() const noexcept(nt_c<vector2>);

    constexpr vector3 xyz() const noexcept(nt_c<vector>);
    constexpr vector3 xzy() const noexcept(nt_c<vector>);
    constexpr vector3 yxz() const noexcept(nt_c<vector>);
    constexpr vector3 yzx() const noexcept(nt_c<vector>);
    constexpr vector3 zxy() const noexcept(nt_c<vector>);
    constexpr vector3 zyx() const noexcept(nt_c<vector>);
    constexpr vector3 xxy() const noexcept(nt_c<vector>);
    constexpr vector3 xxz() const noexcept(nt_c<vector>);
    constexpr vector3 yxx() const noexcept(nt_c<vector>);
    constexpr vector3 zxx() const noexcept(nt_c<vector>);
    constexpr vector3 xyx() const noexcept(nt_c<vector>);
    constexpr vector3 xzx() const noexcept(nt_c<vector>);
    constexpr vector3 yyx() const noexcept(nt_c<vector>);
    constexpr vector3 yyz() const noexcept(nt_c<vector>);
    constexpr vector3 xyy() const noexcept(nt_c<vector>);
    constexpr vector3 zyy() const noexcept(nt_c<vector>);
    constexpr vector3 yxy() const noexcept(nt_c<vector>);
    constexpr vector3 yzy() const noexcept(nt_c<vector>);
    constexpr vector3 zzx() const noexcept(nt_c<vector>);
    constexpr vector3 zzy() const noexcept(nt_c<vector>);
    constexpr vector3 xzz() const noexcept(nt_c<vector>);
    constexpr vector3 yzz() const noexcept(nt_c<vector>);
    constexpr vector3 zxz() const noexcept(nt_c<vector>);
    constexpr vector3 zyz() const noexcept(nt_c<vector>);
    constexpr vector3 xxx() const noexcept(nt_c<vector>);
    constexpr vector3 yyy() const noexcept(nt_c<vector>);
    constexpr vector3 zzz() const noexcept(nt_c<vector>);

//  SETTERS    
    constexpr void x(T x_) noexcept(nt_ma<T>);
    constexpr void y(T y_) noexcept(nt_ma<T>);
    constexpr void z(T z_) noexcept(nt_ma<T>);

    constexpr void xy(T a, T b) noexcept(nt_ma<T>);
    constexpr void xz(T a, T b) noexcept(nt_ma<T>);
    constexpr void yz(T a, T b) noexcept(nt_ma<T>);

    constexpr void xyz(T a, T b, T c) noexcept(nt_ma<T>);

    constexpr void xy(suitable_vector<vector2> auto&& v);
    constexpr void xz(suitable_vector<vector2> auto&& v);
    constexpr void yz(suitable_vector<vector2> auto&& v);

    constexpr void xyz(suitable_vector<vector3> auto&& v);
    constexpr void xyz(same_dim_vector<vector2> auto&& v, T a);
    constexpr void xyz(T a, same_dim_vector<vector2> auto&& v);

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
    
// CAST
    operator Vector<4, T, !is_point_val>();
}; // Vector<4, T>


template < no_cvref T, bool is_p > constexpr 
vector<T, is_p>::Vector() noexcept(nt_c<T>)
    : _x{  }, _y{  }, _z{  } {
}

template < no_cvref T, bool is_p > constexpr 
vector<T, is_p>::Vector(T val) noexcept(nt_cc<T>)
    : _x{val}, _y{val}, _z{val} {
}

template < no_cvref T, bool is_p > constexpr 
vector<T, is_p>::Vector(T x_, T y_) noexcept(nt_cc<T>)
    : _x{x_}, _y{y_}, _z{  } {
}

template < no_cvref T, bool is_p > constexpr 
vector<T, is_p>::Vector(T x_, T y_, T z_) noexcept(nt_cc<T>)
    : _x{x_}, _y{y_}, _z{z_} {
}

template < no_cvref T, bool is_p > constexpr
vector<T, is_p>::Vector(suitable_vector<vector3> auto&& vec) noexcept(nt_cc<T>)
        : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
        , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
        , _z{std::forward<share_category<decltype(vec), T>>(vec._z)} {
}


template < no_cvref T, bool is_p > constexpr
vector<T, is_p>::Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
    , _z{} {
}

template < no_cvref T, bool is_p > constexpr
vector<T, is_p>::Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>)
    : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
    , _z{z_} {
}

template < no_cvref T, bool is_p > constexpr
vector<T, is_p>::Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : _x{x_}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _z{std::forward<share_category<decltype(vec), T>>(vec._y)} {
}


template < no_cvref T, bool is_p > constexpr vector<T, is_p>&
vector<T, is_p>::operator =(suitable_vector<vector3> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
    if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = std::forward<share_category<decltype(vec), T>>(vec._z);

    return *this;
}

template < no_cvref T, bool is_p > constexpr vector<T, is_p>&
vector<T, is_p>::operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = T();

    return *this;
}

template < no_cvref T, bool is_p > constexpr T 
vector<T, is_p>::x() const noexcept(nt_c<T>) {
    return _x;
}

template < no_cvref T, bool is_p > constexpr T 
vector<T, is_p>::y() const noexcept(nt_c<T>) {
    return _y;
}

template < no_cvref T, bool is_p > constexpr T 
vector<T, is_p>::z() const noexcept(nt_c<T>) {
    return _z;
}

template < no_cvref T, bool is_p > constexpr T 
vector<T, is_p>::w() const noexcept(nt_c<T>) {
    return _w;
}

template < no_cvref T, bool is_p > constexpr bool 
vector<T, is_p>::is_point() const noexcept(nt_c<T>) {
    return bool(_w);
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::xy() const noexcept(nt_c<vector2>) {
    return { _x, _y }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::yx() const noexcept(nt_c<vector2>) {
    return { _y, _x }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::zx() const noexcept(nt_c<vector2>) {
    return { _z, _x }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::zy() const noexcept(nt_c<vector2>) {
    return { _z, _y }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::xz() const noexcept(nt_c<vector2>) {
    return { _x, _z }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::yz() const noexcept(nt_c<vector2>) {
    return { _y, _z }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::xx() const noexcept(nt_c<vector2>) {
    return { _x, _x }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::yy() const noexcept(nt_c<vector2>) {
    return { _y, _y }; 
}

template < no_cvref T, bool is_p > constexpr vector2<T> 
vector<T, is_p>::zz() const noexcept(nt_c<vector2>) {
    return { _z, _z }; 
}


template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xyz() const noexcept(nt_c<vector>) {
    return { _x, _y, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xzy() const noexcept(nt_c<vector>) {
    return { _x, _z, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yxz() const noexcept(nt_c<vector>) {
    return { _y, _x, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yzx() const noexcept(nt_c<vector>) {
    return { _y, _z, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zxy() const noexcept(nt_c<vector>) {
    return { _z, _x, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zyx() const noexcept(nt_c<vector>) {
    return { _z, _y, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xxy() const noexcept(nt_c<vector>) {
    return { _x, _x, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xxz() const noexcept(nt_c<vector>) {
    return { _x, _x, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yxx() const noexcept(nt_c<vector>) {
    return { _y, _x, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zxx() const noexcept(nt_c<vector>) {
    return { _z, _x, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xyx() const noexcept(nt_c<vector>) {
    return { _x, _y, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xzx() const noexcept(nt_c<vector>) {
    return { _x, _z, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yyx() const noexcept(nt_c<vector>) {
    return { _y, _y, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yyz() const noexcept(nt_c<vector>) {
    return { _y, _y, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xyy() const noexcept(nt_c<vector>) {
    return { _x, _y, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zyy() const noexcept(nt_c<vector>) {
    return { _z, _y, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yxy() const noexcept(nt_c<vector>) {
    return { _y, _x, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yzy() const noexcept(nt_c<vector>) {
    return { _y, _z, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zzx() const noexcept(nt_c<vector>) {
    return { _z, _z, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zzy() const noexcept(nt_c<vector>) {
    return { _z, _z, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xzz() const noexcept(nt_c<vector>) {
    return { _x, _z, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yzz() const noexcept(nt_c<vector>) {
    return { _y, _z, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zxz() const noexcept(nt_c<vector>) {
    return { _z, _x, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zyz() const noexcept(nt_c<vector>) {
    return { _z, _y, _z };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::xxx() const noexcept(nt_c<vector>) {
    return { _x, _x, _x };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::yyy() const noexcept(nt_c<vector>) {
    return { _y, _y, _y };
}

template < no_cvref T, bool is_p > constexpr vector3<T>
vector<T, is_p>::zzz() const noexcept(nt_c<vector>) {
    return { _z, _z, _z };
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::x(T x_) noexcept(nt_ma<T>) {
    _x = x_;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::y(T y_) noexcept(nt_ma<T>) {
    _y = y_;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::z(T z_) noexcept(nt_ma<T>) {
    _z = z_;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xy(T a, T b) noexcept(nt_ma<T>) {
    _x = a; _y = b;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xz(T a, T b) noexcept(nt_ma<T>) {
    _x = a; _z = b;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::yz(T a, T b) noexcept(nt_ma<T>) {
    _y = a; _z = b;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xyz(T x_, T y_, T z_) noexcept(nt_ma<T>) {
    _x = x_; 
    _y = y_; 
    _z = z_;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xy(suitable_vector<vector2> auto&& vec) {
    _x = vec.x();
    _y = vec.y();
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xz(suitable_vector<vector2> auto&& vec) {
    _x = vec.x();
    _z = vec.y();
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::yz(suitable_vector<vector2> auto&& vec) {
    _y = vec.x();
    _z = vec.y();
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xyz(suitable_vector<vector3> auto&& vec) {
    _x = vec.x();
    _y = vec.y();
    _z = vec.z();
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xyz(same_dim_vector<vector2> auto&& vec, T a) {
    _x = vec.x();
    _y = vec.y();
    _z = a;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::xyz(T a, same_dim_vector<vector2> auto&& vec) {
    _x = a;
    _y = vec.x();
    _z = vec.y();
}

template < no_cvref T, bool is_p > constexpr bool
vector<T, is_p>::colinear_to(vector_4 auto&& rhs) const noexcept {
    if((!_x && !rhs._x && _y && rhs._y) 
    || (!_y && !rhs._y && _x && rhs._x)) return true;
    if (!(_x && rhs._x) || !(_y && rhs._y)) return false;
    if ((_x > rhs._x && _y < rhs._y) || (_x < rhs._x && _y > rhs._y)) return false;
    if (_x > rhs._x) return _x / rhs._x == _y / rhs._y || _x / rhs._x == -(_y / rhs._y);
    else return rhs._x / _x == rhs._y / _y || rhs._x / _x == -(rhs._y / _y);
}

template < no_cvref T, bool is_p > constexpr bool
vector<T, is_p>::is_normalize() const noexcept {
    if constexpr (std::floating_point<T> || std::integral<T>)
        if (_x > 1.0 || _y > 1.0 || _z > 1.0) return false;
    return abs(length() - static_cast<T>(1.0)) < HelperData::eps;
}

template < no_cvref T, bool is_p > constexpr bool
vector<T, is_p>::orthogonal_to(vector_4 auto&& vec) const noexcept {
    return !(*this * vec);
}

template < no_cvref T, bool is_p > constexpr bool 
vector<T, is_p>::codirectional_to(vector_4 auto&& vec) const noexcept {
    return colinear_to(vec)? vec._x / _x == vec._y / _y == vec._z / _z: false;
}

template < no_cvref T, bool is_p > constexpr void
vector<T, is_p>::normalize() noexcept {
    _x == 0 && _y == 0 && _z == 0? this->xyz(0, 0, 0):
    _x == 0 && _y == 0 ?           this->xyz(0, 0, 1):
    _y == 0 && _z == 0 ?           this->xyz(1, 0, 0):
    _x == 0 && _z == 0 ?           this->xyz(0, 1, 0):
    *this /= length();
}

template < no_cvref T, bool is_p > constexpr auto
vector<T, is_p>::length() const noexcept {
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

template < no_cvref T, bool is_p > constexpr double    
vector<T, is_p>::cos_angle(vector_4 auto&& vec) const noexcept {
    return  is_normalize()?
            vec.is_normalize()?
            (*this * vec):
            (*this * vec) / vec.length():
            vec.is_normalize()?
            (*this * vec) / length():
            (*this * vec) / (length() * vec.length());   
}

template < no_cvref T, bool is_p > 
vector<T, is_p>::operator Vector<4, T, !is_p>() {
    return {_x, _y, _z};
}

}; // mathon::impl