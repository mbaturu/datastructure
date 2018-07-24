/*
*	This program specifies the largest triangle among the triangles
*	formed by input coordinates.
*
*	
*	you should take care of the integer overflow by using double.
*	and avoid floating poing overflow
*										by mbaturu
*/

#include <stdlib.h>
#include <stdio.h>

struct Point{
	int x;
	int y;
};

long long number_processed;

double Triangle_Dimension(struct Point,struct Point,struct Point);
int Is_Triangle(struct Point,struct Point,struct Point);

int main(int argc,char** argv){
	if(argc!=2){
		printf("need to sepcify the data file.\n");
	}

	FILE* fp=fopen(argv[1],"r");
	int count;
	fscanf(fp,"%d\n",&count);
	struct Point* p=(struct Point*)malloc(sizeof(struct Point)*count);
	for(int i=0;i<count;i++){
		fscanf(fp,"(%d,%d)\n",&p[i].x,&p[i].y);
	}
	fclose(fp);
	double max=0.0;
	//search for the largest triangle:
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			for(int k=j+1;k<count;k++){
				double temp=Triangle_Dimension(p[i],p[j],p[k]);
				number_processed++;
				if(number_processed%1000000000==0){
					printf("already processed: %lld\n",number_processed);
				}
				if(temp>=0.0&&temp>max){
					max=temp;
					printf("now the max area is: %.2lf   ",max);
					printf("the points are (%d,%d),(%d,%d),(%d,%d)\n",p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
				}
			}
		}
	}
	printf("The biggest triangle is %.2lf\n",max);
	return(0);
}

double Triangle_Dimension(struct Point a,struct Point b,struct Point c){
	if(Is_Triangle(a,b,c)==0){
		return(-1.0);
	}
	//dot product

	struct Point ba={b.x-a.x,b.y-a.y};
	struct Point ca={c.x-a.x,c.y-a.y};
	
	double area=(abs(ba.x*ca.y-ba.y*ca.x)/2.0);
	return(area);
}

//any errors should be considered?
int Is_Triangle(struct Point a,struct Point b,struct Point c){
	double k1,k2;
	//there is a trap here,you should consider this when dividing
	if((!(b.x-a.x))&&(!(c.x-a.x))){
		return 0;
	}
	if(!(b.x-a.x)){
		return 1;
	}
	if(!(c.x-a.x)){
		return 1;
	}
	//othberwise there is gonna be floating point exception(core dumped)	
	k1=(b.y-a.y)/(b.x-a.x);
	k2=(c.y-a.y)/(c.x-a.x);
	if(k1==k2){
		return 0;
	}else{
		return 1;
	}
}

