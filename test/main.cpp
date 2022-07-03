import Math.Vector4;
import Math.Vector3;
import Math.Vector2;
import Math.Matrix4;
import Math.Quaternion;

#include "VectorTest.hpp"
#include "MatrixTest.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/ext/quaternion_trigonometric.hpp>
#include <glm/gtx/string_cast.hpp>

int main() {
    Vector2Test::run();
    Vector3Test::run();
    Vector4Test::run();

    Matrix2Test::run();
    Matrix3Test::run();
    Matrix4Test::run();

    get_statistic();

    glm::vec3 pos(10, 12, 18);
    auto rot = glm::angleAxis(4.f, glm::vec3{1, 1, 1});
    glm::vec3 sca(2, 6, 8);

    auto mat = glm::mat4(1.0f);
    mat = glm::translate(mat, pos);

    mat *= glm::toMat4(rot);

    mat = glm::scale(mat, sca);

    // std::cout << glm::to_string(glm::toMat4(rot)) << std::endl;
    // std::cout << glm::to_string(rot) << std::endl;
    std::cout << glm::to_string(mat) << std::endl;

    // std::cout << mat[0][1] << std::endl;
}