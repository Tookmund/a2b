#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void printbinchar(unsigned char c)
{
	for( int i = 7; i >= 0; i-- )
	{
		printf( "%d", ( c >> i ) & 1 ? 1 : 0 );
	}
	printf(" ");
}

int main(int argc, char **argv)
{
	if (argc >= 2)
	{
		close(0);
		int in = open(argv[1], O_RDONLY);
		if (in != 0)
		{
			fprintf(stderr, "Failed opening input '%s' [%d]\n", argv[1], in);
			exit(1);
		}
	}
	if (argc == 3)
	{
		close(1);
		int out = open(argv[2], O_WRONLY);
		if (out != 1)
		{
			fprintf(stderr, "Failed opening output '%s' [%d]\n", argv[2], out);
			exit(2);
		}
	}
	if (argc > 3)
	{
		fprintf(stderr, "Too many arguments!\n");
		exit(3);
	}

	int c;
	while ((c = getchar()) != EOF) printbinchar(c);
}
