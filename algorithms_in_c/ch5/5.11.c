#include <stdio.h>

int a[100];

int F(int n){
	if(n==0)return a[n]=0;
	if(n==1)return a[n]=1;
	if(a[n]!=0)return a[n];
	return a[n]=F(n-1)+F(n-2);
}

int main(){
	printf("%d\n",F(30));
	return 0;
}
