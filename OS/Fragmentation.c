#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void main()
{
	int ch,choice,loc,flag=0,i;
	char mem[158],full=178,empty=176,size;
	clrscr();
	printf("\nENTER YOUR CHOICE");
	printf("\n1.)Implementing External fragmentation");
	printf("\n2.)Implementing Internal fragmentation( using paging )");
	scanf("%d",&ch);
	for(i=0;i<158;i++)
	{
		mem[i]=empty;
	}

	while(1)
	{
		if(ch == 1)
		{
			printf("\nHow would you like to proceed?");
			printf("\n1.)Allocate memory to a program");
			printf("\n2.)Display current memory fragmentation status");
			printf("\n3.)Quit");
			scanf("%d",&choice);
if( choice == 1)
			{
				flag=0;
				printf("\nEnter the size of the program: ");
				scanf("%d",&size);
				getloc:srand(size);
				loc=rand();
				loc=loc%157;
				if(flag>500)
				{
					printf("\nMemory allocation Failed!!\n");
					continue;
				}
				if(mem[loc]!=full)
				{
					for(i=loc;i<loc+size;i++)
					{
						if(mem[i]==full)
						{
							flag++;
							goto getloc;
						}
					}
					for(i=loc;i<loc+size;i++)
						mem[i]=full;
				}
				else
				{
					flag++;
					goto getloc;
				}
                                       }
else if(choice == 2)
			{
				printf("\n%c",219);
				for(i=0;i<158;i++)
					printf("%c",mem[i]);
				printf("%c",219);
			}
			else
				exit(0);
		}
	}
}				













