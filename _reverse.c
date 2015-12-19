#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s) {
	int i, j;
	char c;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(void)
{
	char s1[] = "ABCDEFG";
	reverse(s1);
	printf("%s\n",s1);
	return 0;
}