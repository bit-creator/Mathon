export module Math.Impl.Vector3;
export import Math.Impl.Vector2;
export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier;

import <memory>;
import <concepts>;
import <cmath>;
// import std;

template <typename T>
using vector = mathon::impl::Vector<3, T, false>;

template <typename T>
using vector2 = mathon::impl::Vector<2, T, false>;

namespace mathon::impl::operators { struct impl; };

export namespace mathon::impl {
template <
    no_cvref T
> class Vector<3, T, false> {
template < LenghtT, no_cvref >          friend class Matrix;
template < LenghtT, no_cvref, bool >    friend class Vector;
template < no_cvref >                   friend class Quaternion;

public:
using value_type = T;
using vector     = vector<value_type>;
using vector2    = vector2<value_type>;
using reference  = vector&;

public:
    constexpr static inline LenghtT dimensions = 3;

private:
    value_type                               _x;
    value_type                               _y;
    value_type                               _z;

public:
// DESTRUCTOR
    constexpr ~Vector() noexcept(nt_d<T>) =default;

//  CONSTRUCTORS
    constexpr Vector() noexcept(nt_c<T>);

    constexpr explicit Vector(T val) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, T y_, T z_) noexcept(nt_cc<T>);
    
    constexpr Vector(suitable_vector<vector> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);
    constexpr Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>);
    constexpr Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>);

    constexpr reference
    operator =(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

    constexpr reference
    operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

//  GETTERS
    constexpr value_type x() const noexcept(nt_c<T>);
    constexpr value_type y() const noexcept(nt_c<T>);
    constexpr value_type z() const noexcept(nt_c<T>);

    constexpr vector2 xy() const noexcept(nt_c<vector2>);
    constexpr vector2 yx() const noexcept(nt_c<vector2>);
    constexpr vector2 zx() const noexcept(nt_c<vector2>);
    constexpr vector2 zy() const noexcept(nt_c<vector2>);
    constexpr vector2 xz() const noexcept(nt_c<vector2>);
    constexpr vector2 yz() const noexcept(nt_c<vector2>);
    constexpr vector2 xx() const noexcept(nt_c<vector2>);
    constexpr vector2 yy() const noexcept(nt_c<vector2>);
    constexpr vector2 zz() const noexcept(nt_c<vector2>);

    constexpr vector xyz() const noexcept(nt_c<vector>);
    constexpr vector xzy() const noexcept(nt_c<vector>);
    constexpr vector yxz() const noexcept(nt_c<vector>);
    constexpr vector yzx() const noexcept(nt_c<vector>);
    constexpr vector zxy() const noexcept(nt_c<vector>);
    constexpr vector zyx() const noexcept(nt_c<vector>);
    constexpr vector xxy() const noexcept(nt_c<vector>);
    constexpr vector xxz() const noexcept(nt_c<vector>);
    constexpr vector yxx() const noexcept(nt_c<vector>);
    constexpr vector zxx() const noexcept(nt_c<vector>);
    constexpr vector xyx() const noexcept(nt_c<vector>);
    constexpr vector xzx() const noexcept(nt_c<vector>);
    constexpr vector yyx() const noexcept(nt_c<vector>);
    constexpr vector yyz() const noexcept(nt_c<vector>);
    constexpr vector xyy() const noexcept(nt_c<vector>);
    constexpr vector zyy() const noexcept(nt_c<vector>);
    constexpr vector yxy() const noexcept(nt_c<vector>);
    constexpr vector yzy() const noexcept(nt_c<vector>);
    constexpr vector zzx() const noexcept(nt_c<vector>);
    constexpr vector zzy() const noexcept(nt_c<vector>);
    constexpr vector xzz() const noexcept(nt_c<vector>);
    constexpr vector yzz() const noexcept(nt_c<vector>);
    constexpr vector zxz() const noexcept(nt_c<vector>);
    constexpr vector zyz() const noexcept(nt_c<vector>);
    constexpr vector xxx() const noexcept(nt_c<vector>);
    constexpr vector yyy() const noexcept(nt_c<vector>);
    constexpr vector zzz() const noexcept(nt_c<vector>);

//  SETTERS
    constexpr void x(T x_) noexcept(nt_ma<T>);
    constexpr void y(T y_) noexcept(nt_ma<T>);
    constexpr void z(T z_) noexcept(nt_ma<T>);

    constexpr void xy(T a, T b) noexcept(nt_ma<T>);
    constexpr void xz(T a, T b) noexcept(nt_ma<T>);
    constexpr void yz(T a, T b) noexcept(nt_ma<T>);

    constexpr void xyz(T x_, T y_, T z_) noexcept(nt_ma<T>);

    constexpr void xy(suitable_vector<vector2> auto&& vec);
    constexpr void xz(suitable_vector<vector2> auto&& vec);
    constexpr void yz(suitable_vector<vector2> auto&& vec);

    constexpr void xyz(suitable_vector<vector> auto&& vec);
    constexpr void xyz(same_dim_vector<vector2> auto&& vec, T a);
    constexpr void xyz(T a, same_dim_vector<vector2> auto&& vec);

// OPERATORS
    friend struct operators::impl;

// LOGICAL
    constexpr bool is_normalize()                        const noexcept;
    constexpr bool colinear_to(vector_3 auto&& vec)      const noexcept;
    constexpr bool orthogonal_to(vector_3 auto&& vec)    const noexcept;
    constexpr bool codirectional_to(vector_3 auto&& vec) const noexcept;

// MODIFIER
    constexpr void normalize() noexcept;

// INFO
    constexpr auto   length() const noexcept;
    constexpr double cos_angle(vector_3 auto&& vec) const noexcept;
}; // Vector<3, T>

template < no_cvref T > constexpr 
vector<T>::Vector() noexcept(nt_c<T>)
    : _x{  }, _y{  }, _z{  } {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T val) noexcept(nt_cc<T>)
    : _x{val}, _y{val}, _z{val} {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_) noexcept(nt_cc<T>)
    : _x{x_}, _y{y_}, _z{  } {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_, T z_) noexcept(nt_cc<T>)
    : _x{x_}, _y{y_}, _z{z_} {
}

template < no_cvref T > constexpr
vector<T>::Vector(suitable_vector<vector> auto&& vec) noexcept(nt_cc<T>)
        : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
        , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
        , _z{std::forward<share_category<decltype(vec), T>>(vec._z)} {
}


template < no_cvref T > constexpr
vector<T>::Vector(same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
    , _z{} {
}

template < no_cvref T > constexpr
vector<T>::Vector(same_dim_vector<vector2> auto&& vec, T z_) noexcept(nt_cc<T>)
    : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._y)}
    , _z{z_} {
}

template < no_cvref T > constexpr
vector<T>::Vector(T x_, same_dim_vector<vector2> auto&& vec) noexcept(nt_cc<T>)
    : _x{x_}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _z{std::forward<share_category<decltype(vec), T>>(vec._y)} {
}

template < no_cvref T > constexpr vector<T>&
vector<T>::operator =(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
    if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = std::forward<share_category<decltype(vec), T>>(vec._z);

    return *this;
}

template < no_cvref T > constexpr vector<T>&
vector<T>::operator =(same_dim_vector<vector2> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
    _z = T();

    return *this;
}

template < no_cvref T > constexpr T 
vector<T>::x() const noexcept(nt_c<T>) {
    return _x;
}

template < no_cvref T > constexpr T 
vector<T>::y() const noexcept(nt_c<T>) {
    return _y;
}

template < no_cvref T > constexpr T 
vector<T>::z() const noexcept(nt_c<T>) {
    return _z;
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::xy() const noexcept(nt_c<vector2>) {
    return { _x, _y }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::yx() const noexcept(nt_c<vector2>) {
    return { _y, _x }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::zx() const noexcept(nt_c<vector2>) {
    return { _z, _x }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::zy() const noexcept(nt_c<vector2>) {
    return { _z, _y }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::xz() const noexcept(nt_c<vector2>) {
    return { _x, _z }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::yz() const noexcept(nt_c<vector2>) {
    return { _y, _z }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::xx() const noexcept(nt_c<vector2>) {
    return { _x, _x }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::yy() const noexcept(nt_c<vector2>) {
    return { _y, _y }; 
}

template < no_cvref T > constexpr vector2<T> 
vector<T>::zz() const noexcept(nt_c<vector2>) {
    return { _z, _z }; 
}


template < no_cvref T > constexpr vector<T>
vector<T>::xyz() const noexcept(nt_c<vector>) {
    return { _x, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzy() const noexcept(nt_c<vector>) {
    return { _x, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxz() const noexcept(nt_c<vector>) {
    return { _y, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzx() const noexcept(nt_c<vector>) {
    return { _y, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxy() const noexcept(nt_c<vector>) {
    return { _z, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyx() const noexcept(nt_c<vector>) {
    return { _z, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxy() const noexcept(nt_c<vector>) {
    return { _x, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxz() const noexcept(nt_c<vector>) {
    return { _x, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxx() const noexcept(nt_c<vector>) {
    return { _y, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxx() const noexcept(nt_c<vector>) {
    return { _z, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyx() const noexcept(nt_c<vector>) {
    return { _x, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzx() const noexcept(nt_c<vector>) {
    return { _x, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyx() const noexcept(nt_c<vector>) {
    return { _y, _y, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyz() const noexcept(nt_c<vector>) {
    return { _y, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xyy() const noexcept(nt_c<vector>) {
    return { _x, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyy() const noexcept(nt_c<vector>) {
    return { _z, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yxy() const noexcept(nt_c<vector>) {
    return { _y, _x, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzy() const noexcept(nt_c<vector>) {
    return { _y, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzx() const noexcept(nt_c<vector>) {
    return { _z, _z, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzy() const noexcept(nt_c<vector>) {
    return { _z, _z, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xzz() const noexcept(nt_c<vector>) {
    return { _x, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yzz() const noexcept(nt_c<vector>) {
    return { _y, _z, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zxz() const noexcept(nt_c<vector>) {
    return { _z, _x, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zyz() const noexcept(nt_c<vector>) {
    return { _z, _y, _z };
}

template < no_cvref T > constexpr vector<T>
vector<T>::xxx() const noexcept(nt_c<vector>) {
    return { _x, _x, _x };
}

template < no_cvref T > constexpr vector<T>
vector<T>::yyy() const noexcept(nt_c<vector>) {
    return { _y, _y, _y };
}

template < no_cvref T > constexpr vector<T>
vector<T>::zzz() const noexcept(nt_c<vector>) {
    return { _z, _z, _z };
}

template < no_cvref T > constexpr void
vector<T>::x(T x_) noexcept(nt_ma<T>) {
    _x = x_;
}

template < no_cvref T > constexpr void
vector<T>::y(T y_) noexcept(nt_ma<T>) {
    _y = y_;
}

template < no_cvref T > constexpr void
vector<T>::z(T z_) noexcept(nt_ma<T>) {
    _z = z_;
}

template < no_cvref T > constexpr void
vector<T>::xy(T a, T b) noexcept(nt_ma<T>) {
    _x = a; _y = b;
}

template < no_cvref T > constexpr void
vector<T>::xz(T a, T b) noexcept(nt_ma<T>) {
    _x = a; _z = b;
}

template < no_cvref T > constexpr void
vector<T>::yz(T a, T b) noexcept(nt_ma<T>) {
    _y = a; _z = b;
}

template < no_cvref T > constexpr void
vector<T>::xyz(T x_, T y_, T z_) noexcept(nt_ma<T>) {
    _x = x_; 
    _y = y_; 
    _z = z_;
}

template < no_cvref T > constexpr void
vector<T>::xy(suitable_vector<vector2> auto&& vec) {
    _x = vec.x();
    _y = vec.y();
}

template < no_cvref T > constexpr void
vector<T>::xz(suitable_vector<vector2> auto&& vec) {
    _x = vec.x();
    _z = vec.y();
}

template < no_cvref T > constexpr void
vector<T>::yz(suitable_vector<vector2> auto&& vec) {
    _y = vec.x();
    _z = vec.y();
}


template < no_cvref T > constexpr void
vector<T>::xyz(suitable_vector<vector> auto&& vec) {
    _x = vec.x();
    _y = vec.y();
    _z = vec.z();
}

template < no_cvref T > constexpr void
vector<T>::xyz(same_dim_vector<vector2> auto&& vec, T a) {
    _x = vec.x();
    _y = vec.y();
    _z = a;
}

template < no_cvref T > constexpr void
vector<T>::xyz(T a, same_dim_vector<vector2> auto&& vec) {
    _x = a;
    _y = vec.x();
    _z = vec.y();
}

template < no_cvref T > constexpr bool
vector<T>::colinear_to(vector_3 auto&& rhs) const noexcept {
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
vector<T>::orthogonal_to(vector_3 auto&& vec) const noexcept {
    return !(*this * vec);
}

template < no_cvref T > constexpr bool 
vector<T>::codirectional_to(vector_3 auto&& vec) const noexcept {
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
vector<T>::cos_angle(vector_3 auto&& vec) const noexcept {
    return  is_normalize()?
            vec.is_normalize()?
            (*this * vec):
            (*this * vec) / vec.length():
            vec.is_normalize()?
            (*this * vec) / length():
            (*this * vec) / (length() * vec.length());   
}

}; // mathon::impl