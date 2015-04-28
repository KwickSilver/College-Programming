#include<stdio.h>
#include<string.h>
main()
{
   char str[1000],wr[50];
   int i,j;
   printf("Enter the statement : ");
   gets(str);
   for(i=0,j=0;i<=strlen(str);i++)
   {
      if(str[i]!=' '&&str[i]!='\0')
      {
         wr[j] = str[i];
         j++;
      }
      else
      {
         wr[j] = '\0';
         if(strlen(wr)>2)
         {
            printf("%s\n",wr);
         }
         j=0;
      }
   }
}
