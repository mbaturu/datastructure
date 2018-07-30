#include <stdlib.h>
#include <stdio.h>

int gcd(int m,int n){
	if(n==0){
		return m;
	}
	gcd(n,m%n);
}

int main(int argc,char** argv){
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);

	printf("%d\n",gcd(a,b));

	return(0);
}
