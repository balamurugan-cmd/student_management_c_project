#include"struct.h"

void sort(void);
void name_sort(void);
void prec_sort(void);
int main(void);
void pf(int,char*,float);

void sort()
{
A:
	unsigned char op;

	printf("\n\t\t\t\t\t+-----------------------------------------+");
	printf("\n\t\t\t\t\t|Enter \t\t\t\t\t  |"
	"\n\t\t\t\t\t|N/n : Sort with Name\t\t\t  |"
	"\n\t\t\t\t\t|P/p : Sort with percentage\t\t  |"
	"\n\t\t\t\t\t|B/b : Back to Main menu\t\t  |");
	printf("\n\t\t\t\t\t+-----------------------------------------+\n");
	
	printf("\nEnter Your Choice:");
	scanf(" %c",&op);

	switch(op)
	{
		case 'N':
		case 'n':
			name_sort();
			break;
		case 'P':
		case 'p':
			prec_sort();
			break;
		case 'B':
		case 'b':
			main();
			break;
		default:
			printf("\nInvalid value Back to main menu\n");
			sleep(3);
			main();
			break;
	}
}

void name_sort()
{
	unsigned char op='a';

	printf("\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");

	while(op<='z')
	{
		struct add *ptr=hptr;
		while(ptr)
		{	
			if((strncmp(ptr->name,&op,1))==0)
				pf(ptr->roll,ptr->name,ptr->mark);
			ptr=ptr->next;
		}
		op++;
	}
	printf("\nBack to main Menu? y or n :");
	scanf(" %c",&op);
	if(op=='y')
		return;
	else
		exit(0);
}

void prec_sort()
{
	int num=100;
	unsigned char op;
	printf("\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");

	while(num>=0)
	{
		struct add *ptr=hptr;
		while(ptr)
		{	
			if(((int)(ptr->mark))==num)
				pf(ptr->roll,ptr->name,ptr->mark);
			ptr=ptr->next;
		}
		num--;
	}
	printf("\nBack to main Menu? y or n :");
	scanf(" %c",&op);
	if(op=='y')
		return;
	else
		exit(0);
}
