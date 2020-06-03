#include <stdio.h>
#include <cs50.h>

int get_height(string prompt);
void print_opening(int height, int row);
void print_hash(int row);

int main(void)
{
	// Get the pyramid height from the user
	int height = get_height("Height: ");

	for (int i = 0; i < height; i++)
	{
		print_opening(height, i);
		print_hash(i);
		printf("  ");
		print_hash(i);
		printf("\n");
	}
}

// prompts the user for an integer between 1 to 8 inclusive
int get_height(string prompt)
{
	int height;
	do
	{
		height = get_int("Height: \n");
	}
	while (height < 1 || height > 8);
	return height;
}

void print_opening(int height, int row)
{
	for (int i = 0; i < height - row - 1; i++)
	{
		printf(" ");
	}
}

void print_hash(int row)
{
	for (int i = 0; i < row + 1; i++)
	{
		printf("#");
	}
}
