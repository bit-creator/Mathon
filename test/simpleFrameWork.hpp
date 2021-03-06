#ifndef __SIMPLE_FRAME_WORK_HPP__
#define __SIMPLE_FRAME_WORK_HPP__

struct Stats {
    uint32_t            error;
    uint32_t            sucsess;
};
static Stats stats{0, 0};

#define SUCSESS(arg) ++stats.sucsess;
#define ERROR(arg)   std::cout << "       |ERROR|   " << #arg << std::endl; ++stats.error;

#define TEST_ENTITY(arg) std::cout << "TEST " << #arg << std::endl;
#define START_GROUP(arg) std::cout << "Run " << #arg << " tests" << std::endl;
#define END_GROUP(arg) std::cout << std::endl;

#define TEST(arg) auto arg = []() -> bool

#define RET(name, x_, y_) return name.x() == x_ && name.y() == y_;
#define RET3(name, x_, y_, z_) return name.x() == x_ && name.y() == y_ && name.z() == z_;
#define RET4(name, x_, y_, z_, w_) return name.x() == x_ && name.y() == y_ && name.z() == z_ && name.w() == w_;

#define RET_MAT2(name, right) return name._00() == right._00() \
                                  && name._01() == right._01() \
                                  && name._10() == right._10() \
                                  && name._11() == right._11();

#define RET_MAT3(name, right) return name._00() == right._00() \
                                  && name._01() == right._01() \
                                  && name._02() == right._02() \
                                  && name._10() == right._10() \
                                  && name._11() == right._11() \
                                  && name._12() == right._12() \
                                  && name._20() == right._20() \
                                  && name._21() == right._21() \
                                  && name._22() == right._22();


#define RET_MAT4(name, right) return name._00() == right._00() \
                                  && name._01() == right._01() \
                                  && name._02() == right._02() \
                                  && name._03() == right._03() \
                                  && name._10() == right._10() \
                                  && name._11() == right._11() \
                                  && name._12() == right._12() \
                                  && name._13() == right._13() \
                                  && name._20() == right._20() \
                                  && name._21() == right._21() \
                                  && name._22() == right._22() \
                                  && name._23() == right._23() \
                                  && name._30() == right._30() \
                                  && name._31() == right._31() \
                                  && name._32() == right._32() \
                                  && name._33() == right._33();

#define CHECK(arg) if(arg()) { SUCSESS(arg) } else { ERROR(arg) }
#define CHECK_GROUP(arg) START_GROUP(arg) arg(); END_GROUP(arg)

#define MSG(arg) std::cout << "|DEBUG_MASSAGE| " << #arg << " = " << arg << std::endl;

void get_statistic() {
    std::cout << "\n\n\tRESULTS" << std::endl
        << " passed: " << stats.sucsess << " \t(" << (stats.sucsess * 100) / (stats.sucsess + stats.error) << "%)" << std::endl
        << " failed: " << stats.error << " \t(" << (stats.error * 100) / (stats.sucsess + stats.error) << "%)" << std::endl;
}

#endif // __SIMPLE_FRAME_WORK_HPP__