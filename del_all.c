#include"struct.h"
int main(void);
void del_all()
{
	struct add *ptr=hptr;

	char op;
	printf("\nDo u want to delete all student data? y or n :");
	scanf(" %c",&op);

	if(op=='y')
	{
		while(ptr)
		{
			hptr=ptr->next;
			free(ptr);
			ptr=hptr;
		}
		printf("\nAll Student Data as been deleted\n\nDo u want to go back into main menu? y or n :");		    scanf(" %c",&op);
		if(op=='y')
			main();
		else
			return;
	}
	else
	{
		printf("\nNo Student Data as been deleted\n\nDo u want to go back into main menu? y or n :");		    scanf(" %c",&op);
		if(op=='y')
			main();
		else
			return;
	}
}
