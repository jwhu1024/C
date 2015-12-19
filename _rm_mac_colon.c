#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_colon (char *s, char *d)
{
	int i = 0, coi = 2;
	int s_len = strlen(s);
	
	memset(d, 0, s_len);
	
	for (i=0; i<s_len; i++, s++)
	{
		if (i != coi) {
			*d++ = *s;
		}
		else
			coi += 3;
	}
	return;
}

int main (int argc, char argv[])
{
	char *p = "80:00:0B:82:DA:8E";
	printf("%s\n", p);
	
	int len = strlen(p);
	
	char *d = (char*) malloc (sizeof(char) * 12);
	
	remove_colon(p, d);
	
	printf("%s\n", d);
	
	if (d)
		free(d);
	
	return 0;
}