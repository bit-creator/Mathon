include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Matrix4  Matrix4t.cppm )
precompile ( Math.Matrix4f Matrix4f.cppm )
precompile ( Math.Matrix4d Matrix4d.cppm )
precompile ( Math.Matrix4i Matrix4i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)