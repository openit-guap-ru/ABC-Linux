/* Пример создания нового
   процесса с разной работой процессов
   ребенка и родителя */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "lab4.h"

int main()
{
    pid_t pid, ppid;
    int a =  0; 
    int b =  100; 

    /* При успешном создании нового процесса
       с этого места псевдопараллельно 
       начинают работать два процесса: старый
       и новый */
    /* Узнаем идентификаторы роди-
       тельского процесса (в каждом из 
       процессов) */

    pid = getpid();
    ppid = getppid();

    if(fork() == -1){
    /* ошибка */
    } else if (pid == 0){
    /* ребенок */
      a = DO_A(a);
    /* Печатаем значения PID, PPID и вычислен-
       ное значение переменной a,b (в каждом из
       процессов) */
      printf("My pid = %d, my ppid = %d,result a = %d,result b = %d\n",(int)pid,(int)ppid,a,b);
    } else {
    /* родитель */
      b = DO_B(b);
    /* Печатаем значения PID, PPID и вычислен-
       ное значение переменной a,b (в каждом из
       процессов) */
      printf("My pid = %d, my ppid = %d,result a = %d,result b = %d\n",(int)pid,(int)ppid,a,b);
    }
    return 0;
}
