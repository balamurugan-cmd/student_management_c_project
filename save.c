#include "struct.h"

int main(void);
static void pf(int,char*,float);

FILE *fp;
static char flag=0,op;
void save()
{
	struct add *ptr=hptr;

	fp=fopen("data.text","w");

	printf("\nDo want to Save the data? y or n :");
	scanf(" %c",&op);
	if(op=='y')
	{
		fprintf(fp,"\t+----------------------------------------------------------------+\n");
		fprintf(fp,"\t| RollNo\t| Name\t\t\t\t| Mark\t\t |\n");
		fprintf(fp,"\t+----------------------------------------------------------------+\n");

		while(ptr!=0)
		{
			flag=1;		
			pf(ptr->roll,ptr->name,ptr->mark);
			ptr=ptr->next;
		}
		if(flag==1)
		{
			printf("\nData Saved Sussefully\nBack to Main Menu y or n : ");
			scanf(" %c",&op);
			if(op=='n')
				exit(0);
			else
				main();
		}
		else
		{
			printf("\nNo data has been saved!\nCheck the data Persent or Not!\nBack to Main Menu y or n : ");
			scanf(" %c",&op);
			if(op=='n')
				exit(0);
			else
				main();
		}
	}
	else
	{
			printf("\nNo data has been saved!\nBack to Main Menu y or n : ");
			scanf(" %c",&op);
			if(op=='n')
				exit(0);
			else
				main();
	}
}
void pf(int roll,char*name,float mark)
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

	fprintf(fp,"\t|%d",roll);//roll
	for(int i=0;i<14;i++)
		fprintf(fp," ");
	fprintf(fp,"|");

	fprintf(fp,"%s",name);//name
	for(int i=0;i<31-len;i++)
		fprintf(fp," ");
	fprintf(fp,"|");

	fprintf(fp,"%.2f",mark);//mark
	for(int i=0;i<10+j;i++)
		fprintf(fp," ");
	fprintf(fp,"|");

	fprintf(fp,"\n\t+");
	for(int i=0;i<64;i++)
		fprintf(fp,"-");
	fprintf(fp,"+\n");

}
