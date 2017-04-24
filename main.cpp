#include <iostream>
#include "YJ_Structs.h"
#include "YJ_Constants.h"
#include "YJ_HelperMethod.h"
#include "SortAlgs/yj_direct_insertion_sort.h"
#include "SortAlgs/yj_bin_search.h"
#include "SortAlgs/yj_bin_insertion_sort.h"
#include "SortAlgs/yj_shell_sort.h"
#include "SortAlgs/yj_bubble_sort.h"
#include "SortAlgs/yj_quick_sort.h"
#include "SortAlgs/yj_simple_select_sort.h"
#include "SortAlgs/yj_heap_sort.h"
#include "SortAlgs/yj_merge_sort.h"
#include "SortAlgs/LinearAlgs/yj_counting_sort.h"
#include "SortAlgs/LinearAlgs/yj_radix_sort.h"

using namespace std;

int main() {
    int len = SORT_NUM;
    int myArr[len];
    create_array_with_random_numbers(myArr, len);
    cout << "origin array: ";
    print_array(myArr, len);

    //直接插入排序
    //yj_direct_insertion_sort(myArr, len);

    //二分查找法
//    yj_direct_insertion_sort2(myArr, len);
//    int key = myArr[7];
//    cout << key << endl;
//    cout << yj_origin_bin_search(myArr, len, key) << endl;//out 7

    //二分插入排序
    //yj_bin_insertion_sort(myArr, len);

    //希尔排序
//    int stepArr[] = {5, 3, 2, 1};
//    yj_shell_sort(myArr, len, stepArr, 4);

    //冒泡排序
//    yj_bubble_sort2(myArr, len);

    //快速排序
//    yj_quick_sort(myArr, 0, len-1);

    //简单选择排序
//    yj_simple_select_sort(myArr, len);


    //堆排序
//    yj_heap_sort(myArr, len);

    //2路归并排序
//    yj_merge_sort(myArr, 0, len-1);

/*
 *  比较排序总结：
 *     比较排序即需要比较待排序的序列中元素的相互大小来确定先后关系，他们的时间复杂度下限是O(n*logn)
 *
 *     常见的排序算法中还有三种线性时间复杂度的排序算法，时间复杂度可以到O(n)。分别为：计数排序，基数排序，桶排序
 */

    // 计数排序
//    yj_counting_sort(myArr, len);

    //基数radix（每一位）排序
    yj_radix_sort(myArr, len);

    cout << "sorted array: ";
    print_array(myArr, len);


    return 0;
}