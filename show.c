#include "struct.h"

void pf(int,char*,float);
void show()
{
	struct add *ptr=hptr;
	char op;
	if(ptr==0)
	{
		printf("\nThere is no Students \n");
		printf("\nBack to Main Menu y or n : ");
		scanf(" %c",&op);
		if(op=='n')
			exit(0);
		return;
	}
	printf("\n\t\t\t\t\t\tList of Student\n\n");
	
	printf("\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");
	while(ptr)
	{
		pf(ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
	printf("\nBack to Main Menu y or n : ");
	scanf(" %c",&op);
	if(op=='n')
		exit(0);
	else
		return;
}
