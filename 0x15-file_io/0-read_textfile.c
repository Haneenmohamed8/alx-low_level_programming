#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: the name of the file to read
 * @letters: the number of letters to read from the file
 *
 * Return:actual number of letters it could read and print, or 0on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_read;
	int file_descriptor;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);
	return (bytes_read);
}
