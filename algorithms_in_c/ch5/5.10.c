#include <stdio.h>

int F(int a){
	if(a==0)return 0;
	if(a==1)return 1;
	return F(a-1)+F(a-2);
}

int main(){
	int N=30;
	
	int R=F(N);
	printf("%d\n",R);
	return 0;
}
