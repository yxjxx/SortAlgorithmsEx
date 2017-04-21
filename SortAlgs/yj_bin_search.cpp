//
// Created by Jing Yang on 2017/04/20Thursday.
//

#include "yj_bin_search.h"


/*
 *  @brief 原始的二分查找法，查找成功返回元素所在位置，查找失败返回-1
 *
 *  @param myArr 已经排好序的数组
 *  @param len   数组的长度
 *  @param key   待查找的关键字
 */
int yj_origin_bin_search(int myArr[], int len, int key) {
    int mid;
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (myArr[mid] == key) {
            return mid;
        } else if(myArr[mid] > key) {//只需要继续检查左半部分
            right = mid - 1;
        } else { // myArr[mid] < key 只需要继续检查右半部分
            left = mid + 1;
        }
    }
    return -1;
}
/*
 *  @brief 为折半插入排序算法设计的二分查找算法，查找成功返回元素所在位置，查找失败返回high指针位置，以便在此位置之后插入
 */
int yj_bin_search_for_bin_insertion_sort(int myArr[], int low, int high, int key) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if(myArr[mid] == key) {
            return mid;
        } else if(myArr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high+1;
}