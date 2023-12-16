#include "monty.h"

/**
 * parse_buffer - parses the buffer into opcode and parameters
 * @buffer: buffer from line in file
 * @opcode: monty opcode
 * @parameters: parameters for the opcode
 * @line_number: Line number of the open file
 * @data: Value of the element
 * Return: void
 */
void parse_buffer(char *buffer, char *opcode, char *parameters,
		unsigned int *line_number, int *data)
{
	sscanf(buffer, "%s %[^\n]", opcode, parameters);
	if ((strcmp(opcode, "push") == 0) &&
			(valid_integer(parameters) == EXIT_FAILURE))
	{
		fprintf(stderr, "L%d: usage: push integer\n", *line_number);
		exit(EXIT_FAILURE);
	}

	(*data) = atoi(parameters);
	(*line_number)++;
}
/**
 * valid_integer - checks whether contents of parameter is valid
 * @str: string to check
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int valid_integer(const char *str)
{
	size_t i;

	if (!isdigit(str[0]) && (str[0] != '-' || !isdigit(str[1])))
		return (EXIT_FAILURE);
	for (i = 1; str[i] != '\0'; ++i)
		if (!isdigit(str[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
