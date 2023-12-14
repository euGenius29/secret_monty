#include "monty.h"

/**
 * parse_buffer - parses the buffer into opcode and parameters
 * @buffer - buffer from line in file
 * @opcode - monty opcode
 * @parameters - parameters for the opcode
 * Return: void
 */
void parse_buffer(char *buffer, char *opcode, char *parameters, unsigned int *line_number, int *data)
{
	sscanf(buffer, "%s %[^\n]", opcode, parameters);
	if((strcmp(parameters, "") == 0) || parameters[0] < 48 || parameters [0] > 57)
	{
		fprintf(stderr,"L%d: usage: push integer\n", *line_number);
		exit(EXIT_FAILURE);
	}

	(*data) = atoi(parameters);
	(*line_number)++;
}
