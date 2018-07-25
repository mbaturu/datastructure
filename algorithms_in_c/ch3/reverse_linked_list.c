#include <stdlib.h>
#include <stdio.h>

long long int N;

typedef int Item;
typedef struct _Node* Link;
typedef struct _Node{
	Item item;
	Link link;
}Node;

Link Reverse_List(Link);

int main(int argc,char** argv){
	FILE* fp=fopen(argv[1],"r");
	fscanf(fp,"%lld\n",&N);

	Link head=(Link)malloc(sizeof(Node));
	head->link=NULL;
	head->item=0;
	Link p=head;

	for(int i=0;i<N;i++){
		p->link=(Link)malloc(sizeof(Node));
		p=p->link;
		fscanf(fp,"%d\n",&(p->item));
	}

	p->link=NULL;

	printf("traverse the list: \n");
	
	for(p=head->link;p!=NULL;p=p->link){
		printf("%d -> \n",p->item);
	}
	
	head->link=Reverse_List(head);
	
	printf("traverse the list: \n");

	for(p=head->link;p!=NULL;p=p->link){
		printf("%d -> \n",p->item);
	}
	
	return(0);
}

Link Reverse_List(Link head){
	Link p=head->link;
	Link x=p;
	Link y=p->link,z=y->link;
	while(z!=NULL){
		z=y->link;
		y->link=x;
		x=y;
		y=z;
	}
	head->link->link=NULL;
	return(x);
}











