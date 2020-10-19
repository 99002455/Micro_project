#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status_1;
    int execute_1;
    int s;

    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
                                   
        execute_1 = execl("/usr/bin/gcc","gcc","-c","parent.c",NULL); 
	execl("/bin/gcc","gcc","parent.o","-o",s,NULL); 

                            
        if(execute_1<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status_1,0); 
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status_1));
		
    }
    return 0;

}
