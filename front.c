#include"struct.h"

void add(void);
void show(void);
void ext(void);
void del(void);
void modify(void);
void del_all(void);
void sort(void);
void reverse(struct add *);
void print(int,char*,float);
void save(void);

struct add *hptr=NULL;

int main()
{
	char op;
	system("clear");
	printf("\n\t\t\t\t\t+-------------------------------+"
	"\n\t\t\t\t\t| **** STUDENT RECORD MENU **** |"
	"\n\t\t\t\t\t| A/a : Add New Record\t\t|"
	"\n\t\t\t\t\t| D/d : Delete A Record\t\t|"
	"\n\t\t\t\t\t| S/s : Show the List\t\t|"
	"\n\t\t\t\t\t| M/m : Modify A record\t\t|"
	"\n\t\t\t\t\t| V/v : Save\t\t\t|"
	"\n\t\t\t\t\t| E/e : Exit\t\t\t|"
	"\n\t\t\t\t\t| T/t : Sort the List\t\t|"
	"\n\t\t\t\t\t| L/l : Delete All the Records\t|"
	"\n\t\t\t\t\t| R/r : Reverse the List\t|"	
	"\n\t\t\t\t\t+-------------------------------+"
	"\nEnter Your Choice: ");

	scanf(" %c",&op);

	switch(op)
	{
		case 'a' :
		case 'A' :
			add();
			main();
			break;
		case 'S' :
		case 's' :
			show();
			main();
			break;
		case 'D' :
		case 'd' :
			del();
			main();
			break;
		case 'M' :
		case 'm' :
			modify();
			main();
			break;
		case 'L' :
		case 'l' :
			del_all();
			main();
			break;
		case 'T' :
		case 't' :
			sort();
			main();
			break;
		case 'V' :
		case 'v' :
			save();
			printf("\nBack to Main Menu y or n : ");
			scanf(" %c",&op);
			if(op=='n')
				exit(0);
			else
				main();
			break;
		case 'E' :
		case 'e' :
			exit(0);
		case 'R' :
		case 'r' :
			reverse(hptr);
			printf("\nBack to Main Menu y or n : ");
			scanf(" %c",&op);
			if(op=='n')
				exit(0);
			else
				main();
			break;
		default:
			printf("\nInvalid Input Value\n");
			break;
	}
}
