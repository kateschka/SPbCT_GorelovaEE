#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main()
{
int pid;
int var = 1;
printf("Single process, var=%d\n",var);
var ++;
printf("Single process, var=%d\n",var);
pid=fork();

if(pid > 0)
{
printf("Родительский процесс, var=%d\n", var);
var+=3;
printf("Родительский процесс, var=%d\n", var);
sleep(1);
}
else if(pid == 0)
{
printf("Дочерний процесс, var=%d\n",var);
var+=5;
printf("Дочерний процесс, var=%d\n",var);
}

else {
perror("Fork error ");
return -1;
}
return 0;
} 