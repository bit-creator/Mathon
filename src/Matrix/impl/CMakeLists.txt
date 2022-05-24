include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Impl.Matrix2 Matrix2.cppm )
precompile ( Math.Impl.Matrix3 Matrix3.cppm )
precompile ( Math.Impl.Matrix4 Matrix4.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)