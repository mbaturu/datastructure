#include <stdlib.h>
#include <stdio.h>

int bag[10];
//use a macro to get the input? 

void Insert_Sort(int );

int main(){
	for(int i=0;i<10;i++){
		scanf("%d",&bag[i]);
	}
	for(int i=0;i<10;i++){
		printf("%d ",bag[i]);
	}
	putchar('\n');
	Insert_Sort(bag);
	return(0);
}
