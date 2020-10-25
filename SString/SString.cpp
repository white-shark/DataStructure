#include<stdio.h>
#include<stdlib.h>

#define MaxLen 255

typedef struct {
    char ch[MaxLen];
    int length;
}SString;

//求子串
bool SubString(SString &Sub,SString S,int pos,int len){
    //子串范围越界
    if(pos+len-1 > S.length){
        return false;
    }
    for(int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1]=S.ch[i];
    }
    Sub.length = len;
    return true;
}

//比较操作。若S>T,返回>0；S=T，返回=0；S<T,返回<0
int StrCompare(SString S,SString T){
    for (int i=1; i<=S.length && i<=T.length; i++) {
        if (S.ch[i]!=T.ch[i]) {
            return S.ch[i]-T.ch[i];
        }
    }
    return S.length-T.length;
    
}

//定位操作，寻找子串第一次出现的位置
int Index(SString S,SString T){
    int i=1;
    int n=S.length;
    int m=T.length;
    SString sub;
    while (i<=n-m+1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T)!=0) {
            i++;
        }
        else{
            return i;
        }
    }
    return 0;
}

//朴素模式匹配算法，定位子串。
int Index_1(SString S,SString T){
    int k=1;
    int i=k;
    int j=1;
    while (i<=S.length && j<=T.length) {
        if (S.ch[i] == T.ch[i]) {
            ++i;
            ++j;
        }
        else{
            k++;
            i=k;
            j=1;
        }
    }
    if (j>T.length) {
        return k;
    }
    else{
        return 0;
    }
}


/*
 *KMP算法
 */
//KMP算法求子串的next数组
void get_next(SString T,int next[]){
    int i=1;
    int j=0;
    next[1]=0;
    while (i<T.length) {
        if(j==0 || T.ch[i]==T.ch[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

//KMP算法
int index_KMP(SString S,SString T){
    int i=1;
    int j=1;
    int next[T.length+1];
    get_next(T, next);
    while (i<S.length &&j<T.length) {
        if (j==0 || S.ch[i]==T.ch[i]) {
            ++i;
            ++j;
        }
        else{
            j=next[j];
        }
    }
    if (j>T.length) {
        return i-T.length;
    }
    else{
        return 0;
    }
    
}

