export module Math.Impl.Vector2;
export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier; 

import <memory>;
import <concepts>;
import <cmath>;
// import std;

template <typename T>
using vector = mathon::impl::Vector<2, T, false>;

namespace mathon::impl::operators { struct impl; };

export namespace mathon::impl {
template <
    no_cvref T
> class Vector<2, T, false> {
template <
    LenghtT l,
    no_cvref U,
    bool is_p
> friend class Vector;
public:
using value_type = T;
using vector     = Vector<2, value_type>;
using reference  = vector&;

public:
    constexpr static inline LenghtT dimensions = 2;

private:
    value_type                               _x;
    value_type                               _y;

public:
// DESTRUCTOR
    constexpr 
    ~Vector() noexcept(nt_d<T>) =default;

//  CONSTRUCTORS
    constexpr Vector() noexcept(nt_c<T>) requires std::default_initializable<T>;
    constexpr explicit Vector(value_type val) noexcept(nt_cc<T>);
    constexpr Vector(value_type x_, value_type y_) noexcept(nt_cc<T>);
    constexpr Vector(suitable_vector<vector> auto&& vec) noexcept(nt_cc<T> && nt_mc<T>);

// ASSIGMENTS
    constexpr reference
    operator =(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

//  GETTERS
    constexpr T x() const noexcept(nt_c<T>);
    constexpr T y() const noexcept(nt_c<T>);

    constexpr vector xy() const noexcept(nt_c<vector>);
    constexpr vector yx() const noexcept(nt_c<vector>);
    constexpr vector xx() const noexcept(nt_c<vector>);
    constexpr vector yy() const noexcept(nt_c<vector>);

//  SETTERS
    constexpr void x(T x_) noexcept(nt_ma<T>);
    constexpr void y(T y_) noexcept(nt_ma<T>);
    constexpr void xy(T x_, T y_) noexcept(nt_ma<T>);
    constexpr void xy(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

// OPERATORS
    friend struct operators::impl;

// LOGICAL
    constexpr bool is_normalize()                        const noexcept;
    constexpr bool colinear_to(vector_2 auto&& vec)      const noexcept;
    constexpr bool orthogonal_to(vector_2 auto&& vec)    const noexcept;
    constexpr bool codirectional_to(vector_2 auto&& vec) const noexcept;

// MODIFIER
    constexpr void normalize() noexcept;

// INFO
    constexpr auto   length() const noexcept;
    constexpr double cos_angle(vector_2 auto&& vec) const noexcept;
}; // Vector<2, T>

//  CONSTRUCTORS
template < no_cvref T > constexpr 
vector<T>::Vector() noexcept(nt_c<T>)
    requires std::default_initializable<T>
        : _x{  }, _y{  } {
}

template < no_cvref T > constexpr 
vector<T>::Vector(T val) noexcept(nt_cc<T>)
    : _x{val}, _y{val} { 
}

template < no_cvref T > constexpr 
vector<T>::Vector(T x_, T y_) noexcept(nt_cc<T>)
    : _x{std::move(x_)}, _y{std::move(y_)} {
}

template < no_cvref T > constexpr
vector<T>::Vector(suitable_vector<vector> auto&& vec) 
        noexcept(nt_cc<T> && nt_mc<T>)
    : _x{std::forward<share_category<decltype(vec), T>>(vec._x)}
    , _y{std::forward<share_category<decltype(vec), T>>(vec._y)} {
}

//  ASSIGMENTS
template < no_cvref T > constexpr vector<T>&
vector<T>::operator =(suitable_vector<vector> auto&& vec) 
        noexcept(nt_ca<T> && nt_ma<T>) {
    if constexpr (same_vector<decltype(vec), vector>)
        if(&vec == this)
            return *this;
    
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);

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

template < no_cvref T > constexpr vector<T> 
vector<T>::xy() const noexcept(nt_c<vector>) { 
    return { _x, _y }; 
}

template < no_cvref T > constexpr vector<T> 
vector<T>::yx() const noexcept(nt_c<vector>) { 
    return { _y, _x }; 
}

template < no_cvref T > constexpr vector<T> 
vector<T>::xx() const noexcept(nt_c<vector>) { 
    return { _x, _x }; 
}

template < no_cvref T > constexpr vector<T> 
vector<T>::yy() const noexcept(nt_c<vector>) { 
    return { _y, _y }; 
}

template < no_cvref T > constexpr void 
vector<T>::x(T x_) noexcept(nt_ma<T>) { 
    _x = std::move(x_); 
}

template < no_cvref T > constexpr void 
vector<T>::y(T y_) noexcept(nt_ma<T>) { 
    _y = std::move(y_); 
}

template < no_cvref T > constexpr void 
vector<T>::xy(T x_, T y_) noexcept(nt_ma<T>) { 
    _x = std::move(x_); 
    _y = std::move(y_); 
}

template < no_cvref T > constexpr void 
vector<T>::xy(suitable_vector<vector> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>) {
    _x = std::forward<share_category<decltype(vec), T>>(vec._x);
    _y = std::forward<share_category<decltype(vec), T>>(vec._y);
}

template < no_cvref T > constexpr bool 
vector<T>::colinear_to(vector_2 auto&& rhs) const noexcept {
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
        if (_x > 1.0 || _y > 1.0) return false;
    return abs(length() - static_cast<T>(1.0)) < HelperData::eps;
}

template < no_cvref T > constexpr bool
vector<T>::orthogonal_to(vector_2 auto&& vec) const noexcept {
    return !(*this * vec);
}

template < no_cvref T > constexpr bool 
vector<T>::codirectional_to(vector_2 auto&& vec) const noexcept {
    return colinear_to(vec)? vec._x / _x == vec._y / _y: false;
}

template < no_cvref T > constexpr void
vector<T>::normalize() noexcept {
    _x == 0 && _y == 0? *this = {0, 0}:
    _x == 0?            *this = {0, 1}:
    _y == 0?            *this = {1, 0}:
    *this = *this / length();
}

template < no_cvref T > constexpr auto
vector<T>::length() const noexcept {
    return _x? _y? sqrt(_x * _x + _y * _y): _x: _y;
}

template < no_cvref T > constexpr double    
vector<T>::cos_angle(vector_2 auto&& vec) const noexcept {
    return  is_normalize()?
            vec.is_normalize()?
            (*this * vec):
            (*this * vec) / vec.length():
            vec.is_normalize()?
            (*this * vec) / length():
            (*this * vec) / (length() * vec.length());   
}
}; // mathon::impl
