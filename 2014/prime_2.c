#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc!=2){
		printf("format: %s <number>\n",argv[0]);
		exit(0);
	}
	
	int num_test=atoi(argv[1]);
	int temp=sqrt(num_test);
	for(int i=2;i<temp;i++){
		if(num_test%i==0){
			printf("not a prime number\n");
			exit(0);	
		}
	}
	printf("is a prime nunmber\n");
	exit(0);
}
