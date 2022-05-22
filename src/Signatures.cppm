export module Math.Impl.Signatures;
export import Math.Impl.Utilites;

import <type_traits>;
import <concepts>;
// export import std;

export namespace mathon::impl {
    template < 
        LenghtT rows, 
        LenghtT cols,
        no_cvref T
    > class Matrix;

    template < 
        LenghtT dims, 
        no_cvref T
    > class QuadMatrix;
        
    template < 
        LenghtT dims,
        no_cvref T
    > class Vector;

    template < 
        LenghtT dims, 
        no_cvref T
    > class Color;

    template < 
        no_cvref T
    > class Quaternion;

    template < typename Vec >
    concept correct_vector = 
        has_value_type<Vec> && has_dimensions<Vec>
        && pure_same_as < Vec, Vector < dimensions<Vec>, value_type<Vec> >
    >;

    template < typename value, typename Vec >
    concept suitable_value_type = correct_vector<Vec> 
        && std::convertible_to<value, value_type<Vec>>;

    template < typename Vec >
    concept vector_2 = correct_vector<Vec> && equal<dimensions<Vec>, 2>;

    template < typename Vec >
    concept vector_3 = correct_vector<Vec> && equal<dimensions<Vec>, 3>;

    template < typename Vec >
    concept vector_4 = correct_vector<Vec> && equal<dimensions<Vec>, 4>;

    template <
        typename Vec,
        typename BaseVec
    > concept same_vector = correct_vector<Vec> && correct_vector<BaseVec>
        && std::same_as < value_type < Vec >, value_type < BaseVec > >
        && equal < dimensions < Vec >, dimensions < BaseVec > >;

    template <
        typename Vec,
        typename BaseVec
    > concept same_dim_vector = correct_vector<Vec> && correct_vector<BaseVec>
        && no_cvref_convertible_to<value_type<Vec>, value_type<BaseVec>>
        && equal < dimensions < Vec >, dimensions < BaseVec > >;

    template <
        typename Vec,
        typename BaseVec
    > concept suitable_vector = correct_vector<Vec> && correct_vector<BaseVec>
        && no_cvref_convertible_to<value_type<Vec>, value_type<BaseVec>>
        && not_less_then < dimensions < Vec >, dimensions < BaseVec > >;
} // Mathon::impl