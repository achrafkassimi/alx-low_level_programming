#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/* Function to allocate a buffer of a given size. */
char *create_buffer(char *size)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", size);
		exit(99);
	}
	return (buffer);
}

/* Function to close a file. */
void close_file(int cf)
{
	int c = close(cf);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", cf);
		exit(100);
	}
}

/* Function to copy the contents of one file to another. */
void copy_file(char *src_file, char *dst_file)
{
	int dst_fd;
	char *buffer;
	int bytes_read = 0;
	int bytes_written = 0;

	/* Open the source and destination files. */
	int src_fd = open(src_file, O_RDONLY);

	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_file);
		exit(98);
	}

	dst_fd = open(dst_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (dst_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", dst_file);
		close_file(src_fd);
		exit(99);
	}

	/* Create a buffer to store the data read from the source file. */
	buffer = create_buffer(dst_file);

	/* Read from the source file and write to the destination file until the end of the source file is reached. */
	bytes_read = read(src_fd, buffer, 1024);

	while (bytes_read > 0)
	{
		bytes_written = write(dst_fd, buffer, bytes_read);

		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst_file);
			free(buffer);
			close_file(src_fd);
			close_file(dst_fd);
			exit(99);
		}
		bytes_read = read(src_fd, buffer, 1024);
		dst_fd = open(dst_file, O_WRONLY | O_APPEND);
	}

	/* Close the source and destination files. */
	close_file(src_fd);
	close_file(dst_fd);

	/* Free the buffer. */
	free(buffer);

	/* Return success. */
	/* return (0); */
}

int main(int argc, char *argv[])
{

	/* Check if the correct number of arguments are provided. */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Copy the contents of the source file to the destination file. */
	copy_file(argv[1], argv[2]);

	/* Return the appropriate exit code. */
	return (0);
}
