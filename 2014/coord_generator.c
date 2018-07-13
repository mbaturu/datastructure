/*
*	2D coordinates random generator.
*
*
*
*            Protected by the GPL.
*						by mbaturu
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct Point{
	int x;
	int y;
};

int main(int argc,char** argv){
	if(argc!=2){
		printf("format: coorg <number of coordinates> or input -h for help\n");
		exit(0);
	}
	if(strcmp(argv[1],"-h")==0){
		printf("This program by mbaturu is for generating random 2D coordinates.\n"
			"You specify the number of coordinates you want it to generate on\n"
			"the command line as arguments.The ouput would be in a file for \n"
			"your future use.\n"
			"\n"
			"\n"
			"Format: coorg <number of coordinates> or input -h for help\n");
	}
	int len=strlen(argv[1]);
	for(int i=0;i<len;i++){
		if(isdigit(argv[1][i])==0){
			printf("need a number as argument.\n");
			exit(0);
		}
	}
	int count=atoi(argv[1]);
	struct Point* p=(struct Point*)malloc(sizeof(struct Point)*count);
	//the library doesn't have a double generator?
	for(int i=0;i<count;i++){
		srand((int)clock());
		p[i].x=rand();
		p[i].y=rand();
	}
	FILE* fp=fopen("2D_coordinates","w+");
	fprintf(fp,"%d\n",count);
	for(int i=0;i<count;i++){
		fprintf(fp,"(%d,%d)\n",p[i].x,p[i].y);
	}
	fclose(fp);
	return 0;
}
