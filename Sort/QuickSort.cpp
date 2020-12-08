//
//  QuickSort.cpp
//  test
//
//  Created by WhiteShark on 2020/12/7.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

int Partition(int a[],int low,int high){
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot) {
            ++low;
        }
        a[high] = a[low];
        
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[],int low,int high){
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}
