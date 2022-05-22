include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Vector2  Vector2t.cppm )
precompile ( Math.Vector2f Vector2f.cppm )
precompile ( Math.Vector2d Vector2d.cppm )
precompile ( Math.Vector2i Vector2i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)