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

    cout << "sorted array: ";
    print_array(myArr, len);


    return 0;
}