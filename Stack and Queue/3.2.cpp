// P71 3.2

#include<stdio.h>
#include<stdlib.h>

bool Judge(char a[]){
    int j = 0;
    int k = 0;
    int i=0;
    while (a[i] != '\0') {
        if (a[i] == 'I') {
            j=j+1;
        }
        else if(a[i] == 'O') {
            k=k+1;
        }
        if (k > j) {
            return false;
        }
        i++;
    }
    if(j == k){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    char a[6] = {'I','O','I','I','O','O'};
    bool res = Judge(a);
    printf("%d\n",res);
}
