#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error_usage()
{
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    exit(97);
}

void error_read(char *filename)
{
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
    exit(98);
}

void error_write(char *filename)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
    exit(99);
}

void error_close(int fd)
{
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    exit(100);
}

int main(int argc, char **argv)
{
    int fd_from, fd_to, r_bytes, w_bytes;
    char buffer[BUFFER_SIZE];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    if (argc != 3)
        error_usage();

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_read(argv[1]);

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd_to == -1)
        error_write(argv[2]);

    while ((r_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        w_bytes = write(fd_to, buffer, r_bytes);
        if (w_bytes != r_bytes)
            error_write(argv[2]);
    }

    if (r_bytes == -1)
        error_read(argv[1]);

    if (close(fd_from) == -1)
        error_close(fd_from);

    if (close(fd_to) == -1)
        error_close(fd_to);

    return (0);
}
