#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    
    int fd;
    ssize_t size;
    char testString[14];
    char name[]="test.fifo";

    pid_t pid, ppid;

    fd = open(name, O_WRONLY);

    if (mknod(name, __S_IFIFO | 0666, 0) < 0) {
        // Если открыть FIFO не удалось, печатаем об этом сообщение и прекращаем работу */

        printf("Can\'t open FIFO for writting\n");
        exit(-1);
    } else {

        size = write(fd, "Program test!", 14);

        if (size < 14) {
            // Если записалось меньшее количество байт, сообщаем об ошибке и завершаем работу

            printf("Can\'t write all string to FIFO\n");
            exit(-1);
        }

        pid = getpid();
        ppid = getppid();

        printf("Access writing!\n");
        printf("Proc1 pid = %d, ppid = %d\n", (int)pid, (int)ppid); 

        }

        close(fd);

    return 0;
}