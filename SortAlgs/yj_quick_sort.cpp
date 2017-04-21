//
// Created by Jing Yang on 2017/04/21Friday.
//

#include <panel.h>
#include "yj_quick_sort.h"
/*
 *  @brief 快速排序
 *
 *  @analysis 时间复杂度：最好O(n*logn),越接近无序，效率越高
 *                      最差O(n^2),越接近有序，效率越低
 *
 *                      平均时间复杂度O(n*logn),而且取到平均时间复杂度的概率很大
 *
 *            空间复杂度：O(logn),因为快排是递归进行的，需要栈的辅助
 *                      快速排序空间复杂度只是在通常情况下才为O(log2n)，如果是最坏情况的话，很显然就要O(n)的空间了。
 *                      当然，可以通过随机化选择pivot来将空间复杂度降低到O(log2n)。
 *
 *            稳定性：快速排序是不稳定的，比如序列为 5 3 3 4 3 8 9 10 11，现在中枢元素5和3(第5个元素，
 *            下标从1开始计)交换就会把元素3的稳定性打乱，所以快速排序是一个不稳定的排序算法，不稳定发生在中枢元素和a[j] 交换的时刻。
 *
 */

void yj_quick_sort (int myArr[], int begin, int end){
    if(begin >= end){
        return;
    } //递归结束调节

    int pivot = myArr[begin];
    int left = begin;
    int right = end;

    while(left < right){
        while (left < right && myArr[right] > pivot) {
            right--;
        }
        if (left < right) { //加 if 判断的原因是，可能 pivot 已经是最小的了。上面的 while 已经把 right 减为和 left 相等了
            myArr[left] = myArr[right];
            left++;
        }

        while(left < right && myArr[left] < pivot) {
            left++;
        }
        if (left < right) {
            myArr[right] = myArr[left];
            right--;
        }
    }
    myArr[left] = pivot;

    yj_quick_sort(myArr, begin, left - 1);
    yj_quick_sort(myArr, left + 1, end);

}