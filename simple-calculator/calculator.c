#include <stdio.h>

/**
 * print_menu - prints the calculator menu
 *
 * Return: void
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}

/**
 * read_operands - prompts for and reads two integers
 * @a: pointer to store the first number
 * @b: pointer to store the second number
 *
 * Return: 1 on success, 0 on failure
 */
int read_operands(int *a, int *b)
{
	printf("A: ");
	if (scanf("%d", a) != 1)
		return (0);
	printf("B: ");
	if (scanf("%d", b) != 1)
		return (0);
	return (1);
}

/**
 * main - entry point of the simple calculator
 *
 * Return: Always 0
 */
int main(void)
{
	int choice, a, b;

	printf("Simple Calculator\n");
	print_menu();

	while (1)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
			return (0);

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		if (!read_operands(&a, &b))
			return (0);

		if (choice == 1)
			printf("Result: %d\n", a + b);
	}

	return (0);
}
