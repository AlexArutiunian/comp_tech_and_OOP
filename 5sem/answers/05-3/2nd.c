// Вторая программа. Данная программа ответственна за занесение данных в pipe()

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
 
int main(int argc, char* argv[])
{

    int fd[2];
    size_t size;
    char str[14]={"Program test!"};
 
    // Аргументы приходят в виде const char*. 
    // преобразуем в число. 
    fd[0] = atoi(argv[0]);
    fd[1] = atoi(argv[1]);
 
    // Закрытие входного потока данных
    close(fd[0]);
    size=write(fd[1], str, 14);
    if (size!=14)
    {
        printf("%zu", size);
        printf("Can't write all string\n");
        exit(-1);
    }
    
    // Закрытие выходного потока данных
    close(fd[1]);
    return 0;
}