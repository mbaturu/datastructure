#include <stdio.h>

typedef struct{int size;int val;}Item;

Item items[]={
	3,4,
	4,5,
	7,10,
	8,11,
	9,13
};

int knap(int cap){
	int i,space,max,t;
	for(i=0,max=0;i<5;i++)
		if((space=cap-items[i].size)>=0)
			if((t=knap(space)+items[i].val)>max)
				max=t;
	return max;
}



int main(){
	printf("%d\n",knap(17));
	return(0);
}
