#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_bytes_read, n_bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	n_bytes_read = read(fd, buffer, letters);
	if (n_bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	buffer[n_bytes_read] = '\0';

	n_bytes_written = write(STDOUT_FILENO, buffer, n_bytes_read);
	if (n_bytes_written == -1 || n_bytes_written != n_bytes_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (n_bytes_written);
}
