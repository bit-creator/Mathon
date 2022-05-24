export module Math.Impl.Matrix2;

export import Math.Impl.Operators;
export import Math.Impl.Signatures;

import Math.Impl.ShareModifier;
import Math.Impl.Vector2;
import Math.Impl.Vector3;
import Math.Impl.Vector4;

import <memory>;
import <concepts>;
import <cmath>;

template <typename T>
using matrix = mathon::impl::Matrix<2, T>;

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
> class Matrix<2, T> {
template <
    LenghtT l,
    no_cvref U
> friend class Matrix;
public:
using value_type = T;
using matrix     = Matrix<2, value_type>;
using reference  = matrix&;

public:
    constexpr static inline LenghtT dimensions = 2;

private:
    value_type                                 _00;
    value_type                                 _01;
    
    value_type                                 _10;
    value_type                                 _11; 

public:
// DESTRUCTOR
    constexpr 
    ~Matrix() noexcept(nt_d<T>) =default;

//  CONSTRUCTORS
    // constexpr Matrix() noexcept(nt_c<T>) requires std::default_initializable<T>;
    // constexpr explicit Matrix(value_type val) noexcept(nt_cc<T>);
    // constexpr Matrix(value_type _00_, value_type _01_, value_type _10_, value_type _11_) noexcept(nt_cc<T>);
    // constexpr Matrix(value_type _00_, value_type _01_, vector2 vec) noexcept(nt_cc<T>);
    // constexpr Matrix(vector2 vec, value_type _10_, value_type _11_) noexcept(nt_cc<T>);
    // constexpr Matrix(value_type _00_, vector2 vec, value_type _11_) noexcept(nt_cc<T>);
    // constexpr Matrix(vector2 vec, vector2 vec2) noexcept(nt_cc<T>);
    // constexpr Matrix(value_type _00_, vector3 vec) noexcept(nt_cc<T>);
    // constexpr Matrix(vector3 vec, value_type _11_) noexcept(nt_cc<T>);
    // constexpr Matrix(vector4 vec) noexcept(nt_cc<T>);

    // constexpr Matrix(suitable_matrix<matrix> auto&& vec) noexcept(nt_cc<T> && nt_mc<T>);

// ASSIGMENTS
    // constexpr reference
    // operator =(suitable_matrix<matrix> auto&& vec) noexcept(nt_ca<T> && nt_ma<T>);

    // constexpr value_type _00() const noexcept(nt_c<vector>);
    // constexpr value_type _01() const noexcept(nt_c<vector>);
    // constexpr value_type _10() const noexcept(nt_c<vector>);
    // constexpr value_type _11() const noexcept(nt_c<vector>);

    // constexpr vector first_columb() const noexcept(nt_c<vector>);
    // constexpr vector second_columb() const noexcept(nt_c<vector>);
    // constexpr vector first_row() const noexcept(nt_c<vector>);
    // constexpr vector second_row() const noexcept(nt_c<vector>);

    // constexpr void* elements();

    // void shuffle();

    // bool indentity();

}; // Matrix<2, T>

// template < no_cvref T > constexpr
// Matrix<2, T>::Matrix() noexcept(nt_c<T>) requires std::default_initializable<T>
//     : Matrix(T(1), T(0), T(0), T(1)) {
// }

// template < no_cvref T > constexpr explicit
// Matrix(value_type val) noexcept(nt_cc<T>);
//     : Matrix(val, val, val, val) {
// }

// template < no_cvref T > constexpr
// Matrix(value_type _00_, value_type _01_, value_type _10_, value_type _11_) noexcept(nt_cc<T>)
//     : _00(_00_), _01(_01_),
//       _10(_10_), _11(_11_) {
// }

// template < no_cvref T > constexpr 
// Matrix(value_type _00_, value_type _01_, vector2 vec) noexcept(nt_cc<T>)
//     : Matrix(_00_, _01_, vec.x(), vec.y()) {
// }

// template < no_cvref T > constexpr 
// Matrix(vector2 vec, value_type _10_, value_type _11_) noexcept(nt_cc<T>)
//     : Matrix(vec.x(), vec.y(), _10_, _11_) {
// }

// template < no_cvref T > constexpr 
// Matrix(value_type _00_, vector2 vec, value_type _11_) noexcept(nt_cc<T>)
//     : Matrix(_00_, vec.x(), vec.y(), _11_) {
// }

// template < no_cvref T > constexpr 
// Matrix(vector2 vec, value_type _10_, value_type _11_) noexcept(nt_cc<T>)
//     : Matrix(vec.x(), vec.y(), vec2.x(), vec2.y()) {
// }

// template < no_cvref T > constexpr 
// Matrix(value_type _00_, vector3 vec) noexcept(nt_cc<T>)
//     : Matrix(_00_, vec.x(), vec.y(), vec.z()) {
// }

// template < no_cvref T > constexpr 
// Matrix(vector3 vec, value_type _11_) noexcept(nt_cc<T>)
//     : Matrix(vec.x(), vec.y(), vec.z(), _11_) {
// }

// template < no_cvref T > constexpr 
// Matrix(vector4 vec) noexcept(nt_cc<T>)
//     : Matrix(vec.x(), vec.y(), vec.z(), vec.w()) {
// }





}; // mathon::impl