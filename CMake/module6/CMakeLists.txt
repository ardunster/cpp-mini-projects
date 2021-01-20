cmake_minimum_required(VERSION 3.0.0)

project(Calculator VERSION 1.0.0)

add_subdirectory(maths)
add_subdirectory(print)

add_executable(calculator
main.cpp)

target_link_libraries(calculator
maths
print)

# set(A "12345" CACHE STRING "This sets variable A in persistent Cache")
# set(A Steve)

# message(${A})

# message($CACHE{A})

# message(${CMAKE_VERSION})
# message("In module directory: ${CMAKE_PROJECT_NAME}")
# message(${PROJECT_NAME})