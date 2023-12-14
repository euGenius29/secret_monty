#include "monty.h"

/**
 * main - accepts file as input and parses it on to execute commands
 * @argc - argument count on command line
 * @argv - argument values passed
 * Return: 0 on succesd, -1 on error
 */

int data = 0;
int main(int argc, char *argv[])
{
	char buffer[256], opcode[50], parameters[200];
	stack_t *stack = NULL;
	unsigned int line_number;
	const char *filename;
	size_t filename_lenght;
	FILE *file;

	line_number = 0;
	filename = argv[1];
	filename_lenght = strlen(filename);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (strcmp(filename + filename_lenght - 2, ".m") != 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		memset(opcode, '\0', sizeof(opcode));
		parse_buffer(buffer, opcode, parameters, &line_number, &data);
		if (strcmp(opcode, "") == 0)
			continue;
		if (execute_instruction(opcode, &stack, line_number) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	printf("all codes in file executed\n");
	fclose(file);
	return (EXIT_SUCCESS);

}
