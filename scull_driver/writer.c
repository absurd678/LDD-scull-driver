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
    char ch, write_buf[BUFF_SIZE];
    char device[] = "/dev/sculln";
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    // Генерируем случайное число от 0 до 2
    int device_number = rand() % 3;
    
    // Формируем строку устройства
    snprintf(device, sizeof(device), "/dev/scull%d", device_number);
    
    printf("Using device: %s\n", device);
    
    fd = open(device, O_WRONLY);

    if (fd < 0) {
        perror("Failed to open device");
        return -1;
    }

    for(;;){
        srand(time(NULL));
        int random_value = rand();  // Генерируем случайное число
        memset(write_buf, 0, sizeof(write_buf));  // Очищаем буфер
        memcpy(write_buf, &random_value, sizeof(int));  // Копируем число в буфер

        write(fd, write_buf, sizeof(write_buf));
        printf("write: %d\n", write_buf);
        sleep(5);                       
    }

    return 0;
}