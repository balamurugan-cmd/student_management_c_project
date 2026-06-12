#include "struct.h"


void show(void);
void print(int,char*,float);

static int x=1;
static struct add *ptr=NULL;

void add()
{
A:
	char op;
	do
	{
		short int check=0;
		struct add *temp=(struct add*)malloc(sizeof(struct add));
	
		printf("\nEnter the Student name : ");
		scanf(" %[^\n]s",temp->name);
		printf("\nEnter the mark : ");
		scanf("%f",&temp->mark);	
		
		check=temp->mark;
		if(check>100)
		{
			printf("\nMark Should be less than or equal to 100 !\n");
			free(temp);
			printf("\n\nDo u want add New student y or n : ");
			scanf(" %c",&op);
			if(op=='y')
				goto A;				
			else
				return;	
		}	
		temp->roll=x++;
		temp->next=NULL;
	
		if(hptr==0)
			hptr=temp;
		else
			ptr->next=temp;
		ptr=temp;	
	
		printf("\n\t\t\t\t\t\tNew Add Student\n\n");
		
		printf("\t\t\t+----------------------------------------------------------------+\n");
		printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
		printf("\t\t\t+----------------------------------------------------------------+\n");
		
		print(ptr->roll,ptr->name,ptr->mark);

		printf("\n\nDo u want add New student y or n : ");
		scanf(" %c",&op);
	}while(op=='y');
	return;
}
void print(int roll,char*name,float mark)
{
	short int len=strlen(name);
	short int mk=mark;
	char j=0;
	if((mk>=10)&&(mk<=99))
		j=1;
	else if(mk==100)
		j=0;
	else
		j=2;

	printf("\t\t\t|%d",roll);//roll
	for(int i=0;i<14;i++)
		printf(" ");
	printf("|");

	printf("%s",name);//name
	for(int i=0;i<31-len;i++)
		printf(" ");
	printf("|");
	
	printf("%.2f",mark);//mark
	for(int i=0;i<10+j;i++)
		printf(" ");
	printf("|");
	
	printf("\n\t\t\t+");
	for(int i=0;i<64;i++)
		printf("-");
	printf("+\n");

}
