#include"struct.h"

void pf(int roll,char*,float);

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
