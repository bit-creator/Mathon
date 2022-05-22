# function(precompile module source)
# add_custom_target(${module}
#   COMMAND
#     ${CMAKE_CXX_COMPILER}
#     -std=c++${CMAKE_CXX_STANDARD}
#     -stdlib=libstdc++
#     -fprebuilt-module-path=${CMAKE_CURRENT_SOURCE_DIR}/precompiled
#     -c --precompile ${CMAKE_CURRENT_SOURCE_DIR}/${source}
#     -o ${PRECOMPILED_MODULES_DIR}/${module}.pcm 
# )
# set(sources ${sources} ${source} PARENT_SCOPE)
# endfunction(precompile)


function(precompile module source)
add_custom_target(${module})
add_custom_command(TARGET ${module}
  COMMAND
    ${CMAKE_CXX_COMPILER}
    -std=c++20
    -stdlib=libc++
    -fmodules
    -fprebuilt-module-path=${PRECOMPILED_MODULES_DIR}
    -fPIC
    -Wall
    -Wextra
    -fmath-errno
    -O3
    -march=native
    -ffast-math
    -fcxx-exceptions
    -c --precompile
    ${CMAKE_CURRENT_SOURCE_DIR}/${source}
    -o ${PRECOMPILED_MODULES_DIR}/${module}.pcm 
)
# set_property(TARGET ${module} PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
set(sources ${sources} ${CMAKE_CURRENT_SOURCE_DIR}/${source} PARENT_SCOPE)
set(dependencies ${module} ${dependencies} PARENT_SCOPE)
endfunction(precompile)