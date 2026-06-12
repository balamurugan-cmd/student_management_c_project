#include"struct.h"

void roll_modify(void);
void name_modify(void);
void list(struct add*);
void pf(int,char*,float);
char op=0;

void modify()
{
	
	printf("\n\t\t\t\t+------------------------------------------------+\n");
	
	printf("\t\t\t\t| Enter which record to search for modification\t |"
		"\n\t\t\t\t| R/r :  To search Rollno\t\t\t |"
		"\n\t\t\t\t| N/n : To search Name\t\t\t\t |"
		"\n\t\t\t\t| B/b : Back to main menu\t\t\t |");
	
	printf("\n\t\t\t\t+------------------------------------------------+\n");
	
	printf("\nEnter Your Choice : ");
	scanf(" %c",&op);

	switch(op)
	{
		case 'r' :
		case 'R' :
			roll_modify();
			break;
		case 'N' :
		case 'n' :
			name_modify();
			break;
		case 'b' :
		case 'B' :
			main();
			break;
	}
}
void roll_modify()
{
	unsigned int roll;
	struct add *ptr=hptr;
	
	printf("\nEnter the Roll number : ");
	scanf("%d",&roll);

	while(ptr)
	{
        	printf("\n\t\t\t+----------------------------------------------------------------+\n");
		printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
		printf("\t\t\t+----------------------------------------------------------------+\n");
		
		if(ptr->roll==roll)
		{
			pf(ptr->roll,ptr->name,ptr->mark);
			break;
		}
		ptr=ptr->next;
	}
	if(ptr==0)
	{
		printf("\nNo data found\nDo u want Continue? y or n : ");
		scanf(" %c",&op);
		if(op=='y')
			modify();
		else
			return;
	}
	else
	{

		printf("\n\t\t\t\t+------------------------------------------------+\n");
	
		printf("\t\t\t\t| Enter which record to modification\t\t |"
		"\n\t\t\t\t| N/n :  Name\t\t\t\t\t |"
		"\n\t\t\t\t| P/p : Percentage\t\t\t\t |");
		
		printf("\n\t\t\t\t+------------------------------------------------+\n");

		printf("\nEnter Your Choice:");
		scanf(" %c",&op);

		switch(op)
		{
			case 'N' :
			case 'n' :
				printf("\nEnter the new Name :");
				scanf("%s",ptr->name);
				list(ptr);
				return;
			case 'P' :
			case 'p' :
				printf("\nEnter the new Mark :");
				scanf("%f",&ptr->mark);
				list(ptr);
				return;
			default:
				printf("\nWrong Value\n");
				break;
		}
	}
}
void list(struct add *ptr)
{
	printf("\n\t\t\t\t\t\tUpdated Student\n");

	printf("\n\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");

	pf((ptr)->roll,(ptr)->name,(ptr)->mark);

	printf("\nDo u want Continue? y or n : ");
	scanf(" %c",&op);

	if(op=='y')
		modify();
	else
		return;

}
void name_modify()
{
	unsigned char name[20];
	struct add *ptr=hptr;
	char flag=0;
	printf("\nEnter the student Name: ");
	scanf("%s",name);

        printf("\n\t\t\t+----------------------------------------------------------------+\n");
	printf("\t\t\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
	printf("\t\t\t+----------------------------------------------------------------+\n");

	while(ptr)
	{
		if(((strcmp(ptr->name,name)==0)))
		{
			pf(ptr->roll,ptr->name,ptr->mark);
			flag=1;
		}
		ptr=ptr->next;
	}
	if(flag==1)
	{
		printf("\nDo u want to Modify? y or n : ");
		scanf(" %c",&op);
		if(op=='y')
			roll_modify();
		else
			return;
	}
	else
	{
		printf("\n\t\t\t\t\tNo data found\nDo u want to continue? y or n : ");
		scanf(" %c",&op);
		if(op=='y')
			modify();
		else
			return;
	}
}
