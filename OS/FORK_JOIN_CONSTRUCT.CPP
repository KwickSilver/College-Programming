#include  <stdio.h>
#include  <sys/types.h>



void  ChildProcess();                /* child process prototype  */
void  ParentProcess();               /* parent process prototype */

int main()
{
     pid_t  pid;

     pid = fork();
     if (pid == 0)
          ChildProcess();
     else
          ParentProcess();
}

void  ChildProcess()
{
cout<<"Child\n";
}

void  ParentProcess()
{
  ;  cout<<"Parent\n"
}
