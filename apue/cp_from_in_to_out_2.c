#include "apue.h"

int main(){
	int c;
	while((c=getc(stdin))!=EOF){
		if(putc(c,stdout)==EOF){
			err_sys("OUTPUT error");
		}
	}


	if(ferror(stdin)){
		err_sys("input error");
	}

	exit(0);

}





