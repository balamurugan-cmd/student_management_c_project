#include "struct.h"

void del(void);
void roll(void);
void show_del(struct add*);
void ext(void);
void name(void);
void save(void);
int main(void);
void pf(int,char*,float);


void del()
{

	unsigned char op;

	printf("\n\t\t\t\t\t+-------------------------------+\n");
	printf("\t\t\t\t\t| Enter\t\t\t\t|"
		"\n\t\t\t\t\t| R/r Enter Rollno to Delete\t|"
		"\n\t\t\t\t\t| N/n Enter Name to Delete\t| "
		"\n\t\t\t\t\t| B/b Back to Main menu\t\t| ");
	printf("\n\t\t\t\t\t+-------------------------------+\n");
	
	printf("\n\n Enter the Choice :");
	scanf(" %c",&op);

	switch(op)
	{
		case 'R' :
		case 'r' :
			roll();
			break;
		case 'N' : 
		case 'n' :
			name();
			break;
		case 'b' : 
		case 'B' :
			main();
			break;
		default:
			printf("\nInvalid Option\n");
			printf("\n\nBack to main menu? y or n :");
			scanf(" %c",&op);
			if(op=='y')
				return;
			else
				exit(0);
	}

}
void roll()
{
	struct add *ptr=hptr;
	struct add *prev=hptr;
	
	unsigned int rn;
	unsigned char delete;
	
	printf("\nEnter The Rollno for delete : ");
	scanf("%d",&rn);
	
	while(ptr)
	{
		if(rn==ptr->roll)
		{
        		printf("\t\t\t+----------------------------------------------------------------+\n");
			printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
			printf("\t\t\t+----------------------------------------------------------------+\n");
			
			pf(ptr->roll,ptr->name,ptr->mark);
			
			printf("\nAre you want to delete y or n : ");
			scanf(" %c",&delete);
			
			if(delete=='y')
			{
				if(ptr==hptr)
				{
					free(hptr);
					hptr=ptr->next;
				}
				else
				{
					prev->next=ptr->next;
					free(ptr);
				}
				show_del(hptr);
				save();
				return;
			}
			else
			{
				printf("\n\nNo data as been delete\n\n");
				return;
			}
		prev=ptr;
		}
		else
			ptr=ptr->next;
	}
	if(ptr==0)
	{
		unsigned char op;
		printf("\n\t\t\t\t\t\tNo data Found\n\nDo u want to continue y or n :");
		scanf(" %c",&op);
		if(op=='y')
			del();
		else
			return;
	}return;
}

void name()
{

	struct add *ptr=hptr;
	struct add *prev=hptr;
	char name[25];
	char flag=0;
	printf("\nEnter the name :");
	scanf("%s",name);
        
        printf("\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");
	
	while(ptr)
	{
		if(((strcmp(ptr->name,name))==0))	
		{
			pf(ptr->roll,ptr->name,ptr->mark);
			flag=1;
		}
		ptr=ptr->next;
	}
	if(flag==1)
	{
		roll();
	}
	else
	{
		unsigned char op;
		printf("\n\t\t\t\t\t\tNo Data Found\nDo u want to continue y or n :");
		scanf(" %c",&op);
		if(op=='y')
			del();
		else
			return;
	}
}

void show_del(struct add *ptr)
{
	printf("\n\t\t\t\t\t\tList of Student\n\n");
        printf("\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");
	while(ptr!=0)
	{
		pf(ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
}
