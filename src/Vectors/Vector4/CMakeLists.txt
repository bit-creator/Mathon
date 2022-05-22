include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Vector4  Vector4t.cppm )
precompile ( Math.Vector4f Vector4f.cppm )
precompile ( Math.Vector4d Vector4d.cppm )
precompile ( Math.Vector4i Vector4i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)