#include <stdio.h>

int main(){
	double N;
	scanf("%lf",&N);
	int lgN;
	for(lgN=0;N>=1;lgN++,N/=2);

	printf("%d\n",lgN);

	return(0);
}

