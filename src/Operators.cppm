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

        template < vector_2 T, vector_2 U >
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

        template < vector_3 T, vector_3 U >
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

    };
};

export {
       constexpr auto operator -(correct_vector auto&& vec) noexcept {
        return impl::reverse <not_modify_value> (
            std::forward<decltype(vec)>(vec)
        );
    }

    constexpr void operator ~(correct_vector auto&& vec) {
        return impl::reverse <modify_value> (
            std::forward<decltype(vec)>(vec)
        );
    }

    constexpr auto operator *(correct_vector auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        return impl::calculateScalar <not_modify_value, std::multiplies<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator *=(correct_vector auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        return impl::calculateScalar <modify_value, std::multiplies<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    // to-do:/ need correct resolve zero division for - & -=
    constexpr auto operator /(correct_vector auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        if(val == 0) return vec;
        return impl::calculateScalar <not_modify_value, std::divides<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator /=(correct_vector auto&& vec, 
            suitable_value_type<decltype(vec)> auto&& val) noexcept {
        using cvt = value_type<decltype(vec)>;
        if(val == 0) return;
        return impl::calculateScalar <modify_value, std::divides<cvt>> (
                std::forward<decltype(vec)>(vec),
                std::forward<decltype(val)>(val)
        );
    }

    constexpr auto operator *(auto&& val, correct_vector auto&& vec) noexcept 
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

    constexpr auto operator +(correct_vector auto&& lhs, correct_vector auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <not_modify_value, std::plus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator +=(correct_vector auto&& lhs, correct_vector auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <modify_value, std::plus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator -(correct_vector auto&& lhs, correct_vector auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <not_modify_value, std::minus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr auto operator -=(correct_vector auto&& lhs, correct_vector auto&& rhs) noexcept {
        using cvt = common_value_type<decltype(lhs), decltype(rhs)>;
        return impl::calculate <modify_value, std::minus<cvt>> (
                std::forward<decltype(lhs)>(lhs),
                std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator <  (correct_vector auto&& lhs, correct_vector auto&& rhs) =delete;
    constexpr bool operator >  (correct_vector auto&& lhs, correct_vector auto&& rhs) =delete;
    constexpr bool operator <= (correct_vector auto&& lhs, correct_vector auto&& rhs) =delete;
    constexpr bool operator >= (correct_vector auto&& lhs, correct_vector auto&& rhs) =delete;

    constexpr bool operator == (correct_vector auto&& lhs, correct_vector auto&& rhs) {
        return impl::equal (
            std::forward<decltype(lhs)>(lhs),
            std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator != (correct_vector auto&& lhs, correct_vector auto&& rhs) {
        return !impl::equal (
            std::forward<decltype(lhs)>(lhs),
            std::forward<decltype(rhs)>(rhs)
        );
    }

    constexpr bool operator ||(correct_vector auto&& lhs, correct_vector auto&& rhs) {
        return lhs.colinear_to(rhs);
    }

    std::ostream& operator <<(std::ostream& out, correct_vector auto&& vec) {
        return impl::dump(out, vec);
    }
}; // Op