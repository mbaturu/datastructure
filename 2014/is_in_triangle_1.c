/*
  calculate the dimensions of the triangle and judge if the a point 
  is in the internal area of the triangle
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Point{
  float x,y;
};

float D_T(float,float,float);

int main(int argc,char** argv){

  if(argc!=4){
    printf("need four commend argument\n");
    exit(0);
  }

  Point pts[4];
  for(int i=0;i<4;i++){
    sscanf(argv[i],"%d,%d",&pts[i].x,&pts[i].y);
  }

  float d1,d2,d3,d4;
  d1=D_T(pts[0],pts[1],pts[2]);
  d2=D_T(pts[0],pts[1],pts[3]);
  d3=D_T(pts[1],pts[2],pts[3]);
  d4=D_T(pts[0],pts[2],pts[3]);

  int result=(int)(d1-d2-d3-d4);
  if(!result){
    printf("the point is in the triangle.\n");
  }
  else{
    printf("the point is not ine trigle.\n");
  }

  return 0;
}

float D_T(Point a,Point b,Point c){
  Point ba, ca;
  ba.x=b.x-a.x;
  ba.y=b.y-a.x;
  ca.x=c.x-a.x;
  ca.y=c.y-a.x;
  
  return (abs(ba.x*ca.y-ba.y*ca.x)/2.0f);
}

  
