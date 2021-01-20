project(MathProject VERSION 1.0.0)

add_library(maths
src/addition.cpp
src/division.cpp)

target_include_directories(maths PUBLIC include)

# set(A "maths")

# message(${A})

# message($CACHE{A})

# message("In maths directory: ${CMAKE_PROJECT_NAME}")
# message(${PROJECT_NAME})