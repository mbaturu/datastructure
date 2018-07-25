#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long N;

int main(int argc,char** argv){
	if(argc!=2){
		printf("need a number argument\n");
		exit(0);
	}
	N=atoll(argv[1]);
	FILE* fp=fopen("random_number","w");
	fprintf(fp,"%lld\n",N);
	for(int i=0;i<N;i++){
		srand((int)clock());
		fprintf(fp,"%d\n",rand());
	}
	fclose(fp);
	return(0);
}
