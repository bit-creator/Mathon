export module Math.Impl.Matrix3;

export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier; 
import Math.Impl.Vector2;
import Math.Impl.Vector3;
import Math.Impl.Vector4;
import Math.Impl.Matrix2;

import <memory>;
import <concepts>;
import <cmath>;

template <typename T>
using matrix = mathon::impl::Matrix<3, T>;

template <typename T>
using matrix2 = mathon::impl::Matrix<2, T>;

template <typename T>
using vector2 = mathon::impl::Vector<2, T>;

template <typename T>
using vector3 = mathon::impl::Vector<3, T>;

template <typename T>
using vector4 = mathon::impl::Vector<4, T>;

namespace mathon::impl::operators { struct impl; };

// to-do:/ add concepts for matrix and realize copy/move operations 
export namespace mathon::impl {
template <
    no_cvref T
> class Matrix<3, T> {
template <
    LenghtT l,
    no_cvref U
> friend class Matrix;
public:
using value_type = T;
using matrix     = Matrix<3, value_type>;
using reference  = matrix&;

public:
    constexpr static inline LenghtT dimensions = 3;

private:
    value_type                                 _00;
    value_type                                 _01;
    value_type                                 _02;

    value_type                                 _10;
    value_type                                 _11;
    value_type                                 _12;

    value_type                                 _20;
    value_type                                 _21;
    value_type                                 _22; 

public:
// DESTRUCTOR
    constexpr 
    ~Matrix() noexcept(nt_d<T>) =default;

}; // Matrix<3, T>
}; // mathon::impl