#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFF_SIZE 100

int main()
{
    int fd;
    char ch, read_buf[BUFF_SIZE];
    char device[20];
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    // Генерируем случайное число от 0 до 2
    int device_number = rand() % 3;
    
    // Формируем строку устройства
    snprintf(device, sizeof(device), "/dev/scull%d", device_number);
    
    printf("Using device: %s\n", device);
    
    fd = open(device, O_RDWR);

    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }

    for(;;){
        read(fd, read_buf, sizeof(read_buf));
        printf("scull: %d\n", read_buf);
        sleep(5);                       
    }

    return 0;
}