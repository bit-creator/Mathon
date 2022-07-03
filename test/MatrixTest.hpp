#include <iostream>

#include "simpleFrameWork.hpp"

namespace Matrix2Test {
namespace mth = mathon;

void run() {
    TEST_ENTITY(MATRIX_2)
}
};

namespace Matrix3Test {
namespace mth = mathon;

void run() {
    TEST_ENTITY(MATRIX_3)
}
};

namespace Matrix4Test {
namespace mth = mathon;

void quat() {
    TEST(copy) {
        mth::Quaternion4f q(3, {1, 0, 0});
        mth::Quaternion4f p = q;

        return true;
    };

    TEST(move) {
        mth::Quaternion4f q(3, {1, 0, 0});
        mth::Quaternion4f p = mth::Quaternion4f(3, {1, 0, 0});

        return true;
    };

    CHECK(copy)
}

void operators() {
    TEST(multiplication) {
        mth::Matrix4f mat;
        mth::Matrix4f mat2 = mat * mat;

        RET_MAT4(mat2, mat)
    };

    TEST(multiplication2) {
        mth::Matrix4f mat {
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
        };

        mth::Matrix4f mat2 = mat * mat;

        mth::Matrix4f correct_mat ={
             90, 100, 110, 120,
            202, 228, 254, 280,
            314, 356, 398, 440,
            426, 484, 542, 600
        };
        RET_MAT4(mat2, correct_mat)
    };

    TEST(make_model) {
        mth::Vector3f scale(2, 6, 8);
        mth::Vector3f translate(10, 12, 18);
        mth::Quaternion4f quat(4, {1, 1, 1});

        mth::Matrix4f mat{scale, quat, translate};

        mth::Matrix4f correct_mat = {
            -4.61457,	14.4627,	7.17473,	10,
 	        1.79368,	-13.8437,	19.2836,	12,
 	        4.82089,	5.38105,	-18.4583,	18,
 	        0,          0,          0,          1,
        };

        // std::cout << mat;
        // std::cout << correct_mat;

        RET_MAT4(mat, correct_mat)
    };
  
    CHECK(multiplication)
    CHECK(multiplication2)
    CHECK(make_model)
}

void run() {
    TEST_ENTITY(QUATERNION)
    CHECK_GROUP(quat)


    TEST_ENTITY(MATRIX_4)
    CHECK_GROUP(operators)
}
};