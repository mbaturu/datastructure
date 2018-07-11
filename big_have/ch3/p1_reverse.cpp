/*
	reverse a list
*/

#include <stdio.h>
#include <math.h>

#define MAX 1000
int list[MAX];

template<class T>
void Reverse(T* list,int len){
	for(int i=0;i<len/2;i++){
		int temp=list[i];
		list[i]=list[len-1-i];
		list[len-1-i]=temp;
		printf("%d<->%d\n",list[len-1-i],list[i]);
	}
}

int main(int argc, char** argv){
	//if(argc....
	for(int i=0;i<MAX;i++){
		list[i]=pow(i,2)-1;
	}
	Reverse<int>(list,MAX);
}

