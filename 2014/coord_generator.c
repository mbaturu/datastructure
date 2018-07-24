/*
*	2D coordinates random generator.
*	
*
*	you could make it included as two functions:
*	the first is generate values, and the second is
*	read values, thru the header file as the interface
*            Protected by the GPL3.
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

int range=0;

int main(int argc,char** argv){
	//switch(argc)
	if(argc==1||argc>4){
		printf("format: coorg <number of coordinates> [-r <range>] or input -h for help\n");
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
	if(argc==3&&!strcmp(argv[2],"-r")){
		printf("format: <number of coordinates> [-r <range]>\n");
	}
	if(argc==4&&!strcmp(argv[2],"-r")){
		range=atoi(argv[3]);
		if(range<=1){
			printf("should not be less than or equal to 1.\n");
			exit(0);
		}
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
		if(range>1){
			p[i].x=rand()%range;
			p[i].y=rand()%range;
		}else{
			p[i].x=rand();
			p[i].y=rand();
		}
	}
	FILE* fp=fopen("2D_coordinates","w+");
	fprintf(fp,"%d\n",count);
	for(int i=0;i<count;i++){
		fprintf(fp,"(%d,%d)\n",p[i].x,p[i].y);
	}
	fclose(fp);
	return 0;
}
