export module Math.Impl.Operators;
export import Math.Impl.Signatures;

export import Math.Impl.ShareModifier; 

import <memory>;
import <iostream>;
// import std;

using namespace mathon::impl;
using namespace mathon::impl::operators;


inline static constexpr bool modify_value       = true;
inline static constexpr bool not_modify_value   = false;

export inline constexpr bool is_row_order = false;

namespace mathon::impl::operators {
    struct impl {
// VECTOR_2
        template < bool modify, vector_2 T >
        static constexpr return_type<modify, std::remove_cvref_t<T>>
        reverse(T&& vec) noexcept {
            if constexpr (modify) {
                vec._x = -vec._x; 
                vec._y = -vec._y;
            } else return {-vec._x, -vec._y};
        }

        template <vector_2 T, vector_2 U >
        static constexpr common_value_type<T, U>
        multiply(T&& lhs, U&& rhs) noexcept {
            return lhs._x * rhs._x + lhs._y * rhs._y;
        }

        template <
            bool modify, typename Op, vector_2 T, suitable_value_type<T> U,
            typename Ret = return_type<modify, std::remove_cvref_t<T>>
        > static constexpr Ret
        calculateScalar(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs);
                lhs._y = std::invoke(Op{}, lhs._y, rhs);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs),
                std::invoke(Op{}, lhs._y, rhs)
            };    
        }

        template <
            bool modify, typename Op, vector_2 T, vector_2 U,
            typename Ret = return_type<modify, Vector<2, common_value_type<T, U>>>
        > static constexpr Ret
        calculate(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs._x);
                lhs._y = std::invoke(Op{}, lhs._y, rhs._y);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs._x),
                std::invoke(Op{}, lhs._y, rhs._y)
            };    
        }

        template < vector_2 T, vector_2 U >
        static constexpr bool
        equal(T&& lhs, U&& rhs) noexcept {
            return  lhs._x == rhs._x?
                    lhs._y == rhs._y?
                    true: false: false;
        }

        template < vector_2 T >
        static constexpr std::ostream&
        dump(std::ostream& out, T&& vec) noexcept {
        out << "dump:\n\tx = "
        << vec.x() << "\n\ty = "
        << vec.y() << std::endl;
        return out;
        }

// VECTOR_3
        template < bool modify, vector_3 T >
        static constexpr return_type<modify, std::remove_cvref_t<T>>
        reverse(T&& vec) noexcept {
            if constexpr (modify) {
                vec._x = -vec._x;
                vec._y = -vec._y;
                vec._z = -vec._z;
            } else return {-vec._x, -vec._y, -vec._z};
        }

        template <vector_3 T, vector_3 U >
        static constexpr common_value_type<T, U>
        multiply(T&& lhs, U&& rhs) noexcept {
            return lhs._x * rhs._x + lhs._y * rhs._y + lhs._z * rhs._z;
        }

        template <
            bool modify, typename Op, vector_3 T, suitable_value_type<T> U,
            typename Ret = return_type<modify, std::remove_cvref_t<T>>
        > static constexpr Ret
        calculateScalar(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs);
                lhs._y = std::invoke(Op{}, lhs._y, rhs);
                lhs._z = std::invoke(Op{}, lhs._z, rhs);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs),
                std::invoke(Op{}, lhs._y, rhs),
                std::invoke(Op{}, lhs._z, rhs)
            };    
        }

        template <
            bool modify, typename Op, vector_3 T, vector_3 U,
            typename Ret = return_type<modify, Vector<3, common_value_type<T, U>>>
        > static constexpr Ret
        calculate(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs._x);
                lhs._y = std::invoke(Op{}, lhs._y, rhs._y);
                lhs._z = std::invoke(Op{}, lhs._z, rhs._z);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs._x),
                std::invoke(Op{}, lhs._y, rhs._y),
                std::invoke(Op{}, lhs._z, rhs._z)
            };    
        }

        template < vector_3 T, vector_3 U >
        static constexpr bool
        equal(T&& lhs, U&& rhs) noexcept {
            return  lhs._x == rhs._x?
                    lhs._y == rhs._y?
                    lhs._z == rhs._z?
                    true: false: false: false;
        }

        template < vector_3 T >
        static constexpr std::ostream&
        dump(std::ostream& out, T&& vec) noexcept {
        out << "dump:\n\tx = "
        << vec.x() << "\n\ty = "
        << vec.y() << "\n\tz = "
        << vec.z() << std::endl;
        return out;
        }

// VECTOR_4
        template < bool modify, vector_4 T >
        static constexpr return_type<modify, std::remove_cvref_t<T>>
        reverse(T&& vec) noexcept {
            if constexpr (modify) {
                vec._x = -vec._x;
                vec._y = -vec._y;
                vec._z = -vec._z;
            } else return {-vec._x, -vec._y, -vec._z};
        }

        template <vector_4 T, vector_4 U >
        static constexpr common_value_type<T, U>
        multiply(T&& lhs, U&& rhs) noexcept {
            return lhs._x * rhs._x + lhs._y * rhs._y + lhs._z * rhs._z;
        }

        template <
            bool modify, typename Op, vector_4 T, suitable_value_type<T> U,
            typename Ret = return_type<modify, std::remove_cvref_t<T>>
        > static constexpr Ret
        calculateScalar(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs);
                lhs._y = std::invoke(Op{}, lhs._y, rhs);
                lhs._z = std::invoke(Op{}, lhs._z, rhs);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs),
                std::invoke(Op{}, lhs._y, rhs),
                std::invoke(Op{}, lhs._z, rhs)
            };    
        }

        template <
            bool modify, typename Op, vector_4 T, vector_4 U,
            typename Ret = return_type<modify, Vector<3, common_value_type<T, U>>>
        > static constexpr Ret
        calculate(T&& lhs, U&& rhs) {
            if constexpr (modify) {
                lhs._x = std::invoke(Op{}, lhs._x, rhs._x);
                lhs._y = std::invoke(Op{}, lhs._y, rhs._y);
                lhs._z = std::invoke(Op{}, lhs._z, rhs._z);
            } else return { 
                std::invoke(Op{}, lhs._x, rhs._x),
                std::invoke(Op{}, lhs._y, rhs._y),
                std::invoke(Op{}, lhs._z, rhs._z)
            };    
        }

        template < vector_4 T, vector_4 U >
        static constexpr bool
        equal(T&& lhs, U&& rhs) noexcept {
            return  lhs._x == rhs._x?
                    lhs._y == rhs._y?
                    lhs._z == rhs._z?
                    true: false: false: false;
        }

        template < vector_4 T >
        static constexpr std::ostream&
        dump(std::ostream& out, T&& vec) noexcept {
        out << "dump:\n\tx = "
        << vec.x() << "\n\ty = "
        << vec.y() << "\n\tz = "
        << vec.z() << std::endl;
        return out;
        }

// Matrix4
        template <bool modify, matrix_4 T, matrix_4 U >
        static constexpr return_type<modify, Matrix<4, common_value_type<T, U>>>
        multiply_matrix(T&& lhs, U&& rhs) noexcept {
            if constexpr (modify) {
                T& res = lhs;
                if constexpr (!is_row_order) res = rhs;
                Vector<3, T> tmp;
                tmp.x(lhs._00 * rhs._00 + lhs._01 * rhs._10 + lhs._02 * rhs._20 + lhs._03 * rhs._30);
                tmp.y(lhs._00 * rhs._01 + lhs._01 * rhs._11 + lhs._02 * rhs._21 + lhs._03 * rhs._31);
                tmp.z(lhs._00 * rhs._02 + lhs._01 * rhs._12 + lhs._02 * rhs._22 + lhs._03 * rhs._32);
                if constexpr (is_row_order) res._00 = tmp._x; else res._00 = tmp._x;
                if constexpr (is_row_order) res._01 = tmp._y; else res._10 = tmp._y;
                if constexpr (is_row_order) res._02 = tmp._z; else res._20 = tmp._z;
                if constexpr (is_row_order) 
                    res._03 = lhs._00 * rhs._03 + lhs._01 * rhs._13 + lhs._02 * rhs._23 + lhs._03 * rhs._33;
                else res._30 = lhs._00 * rhs._03 + lhs._01 * rhs._13 + lhs._02 * rhs._23 + lhs._03 * rhs._33;

                tmp.x(lhs._10 * rhs._00 + lhs._11 * rhs._10 + lhs._12 * rhs._20 + lhs._13 * rhs._30);
                tmp.y(lhs._10 * rhs._01 + lhs._11 * rhs._11 + lhs._12 * rhs._21 + lhs._13 * rhs._31);
                tmp.z(lhs._10 * rhs._02 + lhs._11 * rhs._12 + lhs._12 * rhs._22 + lhs._13 * rhs._32);
                if constexpr (is_row_order) res._10 = tmp._x; else res._01 = tmp._x;
                if constexpr (is_row_order) res._11 = tmp._y; else res._11 = tmp._y;
                if constexpr (is_row_order) res._12 = tmp._z; else res._21 = tmp._z;
                if constexpr (is_row_order) 
                    res._13 = lhs._10 * rhs._03 + lhs._11 * rhs._13 + lhs._12 * rhs._23 + lhs._13 * rhs._33;
                else res._31 = lhs._10 * rhs._03 + lhs._11 * rhs._13 + lhs._12 * rhs._23 + lhs._13 * rhs._33;

                tmp.x(lhs._20 * rhs._00 + lhs._21 * rhs._10 + lhs._22 * rhs._20 + lhs._23 * rhs._30);
                tmp.y(lhs._20 * rhs._01 + lhs._21 * rhs._11 + lhs._22 * rhs._21 + lhs._23 * rhs._31);
                tmp.z(lhs._20 * rhs._02 + lhs._21 * rhs._12 + lhs._22 * rhs._22 + lhs._23 * rhs._32);
                if constexpr (is_row_order) res._20 = tmp._x; else res._02 = tmp._x;
                if constexpr (is_row_order) res._21 = tmp._y; else res._12 = tmp._y;
                if constexpr (is_row_order) res._22 = tmp._z; else res._22 = tmp._z;
                if constexpr (is_row_order) 
                    res._23 = lhs._20 * rhs._03 + lhs._21 * rhs._13 + lhs._22 * rhs._23 + lhs._23 * rhs._33;
                else res._32 = lhs._20 * rhs._03 + lhs._21 * rhs._13 + lhs._22 * rhs._23 + lhs._23 * rhs._33;

                tmp.x(lhs._30 * rhs._00 + lhs._31 * rhs._10 + lhs._32 * rhs._20 + lhs._33 * rhs._30);
                tmp.y(lhs._30 * rhs._01 + lhs._31 * rhs._11 + lhs._32 * rhs._21 + lhs._33 * rhs._31);
                tmp.z(lhs._30 * rhs._02 + lhs._31 * rhs._12 + lhs._32 * rhs._22 + lhs._33 * rhs._32);
                if constexpr (is_row_order) res._30 = tmp._x; else res._03 = tmp._x;
                if constexpr (is_row_order) res._31 = tmp._y; else res._13 = tmp._y;
                if constexpr (is_row_order) res._32 = tmp._z; else res._23 = tmp._z;
                if constexpr (is_row_order) 
                    res._33 = lhs._30 * rhs._03 + lhs._31 * rhs._13 + lhs._32 * rhs._23 + lhs._33 * rhs._33;
                else res._33 = lhs._30 * rhs._03 + lhs._31 * rhs._13 + lhs._32 * rhs._23 + lhs._33 * rhs._33;
            
            } else if constexpr (!is_row_order) return {
                lhs._00 * rhs._00 + lhs._01 * rhs._10 + lhs._02 * rhs._20 + lhs._03 * rhs._30,
                lhs._10 * rhs._00 + lhs._11 * rhs._10 + lhs._12 * rhs._20 + lhs._13 * rhs._30,
                lhs._20 * rhs._00 + lhs._21 * rhs._10 + lhs._22 * rhs._20 + lhs._23 * rhs._30,
                lhs._30 * rhs._00 + lhs._31 * rhs._10 + lhs._32 * rhs._20 + lhs._33 * rhs._30,

                lhs._00 * rhs._01 + lhs._01 * rhs._11 + lhs._02 * rhs._21 + lhs._03 * rhs._31,
                lhs._10 * rhs._01 + lhs._11 * rhs._11 + lhs._12 * rhs._21 + lhs._13 * rhs._31,
                lhs._20 * rhs._01 + lhs._21 * rhs._11 + lhs._22 * rhs._21 + lhs._23 * rhs._31,
                lhs._30 * rhs._01 + lhs._31 * rhs._11 + lhs._32 * rhs._21 + lhs._33 * rhs._31,

                lhs._00 * rhs._02 + lhs._01 * rhs._12 + lhs._02 * rhs._22 + lhs._03 * rhs._32,
                lhs._10 * rhs._02 + lhs._11 * rhs._12 + lhs._12 * rhs._22 + lhs._13 * rhs._32,
                lhs._20 * rhs._02 + lhs._21 * rhs._12 + lhs._22 * rhs._22 + lhs._23 * rhs._32,
                lhs._30 * rhs._02 + lhs._31 * rhs._12 + lhs._32 * rhs._22 + lhs._33 * rhs._32,

                lhs._00 * rhs._03 + lhs._01 * rhs._13 + lhs._02 * rhs._23 + lhs._03 * rhs._33,
                lhs._10 * rhs._03 + lhs._11 * rhs._13 + lhs._12 * rhs._23 + lhs._13 * rhs._33,
                lhs._20 * rhs._03 + lhs._21 * rhs._13 + lhs._22 * rhs._23 + lhs._23 * rhs._33,
                lhs._30 * rhs._03 + lhs._31 * rhs._13 + lhs._32 * rhs._23 + lhs._33 * rhs._33,
            }; else return {
                lhs._00 * rhs._00 + lhs._01 * rhs._10 + lhs._02 * rhs._20 + lhs._03 * rhs._30,
                lhs._00 * rhs._01 + lhs._01 * rhs._11 + lhs._02 * rhs._21 + lhs._03 * rhs._31,
                lhs._00 * rhs._02 + lhs._01 * rhs._12 + lhs._02 * rhs._22 + lhs._03 * rhs._32,
                lhs._00 * rhs._03 + lhs._01 * rhs._13 + lhs._02 * rhs._23 + lhs._03 * rhs._33,

                lhs._10 * rhs._00 + lhs._11 * rhs._10 + lhs._12 * rhs._20 + lhs._13 * rhs._30,
                lhs._10 * rhs._01 + lhs._11 * rhs._11 + lhs._12 * rhs._21 + lhs._13 * rhs._31,
                lhs._10 * rhs._02 + lhs._11 * rhs._12 + lhs._12 * rhs._22 + lhs._13 * rhs._32,
                lhs._10 * rhs._03 + lhs._11 * rhs._13 + lhs._12 * rhs._23 + lhs._13 * rhs._33,

                lhs._20 * rhs._00 + lhs._21 * rhs._10 + lhs._22 * rhs._20 + lhs._23 * rhs._30,
                lhs._20 * rhs._01 + lhs._21 * rhs._11 + lhs._22 * rhs._21 + lhs._23 * rhs._31,
                lhs._20 * rhs._02 + lhs._21 * rhs._12 + lhs._22 * rhs._22 + lhs._23 * rhs._32,
                lhs._20 * rhs._03 + lhs._21 * rhs._13 + lhs._22 * rhs._23 + lhs._23 * rhs._33,

                lhs._30 * rhs._00 + lhs._31 * rhs._10 + lhs._32 * rhs._20 + lhs._33 * rhs._30,
                lhs._30 * rhs._01 + lhs._31 * rhs._11 + lhs._32 * rhs._21 + lhs._33 * rhs._31,
                lhs._30 * rhs._02 + lhs._31 * rhs._12 + lhs._32 * rhs._22 + lhs._33 * rhs._32,
                lhs._30 * rhs._03 + lhs._31 * rhs._13 + lhs._32 * rhs._23 + lhs._33 * rhs._33,
            };
        }

        template < matrix_4 T >
        static constexpr std::ostream&
        dump(std::ostream& out, T&& mat) noexcept {
            out << " \t" << mat._00_()
                << ",\t" << mat._01_()
                << ",\t" << mat._02_()
                << ",\t" << mat._03_()
                << std::endl;

            out << " \t" << mat._10_()
                << ",\t" << mat._11_()
                << ",\t" << mat._12_()
                << ",\t" << mat._13_()
                << std::endl;

            out << " \t" << mat._20_()
                << ",\t" << mat._21_()
                << ",\t" << mat._22_()
                << ",\t" << mat._23_()
                << std::endl;

            out << " \t" << mat._30_()
                << ",\t" << mat._31_()
                << ",\t" << mat._32_()
                << ",\t" << mat._33_()
                << std::endl;

            return out;
        }
    }; // impl
}; // mathon::impl::operators

export {
       constexpr auto operator -(math_primitive auto&& vec) noexcept {
        return impl::reverse <not_modify_value> (
            std::forward<decltype(vec)>(vec)
        );
    }

    constexpr void operator ~(math_primitive auto&& vec) {
        return impl::reverse <modify_value> (
            std::forward<decltype(vec)>(vec)
        );
    }

    constexpr auto operator *(math_primitive auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        return impl::calculateScalar <not_modify_value, std::multiplies<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator *=(math_primitive auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        return impl::calculateScalar <modify_value, std::multiplies<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    // to-do:/ need correct resolve zero division for - & -=
    constexpr auto operator /(math_primitive auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        if(val == 0) return vec;
        return impl::calculateScalar <not_modify_value, std::divides<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator /=(math_primitive auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        if(val == 0) return;
        return impl::calculateScalar <modify_value, std::divides<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator *(auto&& val, math_primitive auto&& vec) noexcept 
            requires(suitable_value_type<decltype(val), decltype(vec)>) {
        using cvt = value_type<decltype(vec)>;
        return impl::calculateScalar <not_modify_value, std::multiplies<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator *(correct_vector auto&& lhs, correct_vector auto&& rhs) noexcept {
        return impl::multiply (
            std::forward<decltype(lhs)>(lhs),
            std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator *(correct_matrix auto&& lhs, correct_matrix auto&& rhs) noexcept {
        if constexpr (is_row_order) {
            return impl::multiply_matrix<false> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
            );
        } else {
            return impl::multiply_matrix<false> (
                std::forward<decltype(rhs)>(rhs),
                std::forward<decltype(lhs)>(lhs)
            );
        }
    }

    constexpr auto operator +(math_primitive auto&& lhs, math_primitive auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <not_modify_value, std::plus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator +=(math_primitive auto&& lhs, math_primitive auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <modify_value, std::plus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator -(math_primitive auto&& lhs, math_primitive auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <not_modify_value, std::minus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator -=(math_primitive auto&& lhs, math_primitive auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <modify_value, std::minus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator <  (math_primitive auto&& lhs, math_primitive auto&& rhs) =delete;
    constexpr bool operator >  (math_primitive auto&& lhs, math_primitive auto&& rhs) =delete;
    constexpr bool operator <= (math_primitive auto&& lhs, math_primitive auto&& rhs) =delete;
    constexpr bool operator >= (math_primitive auto&& lhs, math_primitive auto&& rhs) =delete;

    constexpr bool operator == (math_primitive auto&& lhs, math_primitive auto&& rhs) {
        return impl::equal (
            std::forward<decltype(lhs)>(lhs),
            std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator != (math_primitive auto&& lhs, math_primitive auto&& rhs) {
        return !impl::equal (
            std::forward<decltype(lhs)>(lhs),
            std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator ||(math_primitive auto&& lhs, math_primitive auto&& rhs) {
        return lhs.colinear_to(rhs);
    }

    std::ostream& operator <<(std::ostream& out, math_primitive auto&& vec) {
        return impl::dump(out, vec);
    }
}; // Op