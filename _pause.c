#include <stdio.h>

char c;
int main(){
	printf("Hello\n");
	while((c=getchar())!='\n'&&c!=EOF); 
	printf("Hello\n");
	while((c=getchar())!='\n'&&c!=EOF); 
	printf("Hello\n");
	
}