add_library(print
src/print_result.cpp)

target_include_directories(print PUBLIC include)

install(FILES
${CMAKE_CURRENT_SOURCE_DIR}/include/print/print_result.hpp
DESTINATION
${CMAKE_CURRENT_SOURCE_DIR}/../build/include/print)

install(TARGETS print DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/lib/print)