import Math.Vector4;
import Math.Vector3;
import Math.Vector2;
// import Math.Operators.Vector2;

#include "VectorTest.hpp"
#include "MatrixTest.hpp"

int main() {
    Vector2Test::run();
    Vector3Test::run();
    Vector4Test::run();

    Matrix2Test::run();
    Matrix3Test::run();
    Matrix4Test::run();

    get_statistic();
}