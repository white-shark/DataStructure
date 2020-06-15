#include <stdio.h>
#include <stdlib.h>

void Reverse(int A[],int m,int n,int size){
		if(m>n ||n>size){
		return;
	}
	int mid=(m+n)/2;
	int max=m+n-1;
	for(int i=0;i<mid;i++){
		int temp=A[i];
		A[i]=A[max-i];
		A[max-i]=temp;
	}
	for(int j=0;j<n/2;j++){
		int temp=A[j];
		A[j]=A[n-1-j];
		A[n-1-j]=temp;
	}
	for(int k=0;k<m/2;k++){
		int temp=A[n+k];
		A[n+k]=A[n+m-1-k];
		A[n+m-1-k]=temp;
	}
}

void Reverse1(int A[],int m,int n,int size){
	if(m>n ||n>size){
		return;
	}
	int B[size];
	for(int k=0;k<size;k++){
		B[k]=A[k];
	}
	for(int i=0;i<n;i++){
		A[i]=B[m+i];
	}
	
	for(int j=0;j<m;j++){
		A[n+j]=B[j];
	}
	for(int i=0;i<size;i++){
		printf("%d",A[i]);
	}
	printf("\n");

	printf("\n");
} 


//½Ì²Ä´ð°¸ 
void Reverse2(int A[],int left,int right,int size){
		if(left>right ||right>size){
		return;
	}
	int mid=(left+right)/2;
	for(int i=0;i<=mid-left;i++){
		int temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
	
}


int main(){
	int A[7]={1,2,3,6,7,8,9};
	int m=3;
	int n=4;
	int size=7;
	Reverse2(A,0,m+n-1,size);
	Reverse2(A,0,n-1,size);
	Reverse2(A,n,m+n-1,size);
//	Reverse(A,3,4,size);
	for(int i=0;i<size;i++){
		printf("%d",A[i]);
	}
}
