#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item max(Item a[],int l,int r){
	Item u,v;
	int m=(l+r)/2;
	if(l==r)return a[l];
	u=max(a,l,m);
	v=max(a,m+1,r);
	if(u>v)return u;
	else return v;
}

int main(int argc,char** argv){
	int a[]={3,4,5,6,7,123,34,25,6,10};

	Item maxx=max(a,0,9);

	printf("%d\n",(int)maxx);

	return(0);
}
