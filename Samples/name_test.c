#include <stdio.h>

int main(){
	char first_name[20];
	char last_name[20];
	int age;

	printf("Enter first and last name as well as ur age: ");
	scanf("%19s %19s %i",first_name,last_name,&age);
	printf("First: %s Last: %s Age: %i\n",first_name,last_name,age);


}