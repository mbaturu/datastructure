/*
*	Multiply two numbers using arrays.
*
*
*	you'd better store all the index in form of length.
*
*
*
*						by mBaturu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//global variables
char a[100],b[100],result[100];
int result_len_index;

//prototype
void Multiply(char*,char*,char*);
void Reverse_two(char*,char*);
void Reverse_one(char*);
void Reverse_len_index(char*,int);
void Stoi(char*);
void Itos(char*,int);

int main(int argc,char** argv){
	if(argc!=3){
		printf("need two big number arguments\n");
		exit(0);
	}
	Reverse_two(argv[1],a);
	Reverse_two(argv[2],b);
	Stoi(a);
	Stoi(b);
	Multiply(a,b,result);
	Reverse_len_index(result,result_len_index);
	Itos(result,result_len_index);
	printf("the result is: %s\n",result);
	return 0;
}

//add the test for 100 digits
void Multiply(char* a,char* b,char* result){
	int length_a=strlen(a);//how come it is 10001? it doesn't matter.
	int length_b=strlen(b);
	//int ir_max=(length_a>=length_b?length_b:length_a);
	//if you strlen on pure numbers and then you encounter 0, you may get the wrong length
	//so you need to recored the length of the string.

	for(int j=0;j<length_b;j++){
		for(int i=0;i<length_a;i++){
			//3*6=0x22
			result[i+j]+=a[i]*b[j];
			int k=0;
			while(result[i+j+k]!=0){
				if(result[i+j+k]>9){
					result[i+j+k+1]+=result[i+j+k]/10;
					result[i+j+k]=result[i+j+k]%10;
				} 
				k++;
			}
			result_len_index=i+j+k-1;
		}
	}
}

void Reverse_two(char* orig,char* dest){
	int length=strlen(orig);
	for(int i=0;i<length;i++){
		dest[length-1-i]=orig[i];
	}
	return;
}

void Reverse_one(char* a){
	int len=strlen(a);
	char temp;
	for(int i=0;i<len/2;i++){
		temp=a[i];
		a[i]=a[len-1-i];
		a[len-1-i]=temp;
	}
}

void Reverse_len_index(char* a,int len_index){
	char temp;
	for(int i=0;i<=len_index/2;i++){
		temp=a[i];
		a[i]=a[len_index-i];
		a[len_index-i]=temp;
	}
}

void Stoi(char* a){
	int len=strlen(a);
	for(int i=0;i<len;i++){
		a[i]=a[i]-0x30;
	}
}

void Itos(char* a,int len_index){
	//could be zero, len should not be used
	//int len=strlen(a);
	for(int i=0;i<=len_index;i++){
		a[i]=a[i]+0x30;
	}
}



