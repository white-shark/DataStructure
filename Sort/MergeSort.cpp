//
//  MergeSort.cpp
//  test
//
//  Created by WhiteShark on 2020/12/8.
//  Copyright © 2020 WhiteShark. All rights reserved.
//
//归并排序的递归实现

#include<stdio.h>
#include<stdlib.h>

void Merge(int r[],int r1[],int s,int m,int t){
    int i = s;
    int j = m+1;
    int k = s;
    while (i <= m && j <= t) {
        if (r[i]<=r[j]) {
            r1[k++] = r[i++];
        }
        else{
            r1[k++] = r[j++];
        }
    }
    if (i < m) {
        while (i <= m) {
            r1[k++] = r[i++];
        }
    }
    else{
        while (j <= t) {
            r1[k++] = r[j++];
        }
    }
}
void MergeSort(int r[],int r1[],int s,int t){
    int m;
    if (s == t) {
        r1[s] = r[s];
    }
    else{
        m = (s+t)/2;
        MergeSort(r,r1,s,m);
        MergeSort(r,r1,m+1,t);
        Merge(r1, r, s, m, t);
    }
}

