#include <iostream>

#include "simpleFrameWork.hpp"

namespace Vector2Test {
namespace mth = mathon;

void ConstructibleTests() {
    TEST(defaultConstruct) {
        mathon::Vector2i vec;
        RET(vec, int(), int())
    };

    TEST(constructByValue) {
        mathon::Vector2i vec(4.0);
        RET(vec, 4, 4)
    };

    TEST(constructByPair) {
        mathon::Vector2i vec(6, 8.0);
        RET(vec, 6, 8)
    };

    TEST(copyConstruct) {
        mathon::Vector2f vec{12, 21};
        mathon::Vector2d vec2 = vec;
        RET(vec, vec2.x(), vec2.y())
    };

    TEST(moveConstruct) {
        mathon::Vector2f vec{12, 21};
        mathon::Vector2i vec2 = mathon::Vector2d(vec);
        RET(vec, vec2.x(), vec2.y())
    };

    CHECK(defaultConstruct)
    CHECK(constructByValue)
    CHECK(constructByPair)
    CHECK(copyConstruct)
    CHECK(moveConstruct)
}

void AssigmentTests() {
    TEST(copyAssigment) {
        mathon::Vector2i v(25, 67);
        mathon::Vector2i v2(67, 25);
        v2 = v;
        RET(v2, 25, 67)
    };

    TEST(MoveAssigment) {
        mathon::Vector2i v(25, 67);
        mathon::Vector2i v2(67, 25);
        v2 = mathon::Vector2f(v);
        RET(v2, 25, 67)
    };

    CHECK(copyAssigment)
    CHECK(MoveAssigment)
}

void SetterTests() {
    TEST(SimpleSet) {
        mth::Vector2f v(92, 112);
        v.y(v.x());
        v.x(234);
        RET(v, 234, 92)
    };

    TEST(DoubleSets) {
        mth::Vector2f v(92, 112);
        v.xy(234, v.x());
        RET(v, 234, 92)
    };
    // copy and move sets tested in AssigmentTests well

    CHECK(SimpleSet)
    CHECK(DoubleSets)
}

void Swizzling() {
        // simple getters tested in all other testes
    TEST(yx) {
        mth::Vector2i vec(423, 759);
        mth::Vector2i v2 = vec.yx();
        RET(v2, 759, 423)
    };

    TEST(xx) {
        mth::Vector2i vec(423, 759);
        mth::Vector2i v2 = vec.xx();
        RET(v2, 423, 423)
    };


    TEST(yy) {
        mth::Vector2i vec(423, 759);
        mth::Vector2i v2 = vec.yy();
        RET(v2, 759, 759)
    };

    CHECK(yx)
    CHECK(xx)
    CHECK(yy)
}

void Operators() {
    TEST(reverse) {
        mth::Vector2f v{5, -2};
        v = -v;
        RET(v, -5, 2)
    };

    TEST(reverse2) {
        mth::Vector2f v{5, -2};
        ~v;
        RET(v, -5, 2)
    };

    TEST(multiplication) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2{8.0, 4.0f};

        return v * v2 == 64;
    };

    TEST(scalarMultiplication) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2 = v * 10;
        
        RET(v2, 40, 80)
    };


    TEST(scalarMultiplication2) {
        double i = 10.0;
        mth::Vector2i v{4, 8};
        mth::Vector2f v2 = v * i;
        
        RET(v2, 40, 80)
    };

    TEST(scalarMultiplication3) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2 = 10 * v;
        
        RET(v2, 40, 80)
    };
    
    TEST(scalarMultiplication4) {
        mth::Vector2i v{4, 8};
        v *= 10;
        
        RET(v, 40, 80)
    };

    TEST(scalarDiv) {
        mth::Vector2i v{40, 80};
        mth::Vector2f v2 = v / 10;
        
        RET(v2, 4, 8)
    };
    
    TEST(scalarDiv2) {
        mth::Vector2i v{40, 80};
        v /= 10;
        
        RET(v, 4, 8)
    };

    TEST(plusOperator) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2 = v + mth::Vector2d(8, 4);
        v2 += v;

        RET(v2, 16, 20)
    };

    TEST(plusOperator2) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2 = mth::Vector2f(8, 4) + v;
        
        RET(v2, 12, 12)
    };

    TEST(plusOperator3) {
        mth::Vector2f v = mth::Vector2i(4, 8) + mth::Vector2i(8, 4);
        
        RET(v, 12, 12)
    };

    TEST(minusOperator) {
        mth::Vector2f v = mth::Vector2i(4, 8) - mth::Vector2i(8, 4);
        v -= mth::Vector2d(4., 8.);
        
        RET(v,-8, -4)
    };

    TEST(comparison) {
        mth::Vector2i v{4, 8};
        mth::Vector2f v2{4, 8};
        mth::Vector2f v3{8, 4};
        mth::Vector2i v4{v == v2, v != v3};
        
        RET(v4, 1, 1)
    };

    TEST(colinear) {
        mth::Vector2i v{0, 8};
        mth::Vector2f v2{4, 0};
        mth::Vector2f v3{0, 0};
        mth::Vector2i v4{v3 || v2, v || v3};
        
        RET(v4, 0, 0)
    };

    TEST(colinear2) {
        mth::Vector2i v{0, 8};
        mth::Vector2f v2{4, 0};
        mth::Vector2f v3{3, 0};
        mth::Vector2i v4{v3 || v2, v || v2};
        
        RET(v4, 1, 0)
    };

    TEST(colinear3) {
        mth::Vector2i v{6, 8};
        mth::Vector2f v2{3, 4};
        mth::Vector2f v3{3, 5};
        mth::Vector2i v4{v || v2, v3 || v2};
        
        RET(v4, 1, 0)
    };

    TEST(colinear4) {
        mth::Vector2i v{6, 8};
        mth::Vector2f v2{3, 4};
        mth::Vector2f v3{3, 5};
        mth::Vector2i v4{v2 || v, v3 || v2};
        
        RET(v4, 1, 0)
    };

    TEST(normalize) {
        mth::Vector2f v{3, 4};
        mth::Vector2f v2{0.2, 0};

        mth::Vector2i v4{v.is_normalize(), v2.is_normalize()};
        
        RET(v4, 0, 0)
    };

    TEST(normalize2) {
        mth::Vector2f v{1, 1};
        mth::Vector2f v2{0, 1};

        mth::Vector2i v4{v.is_normalize(), v2.is_normalize()};
        
        RET(v4, 0, 1)
    };

    TEST(normalize3) {
        mth::Vector2f v{3, 5};
        mth::Vector2f v2{4, 2};
        v.normalize(); v2.normalize();
        mth::Vector2i v4{v.is_normalize(), v2.is_normalize()};
        
        RET(v4, 1, 1)
    };

    TEST(dump) {
        mth::Vector2f v{3, 5};
        mth::Vector2f v2{4, 2};
        
        std::cout << v << v2 << std::endl;

        return true;
    };

    CHECK(reverse)
    CHECK(reverse2)
    CHECK(multiplication)
    CHECK(scalarMultiplication)
    CHECK(scalarMultiplication2)
    CHECK(scalarMultiplication3)
    CHECK(scalarMultiplication4)
    CHECK(scalarDiv)
    CHECK(scalarDiv2)
    CHECK(plusOperator)
    CHECK(plusOperator2)
    CHECK(plusOperator3)
    CHECK(minusOperator)
    CHECK(comparison)
    CHECK(colinear)
    CHECK(colinear2)
    CHECK(colinear3)
    CHECK(colinear4)
    CHECK(normalize)
    CHECK(normalize2)
    CHECK(normalize3)
    CHECK(dump)
}

void run() {
    TEST_ENTITY(VECTOR_2)
    CHECK_GROUP(ConstructibleTests)
    CHECK_GROUP(AssigmentTests)
    CHECK_GROUP(SetterTests)
    CHECK_GROUP(Swizzling)
    CHECK_GROUP(Operators)
}

}; // Vector2Test

namespace Vector3Test {
namespace mth = mathon;

void ConstructibleTests() {
    TEST(defaultConstruct) {
        mth::Vector3i vec;
        RET3(vec, int(), int(), int())
    };

    TEST(constructByValue) {
        mathon::Vector3i vec(4.0);
        RET3(vec, 4, 4, 4)
    };

    TEST(constructByPair) {
        mathon::Vector3i vec(6, 8.0);
        RET3(vec, 6, 8, 0)
    };

    TEST(constructByVector) {
        mathon::Vector3i vec(mth::Vector2f(6, 8));
        RET3(vec, 6, 8, 0)
    };    
    
    TEST(constructByVectorWithVal) {
        mth::Vector2f vec2f(6, 8);
        mathon::Vector3i vec(0, vec2f);
        RET3(vec, 0, 6, 8)
    };

    TEST(constructByVectorWithVal2) {
        mth::Vector2f vec2f(6, 8);
        mathon::Vector3i vec(vec2f, 0);
        RET3(vec, 6, 8, 0)
    };

    TEST(copyConstruct) {
        mathon::Vector3f vec{12, 21};
        mathon::Vector3d vec2 = vec;
        RET3(vec, vec2.x(), vec2.y(), vec2.z())
    };

    TEST(moveConstruct) {
        mathon::Vector3f vec{12, 21};
        mathon::Vector3i vec2 = mathon::Vector3d(vec);
        RET3(vec, vec2.x(), vec2.y(), vec2.z())
    };

    CHECK(defaultConstruct)
    CHECK(constructByValue)
    CHECK(constructByPair)
    CHECK(constructByVector)
    CHECK(constructByVectorWithVal)
    CHECK(constructByVectorWithVal2)
    CHECK(copyConstruct)
    CHECK(moveConstruct)
}

void AssigmentTests() {
    TEST(Vec3CopyAssigment) {
        mth::Vector3d vec{3.0};
        mth::Vector3f vec2{0, 6, 8};
        vec2 = vec;
        RET3(vec2, 3.0, 3.0, 3.0)
    };

    TEST(Vec3MoveAssigment) {
        mth::Vector3f vec2{0, 6, 8};
        vec2 = mth::Vector3d{3.0};
        RET3(vec2, 3.0, 3.0, 3.0)
    };

    TEST(Vec3SelfAssigment) {
        mth::Vector3f vec2{0, 6, 8};
        vec2 = vec2;
        RET3(vec2, 0.0, 6.0, 8.0)
    };

    TEST(Vec2CopyAssigment) {
        mth::Vector2d vec{3.0};
        mth::Vector3f vec2{0, 6, 8};
        vec2 = vec;
        RET3(vec2, 3.0, 3.0, 0.0)
    };

    TEST(Vec2MoveAssigment) {
        mth::Vector3f vec2{0, 6, 8};
        vec2 = mth::Vector2d{3.0};
        RET3(vec2, 3.0, 3.0, 0.0)
    };

    CHECK(Vec3CopyAssigment)
    CHECK(Vec3MoveAssigment)
    CHECK(Vec3SelfAssigment)
    CHECK(Vec2CopyAssigment)
    CHECK(Vec2MoveAssigment)
}

void SetterTests() {
    TEST(SimpleSet) {
        mth::Vector3f v(92, 112);
        v.z(v.x() + v.y());
        v.x(234);
        v.y(654);
        RET3(v, 234, 654, 204)
    };

    TEST(DoubleSets) {
        mth::Vector3f v(92, 112);
        mth::Vector2f v2(92, 112);

        v.yz(v2);
        RET3(v, 92, 92, 112)
    };

    TEST(TripleSets) {
        mth::Vector3f v(92, 112);
        mth::Vector2f v2(92, 112);

        v.xyz(234, v2);
        RET3(v, 234, 92, 112)
    };
    // copy and move sets tested in AssigmentTests well

    CHECK(SimpleSet)
    CHECK(DoubleSets)
    CHECK(TripleSets)
}

void Swizzling() {
    TEST(SimpleGet) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.z(), vec.x(), vec.y());
        RET3(vec2, 3, 1, 2)
    };

    TEST(xy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.z(), vec.xy());
        RET3(vec2, 3, 1, 2)
    };

    TEST(xz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.z(), vec.xz());
        RET3(vec2, 3, 1, 3)
    };

    TEST(yx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yx(), vec.x());
        RET3(vec2, 2, 1, 1)
    };

    TEST(yz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yz(), vec.x());
        RET3(vec2, 2, 3, 1)
    };

    TEST(zx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.z(), vec.zx());
        RET3(vec2, 3, 3, 1)
    };

    TEST(zy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zy(), vec.x());
        RET3(vec2, 3, 2, 1)
    };

    TEST(xx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xx(), vec.x());
        RET3(vec2, 1, 1, 1)
    };

    TEST(yy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.y(), vec.yy());
        RET3(vec2, 2, 2, 2)
    };

    TEST(zz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.z(), vec.zz());
        RET3(vec2, 3, 3, 3)
    };

    TEST(xyz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xyz());
        RET3(vec2, 1, 2, 3)
    };

    TEST(xzy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xzy());
        RET3(vec2, 1, 3, 2)
    };

    TEST(yxz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yxz());
        RET3(vec2, 2, 1, 3)
    };

    TEST(yzx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yzx());
        RET3(vec2, 2, 3, 1)
    };

    TEST(zxy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zxy());
        RET3(vec2, 3, 1, 2)
    };

    TEST(zyx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zyx());
        RET3(vec2, 3, 2, 1)
    };

    TEST(xxy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xxy());
        RET3(vec2, 1, 1, 2)
    };

    TEST(xxz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xxz());
        RET3(vec2, 1, 1, 3)
    };    
    
    TEST(yxx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yxx());
        RET3(vec2, 2, 1, 1)
    };

    TEST(zxx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zxx());
        RET3(vec2, 3, 1, 1)
    };

    TEST(xyx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xyx());
        RET3(vec2, 1, 2, 1)
    };

    TEST(xzx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xzx());
        RET3(vec2, 1, 3, 1)
    };

    TEST(yyx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yyx());
        RET3(vec2, 2, 2, 1)
    };

    TEST(yyz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yyz());
        RET3(vec2, 2, 2, 3)
    };

    TEST(xyy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xyy());
        RET3(vec2, 1, 2, 2)
    };

    TEST(zyy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zyy());
        RET3(vec2, 3, 2, 2)
    };

    TEST(yxy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yxy());
        RET3(vec2, 2, 1, 2)
    };

    TEST(yzy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yzy());
        RET3(vec2, 2, 3, 2)
    };

    TEST(zzx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zzx());
        RET3(vec2, 3, 3, 1)
    };

    TEST(zzy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zzy());
        RET3(vec2, 3, 3, 2)
    };

    TEST(xzz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xzz());
        RET3(vec2, 1, 3, 3)
    };

    TEST(yzz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yzz());
        RET3(vec2, 2, 3, 3)
    };

    TEST(zxz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zxz());
        RET3(vec2, 3, 1, 3)
    };

    TEST(zyz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zyz());
        RET3(vec2, 3, 2, 3)
    };

    TEST(xxx) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.xxx());
        RET3(vec2, 1, 1, 1)
    };

    TEST(yyy) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.yyy());
        RET3(vec2, 2, 2, 2)
    };
        
    TEST(zzz) {
        mth::Vector3d vec{1, 2, 3};
        mth::Vector3i vec2(vec.zzz());
        RET3(vec2, 3, 3, 3)
    };

    CHECK(SimpleGet)
    CHECK(xy)
    CHECK(xz)
    CHECK(yx)
    CHECK(yz)
    CHECK(zx)
    CHECK(zy)
    CHECK(xx)
    CHECK(yy)
    CHECK(zz)

    CHECK(xyz)
    CHECK(xzy)
    CHECK(yxz)
    CHECK(yzx)
    CHECK(zxy)
    CHECK(zyx)
    CHECK(xxy)
    CHECK(xxz)
    CHECK(yxx)
    CHECK(zxx)
    CHECK(xyx)
    CHECK(xzx)
    CHECK(yyx)
    CHECK(yyz)
    CHECK(xyy)
    CHECK(zyy)
    CHECK(yxy)
    CHECK(yzy)
    CHECK(zzx)
    CHECK(zzy)
    CHECK(xzz)
    CHECK(yzz)
    CHECK(zxz)
    CHECK(zyz)
    CHECK(xxx)
    CHECK(yyy)
    CHECK(zzz)
}

void Operators() {
    TEST(reverse) {
        mth::Vector3f v{5, -2, 6};
        v = -v;
        RET3(v, -5, 2, -6)
    };

    TEST(reverse2) {
        mth::Vector3f v{5, -2, 6};
        ~v;
        RET3(v, -5, 2, -6)
    };

    TEST(multiplication) {
        mth::Vector3i v{4, 8, 2};
        mth::Vector3f v2{8.0, 4.0f, 2};

        return v * v2 == 68;
    };

    TEST(scalarMultiplication) {
        mth::Vector3i v{4, 8, 6};
        mth::Vector3f v2 = v * 10;
        
        RET3(v2, 40, 80, 60)
    };


    TEST(scalarMultiplication2) {
        double i = 10.0;
        mth::Vector3i v{4, 8, 6};
        mth::Vector3f v2 = v * i;
        
        RET3(v2, 40, 80, 60)
    };

    TEST(scalarMultiplication3) {
        mth::Vector3i v{4, 8, 6};
        mth::Vector3f v2 = 10 * v;
        
        RET3(v2, 40, 80, 60)
    };
    
    TEST(scalarMultiplication4) {
        mth::Vector3i v{4, 8, 6};
        v *= 10;
        
        RET3(v, 40, 80, 60)
    };

    TEST(scalarDiv) {
        mth::Vector3i v{40, 80, 60};
        mth::Vector3f v2 = v / 10;
        
        RET3(v2, 4, 8, 6)
    };
    
    TEST(scalarDiv2) {
        mth::Vector3i v{40, 80, 60};
        v /= 10;
        
        RET3(v, 4, 8, 6)
    };

    TEST(plusOperator) {
        mth::Vector3i v{4, 8, 6};
        mth::Vector3f v2 = v + mth::Vector3d(8, 4, 6);
        v2 += v;

        RET3(v2, 16, 20, 18)
    };

    TEST(plusOperator2) {
        mth::Vector3i v{4, 8, 6};
        mth::Vector3f v2 = mth::Vector3f(8, 4, 6) + v;
        
        RET3(v2, 12, 12, 12)
    };

    TEST(plusOperator3) {
        mth::Vector3f v = mth::Vector3i(4, 8, 6) + mth::Vector3i(8, 4, 6);
        
        RET3(v, 12, 12, 12)
    };

    TEST(minusOperator) {
        mth::Vector3f v = mth::Vector3i(4, 8, 6) - mth::Vector3i(8, 4, 6);
        v -= mth::Vector3d(4., 8., 6.);
        
        RET3(v, -8, -4, -6)
    };

    TEST(comparison) {
        mth::Vector3i v {4, 8, 6};
        mth::Vector3f v2{4, 8, 6};
        mth::Vector3f v3{8, 4, 6};
        mth::Vector3i v4{v == v2, v != v3};
        
        RET3(v4, 1, 1, 0)
    };

    TEST(colinear) {
        mth::Vector3i v {0, 8, 0};
        mth::Vector3f v2{4, 0, 0};
        mth::Vector3f v3{0, 0, 0};
        mth::Vector3i v4{v3 || v2, v || v3};
        
        RET3(v4, 0, 0, 0)
    };

    TEST(colinear2) {
        mth::Vector3f v2{4, 0, 6};
        mth::Vector3f v3{3, 0, 6};
        mth::Vector3i v {0, 8, 6};
        mth::Vector3i v4{v3 || v2, v || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(colinear3) {
        mth::Vector3i v {6, 8, 6};
        mth::Vector3f v2{3, 4, 6};
        mth::Vector3f v3{3, 5, 6};
        mth::Vector3i v4{v || v2, v3 || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(colinear4) {
        mth::Vector3i v {6, 8, 6};
        mth::Vector3f v2{3, 4, 6};
        mth::Vector3f v3{3, 5, 6};
        mth::Vector3i v4{v2 || v, v3 || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(normalize) {
        mth::Vector3f v{3, 4};
        mth::Vector3f v2{0.2, 0};

        mth::Vector3i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 0, 0, 0)
    };

    TEST(normalize2) {
        mth::Vector3f v{1, 1};
        mth::Vector3f v2{0, 1};

        mth::Vector3i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 0, 1, 0)
    };

    TEST(normalize3) {
        mth::Vector3f v{3, 5};
        mth::Vector3f v2{4, 2};
        v.normalize(); v2.normalize();
        mth::Vector3i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 1, 1, 0)
    };

    TEST(dump) {
        mth::Vector3f v{3, 5};
        mth::Vector3f v2{4, 2};
        
        std::cout << v << v2 << std::endl;

        return true;
    };

    CHECK(reverse)
    CHECK(reverse2)
    CHECK(multiplication)
    CHECK(scalarMultiplication)
    CHECK(scalarMultiplication2)
    CHECK(scalarMultiplication3)
    CHECK(scalarMultiplication4)
    CHECK(scalarDiv)
    CHECK(scalarDiv2)
    CHECK(plusOperator)
    CHECK(plusOperator2)
    CHECK(plusOperator3)
    CHECK(minusOperator)
    CHECK(comparison)
    CHECK(colinear)
    CHECK(colinear2)
    CHECK(colinear3)
    CHECK(colinear4)
    CHECK(normalize)
    CHECK(normalize2)
    CHECK(normalize3)
    CHECK(dump)
}

void run() {
    TEST_ENTITY(VECTOR_3)
    CHECK_GROUP(ConstructibleTests)
    CHECK_GROUP(AssigmentTests)
    CHECK_GROUP(SetterTests)
    CHECK_GROUP(Swizzling)
    CHECK_GROUP(Operators)
}
} // Vector3Test

namespace Vector4Test {
namespace mth = mathon;

void ConstructibleTests() {
    TEST(defaultConstruct) {
        mth::Vector4i vec;
        RET4(vec, int(), int(), int(), int())
    };

    TEST(constructByValue) {
        mathon::Vector4i vec(4.0);
        RET4(vec, 4, 4, 4, 0)
    };

    TEST(constructByPair) {
        mathon::Vector4i vec(6, 8.0);
        RET4(vec, 6, 8, 0, 0)
    };

    TEST(constructByVector) {
        mathon::Vector4i vec(mth::Vector2f(6, 8));
        RET4(vec, 6, 8, 0, 0)
    };
    
    TEST(constructByVectorWithVal) {
        mth::Vector2f vec2f(6, 8);
        mathon::Vector4i vec(0, vec2f);
        RET4(vec, 0, 6, 8, 0)
    };

    TEST(constructByVectorWithVal2) {
        mth::Vector2f vec2f(6, 8);
        mathon::Vector4i vec(vec2f, 0);
        RET4(vec, 6, 8, 0, 0)
    };

    TEST(copyConstruct) {
        mathon::Vector4f vec{12, 21};
        mathon::Vector4d vec2 = vec;
        RET4(vec, vec2.x(), vec2.y(), vec2.z(), vec2.w())
    };

    TEST(moveConstruct) {
        mathon::Vector4f vec{12, 21};
        mathon::Vector4i vec2 = mathon::Vector3d(vec);
        RET4(vec, vec2.x(), vec2.y(), vec2.z(), vec2.w())
    };

    CHECK(defaultConstruct)
    CHECK(constructByValue)
    CHECK(constructByPair)
    CHECK(constructByVector)
    CHECK(constructByVectorWithVal)
    CHECK(constructByVectorWithVal2)
    CHECK(copyConstruct)
    CHECK(moveConstruct)
}

void AssigmentTests() {
    TEST(Vec4CopyAssigment) {
        mth::Vector4d vec{3.0};
        mth::Vector4f vec2{0, 6, 8};
        vec2 = vec;
        RET4(vec2, 3.0, 3.0, 3.0, 0.0)
    };

    TEST(Vec4MoveAssigment) {
        mth::Vector4f vec2{0, 6, 8};
        vec2 = mth::Vector4d{3.0};
        RET4(vec2, 3.0, 3.0, 3.0, 0.0)
    };

    TEST(Vec4SelfAssigment) {
        mth::Vector4f vec2{0, 6, 8};
        vec2 = vec2;
        RET4(vec2, 0.0, 6.0, 8.0, 0.0)
    };

    TEST(Vec3CopyAssigment) {
        mth::Vector3d vec{3.0};
        mth::Vector4f vec2{0, 6, 8};
        vec2 = vec;
        RET4(vec2, 3.0, 3.0, 3.0, 0.0)
    };

    TEST(Vec3MoveAssigment) {
        mth::Vector4f vec2{0, 6, 8};
        vec2 = mth::Vector3d{3.0};
        RET4(vec2, 3.0, 3.0, 3.0, 0.0)
    };

    TEST(Vec2CopyAssigment) {
        mth::Vector2d vec{3.0};
        mth::Vector4f vec2{0, 6, 8};
        vec2 = vec;
        RET4(vec2, 3.0, 3.0, 0.0, 0.0)
    };

    TEST(Vec2MoveAssigment) {
        mth::Vector4f vec2{0, 6, 8};
        vec2 = mth::Vector2d{3.0};
        RET4(vec2, 3.0, 3.0, 0.0, 0.0)
    };

    CHECK(Vec4CopyAssigment)
    CHECK(Vec4MoveAssigment)
    CHECK(Vec4SelfAssigment)
    CHECK(Vec3CopyAssigment)
    CHECK(Vec3MoveAssigment)
    CHECK(Vec2CopyAssigment)
    CHECK(Vec2MoveAssigment)
}

void SetterTests() {
    TEST(SimpleSet) {
        mth::Vector4f v(92, 112);
        v.z(v.x() + v.y());
        v.x(234);
        v.y(654);
        RET3(v, 234, 654, 204)
    };

    TEST(DoubleSets) {
        mth::Vector4f v(92, 112);
        mth::Vector2f v2(92, 112);

        v.yz(v2);
        RET3(v, 92, 92, 112)
    };

    TEST(TripleSets) {
        mth::Vector4f v(92, 112);
        mth::Vector2f v2(92, 112);

        v.xyz(234, v2);
        RET3(v, 234, 92, 112)
    };
    // copy and move sets tested in AssigmentTests well

    CHECK(SimpleSet)
    CHECK(DoubleSets)
    CHECK(TripleSets)
}

void Swizzling() {
    TEST(SimpleGet) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.z(), vec.x(), vec.y());
        RET3(vec2, 3, 1, 2)
    };

    TEST(xy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.z(), vec.xy());
        RET3(vec2, 3, 1, 2)
    };

    TEST(xz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.z(), vec.xz());
        RET3(vec2, 3, 1, 3)
    };

    TEST(yx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yx(), vec.x());
        RET3(vec2, 2, 1, 1)
    };

    TEST(yz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yz(), vec.x());
        RET3(vec2, 2, 3, 1)
    };

    TEST(zx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.z(), vec.zx());
        RET3(vec2, 3, 3, 1)
    };

    TEST(zy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zy(), vec.x());
        RET3(vec2, 3, 2, 1)
    };

    TEST(xx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xx(), vec.x());
        RET3(vec2, 1, 1, 1)
    };

    TEST(yy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.y(), vec.yy());
        RET3(vec2, 2, 2, 2)
    };

    TEST(zz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.z(), vec.zz());
        RET3(vec2, 3, 3, 3)
    };

    TEST(xyz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xyz());
        RET3(vec2, 1, 2, 3)
    };

    TEST(xzy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xzy());
        RET3(vec2, 1, 3, 2)
    };

    TEST(yxz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yxz());
        RET3(vec2, 2, 1, 3)
    };

    TEST(yzx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yzx());
        RET3(vec2, 2, 3, 1)
    };

    TEST(zxy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zxy());
        RET3(vec2, 3, 1, 2)
    };

    TEST(zyx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zyx());
        RET3(vec2, 3, 2, 1)
    };

    TEST(xxy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xxy());
        RET3(vec2, 1, 1, 2)
    };

    TEST(xxz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xxz());
        RET3(vec2, 1, 1, 3)
    };    
    
    TEST(yxx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yxx());
        RET3(vec2, 2, 1, 1)
    };

    TEST(zxx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zxx());
        RET3(vec2, 3, 1, 1)
    };

    TEST(xyx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xyx());
        RET3(vec2, 1, 2, 1)
    };

    TEST(xzx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xzx());
        RET3(vec2, 1, 3, 1)
    };

    TEST(yyx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yyx());
        RET3(vec2, 2, 2, 1)
    };

    TEST(yyz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yyz());
        RET3(vec2, 2, 2, 3)
    };

    TEST(xyy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xyy());
        RET3(vec2, 1, 2, 2)
    };

    TEST(zyy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zyy());
        RET3(vec2, 3, 2, 2)
    };

    TEST(yxy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yxy());
        RET3(vec2, 2, 1, 2)
    };

    TEST(yzy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yzy());
        RET3(vec2, 2, 3, 2)
    };

    TEST(zzx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zzx());
        RET3(vec2, 3, 3, 1)
    };

    TEST(zzy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zzy());
        RET3(vec2, 3, 3, 2)
    };

    TEST(xzz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xzz());
        RET3(vec2, 1, 3, 3)
    };

    TEST(yzz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yzz());
        RET3(vec2, 2, 3, 3)
    };

    TEST(zxz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zxz());
        RET3(vec2, 3, 1, 3)
    };

    TEST(zyz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zyz());
        RET3(vec2, 3, 2, 3)
    };

    TEST(xxx) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.xxx());
        RET3(vec2, 1, 1, 1)
    };

    TEST(yyy) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.yyy());
        RET3(vec2, 2, 2, 2)
    };
        
    TEST(zzz) {
        mth::Vector4d vec{1, 2, 3};
        mth::Vector4i vec2(vec.zzz());
        RET3(vec2, 3, 3, 3)
    };

    CHECK(SimpleGet)
    CHECK(xy)
    CHECK(xz)
    CHECK(yx)
    CHECK(yz)
    CHECK(zx)
    CHECK(zy)
    CHECK(xx)
    CHECK(yy)
    CHECK(zz)

    CHECK(xyz)
    CHECK(xzy)
    CHECK(yxz)
    CHECK(yzx)
    CHECK(zxy)
    CHECK(zyx)
    CHECK(xxy)
    CHECK(xxz)
    CHECK(yxx)
    CHECK(zxx)
    CHECK(xyx)
    CHECK(xzx)
    CHECK(yyx)
    CHECK(yyz)
    CHECK(xyy)
    CHECK(zyy)
    CHECK(yxy)
    CHECK(yzy)
    CHECK(zzx)
    CHECK(zzy)
    CHECK(xzz)
    CHECK(yzz)
    CHECK(zxz)
    CHECK(zyz)
    CHECK(xxx)
    CHECK(yyy)
    CHECK(zzz)
}

void Operators() {
    TEST(reverse) {
        mth::Vector4f v{5, -2, 6};
        v = -v;
        RET3(v, -5, 2, -6)
    };

    TEST(reverse2) {
        mth::Vector4f v{5, -2, 6};
        ~v;
        RET3(v, -5, 2, -6)
    };

    TEST(multiplication) {
        mth::Vector4i v{4, 8, 2};
        mth::Vector4f v2{8.0, 4.0f, 2};

        return v * v2 == 68;
    };

    TEST(scalarMultiplication) {
        mth::Vector4i v{4, 8, 6};
        mth::Vector4f v2 = v * 10;
        
        RET3(v2, 40, 80, 60)
    };


    TEST(scalarMultiplication2) {
        double i = 10.0;
        mth::Vector4i v{4, 8, 6};
        mth::Vector4f v2 = v * i;
        
        RET3(v2, 40, 80, 60)
    };

    TEST(scalarMultiplication3) {
        mth::Vector4i v{4, 8, 6};
        mth::Vector4f v2 = 10 * v;
        
        RET3(v2, 40, 80, 60)
    };
    
    TEST(scalarMultiplication4) {
        mth::Vector4i v{4, 8, 6};
        v *= 10;
        
        RET3(v, 40, 80, 60)
    };

    TEST(scalarDiv) {
        mth::Vector4i v{40, 80, 60};
        mth::Vector4f v2 = v / 10;
        
        RET3(v2, 4, 8, 6)
    };
    
    TEST(scalarDiv2) {
        mth::Vector4i v{40, 80, 60};
        v /= 10;
        
        RET3(v, 4, 8, 6)
    };

    TEST(plusOperator) {
        mth::Vector4i v{4, 8, 6};
        mth::Vector4f v2 = v + mth::Vector4d(8, 4, 6);
        v2 += v;

        RET3(v2, 16, 20, 18)
    };

    TEST(plusOperator2) {
        mth::Vector4i v{4, 8, 6};
        mth::Vector4f v2 = mth::Vector4f(8, 4, 6) + v;
        
        RET3(v2, 12, 12, 12)
    };

    TEST(plusOperator3) {
        mth::Vector4f v = mth::Vector4i(4, 8, 6) + mth::Vector4i(8, 4, 6);
        
        RET3(v, 12, 12, 12)
    };

    TEST(minusOperator) {
        mth::Vector4f v = mth::Vector4i(4, 8, 6) - mth::Vector4i(8, 4, 6);
        v -= mth::Vector4d(4., 8., 6.);
        
        RET3(v, -8, -4, -6)
    };

    TEST(comparison) {
        mth::Vector4i v {4, 8, 6};
        mth::Vector4f v2{4, 8, 6};
        mth::Vector4f v3{8, 4, 6};
        mth::Vector4i v4{v == v2, v != v3};
        
        RET3(v4, 1, 1, 0)
    };

    TEST(colinear) {
        mth::Vector4i v {0, 8, 0};
        mth::Vector4f v2{4, 0, 0};
        mth::Vector4f v3{0, 0, 0};
        mth::Vector4i v4{v3 || v2, v || v3};
        
        RET3(v4, 0, 0, 0)
    };

    TEST(colinear2) {
        mth::Vector4f v2{4, 0, 6};
        mth::Vector4f v3{3, 0, 6};
        mth::Vector4i v {0, 8, 6};
        mth::Vector4i v4{v3 || v2, v || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(colinear3) {
        mth::Vector4i v {6, 8, 6};
        mth::Vector4f v2{3, 4, 6};
        mth::Vector4f v3{3, 5, 6};
        mth::Vector4i v4{v || v2, v3 || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(colinear4) {
        mth::Vector4i v {6, 8, 6};
        mth::Vector4f v2{3, 4, 6};
        mth::Vector4f v3{3, 5, 6};
        mth::Vector4i v4{v2 || v, v3 || v2};
        
        RET3(v4, 1, 0, 0)
    };

    TEST(normalize) {
        mth::Vector4f v{3, 4};
        mth::Vector4f v2{0.2, 0};

        mth::Vector4i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 0, 0, 0)
    };

    TEST(normalize2) {
        mth::Vector4f v{1, 1};
        mth::Vector4f v2{0, 1};

        mth::Vector4i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 0, 1, 0)
    };

    TEST(normalize3) {
        mth::Vector4f v{3, 5};
        mth::Vector4f v2{4, 2};
        v.normalize(); v2.normalize();
        mth::Vector4i v4{v.is_normalize(), v2.is_normalize()};
        
        RET3(v4, 1, 1, 0)
    };

    TEST(dump) {
        mth::Vector4f v{3, 5};
        mth::Vector4f v2{4, 2};
        
        std::cout << v << v2 << std::endl;

        return true;
    };

    CHECK(reverse)
    CHECK(reverse2)
    CHECK(multiplication)
    CHECK(scalarMultiplication)
    CHECK(scalarMultiplication2)
    CHECK(scalarMultiplication3)
    CHECK(scalarMultiplication4)
    CHECK(scalarDiv)
    CHECK(scalarDiv2)
    CHECK(plusOperator)
    CHECK(plusOperator2)
    CHECK(plusOperator3)
    CHECK(minusOperator)
    CHECK(comparison)
    CHECK(colinear)
    CHECK(colinear2)
    CHECK(colinear3)
    CHECK(colinear4)
    CHECK(normalize)
    CHECK(normalize2)
    CHECK(normalize3)
    CHECK(dump)
}

void run() {
    TEST_ENTITY(VECTOR_4)
    CHECK_GROUP(ConstructibleTests)
    CHECK_GROUP(AssigmentTests)
    CHECK_GROUP(SetterTests)
    CHECK_GROUP(Swizzling)
    CHECK_GROUP(Operators)
}
}; // Vector4Test