//
// Created by Jing Yang on 2017/04/21Friday.
//

#include "yj_heap_sort.h"
#include "../YJ_HelperMethod.h"

void max_heapify_bin_tree(int myArr[], int len, int root) {
    int leftSon = 2*root;
    int rightSon = 2*root + 1;
    int largest = root;//二叉树根节和其左右节点中最大者的下标

    if (leftSon <= len && myArr[leftSon] > myArr[largest]) {
        largest = leftSon;
    }
    if (rightSon <= len && myArr[rightSon] > myArr[largest]) {
        largest = rightSon;
    }

    if (largest != root) {
        swap_element_in_array(myArr, largest, root);
        max_heapify_bin_tree(myArr, len, largest);
    }

}

void build_max_heap(int myArr[], int len) {
    for (int node = len/2; node >= 1 ; --node) {
        max_heapify_bin_tree(myArr, len, node);
    }
}


/*
 *  @brief 堆排序，选择排序的一种
 *
 *          堆是一种数据结构，可以把堆看成是一棵完全二叉树，这棵二叉树满足：任何一个非叶节点的值都不小于其左右孩子节点的值
 *          不断将序列调整为堆，每一趟将二叉树的根节点选出放入有序部分。
 *
 *          注意：堆排序中完全二叉树是从数组下标为1的地方开始存储的，因为只有这样才满足左孩子为2*i，右孩子为2*i+1。
 *               但是由于本文件其它算法都使用下标为0的地方开始存储，所以打印出的结果第一个元素不参与排序，或者调用print_array2不打印第一个元素
 *
 *               不完美的解决方案：把myArray[0..len-1]赋值给newArray[1..len],打印newArray[1..len]
 *
 *  @analysis  时间复杂度平均O(n*logn), 最坏情况下时间复杂度也是O(n*logn)
 *             空间复杂度O(1)，原地排序
 *
 *             使用场景：记录数很多，从中选出最大或最小的5个数之类
 */
void yj_heap_sort (int myArr[], int len){
    int newArr[len+1];
    for (int i = 0; i < len; ++i) {
        newArr[i+1] = myArr[i];
    }

    build_max_heap(newArr, len);//构建一个最大堆

    //不断从最大堆的 root 选择一个元素到数组最后，所以说堆排序是一种选择排序
    int array_len = len;
    for (int i = len; i >=2 ; i--) {
        swap_element_in_array(newArr, 1, i);
        array_len--;
        max_heapify_bin_tree(newArr, array_len, 1);
    }

    for (int i = 0; i < len; ++i) {
        myArr[i] = newArr[i+1];
    }
}

