#include "Implement.h"

void RenderDefault_Title()
{
	for (int coord_y = 0; coord_y < CMD_SCREEN_HEIGHT; coord_y++)
	{
		for (int coord_x = 0; coord_x < CMD_SCREEN_WIDTH; coord_x++)
		{
			//	Boundary Line print
			if (coord_y == 0 || coord_y == CMD_SCREEN_HEIGHT - 1)
			{
				printf_s("| ");
			}
			else if (coord_x == 9 || coord_x == CMD_SCREEN_WIDTH - 1)
			{
				printf_s("--");
			}


		}

		printf_s("\n");
	}
}
void RenderDefault_Game()
{

}
void RenderDefault_End()
{

}

void RenderChar(int x, int y, char targetChar)
{
	for (int coord_y = 0; coord_y < BLOCK_SIZE; coord_y++)
	{
		for (int coord_x = 0; coord_x < BLOCK_SIZE; coord_x++)
		{
			switch (targetChar)
			{
			case 'T':

				break;

			case 'E':

				break;
			case 'R':

				break;

			case 'I':

				break;

			case 'S':

				break;
			}
		}
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}