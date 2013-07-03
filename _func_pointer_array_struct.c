#include <stdio.h>

#define MAX_MATH_ARR	4

int plus (int num1, int num2)
{
	return (num1 + num2);
}

int minus (int num1, int num2)
{
	return (num1 - num2);
}

int multiple (int num1, int num2)
{
	return (num1 * num2);
}

int devide (int num1, int num2)
{
	return (num1 / num2);
}

typedef int (*Calculate) (int, int);
Calculate pCalcu[5]=
{
	plus,
	minus,
	multiple,
	devide
};

typedef struct {
    int (*Calculate) (int, int);
    int act;
} MATH_CLASS;

MATH_CLASS mathclass[MAX_MATH_ARR];

void initialize_func_arr (MATH_CLASS *math)
{
	int idx=0;
	for (; idx<MAX_MATH_ARR; idx++)
	{
		math[idx].Calculate = pCalcu[idx];
		math[idx].act = idx + 1;
	}
	return;
}

void shoe_help ()
{
	printf("==================\n");
	printf("1 : Plus		  \n");
	printf("2 : Minus		  \n");
	printf("3 : Multiple	  \n");
	printf("4 : Devide		  \n");
	printf("==================\n");
}

void main (void)
{
	int i, num_first=0, num_second=0, iact=0;
	initialize_func_arr(mathclass);
	
	while (1)
	{
		// Show the help for user
		shoe_help();
		
		// Input from user
		printf("Please input first number:\n");
		scanf("%d", &num_first);
		printf("Please input second number:\n");
		scanf("%d", &num_second);
		printf("Please input your action:\n\n");
		scanf("%d", &iact);
		
		for (i=0; i<MAX_MATH_ARR; i++)
		{
			if (mathclass[i].Calculate && iact == mathclass[i].act)
			{
				printf("Result : %d\n\n", mathclass[i].Calculate(num_first, num_second));
			}
		}
	}
	system("PAUSE");
	return;
}