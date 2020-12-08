//
//  HeapSort.cpp
//  test
//
//  Created by WhiteShark on 2020/12/8.
//  Copyright © 2020 WhiteShark. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

void Shift(int r[],int k,int m){
    int i = k;
    int j = 2*i;
    while (j <= m) {
        if (j < m && r[j] < r[j+1]) {
            j++;
        }
        if (r[i] > r[j]) {
            break;
        }
        else{
            int temp;
            temp = r[j];
            r[j] = r[i];
            r[i] = temp;
            i = j;
            j = i*2;
        }
    }
}

void HeapSort(int r[],int n){
    for (int i = n/2; i >= 1; i--) {
        Shift(r, i, n);
    }
    for (int i = 1; i < n; i++) {
        int temp;
        temp = r[n-i+1];
        r[n-i+1] = r[1];
        r[1] = temp;
        Shift(r, 1, n - i);
    }
}
