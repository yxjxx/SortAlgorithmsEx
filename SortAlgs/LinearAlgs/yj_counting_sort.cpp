//
// Created by Jing Yang on 2017/04/24Monday.
//

#include "yj_counting_sort.h"
#include "../../YJ_Constants.h"

/*
 *  @brief 计数排序
 *  @algorithm 对每一个输入元素elem，确定出小于elem的元素的个数n，然后将元素elem放到结果数组的第n+1个位置(数组从0开始存储，n+1个位置即A[n])即可
 *
 *  @param myArray[] 待排序数组，先备份，然后用作结果接收数组
 *  @param len  myArray[]待排序数组的长度
 *  @param countArray[] 计数数组，数组长度为NUM_RANGE,计数排序操作的核心数组。先后存储等于其下标的元素的个数和小于等于其下标的元素的个数
 *  @param backupArray[] 因为myArray[]要用作结果接收数组，所以先把要排序的数组备份到backupArray[]中
 *
 *  @analysis 时间复杂度O(len+NUM_RANGE),所以在实践中，当NUM_RANGE=O(len)时，常使用计数排序，运行时间在O(n)
 *            计数排序是稳定的，常用做基数排序的一个子过程
 */
void yj_counting_sort (int myArr[], int len){
    int countArr[NUM_RANGE];
    int backupArr[len];

    for (int i = 0; i < len; ++i) {//遍历 myArr，拷贝一份到 backupArr
        backupArr[i] = myArr[i];
    }
    for (int i = 0; i < NUM_RANGE; ++i) {//遍历 countArr 初始化
        countArr[i] = 0;
    }
    for (int i = 0; i < len; ++i) {//遍历 backupArr，如果待排序数组中出现的元素i,则将countArr[i]加1，循环结束之后countArr[i]包含等于i的个数
        int subIndex = backupArr[i];
        countArr[subIndex]++;
    }
    for (int i = 1; i < NUM_RANGE; ++i) {//遍历 countArr，完成后 countArray[i]包含小于等于i的元素的个数
        countArr[i] += countArr[i-1];
    }
    for (int i = len-1; i >= 0; i--) { //反向遍历 backupArr, 对 backupArr 中的每一个元素, countArr[elem] 包含小于等于 elem 的元素的个数
        int elem = backupArr[i]; //backupArr 中的每一个元素
        int subIndex = countArr[elem] - 1;//小于等于 elem 的元素的个数为 countArr[elem] 则可以把 elem 放到 index 为 （countArr[elem] - 1）的位置
        myArr[subIndex] = elem;
        countArr[elem]--;//相等元素处理
    } //反向遍历 backupArr 可以保持稳定
}