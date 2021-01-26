add_library(maths
src/addition.cpp
src/division.cpp)

target_include_directories(maths PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# target_include_directories(maths PRIVATE 
# $<INSTALL_INTERFACE:include>
# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>)


install(FILES
${CMAKE_CURRENT_SOURCE_DIR}/include/maths/addition.hpp
${CMAKE_CURRENT_SOURCE_DIR}/include/maths/division.hpp
DESTINATION
${CMAKE_CURRENT_SOURCE_DIR}/../build/include/maths)

install(TARGETS maths EXPORT exportmaths DESTINATION /build/lib/maths)

install(EXPORT exportmaths FILE maths-config.cmake DESTINATION /build/lib/maths)

message("Cmake current source: ${CMAKE_CURRENT_SOURCE_DIR}")