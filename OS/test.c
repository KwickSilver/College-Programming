    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    int main(int argc, char *argv[])

    {
      int number = atoi(argv[1]);
      int i;
      int pid;

      pid=fork();

      if (pid!=0){

        wait();
        printf ("hi!");
      }

      else {
        sleep (3);
        int i;

        printf("I am the child\n");

        printf("my pid=%d\n", getpid());

        printf("and my parent pid=%d\n", getppid());

      }

    }
