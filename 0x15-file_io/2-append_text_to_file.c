#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file to append to
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length = 0;

	if (!filename)
		return (-1);

	if (!text_content)
		return (1);

	/* Open the file for writing and appending */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* Get the length of the text content */
	while (text_content[length])
		length++;

	/* Write the text content to the file */
	bytes_written = write(fd, text_content, length);
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
