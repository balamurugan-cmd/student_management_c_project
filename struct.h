#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void);
struct add
{
	int roll;
	float mark;
	char name[25];
	struct add *next;
};
extern struct add *hptr;
