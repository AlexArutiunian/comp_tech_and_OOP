

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

// программа для чтения данных из pipe

int main( int argc, char *argv[]) {
   

    int fd[2], newProc;
    size_t size;
    char str[14];

    // для передачи значения дескриптора в другую программу int преобразовываем в char
    char fd0[11], fd1[11];

    if(pipe(fd) < 0) {
        printf("Can't create pipe\n");
        exit(-1);
    }

    newProc = fork();

    if (newProc < 0) {
        printf("Can't create fork\n");
        exit(-1);

    } else if (newProc > 0) {
        // Внутри родительского процесса
        // Закрытие выходного потока данных
        close(fd[1]);

        read(fd[0], str, 14);
        
        // Закрытие входного потока данных
        close(fd[0]);
        printf ("Result of writing: %s\n", str);

    } else {
        // Внутри порождённого процесса
        // Запись первого аргумента в массив символов
        sprintf(fd0, "%d", fd[0]);
        
        //Запись второго аргумента в массив символов
        sprintf(fd1, "%d", fd[1]);
        
        execl("./2nd", fd0, fd1, NULL);
    }

    return 0;
}