include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Impl.Vector2 Vector2.cppm )
precompile ( Math.Impl.Vector3 Vector3.cppm )
precompile ( Math.Impl.Vector4 Vector4.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)