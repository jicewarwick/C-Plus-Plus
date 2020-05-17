find_library(GTest REQUIRED)

add_library(BeadSort INTERFACE)
target_sources(BeadSort INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/bead_sort.h)

add_library(QuickSort INTERFACE)
target_sources(QuickSort INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/quick_sort.h)

add_executable(Test test.cpp)
target_link_libraries(Test gtest BeadSort QuickSort)
