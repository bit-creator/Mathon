include(${CMAKE_SCRIPTS_DIR}/precompile.cmake)

add_subdirectory(Vectors)

precompile ( Math.Impl.Utilites      Utilites.cppm        )
precompile ( Math.Impl.Operators     Operators.cppm       )
precompile ( Math.Impl.Signatures    Signatures.cppm      )
precompile ( Math.Impl.ShareModifier ShareModifier.cppm   )

add_compile_options(
    -std=c++${CMAKE_CXX_STANDARD}
    -stdlib=libc++
    -fmodules
    -fPIC
    -Wall
    -Wextra
    -fmath-errno
    -O3
    -march=native
    -ffast-math
    -fcxx-exceptions 
    -fprebuilt-module-path=${PRECOMPILED_MODULES_DIR}
)

add_library( mathon SHARED
    ${sources}
)

set(dependencies ${dependencies} PARENT_SCOPE)

# now this doesnt work correct need build all dependencies manually
# add_dependencies(mathon ${dependencies})

target_link_libraries( mathon
    c++
)
