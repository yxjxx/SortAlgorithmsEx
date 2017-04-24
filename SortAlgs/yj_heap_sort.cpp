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

