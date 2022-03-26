#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int open_fd;
    // 打开文件
    open_fd = open("1.jpg", O_RDONLY);
    if (open_fd == -1)
    {
        perror("打开失败\n");
        return;
    }

    // 创建文件
    int create_fd = open("copy.jpg", O_WRONLY | O_CREAT, 770);
    if (create_fd == -1)
    {
        perror("创建文件失败\n");
        return;
    }
    // system("chmod 777 test.txt")  // 这个语句可以修改文件权限

    // 文件缓冲
    char buf[1024];
    int rv1 = -1; // 读文件
    int rv2 = -1; // 写文件
    int count = 0;
    while ((rv1 = read(open_fd, buf, sizeof(buf))) != 0)
    {
        if ((rv2 = write(create_fd, buf, rv1)) < 0)
        {
            printf("Count[%d] write failure \n", count);
            return;
        }
        count++;
    }
    printf("复制完成\n");
    // 复制完成后要关闭文件
    close(open_fd);
    close(create_fd);
}