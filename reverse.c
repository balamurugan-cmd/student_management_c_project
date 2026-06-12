#include"struct.h"

void pf(int,char*,float);

char flag=0;

void reverse(struct add *ptr)
{
	if(flag==0)
	{
		printf("\n\t\t\t\t\t\tList of Student\n\n");
	
		printf("\t\t\t+----------------------------------------------------------------+\n");
		printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
		printf("\t\t\t+----------------------------------------------------------------+\n");
		flag=1;
	}
	if(ptr!=0)
		reverse(ptr->next);
	if(ptr!=0)
	pf(ptr->roll,ptr->name,ptr->mark);
}
