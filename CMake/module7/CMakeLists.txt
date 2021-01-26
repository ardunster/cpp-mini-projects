cmake_minimum_required(VERSION 3.0.0)

project(Calculator VERSION 1.0.0)

add_subdirectory(maths)
add_subdirectory(print)

add_executable(calculator
main.cpp)

target_link_libraries(calculator
maths
print)

# message(${CMAKE_INSTALL_PREFIX})
