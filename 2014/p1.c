/*
	This program aims to prove that any positive eveninteger bigger than
	2 can be the sum of two prime numbers.
							by mBaturu
							2018/7/6
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool Is_Prime(int);

int main(int argc,char** argv){
	if(argc!=2){
		printf("format: %s <number>\n",argv[0]);
		exit(0);
	}
	int num=atoi(argv[1]);
	if(num<=2){
		printf("number should be bigger than 2\n");
		exit(0);
	}
	if(num%2){
		printf("should be even number\n");
		exit(0);
	}
	for(int i=1;i<=(num/2+num%2);i++){
		//there is the trap here, the second Is_Prime is 
		//not evaluated if the first Is_Prime() is true
		//if(Is_Prime(i)&&Is_Prime(num-i)){ --->>> wrong!
		if(Is_Prime(i)){
			if(Is_Prime(num-i)){
				printf("the two prime number are: %d, %d\n",i,num-i);
				printf("the assertion is proved\n");
				exit(0);
			}
		}
	}
	exit(0);
}

bool Is_Prime(int num){
	if(num<=0){
		printf("out of range\n");
		exit(0);
	}
	if(num==1)
		return true;
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
	
