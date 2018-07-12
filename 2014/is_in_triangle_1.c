/*
  calculate the dimensions of the triangle and judge if the a point 
  is in the internal area of the triangle

  									by mbaturu
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Point{
  float x,y;
};

float D_T(struct Point,struct Point,struct Point);

int main(int argc,char** argv){

  if(argc!=5){
    printf("need four command arguments\n");
    exit(0);
  }
  //error was made here, the first argument is not what we want
  struct Point pts[4];
  for(int i=1;i<5;i++){
    sscanf(argv[i],"%f,%f",&pts[i-1].x,&pts[i-1].y);
  }

  float d1,d2,d3,d4;
  d1=D_T(pts[0],pts[1],pts[2]);
  d2=D_T(pts[0],pts[1],pts[3]);
  d3=D_T(pts[1],pts[2],pts[3]);
  d4=D_T(pts[0],pts[2],pts[3]);

  printf("%lf\n",d1);
  printf("%lf\n",d2);
  printf("%lf\n",d3);
  printf("%lf\n",d4);


  
  int result=(int)(d1-d2-d3-d4);
  if(!result){
    printf("the point is in the triangle.\n");
  }
  else{
    printf("the point is not in the tringle.\n");
  }

  printf("%d\n",result);
  return 0;
}

float D_T(struct Point a,struct Point b,struct Point c){
  struct Point ba, ca;
  ba.x=b.x-a.x;
  ba.y=b.y-a.y;
  ca.x=c.x-a.x;
  ca.y=c.y-a.y;
  
  return (abs(ba.x*ca.y-ba.y*ca.x)/2.0f);
}

  
