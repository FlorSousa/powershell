cmake_minimum_required(VERSION 3.13)    # versão do CMake
project(rinha_powershell
  VERSION
    1.0
  DESCRIPTION
    "um projeto bacana"
  LANGUAGES
    CXX
)
set(CMAKE_CXX_STANDARD 20)              # versão da linguagem C++

if(G++)
    # warning options (https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
    add_compile_option(-Wall -Wexta -Wpedantic) 
endif()

include_directories(${CMAKE_SOURCE_DIR}/libs ${CMAKE_SOURCE_DIR}/includes)
set(SOURCE_FILES src/writer.cpp src/classes/stack.cpp)

add_executable(powershell src/main.cpp ${SOURCE_FILES})

# testes
enable_testing()
add_executable(testador tests/testador.cpp ${SOURCE_FILES})
add_test(Tester testador)