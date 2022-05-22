include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

precompile ( Math.Vector3  Vector3t.cppm )
precompile ( Math.Vector3f Vector3f.cppm )
precompile ( Math.Vector3d Vector3d.cppm )
precompile ( Math.Vector3i Vector3i.cppm )

set(sources ${sources} PARENT_SCOPE)
set(dependencies ${dependencies} PARENT_SCOPE)