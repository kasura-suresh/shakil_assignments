/* c PROGRAME TO CHECK A NUMBER IS MULTIPLE OF 2 OR NOT
   date: 20-feb 2020   author: MD SHAKIL ANSARI */


#include<stdio.h>

void Ispow2(int x){
	if((x&(x-1))==0){
		printf("yess..the entered number is a power of 2");
	}
	else
		printf("NO..the entered number is NOT a power of 2");
}
int main(){
	int n;
	printf("Enter any number to check:\n");
	scanf("%d",&n);
	Ispow2(n);
	return 0;
}
