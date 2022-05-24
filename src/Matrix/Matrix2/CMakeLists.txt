include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Matrix2  Matrix2t.cppm )
precompile ( Math.Matrix2f Matrix2f.cppm )
precompile ( Math.Matrix2d Matrix2d.cppm )
precompile ( Math.Matrix2i Matrix2i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)