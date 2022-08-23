export module Math.Impl.Matrix4;

export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier;
import Math.Impl.Matrix2;
import Math.Impl.Matrix3;
import Math.Impl.Vector2;
import Math.Impl.Vector3;
import Math.Impl.Vector4;
import Math.Impl.Quaternion;

import <memory>;
import <concepts>;
import <cmath>;

template <typename T>
using matrix = mathon::impl::Matrix<4, T>;

template <typename T>
using matrix3 = mathon::impl::Matrix<3, T>;

template <typename T>
using matrix2 = mathon::impl::Matrix<2, T>;

template <typename T>
using vector2 = mathon::impl::Vector<2, T>;

template <typename T>
using vector3 = mathon::impl::Vector<3, T>;

template <typename T>
using vector4 = mathon::impl::Vector<4, T>;

namespace mathon::impl::operators { struct impl; };

// Automatic shuffle order
// export template <
//     typename T
// > class Order {
//     T&                   _00;
//     T&                   _01;
//     T&                   _02;
//     T&                   _03;
//     T&                   _10;
//     T&                   _11;
//     T&                   _12;
//     T&                   _13;
//     T&                   _20;
//     T&                   _21;
//     T&                   _22;
//     T&                   _23;
//     T&                   _30;
//     T&                   _31;
//     T&                   _32;
//     T&                   _33;


//     friend mathon::impl::operators::impl;
//     friend matrix<T>;

// public:
//     Order(matrix<T>& mat)
//         : _00(is_row_order ? mat._00 : mat._00)
//         , _01(is_row_order ? mat._01 : mat._10)
//         , _02(is_row_order ? mat._02 : mat._20)
//         , _03(is_row_order ? mat._03 : mat._30)
//         , _10(is_row_order ? mat._10 : mat._01)
//         , _11(is_row_order ? mat._11 : mat._11)
//         , _12(is_row_order ? mat._12 : mat._21)
//         , _13(is_row_order ? mat._13 : mat._31)
//         , _20(is_row_order ? mat._20 : mat._02)
//         , _21(is_row_order ? mat._21 : mat._12)
//         , _22(is_row_order ? mat._22 : mat._22)
//         , _23(is_row_order ? mat._23 : mat._32)
//         , _30(is_row_order ? mat._30 : mat._03)
//         , _31(is_row_order ? mat._31 : mat._13)
//         , _32(is_row_order ? mat._32 : mat._23)
//         , _33(is_row_order ? mat._33 : mat._33) {
//     }
// };

// to-do:/ add concepts for matrix and realize copy/move operations 
export namespace mathon::impl {
template <
    no_cvref T
> class Matrix<4, T> {
template < LenghtT, no_cvref >          friend class Matrix;
template < LenghtT, no_cvref, bool >    friend class Vector;
template < no_cvref >                   friend class Quaternion;

public:
using value_type = T;
using matrix     = Matrix<4, value_type>;
using reference  = matrix&;

public:
    constexpr static inline LenghtT dimensions = 4;

private:
    value_type                                 _00;
    value_type                                 _01;
    value_type                                 _02;
    value_type                                 _03;

    value_type                                 _10;
    value_type                                 _11;
    value_type                                 _12;
    value_type                                 _13;
    
    value_type                                 _20;
    value_type                                 _21;
    value_type                                 _22;
    value_type                                 _23;
    
    value_type                                 _30;
    value_type                                 _31;
    value_type                                 _32;
    value_type                                 _33; 

public:
// DESTRUCTOR
    constexpr 
    ~Matrix() noexcept(nt_d<T>) =default;

// CONSTRUCT
    constexpr
    Matrix() noexcept(nt_d<T>);

    constexpr
    Matrix(value_type val) noexcept(nt_d<T>);

    constexpr
    Matrix(vector3<T> _scale, Quaternion<T> _rotate, vector3<T> _trans) noexcept(nt_d<T>);

    constexpr
    Matrix( value_type _00v, value_type _01v, value_type _02v, value_type _03v,
            value_type _10v, value_type _11v, value_type _12v, value_type _13v,
            value_type _20v, value_type _21v, value_type _22v, value_type _23v,
            value_type _30v, value_type _31v, value_type _32v, value_type _33v)
        noexcept(nt_d<T>) requires(is_row_order);

    constexpr
    Matrix( value_type _00v, value_type _01v, value_type _02v, value_type _03v,
            value_type _10v, value_type _11v, value_type _12v, value_type _13v,
            value_type _20v, value_type _21v, value_type _22v, value_type _23v,
            value_type _30v, value_type _31v, value_type _32v, value_type _33v)
        noexcept(nt_d<T>) requires(!is_row_order);

// OPERATION
    constexpr void scale(vector3<T> _scale);
    constexpr void rotate(Quaternion<T> _rotate);
    constexpr void translate(vector3<T> _trans);

    constexpr value_type det();

    constexpr void lookAt(vector3<T> _trans);

    constexpr void make_model(vector3<T> _scale, Quaternion<T> _rotate, vector3<T> _trans);
    constexpr void make_perspective(float fovy, float aspect, float near, float far);
    
    constexpr matrix inverse();
    constexpr matrix transpose();
    constexpr matrix normal();

    friend operators::impl;

// GETTER
    constexpr value_type _00_() const noexcept;
    constexpr value_type _01_() const noexcept;
    constexpr value_type _02_() const noexcept;
    constexpr value_type _03_() const noexcept;
    constexpr value_type _10_() const noexcept;
    constexpr value_type _11_() const noexcept;
    constexpr value_type _12_() const noexcept;
    constexpr value_type _13_() const noexcept;
    constexpr value_type _20_() const noexcept;
    constexpr value_type _21_() const noexcept;
    constexpr value_type _22_() const noexcept;
    constexpr value_type _23_() const noexcept;
    constexpr value_type _30_() const noexcept;
    constexpr value_type _31_() const noexcept;
    constexpr value_type _32_() const noexcept;
    constexpr value_type _33_() const noexcept;
}; // Matrix<4, T>

template < no_cvref T > constexpr
Matrix<4, T>::Matrix() noexcept(nt_d<T>)
    : _00(T(1)), _01(T(0)), _02(T(0)), _03(T(0))
    , _10(T(0)), _11(T(1)), _12(T(0)), _13(T(0))
    , _20(T(0)) ,_21(T(0)) ,_22(T(1)) ,_23(T(0))
    , _30(T(0)) ,_31(T(0)) ,_32(T(0)) ,_33(T(1)) {
}

template < no_cvref T > constexpr
Matrix<4, T>::Matrix(T val) noexcept(nt_d<T>)
    : _00(val), _01(val), _02(val), _03(val)
    , _10(val), _11(val), _12(val), _13(val)
    , _20(val) ,_21(val) ,_22(val) ,_23(val)
    , _30(val) ,_31(val) ,_32(val) ,_33(val) {
}


template < no_cvref T > constexpr
Matrix<4, T>::Matrix(value_type _00v, value_type _01v, value_type _02v, value_type _03v,
                     value_type _10v, value_type _11v, value_type _12v, value_type _13v,
                     value_type _20v, value_type _21v, value_type _22v, value_type _23v,
                     value_type _30v, value_type _31v, value_type _32v, value_type _33v)
        noexcept(nt_d<T>) requires(is_row_order)
    : _00(_00v), _01(_01v), _02(_02v), _03(_03v)
    , _10(_10v), _11(_11v), _12(_12v), _13(_13v)
    , _20(_20v) ,_21(_21v) ,_22(_22v) ,_23(_23v)
    , _30(_30v) ,_31(_31v) ,_32(_32v) ,_33(_33v) {
}

template < no_cvref T > constexpr
Matrix<4, T>::Matrix(value_type _00v, value_type _01v, value_type _02v, value_type _03v,
                     value_type _10v, value_type _11v, value_type _12v, value_type _13v,
                     value_type _20v, value_type _21v, value_type _22v, value_type _23v,
                     value_type _30v, value_type _31v, value_type _32v, value_type _33v)
        noexcept(nt_d<T>) requires(!is_row_order)
    : _00(_00v), _01(_10v), _02(_20v), _03(_30v)
    , _10(_01v), _11(_11v), _12(_21v), _13(_31v)
    , _20(_02v) ,_21(_12v) ,_22(_22v) ,_23(_32v)
    , _30(_03v) ,_31(_13v) ,_32(_23v) ,_33(_33v) {
}

template < no_cvref T > constexpr
Matrix<4, T>::Matrix(vector3<T> _scale, Quaternion<T> _rotate, vector3<T> _trans) noexcept(nt_d<T>)
    : Matrix() {
    make_model(_scale, _rotate, _trans);
}

template < no_cvref T > constexpr void
Matrix<4, T>::scale(vector3<T> _scale) {
}


template < no_cvref T > constexpr void
Matrix<4, T>::rotate(Quaternion<T> _scale) {

}

template < no_cvref T > constexpr void
Matrix<4, T>::translate(vector3<T> _trans) {
}

template < no_cvref T > constexpr void
Matrix<4, T>::make_model(vector3<T> _scale, Quaternion<T> _rotate, vector3<T> _trans) {
    // tmp
    T xx = 2 * _rotate._axis._x * _rotate._axis._x;
    T yy = 2 * _rotate._axis._y * _rotate._axis._y;
    T zz = 2 * _rotate._axis._z * _rotate._axis._z;
    T xy = 2 * _rotate._axis._x * _rotate._axis._y;
    T zw = 2 * _rotate._axis._z * _rotate._angle;
    T xz = 2 * _rotate._axis._x * _rotate._axis._z;
    T yw = 2 * _rotate._axis._y * _rotate._angle;
    T yz = 2 * _rotate._axis._y * _rotate._axis._z;
    T xw = 2 * _rotate._axis._x * _rotate._angle;

    // Order order(*this);
    if constexpr (is_row_order) {
        _00 = _scale._x * (1 - yy - zz);
        _01 = _scale._y * (xy - zw);
        _02 = _scale._z * (xz + yw);
        _03 = _trans._x;
        _10 = _scale._x * (xy + zw);
        _11 = _scale._y * (1 - xx - zz);
        _12 = _scale._z * (yz - xw);
        _13 = _trans._y;
        _20 = _scale._x * (xz - yw);
        _21 = _scale._y * (yz + xw);
        _22 = _scale._z * (1 - xx - yy);
        _23 = _trans._z;
        _30 = 0;
        _31 = 0;
        _32 = 0;
        _33 = 1;
    } else {
        _00 = _scale._x * (1 - yy - zz);
        _10 = _scale._y * (xy - zw);
        _20 = _scale._z * (xz + yw);
        _30 = _trans._x;
        _01 = _scale._x * (xy + zw);
        _11 = _scale._y * (1 - xx - zz);
        _21 = _scale._z * (yz - xw);
        _31 = _trans._y;
        _02 = _scale._x * (xz - yw);
        _12 = _scale._y * (yz + xw);
        _22 = _scale._z * (1 - xx - yy);
        _32 = _trans._z;
        _03 = 0;
        _13 = 0;
        _23 = 0;
        _33 = 1;
    }
}

template < no_cvref T > constexpr void
Matrix<4, T>::make_perspective(float fovy, float aspect, float near, float far) {
    *this = Matrix<4, T>();
	T const tanHalfFovy = tan(fovy / static_cast<T>(2));
    if constexpr (is_row_order) {
    	_00 = static_cast<T>(1) / (aspect * tanHalfFovy);
    	_11 = static_cast<T>(1) / (tanHalfFovy);
    	_22 = - (far + near) / (far - near);
    	_32 = - static_cast<T>(1);
    	_23 = - (static_cast<T>(2) * far * near) / (far - near);
    } else {
        _00 = static_cast<T>(1) / (aspect * tanHalfFovy);
    	_11 = static_cast<T>(1) / (tanHalfFovy);
    	_22 = - (far + near) / (far - near);
    	_23 = - static_cast<T>(1);
    	_32 = - (static_cast<T>(2) * far * near) / (far - near);
    }
}

template < no_cvref T > constexpr T
Matrix<4, T>::det() {
    return
        _00 * ( _11 * _22 * _33
            +   _12 * _23 * _31
            +   _21 * _32 * _13
            -   _13 * _22 * _31
            -   _11 * _32 * _23
            -   _33 * _12 * _21
        )
    -   _01 * ( _10 * _22 * _33
            +   _12 * _23 * _30
            +   _20 * _32 * _13
            -   _13 * _22 * _30
            -   _10 * _32 * _23
            -   _33 * _12 * _20
        )
    +   _02 * ( _10 * _21 * _33
            +   _11 * _23 * _30
            +   _20 * _31 * _13
            -   _13 * _21 * _30
            -   _10 * _31 * _23
            -   _33 * _11 * _20
        )
    -   _03 * ( _10 * _21 * _32
            +   _11 * _22 * _30
            +   _20 * _31 * _12
            -   _12 * _21 * _30
            -   _10 * _31 * _22
            -   _32 * _11 * _20
        );
}

template < no_cvref T > constexpr Matrix<4, T>
Matrix<4, T>::inverse() {
    Matrix<4, T> tmp;
    if(T detv = det(); detv == 0.0f) throw std::runtime_error("inverse matrix doesnt exist"); 
    else tmp = Matrix<4, T>(1.0f / detv);

    tmp._00 *= + ( _11 * _22 * _33 + _12 * _23 * _31 + _21 * _32 * _13 - _13 * _22 * _31 - _11 * _32 * _23 - _33 * _12 * _21 );
    tmp._01 *= - ( _10 * _22 * _33 + _12 * _23 * _30 + _20 * _32 * _13 - _13 * _22 * _30 - _10 * _32 * _23 - _33 * _12 * _20 );
    tmp._02 *= + ( _10 * _21 * _33 + _11 * _23 * _30 + _20 * _31 * _13 - _13 * _21 * _30 - _10 * _31 * _23 - _33 * _11 * _20 );
    tmp._03 *= - ( _10 * _21 * _32 + _11 * _22 * _30 + _20 * _31 * _12 - _12 * _21 * _30 - _10 * _31 * _22 - _32 * _11 * _20 );

    tmp._10 *= - ( _01 * _22 * _33 + _02 * _23 * _31 + _21 * _32 * _03 - _03 * _22 * _31 - _01 * _32 * _23 - _33 * _02 * _21 );
    tmp._11 *= + ( _00 * _22 * _33 + _02 * _23 * _30 + _20 * _32 * _03 - _03 * _22 * _30 - _00 * _32 * _23 - _33 * _02 * _20 );
    tmp._12 *= - ( _00 * _21 * _33 + _01 * _23 * _30 + _20 * _31 * _03 - _03 * _21 * _30 - _00 * _31 * _23 - _33 * _01 * _20 );
    tmp._13 *= + ( _00 * _21 * _32 + _01 * _22 * _30 + _20 * _31 * _02 - _02 * _21 * _30 - _00 * _31 * _22 - _32 * _01 * _20 );

    tmp._20 *= + ( _01 * _12 * _33 + _02 * _13 * _31 + _11 * _32 * _03 - _03 * _12 * _31 - _01 * _32 * _13 - _33 * _02 * _11 );
    tmp._21 *= - ( _00 * _12 * _33 + _02 * _13 * _30 + _10 * _32 * _03 - _03 * _12 * _30 - _00 * _32 * _13 - _33 * _02 * _10 );
    tmp._22 *= + ( _00 * _11 * _33 + _01 * _13 * _30 + _10 * _31 * _03 - _03 * _11 * _30 - _00 * _31 * _13 - _33 * _01 * _10 );
    tmp._23 *= - ( _00 * _11 * _32 + _01 * _12 * _30 + _10 * _31 * _02 - _02 * _11 * _30 - _00 * _31 * _12 - _32 * _01 * _10 );

    tmp._30 *= - ( _01 * _12 * _23 + _02 * _13 * _21 + _11 * _22 * _03 - _03 * _12 * _21 - _01 * _22 * _13 - _23 * _02 * _11 );
    tmp._31 *= + ( _00 * _12 * _23 + _02 * _13 * _20 + _10 * _22 * _03 - _03 * _12 * _20 - _00 * _22 * _13 - _23 * _02 * _10 );
    tmp._32 *= - ( _00 * _11 * _23 + _01 * _13 * _20 + _10 * _21 * _03 - _03 * _11 * _20 - _00 * _21 * _13 - _23 * _01 * _10 );
    tmp._33 *= + ( _00 * _11 * _22 + _01 * _12 * _20 + _10 * _21 * _02 - _02 * _11 * _20 - _00 * _21 * _12 - _22 * _01 * _10 );

    return tmp;
}


template < no_cvref T > constexpr Matrix<4, T>
Matrix<4, T>::transpose() {
    Matrix<4, T> tmp;

    tmp._00 = _00;
    tmp._01 = _10;
    tmp._02 = _20;
    tmp._03 = _30;
    tmp._10 = _01;
    tmp._11 = _11;
    tmp._12 = _21;
    tmp._13 = _31;
    tmp._20 = _02;
    tmp._21 = _12;
    tmp._22 = _22;
    tmp._23 = _32;
    tmp._30 = _03;
    tmp._31 = _13;
    tmp._32 = _23;
    tmp._33 = _33;

    return tmp;
}

template < no_cvref T > constexpr Matrix<4, T>
Matrix<4, T>::normal() {
    Matrix<4, T> tmp;
    if(T detv = det(); detv == 0.0f) throw std::runtime_error("inverse matrix doesnt exist"); 
    else tmp = Matrix<4, T>(1.0f / detv);

    tmp._00 *= + ( _11 * _22 * _33 + _12 * _23 * _31 + _21 * _32 * _13 - _13 * _22 * _31 - _11 * _32 * _23 - _33 * _12 * _21 );
    tmp._10 *= - ( _10 * _22 * _33 + _12 * _23 * _30 + _20 * _32 * _13 - _13 * _22 * _30 - _10 * _32 * _23 - _33 * _12 * _20 );
    tmp._20 *= + ( _10 * _21 * _33 + _11 * _23 * _30 + _20 * _31 * _13 - _13 * _21 * _30 - _10 * _31 * _23 - _33 * _11 * _20 );
    tmp._30 *= - ( _10 * _21 * _32 + _11 * _22 * _30 + _20 * _31 * _12 - _12 * _21 * _30 - _10 * _31 * _22 - _32 * _11 * _20 );

    tmp._01 *= - ( _01 * _22 * _33 + _02 * _23 * _31 + _21 * _32 * _03 - _03 * _22 * _31 - _01 * _32 * _23 - _33 * _02 * _21 );
    tmp._11 *= + ( _00 * _22 * _33 + _02 * _23 * _30 + _20 * _32 * _03 - _03 * _22 * _30 - _00 * _32 * _23 - _33 * _02 * _20 );
    tmp._21 *= - ( _00 * _21 * _33 + _01 * _23 * _30 + _20 * _31 * _03 - _03 * _21 * _30 - _00 * _31 * _23 - _33 * _01 * _20 );
    tmp._31 *= + ( _00 * _21 * _32 + _01 * _22 * _30 + _20 * _31 * _02 - _02 * _21 * _30 - _00 * _31 * _22 - _32 * _01 * _20 );

    tmp._02 *= + ( _01 * _12 * _33 + _02 * _13 * _31 + _11 * _32 * _03 - _03 * _12 * _31 - _01 * _32 * _13 - _33 * _02 * _11 );
    tmp._12 *= - ( _00 * _12 * _33 + _02 * _13 * _30 + _10 * _32 * _03 - _03 * _12 * _30 - _00 * _32 * _13 - _33 * _02 * _10 );
    tmp._22 *= + ( _00 * _11 * _33 + _01 * _13 * _30 + _10 * _31 * _03 - _03 * _11 * _30 - _00 * _31 * _13 - _33 * _01 * _10 );
    tmp._32 *= - ( _00 * _11 * _32 + _01 * _12 * _30 + _10 * _31 * _02 - _02 * _11 * _30 - _00 * _31 * _12 - _32 * _01 * _10 );

    tmp._03 *= - ( _01 * _12 * _23 + _02 * _13 * _21 + _11 * _22 * _03 - _03 * _12 * _21 - _01 * _22 * _13 - _23 * _02 * _11 );
    tmp._13 *= + ( _00 * _12 * _23 + _02 * _13 * _20 + _10 * _22 * _03 - _03 * _12 * _20 - _00 * _22 * _13 - _23 * _02 * _10 );
    tmp._23 *= - ( _00 * _11 * _23 + _01 * _13 * _20 + _10 * _21 * _03 - _03 * _11 * _20 - _00 * _21 * _13 - _23 * _01 * _10 );
    tmp._33 *= + ( _00 * _11 * _22 + _01 * _12 * _20 + _10 * _21 * _02 - _02 * _11 * _20 - _00 * _21 * _12 - _22 * _01 * _10 );

    return tmp;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_00_() const noexcept {
    return _00;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_01_() const noexcept {
    return _01;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_02_() const noexcept {
    return _02;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_03_() const noexcept {
    return _03;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_10_() const noexcept {
    return _10;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_11_() const noexcept {
    return _11;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_12_() const noexcept {
    return _12;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_13_() const noexcept {
    return _13;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_20_() const noexcept {
    return _20;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_21_() const noexcept {
    return _21;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_22_() const noexcept {
    return _22;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_23_() const noexcept {
    return _23;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_30_() const noexcept {
    return _30;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_31_() const noexcept {
    return _31;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_32_() const noexcept {
    return _32;
}

template < no_cvref T > constexpr T
Matrix<4, T>::_33_() const noexcept {
    return _33;
}

}; // mathon::impl