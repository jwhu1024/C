#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int a;
	char b[200];
} Sinfo;

typedef struct 
{
       char name[20];
       int num;
       float score[3];
	   Sinfo info;
}student;




void KiFreeMemory(void *ptr);

void * KiAllocMemory(int _size);

void KiFreeMemory(void *ptr)
{
	printf("free %p\n", ptr);
	free(ptr);
	ptr = NULL;
}

void *KiAllocMemory(int size)
{
	return malloc(size);
}

void print(void *p)
{
	if (p != NULL)
	{
		student * a = p;
		bzero((char*)a, sizeof(student)); //flush
		strcpy(a->name, "Today is good");
		a->num = 321; 
		a->score[0] = 67.5;
	    a->score[1] = 89;
	    a->score[2] = 78.6;
		a->info.a = 100;
		strcpy(a->info.b, "Trick!");

		//printf("Callee - %d\n", a->num);
	}

}

void Kind1()
{
	student stu;
	print(&stu);
	printf("Caller - %d\n",stu.num);
	printf("Caller - %s\n", stu.name);
	printf("Caller - %f\n", stu.score[0]);
	printf("Caller - %d\n",stu.info.a);
	printf("Caller - %s\n", stu.info.b);
	
}

void Kind2()
{

	student *stu = malloc(sizeof(student));

	print(stu);
	printf("Caller - %d\n",stu->num);
	printf("Caller - %s\n", stu->name);
	printf("Caller - %f\n", stu->score[0]);
	

	free(stu);
	stu = NULL;

}

void Kind3()
{
	student *stu = KiAllocMemory(sizeof(student));

	print(stu);
	printf("Caller - %d\n",stu->num);
	printf("Caller - %s\n", stu->name);
	printf("Caller - %f\n", stu->score[0]);
	
	printf("before%p\n", stu);
	KiFreeMemory(stu);
	printf("after%p\n", stu);


}

void try()
{
	char * ptr = malloc(255);
	int a = 50;
	ptr = (char*) &a;
	printf("%d\n",*ptr);
}

int main()
{
	Kind1();
	//Kind2();
	//try();
	return 0;
}
