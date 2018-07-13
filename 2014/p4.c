/*
*	This program specifies the largest triangle among the triangles
*	formed by input coordinates.
*
*
*
*
*										by mbaturu
*/

#include <stdlib.h>
#include <stdio.h>

struct Point{
	int x;
	int y;
}

double Triangle_Dimension(struct Point,struct Point,struct Point);

int main(int argc,char* argv){
	if(argc!=2){
		printf("need to sepcify the data file.\n");
	}

	FILE* fp=fopen(argv[1],"r");
	int count;
	fscanf(fp,"%d\n",&count);
	struct Point* p=(struct Point*)malloc(sizeof(struct Point)*count);
	for(int i=0;i<count;i++){
		fscanf(fp,"(%d,%d)",&p[i].x,&p[i].y);
	}
	fclose(fp);
	double max=0;
	//search for the largest triangle:
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			for(int k=j+1;k<count;k+=){
				double temp;
				if((temp=Triangle_Dimension(p[i],p[j],p[k]))>max){
					max=temp;
					printf("now the max area is: %.2lf\n",max);
				}
			}
		}
	}
	printf("The biggest max is %.2lf\n",max);
	return(0);
}

double Triangle_Dimension(struct point a,struct Point b,struct Point c){
	struct Point ba={b.x-a.x,b.y-a.y};
	struct Point ca={c.x-a.x,c.y-a.y};
	double area=(abs(ba.x*ca.y-ba.y*ca.x)/2.0f);
	return(area);
}
	






