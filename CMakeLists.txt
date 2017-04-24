cmake_minimum_required(VERSION 3.7)
project(SortAlgorithmsEx)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp YJ_Structs.h YJ_Constants.h YJ_HelperMethod.h YJ_HelperMethod.cpp SortAlgs/yj_direct_insertion_sort.h SortAlgs/yj_direct_insertion_sort.cpp SortAlgs/yj_bin_search.cpp SortAlgs/yj_bin_search.h SortAlgs/yj_bin_insertion_sort.cpp SortAlgs/yj_bin_insertion_sort.h SortAlgs/yj_shell_sort.cpp SortAlgs/yj_shell_sort.h SortAlgs/yj_bubble_sort.cpp SortAlgs/yj_bubble_sort.h SortAlgs/yj_quick_sort.cpp SortAlgs/yj_quick_sort.h SortAlgs/yj_simple_select_sort.cpp SortAlgs/yj_simple_select_sort.h SortAlgs/yj_heap_sort.cpp SortAlgs/yj_heap_sort.h SortAlgs/yj_merge_sort.cpp SortAlgs/yj_merge_sort.h SortAlgs/LinearAlgs/yj_counting_sort.cpp SortAlgs/LinearAlgs/yj_counting_sort.h)
add_executable(SortAlgorithmsEx ${SOURCE_FILES})