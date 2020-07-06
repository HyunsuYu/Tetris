#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "tetris.h"

/*-------------------------------선언------------------------------------*/

// Game screen buffer 크기
#define GAME_BASE_BUFFER_HEIGHT 40
#define GAME_BASE_BUFFER_WIDTH 95

// Game screen buffer내 게임 보드 틀 영역 크기
#define GAME_BOARDFORM_BUFFER_HEIGHT 37
#define GAME_BOARDFORM_BUFFER_WIDTH 16

// Game screen buffer내 게임 보드 판 영역 크기
#define GAME_BOARDPLAY_BUFFER_HEIGHT 31
#define GAME_BOARDPLAY_BUFFER_WIDTH 14

// Game screen buffer내 스코어 표시 영역 크기
#define GAME_SCORE_BUFFER_HEIGHT 7
#define GAME_SCORE_BUFFER_WIDTH 30

// Game screen buffer내 다음 패턴 표시 영역 크기
#define GAME_NEXTPATTRN_BUFFER_HEIGHT 10
#define GAME_NEXTPATTRN_BUFFER_WIDTH 14

// Game screen buffer내 보관된 패턴 표시 영역 크기
#define GAME_KEEPPATTRN_BUFFER_HEIGHT 10
#define GAME_KEEPPATTRN_BUFFER_WIDTH 14

// Game title 표시 영역 크기
#define GAME_TITLE_BUFFER_HEIGHT 30
#define GAME_TITLE_BUFFER_WIDTH 50

// Game screen buffer내 조작키 안내문 표시 영역 크기
#define GAME_INFORMATION_BUFFER_HEIGHT 12
#define GAME_INFORMATION_BUFFER_WIDTH 41

// pattrn size
#define PATTRN_SIZE 4

// alphabet size
#define ALPHABET_SIZE 6

// Game screen buffer내 일시정지 표시 영역 크기
#define GAME_PAUSE_BUFFER_HEIGHT 3
#define GAME_PAUSE_BUFFER_WIDTH 7

// Game end 표시 영역 크기
#define GAME_END_BUFFER_HEIGHT 14
#define GAME_END_BUFFER_WIDTH 98


// Init size
#define PATTRN_KIND 6
#define STRUCT_KIND 1
#define ALPHABET_KIND 10

// 정수형 매개변수중 의미없는 값 채워넣기
#define EMPTY 0

/*---------------------------------------------------------------------*/

typedef struct Spot
{
	int x;
	int y;
}Spot;

typedef struct Buffer_value
{
	Spot main_spot;
	int dx;
	int dy;
}Buffer_value;

typedef struct Pattrn_management
{
	int** A;
	int** B;
	int** C;
	int** D;
	int** E;
	int** empty;
}Pattrn_management;

typedef struct Alphabet_management
{
	int** T;
	int** E;
	int** R;
	int** I;
	int** S;
	int** G;
	int** A;
	int** M;
	int** O;
	int** V;
}Alphabet_management;

/////////////////////////////////////////////////////////////////////////
/* Function */
/////////////////////////////////////////////////////////////////////////

void Init();
void init_buffer();
void init_struct();

/*---------------------------------------------------------------------*/

void Update(bool first_call, bool cheak, int signal);
bool collision_cheak(int signal, bool top_cheak);
void buffer_copy(bool to_board);
void update_nextpattrn();
void update_keeppattrn();
void update_nowpattrn(bool nextpattrn_change);
bool keeppattrn_exist();
void rotate(bool turn_left);
void buffer_clear();
int return_rand_num();
void update_pattrnmove(bool down, bool bigdown, bool left, bool right, int bigbown_length);
bool pattrn_fullstand();
bool pattrn_alonestand();
void remove_onelayer(int layer);
void update_score();
void update_level();

/*---------------------------------------------------------------------*/

int Render(bool first_call, bool cheak, int level, int signal);
int render_form_management(int level);
int render_title();
void render_board_form();
void render_score_form();
void render_keep_form();
void render_next_form();
void render_information_form();
void render_ending_form();
void render_nextpattrn_ani();
void render_keeppattrn_ani();
void render_score_ani();
void render_level_ani();

/*---------------------------------------------------------------------*/

void Realease();

/*---------------------------------------------------------------------*/

int switch_global_signal(int input);

void gotoxy(int x, int y);