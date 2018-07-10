#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[100],b[100],result[100];

void Multiply(char*,char*,char*);
void Reverse_two(char*,char*);
void Reverse_one(char*);

int main(int argc,char** argv){
	if(argc!=3){
		printf("need two big number arguments\n");
		exit(0);
	}
	Reverse_two(argv[1],a);
	Reverse_two(argv[2],b);

	Multiply(a,b,result);
	Reverse_one(result);
	printf("the result is: %s",result);
	return 0;
}
//add the test for 100 digits
void Multiply(char* a,char* b,char* result){
	int length_a=strlen(a);
	int length_b=strlen(b);
	int ir_max=length_a>=length_b?length_b:length_a-1;

	for(int i=0;i<ir_max;i++){
		char temp=a[i]*b[i];
		if(temp>9){
			result[i+1]=temp-temp%10;
			result[i]+=temp%10;
			if(result[i]>9){
				result[i+1]+=result[i]-result[i]%10;
				result[i]=result[i]%10;
			}	  	 
		}else{
			result[i]+=a[i]*b[i];
			if(result[i]>9){
				result[i+1]+=result[i]-result[i]%10;
				result[i]=result[i]%10;
			}
		} 
	}
	if(length_a==length_b){
		return;
	}
	if(length_a>length_b){
		char ir_max_2=length_a-1-ir_max;
		for(int i=ir_max+1;i<length_a;i++){
			char temp=result[i]+a[i];
			if(temp>9){
				result[i+1]=temp-temp%10;
				result[i]=temp%10;
			}
			else{
				result[i]=temp;
			}
		}
	}
	if(length_a<length_b){
		char ir_max_2=length_b-ir_max;
		for(int i=ir_max+1;i<length_b;i++){
			char temp=result[i]+b[i];
			if(temp>9){
				result[i+1]=temp-temp%10;
				result[i]=temp%10;
			}
			else{
				result[i]=temp;
			}
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






