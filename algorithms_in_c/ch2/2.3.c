#include <stdio.h>
#include <stdlib.h>

#define N 100000

int main(){
	int i,j,k,count=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				count++;
	
	return(0);
}
	
