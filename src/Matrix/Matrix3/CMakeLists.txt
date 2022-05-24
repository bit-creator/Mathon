include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Matrix3  Matrix3t.cppm )
precompile ( Math.Matrix3f Matrix3f.cppm )
precompile ( Math.Matrix3d Matrix3d.cppm )
precompile ( Math.Matrix3i Matrix3i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)