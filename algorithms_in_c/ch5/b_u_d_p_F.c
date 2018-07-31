#include <stdio.h>

int a[100];

int F(int N){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=N;i++){
		a[i]=a[i-1]+a[i-2];
	}
	return a[N];
}

int main(){
	int R=F(30);
	printf("%d\n",R);
	return 0;
}
