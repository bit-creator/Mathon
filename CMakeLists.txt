cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_COMPILER clang++-14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(BUILD_DIR ${CMAKE_SOURCE_DIR}/.build)
set(PRECOMPILED_MODULES_DIR ${CMAKE_SOURCE_DIR}/precompiled)
set(3RDPARTY_DIR ${CMAKE_SOURCE_DIR}/3rdparty)
set(CMAKE_SCRIPTS_DIR ${CMAKE_SOURCE_DIR}/cmakeScripts)

project(mathon VERSION 1.0.0)

add_subdirectory(src)

set_target_properties(mathon PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(mathon PROPERTIES SOVERSION 1)
set_target_properties(mathon PROPERTIES PUBLIC_HEADER ${dependencies})
include(GNUInstallDirs)

install (TARGETS mathon
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(mathon.pc.in mathon.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/mathon.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
