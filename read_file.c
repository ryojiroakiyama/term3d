#include "term3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char	*read_file(const char *file_name)
{
	struct stat	sb;
	char		*file_content;
	FILE		*fp;
	char		buf[64];

	if (stat(file_name, &sb) == -1)
		exit_with_error(NULL);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
	{
		sprintf(buf, "error: %s is a directory", file_name);
		exit_with_error(buf);
	}
	fp = fopen(file_name, "r");
	if (!fp)
		exit_with_error(NULL);
	file_content = malloc(sizeof(*file_content) * (sb.st_size + 1));
	if (!file_content)
		exit_with_error(NULL);
	fread(file_content, sizeof(*file_content), sb.st_size, fp);
	if (file_content[sb.st_size - 1] != '\n')
		exit_with_error("last line must be a blank line");
	file_content[sb.st_size] = '\0';
	return (file_content);
}
