#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#pragma region Defines

#define CMD_SCREEN_HEIGHT 50
#define CMD_SCREEN_WIDTH 70

#define GAME_BOARD_SIZE_HEIGHT 40
#define GAME_BOARD_SIZE_WIDTH 15

#define SCORE_BOARD_SIZE_HEIGHT 5
#define SCORE_BOARD_SIZE_WIDTH 9

#define BLOCK_BOARD_SIZE_HEIGHT 12
#define BLOCK_BOARD_SIZE_WIDTH 10

#define INFORMATION_BOARD_SIZE_HEIGHT 25
#define INFORMATION_BOARD_SIZE_WIDTH 40

#define BLOCK_SIZE 4

#pragma endregion

#pragma region Declare

typedef struct GameNode
{
	bool mbisFill;
	int mcolorNum;
}GameNode;

typedef enum EBlockKind
{
	A = 1,
	B,
	C,
	D,
	E
}BlockKind;
typedef enum EGameMode
{
	Title = 1,
	Game,
	End
}EGameMode;

#pragma endregion


#pragma region Properties

GameNode** mgameBoard;
GameNode** mnextBlockBoard;
GameNode** mkeepBlockBoard;

int curScore;
int curLevel;

#pragma endregion

#pragma region Implements
//	screen default frame render
void RenderDefault_Title();
void RenderDefault_Game();
void RenderDefault_End();

void RenderChar(int x, int y, char targetChar);
void gotoxy(int x, int y);

#pragma endregion