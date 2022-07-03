export module Math.Impl.Quaternion;

export import Math.Impl.Operators;
export import Math.Impl.Signatures;

export import Math.Impl.Vector3;
import <cmath>;

import Math.Impl.ShareModifier;

template < typename T>
using Axis = mathon::impl::Vector<3, T>;

export namespace mathon::impl {
template < no_cvref T >
class Quaternion {
template < LenghtT, no_cvref >          friend class Matrix;
template < LenghtT, no_cvref, bool >    friend class Vector;
template < no_cvref >                   friend class Quaternion;

using value_type = T;

private:
    value_type              _angle;
    Axis<T>                 _axis;

public:
// DESTRUCTOR
    constexpr ~Quaternion() noexcept(nt_d<T>) =default;

// CONSTRUCTORS
    constexpr Quaternion();
    constexpr Quaternion(value_type angle, Axis<T> axis);

    Quaternion(const Quaternion&) noexcept =default;
    Quaternion(Quaternion&&) noexcept =default;
    Quaternion(Quaternion&& oth) noexcept
        : _angle(oth._angle), _axis(oth._axis) {};

// ASSIGNMENTS
    Quaternion& operator =(const Quaternion&) noexcept =default;
    Quaternion& operator =(Quaternion&&) noexcept =default;

// GETTER
    constexpr value_type angle() const noexcept;
    constexpr Axis<T>    axis() const noexcept;

// SETTER
    constexpr void angle(value_type angle) noexcept;
    constexpr void axis(Axis<T> axis) noexcept;
};

template < no_cvref T > constexpr
Quaternion<T>::Quaternion()
    : _angle(T(0)), _axis(0, 1, 0) {
}

template < no_cvref T > constexpr
Quaternion<T>::Quaternion(value_type angle, Axis<T> axis)
        : _angle(std::cos(angle / T(2.))), _axis(axis * std::sin(angle / T(2.))) {
    // _axis.normalize();
}

template < no_cvref T > constexpr T
Quaternion<T>::angle() const noexcept {
    return _angle;
}

template < no_cvref T > constexpr Axis<T>
Quaternion<T>::axis() const noexcept {
    return _axis;
}

template < no_cvref T > constexpr void
Quaternion<T>::angle(value_type angle) noexcept {
    _angle = angle;
}

template < no_cvref T > constexpr void
Quaternion<T>::axis(Axis<T> axis) noexcept {
    _axis = axis;
}

};