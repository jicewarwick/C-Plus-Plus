find_library(GTest REQUIRED)


add_library(Sort INTERFACE)
target_sources(Sort INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sort.h)

add_executable(Test test.cpp)
target_link_libraries(Test gtest Sort)
