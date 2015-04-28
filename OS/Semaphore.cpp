#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
int chopstick[5];
int philospher[5];
void eat(int i);
void check(void);
void display();
void menu(void);
void init(void);
void pthink(int);
int philosphers(void);
int i;
void main()
{
 int philospher[5];
 clrscr();
 init();
 menu();
}
void init(void)
{
  int i;
  for(i=0;i<5;i++)
  {
     chopstick[i]=0;
     philospher[i]=0;
  }
}
void menu(void)
{
 int choice;

xx:
  sleep(2);  clrscr();
 printf("\n\n\n\t Available Options Are ");
 printf("\n\t 1.Display");
 printf("\n\t 2.Eat");
 printf("\n\t 3.Think");
 printf("\n\t 4.Quit");
 printf("\n\t Enter Your Choice Please : ");
 scanf("%d",&choice);

 switch(choice)
 {
   case 1 : display(); break;
   case 2 : check(); break;
   case 3 : i=philosphers(); pthink(i); break;
   case 4 : exit(0);
   default : printf("\n\t Invalid Entry. Please Try Again ");  goto xx;
 }
 getch();
}
int philosphers(void)
{
  printf("\n\t Enter Philospher No (0 to 4) :- ");
  scanf("%d",&philospher[i]);
  return(philospher[i]);
}
void eat(int i)
{
      chopstick[i]=1;
      chopstick[(i+1)%5]=1;
      philospher[i]=1;
      menu();
}
void check(void)
{ int ch;
  i=philosphers();
  if((chopstick[i]==0) && (chopstick[(i+1)%5]==0))
   {
       printf("\n\n\t Chopsticks are available. You can Eat.");
       printf("\n\t Would you like to Eat. (1 for yes) ");
       scanf("%d",&ch);

       if(ch==1)
	   eat(i);
   }
   else
   {
      printf("\n\n\t Sorry, Chopsticks are not Available.");
   }
   menu();
}
void display(void)
{
  int j;
  j=philosphers();
  if(philospher[j]==0)
       printf("\n\n\t The Philospher No. %d is Thinking.",j);
  else
       printf("\n\n\t The Philospher No. %d is Eating.",j);

  menu();
}

void pthink(int i)
{
  if(philospher[i]==0)
    {
       printf("\n\n\t You are already Thinking........");
       printf("you are free/thinking");
    }
   if(philospher[i]==1)
    {
	philospher[i]=0;
	chopstick[i]=0;
	chopstick[(i+1)%5]=0;
	printf("you are now thinking %d",philospher[i]);
    }
  menu();
}


