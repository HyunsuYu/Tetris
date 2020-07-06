#include "framework.h"

/////////////////////////////////////////////////////////////////////////
/* Variable */
/////////////////////////////////////////////////////////////////////////

int** BOARD_BUFFER;
int** HIDING_BUFFER;

int** NOW_PATTRN;
int** NEXT_PATTRN;
int** KEEP_PATTRN;


Alphabet_management Alphabet;
Buffer_value Pattrn_value;


int* Pattrn_kind[PATTRN_KIND];
Buffer_value Struct_kind[STRUCT_KIND];
int* Alphabet_kind[ALPHABET_KIND];


int global_signal;
int ran_num;
int now_ran_num;
int memory_ran_num;
int rotate_num;


int now_score;
int now_level;

/////////////////////////////////////////////////////////////////////////
/* Function */
/////////////////////////////////////////////////////////////////////////

void Init()
{
	init_buffer();
	init_struct();
}



void init_buffer()
{
	BOARD_BUFFER = malloc(sizeof(int*) * GAME_BOARDPLAY_BUFFER_HEIGHT);
	HIDING_BUFFER = malloc(sizeof(int*) * GAME_BOARDPLAY_BUFFER_HEIGHT);

	/*-----------------------------------------------------------------------------------------*/

	for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
	{
		BOARD_BUFFER[i] = malloc(sizeof(int) * GAME_BOARDPLAY_BUFFER_WIDTH);
		HIDING_BUFFER[i] = malloc(sizeof(int) * GAME_BOARDPLAY_BUFFER_WIDTH);
	}

	/*-----------------------------------------------------------------------------------------*/

	for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_BOARDPLAY_BUFFER_WIDTH; j++)
		{
			if (i == 0 || i == GAME_BOARDPLAY_BUFFER_HEIGHT - 1)
			{
				BOARD_BUFFER[i][j] = (-1);
				HIDING_BUFFER[i][j] = (-1);
			}

			else if (j == 0 || j == GAME_BOARDPLAY_BUFFER_WIDTH - 1)
			{
				BOARD_BUFFER[i][j] = (-1);
				HIDING_BUFFER[i][j] = (-1);
			}

			else
			{
				BOARD_BUFFER[i][j] = 0;
				HIDING_BUFFER[i][j] = 0;
			}
		}
	}
}

void init_struct()
{
	Buffer_value Game_boardplay;

	//////////////////////////////////////////////////////////////////////
	/*Buffer_value init*/
	//////////////////////////////////////////////////////////////////////

	Game_boardplay.main_spot.x = malloc(sizeof(int));
	Game_boardplay.main_spot.y = malloc(sizeof(int));
	Game_boardplay.dx = malloc(sizeof(int));
	Game_boardplay.dy = malloc(sizeof(int));

	/*----------------------------------------------------------------*/

	Game_boardplay.main_spot.x = 5;
	Game_boardplay.main_spot.y = 7;

	/*---------------------------------------------------------------*/

	Game_boardplay.dx = GAME_BOARDPLAY_BUFFER_WIDTH;
	Game_boardplay.dy = GAME_BOARDPLAY_BUFFER_HEIGHT;

	/*------------------------------------------------------------------*/

	Struct_kind[0] = Game_boardplay;

	///////////////////////////////////////////////////////////////////////////
	/*Pattrn_management init*/
	///////////////////////////////////////////////////////////////////////////

	Pattrn_management Pattrn;

	Pattrn.A = malloc(sizeof(int*) * PATTRN_SIZE);
	Pattrn.B = malloc(sizeof(int*) * PATTRN_SIZE);
	Pattrn.C = malloc(sizeof(int*) * PATTRN_SIZE);
	Pattrn.D = malloc(sizeof(int*) * PATTRN_SIZE);
	Pattrn.E = malloc(sizeof(int*) * PATTRN_SIZE);
	Pattrn.empty = malloc(sizeof(int*) * PATTRN_SIZE);

	/*-----------------------------------------------------------------------*/

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		Pattrn.A[i] = malloc(sizeof(int) * PATTRN_SIZE);
		Pattrn.B[i] = malloc(sizeof(int) * PATTRN_SIZE);
		Pattrn.C[i] = malloc(sizeof(int) * PATTRN_SIZE);
		Pattrn.D[i] = malloc(sizeof(int) * PATTRN_SIZE);
		Pattrn.E[i] = malloc(sizeof(int) * PATTRN_SIZE);
		Pattrn.empty[i] = malloc(sizeof(int) * PATTRN_SIZE);
	}
	/*-----------------------------------------------------------------------*/

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		for (int j = 0; j < PATTRN_SIZE; j++)
		{
			if (i == 0)
			{
				Pattrn.A[i][0] = 0;
				Pattrn.A[i][1] = 0;
				Pattrn.A[i][2] = 0;
				Pattrn.A[i][3] = 0;

				Pattrn.B[i][0] = 0;
				Pattrn.B[i][1] = 0;
				Pattrn.B[i][2] = 0;
				Pattrn.B[i][3] = 0;

				Pattrn.C[i][0] = 0;
				Pattrn.C[i][1] = 1;
				Pattrn.C[i][2] = 0;
				Pattrn.C[i][3] = 0;

				Pattrn.D[i][0] = 0;
				Pattrn.D[i][1] = 0;
				Pattrn.D[i][2] = 0;
				Pattrn.D[i][3] = 0;

				Pattrn.E[i][0] = 0;
				Pattrn.E[i][1] = 0;
				Pattrn.E[i][2] = 0;
				Pattrn.E[i][3] = 0;
			}

			else if (i == 1)
			{
				Pattrn.A[i][0] = 0;
				Pattrn.A[i][1] = 0;
				Pattrn.A[i][2] = 1;
				Pattrn.A[i][3] = 0;

				Pattrn.B[i][0] = 0;
				Pattrn.B[i][1] = 1;
				Pattrn.B[i][2] = 1;
				Pattrn.B[i][3] = 0;

				Pattrn.C[i][0] = 0;
				Pattrn.C[i][1] = 1;
				Pattrn.C[i][2] = 0;
				Pattrn.C[i][3] = 0;

				Pattrn.D[i][0] = 0;
				Pattrn.D[i][1] = 1;
				Pattrn.D[i][2] = 0;
				Pattrn.D[i][3] = 0;

				Pattrn.E[i][0] = 1;
				Pattrn.E[i][1] = 1;
				Pattrn.E[i][2] = 0;
				Pattrn.E[i][3] = 0;
			}

			else if (i == 2)
			{
				Pattrn.A[i][0] = 1;
				Pattrn.A[i][1] = 1;
				Pattrn.A[i][2] = 1;
				Pattrn.A[i][3] = 0;

				Pattrn.B[i][0] = 0;
				Pattrn.B[i][1] = 1;
				Pattrn.B[i][2] = 1;
				Pattrn.B[i][3] = 0;

				Pattrn.C[i][0] = 0;
				Pattrn.C[i][1] = 1;
				Pattrn.C[i][2] = 0;
				Pattrn.C[i][3] = 0;

				Pattrn.D[i][0] = 1;
				Pattrn.D[i][1] = 1;
				Pattrn.D[i][2] = 1;
				Pattrn.D[i][3] = 0;

				Pattrn.E[i][0] = 0;
				Pattrn.E[i][1] = 1;
				Pattrn.E[i][2] = 1;
				Pattrn.E[i][3] = 0;
			}

			else if (i == 3)
			{
				Pattrn.A[i][0] = 0;
				Pattrn.A[i][1] = 0;
				Pattrn.A[i][2] = 0;
				Pattrn.A[i][3] = 0;

				Pattrn.B[i][0] = 0;
				Pattrn.B[i][1] = 0;
				Pattrn.B[i][2] = 0;
				Pattrn.B[i][3] = 0;

				Pattrn.C[i][0] = 0;
				Pattrn.C[i][1] = 1;
				Pattrn.C[i][2] = 0;
				Pattrn.C[i][3] = 0;

				Pattrn.D[i][0] = 0;
				Pattrn.D[i][1] = 0;
				Pattrn.D[i][2] = 0;
				Pattrn.D[i][3] = 0;

				Pattrn.E[i][0] = 0;
				Pattrn.E[i][1] = 0;
				Pattrn.E[i][2] = 0;
				Pattrn.E[i][3] = 0;
			}

			Pattrn.empty[i][j] = 0;
		}
	}

	Pattrn_kind[0] = Pattrn.A;
	Pattrn_kind[1] = Pattrn.B;
	Pattrn_kind[2] = Pattrn.C;
	Pattrn_kind[3] = Pattrn.D;
	Pattrn_kind[4] = Pattrn.E;
	Pattrn_kind[5] = Pattrn.empty;

	/////////////////////////////////////////////////////////////
	//
	//	Pattrn.A	Pattrn.B	Pattrn.C	Pattrn.D	Pattrn.E
	//	□□□□	□□□□	□■□□	□□□□	□□□□
	//	□□■□	□■■□	□■□□	□■□□	■■□□
	//	■■■□	□■■□	□■□□	■■■□	□■■□
	//	□□□□	□□□□	□■□□	□□□□	□□□□
	//
	/////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	/*Alphabet init*/
	////////////////////////////////////////////////////////////////////////

	Alphabet.A = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.E = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.G = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.I = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.M = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.O = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.R = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.S = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.T = malloc(sizeof(int*) * ALPHABET_SIZE);
	Alphabet.V = malloc(sizeof(int*) * ALPHABET_SIZE);

	/*--------------------------------------------------------------------*/

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		Alphabet.A[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.E[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.G[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.I[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.M[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.O[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.R[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.S[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.T[i] = malloc(sizeof(int) * ALPHABET_SIZE);
		Alphabet.V[i] = malloc(sizeof(int) * ALPHABET_SIZE);
	}

	/*--------------------------------------------------------------------*/

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		for (int j = 0; j < ALPHABET_SIZE; j++)
		{
			if (i == 0)
			{
				Alphabet.A[i][0] = 0;
				Alphabet.A[i][1] = 0;
				Alphabet.A[i][2] = 1;
				Alphabet.A[i][3] = 0;
				Alphabet.A[i][4] = 0;

				Alphabet.E[i][0] = 1;
				Alphabet.E[i][1] = 1;
				Alphabet.E[i][2] = 1;
				Alphabet.E[i][3] = 1;
				Alphabet.E[i][4] = 1;

				Alphabet.G[i][0] = 1;
				Alphabet.G[i][1] = 1;
				Alphabet.G[i][2] = 1;
				Alphabet.G[i][3] = 1;
				Alphabet.G[i][4] = 1;

				Alphabet.I[i][0] = 0;
				Alphabet.I[i][1] = 1;
				Alphabet.I[i][2] = 1;
				Alphabet.I[i][3] = 1;
				Alphabet.I[i][4] = 0;

				Alphabet.M[i][0] = 0;
				Alphabet.M[i][1] = 1;
				Alphabet.M[i][2] = 0;
				Alphabet.M[i][3] = 1;
				Alphabet.M[i][4] = 0;

				Alphabet.O[i][0] = 1;
				Alphabet.O[i][1] = 1;
				Alphabet.O[i][2] = 1;
				Alphabet.O[i][3] = 1;
				Alphabet.O[i][4] = 1;

				Alphabet.R[i][0] = 1;
				Alphabet.R[i][1] = 1;
				Alphabet.R[i][2] = 1;
				Alphabet.R[i][3] = 1;
				Alphabet.R[i][4] = 0;

				Alphabet.S[i][0] = 0;
				Alphabet.S[i][1] = 1;
				Alphabet.S[i][2] = 1;
				Alphabet.S[i][3] = 1;
				Alphabet.S[i][4] = 0;

				Alphabet.T[i][0] = 1;
				Alphabet.T[i][1] = 1;
				Alphabet.T[i][2] = 1;
				Alphabet.T[i][3] = 1;
				Alphabet.T[i][4] = 1;

				Alphabet.V[i][0] = 1;
				Alphabet.V[i][1] = 0;
				Alphabet.V[i][2] = 0;
				Alphabet.V[i][3] = 0;
				Alphabet.V[i][4] = 1;
			}

			else if (i == 1)
			{
				Alphabet.A[i][0] = 0;
				Alphabet.A[i][1] = 1;
				Alphabet.A[i][2] = 0;
				Alphabet.A[i][3] = 1;
				Alphabet.A[i][4] = 0;

				Alphabet.E[i][0] = 1;
				Alphabet.E[i][1] = 0;
				Alphabet.E[i][2] = 0;
				Alphabet.E[i][3] = 0;
				Alphabet.E[i][4] = 0;

				Alphabet.G[i][0] = 1;
				Alphabet.G[i][1] = 0;
				Alphabet.G[i][2] = 0;
				Alphabet.G[i][3] = 0;
				Alphabet.G[i][4] = 1;

				Alphabet.I[i][0] = 0;
				Alphabet.I[i][1] = 0;
				Alphabet.I[i][2] = 1;
				Alphabet.I[i][3] = 0;
				Alphabet.I[i][4] = 0;

				Alphabet.M[i][0] = 0;
				Alphabet.M[i][1] = 1;
				Alphabet.M[i][2] = 0;
				Alphabet.M[i][3] = 1;
				Alphabet.M[i][4] = 0;

				Alphabet.O[i][0] = 1;
				Alphabet.O[i][1] = 0;
				Alphabet.O[i][2] = 0;
				Alphabet.O[i][3] = 0;
				Alphabet.O[i][4] = 1;

				Alphabet.R[i][0] = 1;
				Alphabet.R[i][1] = 0;
				Alphabet.R[i][2] = 0;
				Alphabet.R[i][3] = 0;
				Alphabet.R[i][4] = 1;

				Alphabet.S[i][0] = 1;
				Alphabet.S[i][1] = 0;
				Alphabet.S[i][2] = 0;
				Alphabet.S[i][3] = 0;
				Alphabet.S[i][4] = 0;

				Alphabet.T[i][0] = 0;
				Alphabet.T[i][1] = 0;
				Alphabet.T[i][2] = 1;
				Alphabet.T[i][3] = 0;
				Alphabet.T[i][4] = 0;

				Alphabet.V[i][0] = 1;
				Alphabet.V[i][1] = 0;
				Alphabet.V[i][2] = 0;
				Alphabet.V[i][3] = 0;
				Alphabet.V[i][4] = 1;
			}

			else if (i == 2)
			{
				Alphabet.A[i][0] = 0;
				Alphabet.A[i][1] = 1;
				Alphabet.A[i][2] = 1;
				Alphabet.A[i][3] = 1;
				Alphabet.A[i][4] = 0;

				Alphabet.E[i][0] = 1;
				Alphabet.E[i][1] = 1;
				Alphabet.E[i][2] = 1;
				Alphabet.E[i][3] = 1;
				Alphabet.E[i][4] = 1;

				Alphabet.G[i][0] = 1;
				Alphabet.G[i][1] = 0;
				Alphabet.G[i][2] = 0;
				Alphabet.G[i][3] = 0;
				Alphabet.G[i][4] = 0;

				Alphabet.I[i][0] = 0;
				Alphabet.I[i][1] = 0;
				Alphabet.I[i][2] = 1;
				Alphabet.I[i][3] = 0;
				Alphabet.I[i][4] = 0;

				Alphabet.M[i][0] = 1;
				Alphabet.M[i][1] = 0;
				Alphabet.M[i][2] = 1;
				Alphabet.M[i][3] = 0;
				Alphabet.M[i][4] = 1;

				Alphabet.O[i][0] = 1;
				Alphabet.O[i][1] = 0;
				Alphabet.O[i][2] = 0;
				Alphabet.O[i][3] = 0;
				Alphabet.O[i][4] = 1;

				Alphabet.R[i][0] = 1;
				Alphabet.R[i][1] = 1;
				Alphabet.R[i][2] = 1;
				Alphabet.R[i][3] = 1;
				Alphabet.R[i][4] = 1;

				Alphabet.S[i][0] = 0;
				Alphabet.S[i][1] = 1;
				Alphabet.S[i][2] = 1;
				Alphabet.S[i][3] = 1;
				Alphabet.S[i][4] = 0;

				Alphabet.T[i][0] = 0;
				Alphabet.T[i][1] = 0;
				Alphabet.T[i][2] = 1;
				Alphabet.T[i][3] = 0;
				Alphabet.T[i][4] = 0;

				Alphabet.V[i][0] = 0;
				Alphabet.V[i][1] = 1;
				Alphabet.V[i][2] = 0;
				Alphabet.V[i][3] = 1;
				Alphabet.V[i][4] = 0;
			}

			else if (i == 3)
			{
				Alphabet.A[i][0] = 1;
				Alphabet.A[i][1] = 0;
				Alphabet.A[i][2] = 0;
				Alphabet.A[i][3] = 0;
				Alphabet.A[i][4] = 1;

				Alphabet.E[i][0] = 1;
				Alphabet.E[i][1] = 0;
				Alphabet.E[i][2] = 0;
				Alphabet.E[i][3] = 0;
				Alphabet.E[i][4] = 0;

				Alphabet.G[i][0] = 1;
				Alphabet.G[i][1] = 0;
				Alphabet.G[i][2] = 1;
				Alphabet.G[i][3] = 1;
				Alphabet.G[i][4] = 1;

				Alphabet.I[i][0] = 0;
				Alphabet.I[i][1] = 0;
				Alphabet.I[i][2] = 1;
				Alphabet.I[i][3] = 0;
				Alphabet.I[i][4] = 0;

				Alphabet.M[i][0] = 1;
				Alphabet.M[i][1] = 0;
				Alphabet.M[i][2] = 1;
				Alphabet.M[i][3] = 0;
				Alphabet.M[i][4] = 1;

				Alphabet.O[i][0] = 1;
				Alphabet.O[i][1] = 0;
				Alphabet.O[i][2] = 0;
				Alphabet.O[i][3] = 0;
				Alphabet.O[i][4] = 1;

				Alphabet.R[i][0] = 1;
				Alphabet.R[i][1] = 1;
				Alphabet.R[i][2] = 0;
				Alphabet.R[i][3] = 0;
				Alphabet.R[i][4] = 0;

				Alphabet.S[i][0] = 0;
				Alphabet.S[i][1] = 0;
				Alphabet.S[i][2] = 0;
				Alphabet.S[i][3] = 0;
				Alphabet.S[i][4] = 1;

				Alphabet.T[i][0] = 0;
				Alphabet.T[i][1] = 0;
				Alphabet.T[i][2] = 1;
				Alphabet.T[i][3] = 0;
				Alphabet.T[i][4] = 0;

				Alphabet.V[i][0] = 0;
				Alphabet.V[i][1] = 1;
				Alphabet.V[i][2] = 0;
				Alphabet.V[i][3] = 1;
				Alphabet.V[i][4] = 0;
			}

			else if (i == 4)
			{
				Alphabet.A[i][0] = 1;
				Alphabet.A[i][1] = 0;
				Alphabet.A[i][2] = 0;
				Alphabet.A[i][3] = 0;
				Alphabet.A[i][4] = 1;

				Alphabet.E[i][0] = 1;
				Alphabet.E[i][1] = 1;
				Alphabet.E[i][2] = 1;
				Alphabet.E[i][3] = 1;
				Alphabet.E[i][4] = 1;

				Alphabet.G[i][0] = 1;
				Alphabet.G[i][1] = 1;
				Alphabet.G[i][2] = 1;
				Alphabet.G[i][3] = 1;
				Alphabet.G[i][4] = 0;

				Alphabet.I[i][0] = 0;
				Alphabet.I[i][1] = 1;
				Alphabet.I[i][2] = 1;
				Alphabet.I[i][3] = 1;
				Alphabet.I[i][4] = 0;

				Alphabet.M[i][0] = 1;
				Alphabet.M[i][1] = 0;
				Alphabet.M[i][2] = 1;
				Alphabet.M[i][3] = 0;
				Alphabet.M[i][4] = 1;

				Alphabet.O[i][0] = 1;
				Alphabet.O[i][1] = 1;
				Alphabet.O[i][2] = 1;
				Alphabet.O[i][3] = 1;
				Alphabet.O[i][4] = 1;

				Alphabet.R[i][0] = 1;
				Alphabet.R[i][1] = 0;
				Alphabet.R[i][2] = 1;
				Alphabet.R[i][3] = 1;
				Alphabet.R[i][4] = 1;

				Alphabet.S[i][0] = 0;
				Alphabet.S[i][1] = 1;
				Alphabet.S[i][2] = 1;
				Alphabet.S[i][3] = 1;
				Alphabet.S[i][4] = 0;

				Alphabet.T[i][0] = 0;
				Alphabet.T[i][1] = 0;
				Alphabet.T[i][2] = 1;
				Alphabet.T[i][3] = 0;
				Alphabet.T[i][4] = 0;

				Alphabet.V[i][0] = 0;
				Alphabet.V[i][1] = 0;
				Alphabet.V[i][2] = 1;
				Alphabet.V[i][3] = 0;
				Alphabet.V[i][4] = 0;
			}
		}
	}

	Alphabet_kind[0] = Alphabet.A;
	Alphabet_kind[1] = Alphabet.E;
	Alphabet_kind[2] = Alphabet.G;
	Alphabet_kind[3] = Alphabet.I;
	Alphabet_kind[4] = Alphabet.M;
	Alphabet_kind[5] = Alphabet.O;
	Alphabet_kind[6] = Alphabet.R;
	Alphabet_kind[7] = Alphabet.S;
	Alphabet_kind[8] = Alphabet.T;
	Alphabet_kind[9] = Alphabet.V;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//		A			E			G			I			M			O			R			S			T			V
	//	□□■□□	■■■■■	■■■■■	□■■■□	□■□■□	■■■■■	■■■■□	□■■■□	■■■■■	■□□□■
	//	□■□■□	■□□□□	■□□□■	□□■□□	□■□■□	■□□□■	■□□□■	■□□□□	□□■□□	■□□□■
	//	□■■■□	■■■■■	■□□□□	□□■□□	■□■□■	■□□□■	■■■■■	□■■■□	□□■□□	□■□■□
	//	■□□□■	■□□□□	■□■■■	□□■□□	■□■□■	■□□□■	■■□□□	□□□□■	□□■□□	□■□■□
	//	■□□□■	■■■■■	■■■■□	□■■■□	■□■□■	■■■■■	■□■■■	□■■■□	□□■□□	□□■□□
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	/*Pattrn_valse*/
	////////////////////////////////////////////////////////////////////////

	Pattrn_value.main_spot.x = 5;
	Pattrn_value.main_spot.y = 1;
	Pattrn_value.dx = PATTRN_SIZE;
	Pattrn_value.dy = PATTRN_SIZE;

	////////////////////////////////////////////////////////////////////////
	/*score & level*/
	////////////////////////////////////////////////////////////////////////

	now_score = 0;
	now_level = 1;
}

/*---------------------------------------------------------------------*/

void Update(bool first_call, bool cheak, int signal)
{
	if (cheak == true)
	{
		if (collision_cheak((-1), true) == true)
		{
			render_ending_form();

			Realease();

			exit(0);
		}

		if (pattrn_alonestand() == true)
		{
			buffer_copy(false);
			buffer_clear();
			buffer_copy(true);

			update_nowpattrn(true);

			Pattrn_value.main_spot.x = 5;
			Pattrn_value.main_spot.y = 1;
			Pattrn_value.dx = PATTRN_SIZE;
			Pattrn_value.dy = PATTRN_SIZE;
		}
	}

	else
	{
		if (first_call == true)
		{
			update_nowpattrn(false);
			update_nextpattrn();
			update_keeppattrn();

			for (int i = 0; i < Pattrn_value.dy; i++)
			{
				for (int j = 0; j < Pattrn_value.dx; j++)
				{
					BOARD_BUFFER[i + Pattrn_value.main_spot.y][j + Pattrn_value.main_spot.x] = NOW_PATTRN[i][j];
				}
			}
		}

		else
		{
			if (signal == 0)
			{
				if (collision_cheak(signal, false) == true)
				{
					update_pattrnmove(true, false, false, false, 0);
				}
			}

			else if (signal == 1)
			{
				while (collision_cheak(signal, false) == true)
				{
					update_pattrnmove(false, true, false, false, 1);
				}
			}

			else if (signal == 2)
			{
				if (collision_cheak(signal, false) == true)
				{
					update_pattrnmove(false, false, true, false, 0);
				}
			}

			else if (signal == 3)
			{
				if (collision_cheak(signal, false) == true)
				{
					update_pattrnmove(false, false, false, true, 0);
				}
			}

			else if (signal == 4)
			{
				update_keeppattrn();
			}

			else if (signal == 5)
			{
				rotate(true);
			}

			else if (signal == 6)
			{
				rotate(false);
			}

			else if (signal == 7)
			{
				system("pause >nul");
			}
		}
	}
}



bool collision_cheak(int signal, bool top_cheak)
{
	if (top_cheak == false)
	{
		if (signal == 0)
		{
			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				for (int j = 0; j < PATTRN_SIZE; j++)
				{
					if (((HIDING_BUFFER[Pattrn_value.main_spot.y + 1 + i][Pattrn_value.main_spot.x + j] == (-1)) && (NOW_PATTRN[i][j] == 1)) || ((HIDING_BUFFER[Pattrn_value.main_spot.y + 1 + i][Pattrn_value.main_spot.x + j] == NOW_PATTRN[i][j]) && (NOW_PATTRN[i][j] == 1)))
					{
						return false;
					}
				}
			}

			return true;
		}

		else if (signal == 1)
		{
			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				for (int j = 0; j < PATTRN_SIZE; j++)
				{
					if (((HIDING_BUFFER[Pattrn_value.main_spot.y + 1 + i][Pattrn_value.main_spot.x + j] == (-1)) && (NOW_PATTRN[i][j] == 1)) || ((HIDING_BUFFER[Pattrn_value.main_spot.y + 1 + i][Pattrn_value.main_spot.x + j] == NOW_PATTRN[i][j]) && (NOW_PATTRN[i][j] == 1)))
					{
						return false;
					}
				}
			}

			return true;
		}

		else if (signal == 2)
		{
			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				for (int j = 0; j < PATTRN_SIZE; j++)
				{
					if (((HIDING_BUFFER[Pattrn_value.main_spot.y + i][Pattrn_value.main_spot.x - 1 + j] == (-1)) && (NOW_PATTRN[i][j] == 1)) || ((HIDING_BUFFER[Pattrn_value.main_spot.y + i][Pattrn_value.main_spot.x - 1 + j] == NOW_PATTRN[i][j]) && (NOW_PATTRN[i][j] == 1)))
					{
						return false;
					}
				}
			}

			return true;
		}

		else if (signal == 3)
		{
			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				for (int j = 0; j < PATTRN_SIZE; j++)
				{
					if (((HIDING_BUFFER[Pattrn_value.main_spot.y + i][Pattrn_value.main_spot.x + 1 + j] == (-1)) && (NOW_PATTRN[i][j] == 1)) || ((HIDING_BUFFER[Pattrn_value.main_spot.y + i][Pattrn_value.main_spot.x + 1 + j] == NOW_PATTRN[i][j]) && (NOW_PATTRN[i][j] == 1)))
					{
						return false;
					}
				}
			}

			return true;
		}
	}

	else
	{
		for (int i = 0; i < GAME_BOARDPLAY_BUFFER_WIDTH; i++)
		{
			if ((BOARD_BUFFER[1][i] == 1) || ((NOW_PATTRN[2][1] == HIDING_BUFFER[4][i]) && (NOW_PATTRN[2][1] == 1)))
			{
				return true;
			}
		}

		return false;
	}
}

void buffer_copy(bool to_board)
{
	if (to_board == true)
	{
		for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
		{
			for (int j = 0; j < GAME_BOARDPLAY_BUFFER_WIDTH; j++)
			{
				BOARD_BUFFER[i][j] = HIDING_BUFFER[i][j];
			}
		}
	}

	else
	{
		for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
		{
			for (int j = 0; j < GAME_BOARDPLAY_BUFFER_WIDTH; j++)
			{
				HIDING_BUFFER[i][j] = BOARD_BUFFER[i][j];
			}
		}
	}
}

void update_nextpattrn()
{
	static bool cheak = true;

	ran_num = return_rand_num();

	if (cheak == true)
	{
		if (ran_num != 4)
		{
			ran_num += 1;
		}

		else
		{
			ran_num = 0;
		}

		cheak = false;
	}

	/*----------------------------------------------------------------------------*/

	if (ran_num == 0)
	{
		NEXT_PATTRN = Pattrn_kind[ran_num];
	}

	else if (ran_num == 1)
	{
		NEXT_PATTRN = Pattrn_kind[ran_num];
	}

	else if (ran_num == 2)
	{
		NEXT_PATTRN = Pattrn_kind[ran_num];
	}

	else if (ran_num == 3)
	{
		NEXT_PATTRN = Pattrn_kind[ran_num];
	}

	else if (ran_num == 4)
	{
		NEXT_PATTRN = Pattrn_kind[ran_num];
	}
}

void update_keeppattrn()
{
	static bool first_call = true;

	if (first_call == true)
	{
		KEEP_PATTRN = Pattrn_kind[5];

		first_call = false;
	}

	else
	{
		if (keeppattrn_exist() == false)
		{
			KEEP_PATTRN = NOW_PATTRN;

			memory_ran_num = now_ran_num;

			update_nowpattrn(true);
		}

		else
		{
			NOW_PATTRN = KEEP_PATTRN;
			KEEP_PATTRN = Pattrn_kind[5];

			now_ran_num = memory_ran_num;
		}
	}
}

void update_nowpattrn(bool nextpattrn_change)
{
	if (nextpattrn_change == false)
	{
		ran_num = return_rand_num();

		now_ran_num = ran_num;

		if (ran_num == 0)
		{
			NOW_PATTRN = Pattrn_kind[ran_num];
		}

		else if (ran_num == 1)
		{
			NOW_PATTRN = Pattrn_kind[ran_num];
		}

		else if (ran_num == 2)
		{
			NOW_PATTRN = Pattrn_kind[ran_num];
		}

		else if (ran_num == 3)
		{
			NOW_PATTRN = Pattrn_kind[ran_num];
		}

		else if (ran_num == 4)
		{
			NOW_PATTRN = Pattrn_kind[ran_num];
		}
	}

	else
	{
		NOW_PATTRN = NEXT_PATTRN;

		now_ran_num = ran_num;

		update_nextpattrn();
	}
}

bool keeppattrn_exist()
{
	if (KEEP_PATTRN == Pattrn_kind[5])
	{
		return false;
	}

	else
	{
		return true;
	}
}

void rotate(bool turn_left)
{
	static bool first_call = true;

	if (first_call == true)
	{
		rotate_num = 0;

		first_call = false;
	}

	/*------------------------------------------------------------------------*/

	if (turn_left == true)
	{
		if (rotate_num == 0)
		{
			rotate_num = 3;
		}

		else
		{
			rotate_num -= 1;
		}
	}

	else
	{
		if (rotate_num == 3)
		{
			rotate_num = 0;
		}

		else
		{
			rotate_num += 1;
		}
	}
	/*---------------------------------------------------------------------*/

	if (now_ran_num == 0)
	{
		if (rotate_num == 0)
		{
			int** TEMP_00 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_00[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_00[i][0] = 0;
					TEMP_00[i][1] = 0;
					TEMP_00[i][2] = 0;
					TEMP_00[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_00[i][0] = 0;
					TEMP_00[i][1] = 0;
					TEMP_00[i][2] = 1;
					TEMP_00[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_00[i][0] = 1;
					TEMP_00[i][1] = 1;
					TEMP_00[i][2] = 1;
					TEMP_00[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_00[i][0] = 0;
					TEMP_00[i][1] = 0;
					TEMP_00[i][2] = 0;
					TEMP_00[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_00;
		}

		else if (rotate_num == 1)
		{
			int** TEMP_01 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_01[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_01[i][0] = 0;
					TEMP_01[i][1] = 1;
					TEMP_01[i][2] = 0;
					TEMP_01[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_01[i][0] = 0;
					TEMP_01[i][1] = 1;
					TEMP_01[i][2] = 0;
					TEMP_01[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_01[i][0] = 0;
					TEMP_01[i][1] = 1;
					TEMP_01[i][2] = 1;
					TEMP_01[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_01[i][0] = 0;
					TEMP_01[i][1] = 0;
					TEMP_01[i][2] = 0;
					TEMP_01[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_01;
		}

		else if (rotate_num == 2)
		{
			int** TEMP_02 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_02[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_02[i][0] = 0;
					TEMP_02[i][1] = 0;
					TEMP_02[i][2] = 0;
					TEMP_02[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_02[i][0] = 0;
					TEMP_02[i][1] = 1;
					TEMP_02[i][2] = 1;
					TEMP_02[i][3] = 1;
				}

				else if (i == 2)
				{
					TEMP_02[i][0] = 0;
					TEMP_02[i][1] = 1;
					TEMP_02[i][2] = 0;
					TEMP_02[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_02[i][0] = 0;
					TEMP_02[i][1] = 0;
					TEMP_02[i][2] = 0;
					TEMP_02[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_02;
		}

		else if (rotate_num == 3)
		{
			int** TEMP_03 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_03[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_03[i][0] = 0;
					TEMP_03[i][1] = 0;
					TEMP_03[i][2] = 0;
					TEMP_03[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_03[i][0] = 0;
					TEMP_03[i][1] = 1;
					TEMP_03[i][2] = 1;
					TEMP_03[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_03[i][0] = 0;
					TEMP_03[i][1] = 0;
					TEMP_03[i][2] = 1;
					TEMP_03[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_03[i][0] = 0;
					TEMP_03[i][1] = 0;
					TEMP_03[i][2] = 1;
					TEMP_03[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_03;
		}
	}

	else if (now_ran_num == 1)
		;

	else if (now_ran_num == 2)
	{
		if (rotate_num == 0)
		{
			int** TEMP_20 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_20[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_20[i][0] = 0;
					TEMP_20[i][1] = 1;
					TEMP_20[i][2] = 0;
					TEMP_20[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_20[i][0] = 0;
					TEMP_20[i][1] = 1;
					TEMP_20[i][2] = 0;
					TEMP_20[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_20[i][0] = 0;
					TEMP_20[i][1] = 1;
					TEMP_20[i][2] = 0;
					TEMP_20[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_20[i][0] = 0;
					TEMP_20[i][1] = 1;
					TEMP_20[i][2] = 0;
					TEMP_20[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_20;
		}

		else if (rotate_num == 1)
		{
			int** TEMP_21 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_21[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_21[i][0] = 0;
					TEMP_21[i][1] = 0;
					TEMP_21[i][2] = 0;
					TEMP_21[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_21[i][0] = 1;
					TEMP_21[i][1] = 1;
					TEMP_21[i][2] = 1;
					TEMP_21[i][3] = 1;
				}

				else if (i == 2)
				{
					TEMP_21[i][0] = 0;
					TEMP_21[i][1] = 0;
					TEMP_21[i][2] = 0;
					TEMP_21[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_21[i][0] = 0;
					TEMP_21[i][1] = 0;
					TEMP_21[i][2] = 0;
					TEMP_21[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_21;
		}

		else if (rotate_num == 2)
		{
			int** TEMP_22 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_22[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_22[i][0] = 0;
					TEMP_22[i][1] = 0;
					TEMP_22[i][2] = 1;
					TEMP_22[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_22[i][0] = 0;
					TEMP_22[i][1] = 0;
					TEMP_22[i][2] = 1;
					TEMP_22[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_22[i][0] = 0;
					TEMP_22[i][1] = 0;
					TEMP_22[i][2] = 1;
					TEMP_22[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_22[i][0] = 0;
					TEMP_22[i][1] = 0;
					TEMP_22[i][2] = 1;
					TEMP_22[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_22;
		}

		else if (rotate_num == 3)
		{
			int** TEMP_23 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_23[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_23[i][0] = 0;
					TEMP_23[i][1] = 0;
					TEMP_23[i][2] = 0;
					TEMP_23[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_23[i][0] = 0;
					TEMP_23[i][1] = 0;
					TEMP_23[i][2] = 0;
					TEMP_23[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_23[i][0] = 1;
					TEMP_23[i][1] = 1;
					TEMP_23[i][2] = 1;
					TEMP_23[i][3] = 1;
				}

				else if (i == 3)
				{
					TEMP_23[i][0] = 0;
					TEMP_23[i][1] = 0;
					TEMP_23[i][2] = 0;
					TEMP_23[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_23;
		}
	}

	else if (now_ran_num == 3)
	{
		if (rotate_num == 0)
		{
			int** TEMP_30 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_30[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_30[i][0] = 0;
					TEMP_30[i][1] = 0;
					TEMP_30[i][2] = 0;
					TEMP_30[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_30[i][0] = 0;
					TEMP_30[i][1] = 1;
					TEMP_30[i][2] = 0;
					TEMP_30[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_30[i][0] = 1;
					TEMP_30[i][1] = 1;
					TEMP_30[i][2] = 1;
					TEMP_30[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_30[i][0] = 0;
					TEMP_30[i][1] = 0;
					TEMP_30[i][2] = 0;
					TEMP_30[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_30;
		}

		else if (rotate_num == 1)
		{
			int** TEMP_31 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_31[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_31[i][0] = 0;
					TEMP_31[i][1] = 1;
					TEMP_31[i][2] = 0;
					TEMP_31[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_31[i][0] = 0;
					TEMP_31[i][1] = 1;
					TEMP_31[i][2] = 1;
					TEMP_31[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_31[i][0] = 0;
					TEMP_31[i][1] = 1;
					TEMP_31[i][2] = 0;
					TEMP_31[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_31[i][0] = 0;
					TEMP_31[i][1] = 0;
					TEMP_31[i][2] = 0;
					TEMP_31[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_31;
		}

		else if (rotate_num == 2)
		{
			int** TEMP_32 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_32[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_32[i][0] = 0;
					TEMP_32[i][1] = 0;
					TEMP_32[i][2] = 0;
					TEMP_32[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_32[i][0] = 0;
					TEMP_32[i][1] = 1;
					TEMP_32[i][2] = 1;
					TEMP_32[i][3] = 1;
				}

				else if (i == 2)
				{
					TEMP_32[i][0] = 0;
					TEMP_32[i][1] = 0;
					TEMP_32[i][2] = 1;
					TEMP_32[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_32[i][0] = 0;
					TEMP_32[i][1] = 0;
					TEMP_32[i][2] = 0;
					TEMP_32[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_32;
		}

		else if (rotate_num == 3)
		{
			int** TEMP_33 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_33[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_33[i][0] = 0;
					TEMP_33[i][1] = 0;
					TEMP_33[i][2] = 0;
					TEMP_33[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_33[i][0] = 0;
					TEMP_33[i][1] = 0;
					TEMP_33[i][2] = 1;
					TEMP_33[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_33[i][0] = 0;
					TEMP_33[i][1] = 1;
					TEMP_33[i][2] = 1;
					TEMP_33[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_33[i][0] = 0;
					TEMP_33[i][1] = 0;
					TEMP_33[i][2] = 1;
					TEMP_33[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_33;
		}
	}

	else if (now_ran_num == 4)
	{
		if (rotate_num == 0)
		{
			int** TEMP_40 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_40[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_40[i][0] = 0;
					TEMP_40[i][1] = 0;
					TEMP_40[i][2] = 0;
					TEMP_40[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_40[i][0] = 1;
					TEMP_40[i][1] = 1;
					TEMP_40[i][2] = 0;
					TEMP_40[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_40[i][0] = 0;
					TEMP_40[i][1] = 1;
					TEMP_40[i][2] = 1;
					TEMP_40[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_40[i][0] = 0;
					TEMP_40[i][1] = 0;
					TEMP_40[i][2] = 0;
					TEMP_40[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_40;
		}

		else if (rotate_num == 1)
		{
			int** TEMP_41 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_41[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_41[i][0] = 0;
					TEMP_41[i][1] = 0;
					TEMP_41[i][2] = 1;
					TEMP_41[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_41[i][0] = 0;
					TEMP_41[i][1] = 1;
					TEMP_41[i][2] = 1;
					TEMP_41[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_41[i][0] = 0;
					TEMP_41[i][1] = 1;
					TEMP_41[i][2] = 0;
					TEMP_41[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_41[i][0] = 0;
					TEMP_41[i][1] = 0;
					TEMP_41[i][2] = 0;
					TEMP_41[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_41;
		}

		else if (rotate_num == 2)
		{
			int** TEMP_42 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_42[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_42[i][0] = 0;
					TEMP_42[i][1] = 0;
					TEMP_42[i][2] = 0;
					TEMP_42[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_42[i][0] = 0;
					TEMP_42[i][1] = 1;
					TEMP_42[i][2] = 1;
					TEMP_42[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_42[i][0] = 0;
					TEMP_42[i][1] = 0;
					TEMP_42[i][2] = 1;
					TEMP_42[i][3] = 1;
				}

				else if (i == 3)
				{
					TEMP_42[i][0] = 0;
					TEMP_42[i][1] = 0;
					TEMP_42[i][2] = 0;
					TEMP_42[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_42;
		}

		else if (rotate_num == 3)
		{
			int** TEMP_43 = malloc(sizeof(int*) * PATTRN_SIZE);

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				TEMP_43[i] = malloc(sizeof(int) * PATTRN_SIZE);
			}

			for (int i = 0; i < PATTRN_SIZE; i++)
			{
				if (i == 0)
				{
					TEMP_43[i][0] = 0;
					TEMP_43[i][1] = 0;
					TEMP_43[i][2] = 0;
					TEMP_43[i][3] = 0;
				}

				else if (i == 1)
				{
					TEMP_43[i][0] = 0;
					TEMP_43[i][1] = 0;
					TEMP_43[i][2] = 1;
					TEMP_43[i][3] = 0;
				}

				else if (i == 2)
				{
					TEMP_43[i][0] = 0;
					TEMP_43[i][1] = 1;
					TEMP_43[i][2] = 1;
					TEMP_43[i][3] = 0;
				}

				else if (i == 3)
				{
					TEMP_43[i][0] = 0;
					TEMP_43[i][1] = 1;
					TEMP_43[i][2] = 0;
					TEMP_43[i][3] = 0;
				}
			}

			NOW_PATTRN = TEMP_43;
		}
	}
}

void buffer_clear()
{
	for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_BOARDPLAY_BUFFER_WIDTH; j++)
		{
			if (i == 0 || i == GAME_BOARDPLAY_BUFFER_HEIGHT - 1)
			{
				BOARD_BUFFER[i][j] = (-1);
			}

			else if (j == 0 || j == GAME_BOARDPLAY_BUFFER_WIDTH - 1)
			{
				BOARD_BUFFER[i][j] = (-1);
			}

			else
			{
				BOARD_BUFFER[i][j] = 0;
			}
		}
	}
}

int return_rand_num()
{
	srand(time(NULL));
	return rand() % 5;
}

void update_pattrnmove(bool down, bool bigdown, bool left, bool right, int bigbown_length)
{
	if (down == true)
	{
		buffer_clear();
		buffer_copy(true);

		Pattrn_value.main_spot.y += 1;

		for (int i = 0; i < Pattrn_value.dy; i++)
		{
			for (int j = 0; j < Pattrn_value.dx; j++)
			{
				if (NOW_PATTRN[i][j] == 1)
				{
					BOARD_BUFFER[i + Pattrn_value.main_spot.y][j + Pattrn_value.main_spot.x] = NOW_PATTRN[i][j];
				}
			}
		}
	}

	else if (bigdown == true)
	{
		buffer_clear();
		buffer_copy(true);

		Pattrn_value.main_spot.y += 1;

		for (int i = 0; i < Pattrn_value.dy; i++)
		{
			for (int j = 0; j < Pattrn_value.dx; j++)
			{
				if (NOW_PATTRN[i][j] == 1)
				{
					BOARD_BUFFER[i + Pattrn_value.main_spot.y][j + Pattrn_value.main_spot.x] = NOW_PATTRN[i][j];
				}
			}
		}
	}

	else if (left == true)
	{
		buffer_clear();
		buffer_copy(true);

		Pattrn_value.main_spot.x -= 1;

		for (int i = 0; i < Pattrn_value.dy; i++)
		{
			for (int j = 0; j < Pattrn_value.dx; j++)
			{
				if (NOW_PATTRN[i][j] == 1)
				{
					BOARD_BUFFER[i + Pattrn_value.main_spot.y][j + Pattrn_value.main_spot.x] = NOW_PATTRN[i][j];
				}
			}
		}
	}

	else if (right == true)
	{
		buffer_clear();
		buffer_copy(true);

		Pattrn_value.main_spot.x += 1;

		for (int i = 0; i < Pattrn_value.dy; i++)
		{
			for (int j = 0; j < Pattrn_value.dx; j++)
			{
				if (NOW_PATTRN[i][j] == 1)
				{
					BOARD_BUFFER[i + Pattrn_value.main_spot.y][j + Pattrn_value.main_spot.x] = NOW_PATTRN[i][j];
				}
			}
		}
	}
}

bool pattrn_fullstand()
{
	const int FILLED = 1;
	const int NOT_FILED = 0;

	int state;

	for (int i = 1; i < GAME_BOARDPLAY_BUFFER_HEIGHT - 1; i++)
	{
		state = NOT_FILED;

		for (int j = 1; j < GAME_BOARDPLAY_BUFFER_WIDTH - 1; j++)
		{
			if (BOARD_BUFFER[i][j] == 1)
			{
				state = FILLED;
			}

			else
			{
				state = NOT_FILED;

				break;
			}
		}

		if (state == FILLED)
		{
			update_score();
			update_level();

			remove_onelayer(i);
		}
	}
}

bool pattrn_alonestand()
{
	if (collision_cheak(0, false) == false)
	{
		pattrn_fullstand();

		return true;
	}

	else
	{
		return false;
	}
}

void remove_onelayer(int layer)
{
	for (int i = layer; i > 1; i--)
	{
		for (int j = 1; j < GAME_BOARDPLAY_BUFFER_WIDTH - 2; j++)
		{
			BOARD_BUFFER[i][j] = BOARD_BUFFER[i - 1][j];
		}
	}
}

void update_score()
{
	now_score += 100;
}

void update_level()
{
	if (now_level != 1)
		;

	else
	{
		if (now_score >= 1000 && now_score < 2000)
		{
			now_level = 2;
		}

		else if (now_score >= 2000 && now_score < 3000)
		{
			now_level = 3;
		}

		else if (now_score >= 3000 && now_score < 4000)
		{
			now_level = 4;
		}

		else if (now_score >= 4000 && now_score < 5000)
		{
			now_level = 5;
		}

		else if (now_score >= 5000 && now_score < 6000)
		{
			now_level = 6;
		}

		else if (now_score >= 6000 && now_score < 7000)
		{
			now_level = 7;
		}

		else if (now_score >= 7000 && now_score < 8000)
		{
			now_level = 8;
		}

		else if (now_score >= 8000 && now_score < 9000)
		{
			now_level = 9;
		}

		else if (now_score >= 9000 && now_score < 10000)
		{
			now_level = 10;
		}
	}
}

/*---------------------------------------------------------------------*/

int Render(bool first_call, bool cheak, int level, int signal)
{
	if (cheak == true)
	{
		render_nextpattrn_ani();
		render_keeppattrn_ani();
		render_score_ani();
		render_level_ani();
	}

	else
	{
		if (first_call == true)
		{
			if (level == 0)
			{
				return render_form_management(0);
			}

			else if (level == 1)
			{
				render_form_management(1);
				render_nextpattrn_ani();

				return (-1);
			}

			else
			{
				render_form_management(2);

				return (-1);
			}
		}

		else
		{
			if (signal == 0 || signal == 1 || signal == 2 || signal == 3)
			{
				Buffer_value TEMP = Struct_kind[0];

				for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
				{
					gotoxy(TEMP.main_spot.x, TEMP.main_spot.y + i);

					for (int j = 0; j < GAME_BOARDPLAY_BUFFER_WIDTH; j++)
					{
						if (BOARD_BUFFER[i][j] == (-1))
							;

						else if (BOARD_BUFFER[i][j] == 0)
						{
							printf("□");
						}

						else if (BOARD_BUFFER[i][j] == 1)
						{
							printf("■");
						}
					}
				}
			}
		}
	}
}



int render_form_management(int level)
{
	if (level == 0)
	{
		return render_title();
	}

	else if (level == 1)
	{
		render_board_form();
		render_score_form();
		render_keep_form();
		render_next_form();
		render_information_form();

		return (-1);
	}

	else
	{
		render_ending_form();

		return (-1);
	}
}

int render_title()
{
	int draw_state = 0;

	char* cmd_title = malloc(sizeof(char) * 13);
	char* cmd_size = malloc(sizeof(char) * 30);

	int** T = Alphabet_kind[8];
	int** E = Alphabet_kind[1];
	int** R = Alphabet_kind[6];
	int** I = Alphabet_kind[3];
	int** S = Alphabet_kind[7];


	//	set cmd name
	strcpy_s(cmd_title, 13, "title TETRIS");
	system(cmd_title);

	//	set cmd size
	strcpy_s(cmd_size, 30, "mode con cols=95 lines=32");
	system(cmd_size);


	while (draw_state < 4)
	{
		//draw screen
		if (draw_state == 0)		// game title
		{
			int i, j;

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (i == 0)
						printf("□");

					else if (j == 0)
						printf("\n□");
				}
			}

			//	T
			for (i = 0; i < 5; i++)
			{
				gotoxy(4, 2 + i);

				for (j = 0; j < 5; j++)
				{
					if (T[i][j] == 1)
						printf("□");

					else
						printf("  ");
				}

				printf("\n");
			}

			//	E
			for (i = 0; i < 5; i++)
			{

				gotoxy(15, 2 + i);

				for (j = 0; j < 5; j++)
				{
					if (E[i][j] == 1)
						printf("□");

					else
						printf("  ");
				}

				printf("\n");
			}

			//	T
			for (i = 0; i < 5; i++)
			{

				gotoxy(26, 2 + i);

				for (j = 0; j < 5; j++)
				{
					if (T[i][j] == 1)
						printf("□");

					else
						printf("  ");
				}

				printf("\n");
			}

			// R
			for (i = 0; i < 5; i++)
			{

				gotoxy(37, 2 + i);

				for (j = 0; j < 5; j++)
				{
					if (R[i][j] == 1)
						printf("□");

					else
						printf("  ");
				}

				printf("\n");
			}

			// I
			for (i = 0; i < 5; i++)
			{

				gotoxy(48, 2 + i);

				for (j = 0; j < 4; j++)
				{
					if (I[i][j + 1] == 1)
						printf("■");

					else
						printf("  ");
				}

				printf("\n");
			}

			// S
			for (i = 0; i < 5; i++)
			{

				gotoxy(55, 2 + i);

				for (j = 0; j < 5; j++)
				{
					if (S[i][j] == 1)
						printf("□");

					else
						printf("  ");
				}

				printf("\n");
			}

			for (i = 0; i < 3; i++)
			{
				gotoxy(63, 6 + i);

				for (j = 0; j < 3; j++)
				{
					if (j == 2 && i < 2)
						printf("    ■\n");

					else if (i == 2)
						printf("■");
				}
			}


			draw_state++;
		}

		else if (draw_state == 1)	// start / end button
		{
			for (int i = 0; i < 5; i++)
			{
				gotoxy(72, 2 + i);

				for (int j = 0; j < 19; j++)
				{
					if ((j == 0) || (j == 18))
						printf("|");

					else if ((j >= 1 && j <= 17) && (i == 0 || i == 2 || i == 4))
						printf("-");

					else if ((j >= 1 && j <= 17) && (i == 1 || i == 3))
						printf(" ");
				}

				printf("\n");
			}

			gotoxy(74, 3);
			printf("game strat : N");

			gotoxy(74, 5);
			printf("game exit  : M");

			draw_state++;
		}

		else if (draw_state == 2)	// draw information form
		{
			gotoxy(0, 11);

			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 91; j++)
				{
					if (j == 0 || j == 90)
						printf("|");

					else if ((j >= 1 && j <= 89) && (i == 0 || i == 19))
						printf("-");

					else if ((j >= 1 && j <= 89) && (i >= 1 && i <= 18))
						printf(" ");
				}

				printf("\n");
			}

			draw_state++;
		}

		else if (draw_state == 3)	// draw information detail
		{
			gotoxy(5, 13);
			printf("| Moving block |");

			gotoxy(7, 16);
			printf("◀   ▼   ▶");

			gotoxy(7, 18);
			printf(" A   S    D");



			gotoxy(40, 13);
			printf("| Keep block |");

			gotoxy(40, 16);
			printf("'push'   'pop'");

			gotoxy(47, 18);
			printf("L");



			gotoxy(73, 13);
			printf("| Rotate |");

			gotoxy(70, 16);
			printf("'left'   'right'");

			gotoxy(70, 18);
			printf("  O         P");



			gotoxy(8, 22);
			printf("| Pause |");

			gotoxy(2, 25);
			printf("'pause on'  'pause off'");

			gotoxy(12, 27);
			printf("T");



			gotoxy(92, 15);
			printf("M");
			gotoxy(92, 16);
			printf("A");
			gotoxy(92, 17);
			printf("D");
			gotoxy(92, 18);
			printf("E");
			gotoxy(92, 20);
			printf("B");
			gotoxy(92, 21);
			printf("Y");
			gotoxy(92, 23);
			printf("L");
			gotoxy(92, 24);
			printf("I");
			gotoxy(92, 25);
			printf("O");
			gotoxy(92, 26);
			printf("I");
			gotoxy(92, 27);
			printf("E");

			draw_state++;
		}
	}

	while (true)
	{
		int in_put = _getch();

		if (in_put == 'N' || in_put == 'n')				// game start
		{
			free(cmd_size);
			free(cmd_title);

			system("cls");

			return 0;
		}

		else if (in_put == 'M' || in_put == 'm')		// game exit
		{
			free(cmd_size);
			free(cmd_title);

			system("cls");

			return 1;
		}
	}
}

void render_board_form()
{
	char* cmd_size = malloc(sizeof(char) * 30);

	//	set cmd size
	strcpy_s(cmd_size, 30, "mode con cols=95 lines=40");
	system(cmd_size);

	free(cmd_size);

	for (int i = 0; i < GAME_BOARDFORM_BUFFER_HEIGHT; i++)
	{
		gotoxy(3, 2 + i);

		for (int j = 0; j < GAME_BOARDFORM_BUFFER_WIDTH; j++)
		{
			if (j == 0 || j == 15 || (j == 1 && (i >= 4 && i <= 35)) || (j == 14 && (i >= 4 && i <= 35)))
				printf("|");

			else if ((i == 4 || (i == 35 && (j >= 2 && j <= 13))) && (j > 0 && j < 15))
				printf("--");

			else if ((i == 36) && (j == 1 || j == 14))
				printf("-");

			else if ((i == 36) && (j >= 2 && j <= 13))
				printf("--");

			else if (i == 0 && (j >= 2 || j <= 13))
			{
				if (j == 2 || j == 13)
					printf("-");

				else
					printf("--");
			}

			else if (i == 2 && ((j >= 2 && j <= 3) || (j >= 12 && j <= 13)))
				printf("===");

			else if (i == 2 && (j == 1 || j == 14))
				printf("==");

			else if (i == 2 && j == 5)
				printf("T");

			else if (i == 2 && j == 6)
				printf("E");

			else if (i == 2 && j == 7)
				printf("T");

			else if (i == 2 && j == 8)
				printf("R");

			else if (i == 2 && j == 9)
				printf("I");

			else if (i == 2 && j == 10)
				printf("S");

			else if ((i >= 5 && i <= 33) && (j >= 2 && j <= 13))
				printf("□");

			else if ((i == 1 || i == 3) && (j >= 2 && j <= 13))
				printf("  ");

			else if ((i == 1 || i == 3) && (j == 1 || j == 14))
				printf(" ");

			else
				printf("  ");
		}
	}
}

void render_score_form()
{
	// 스코어창 틀 생성
	for (int i = 0; i < GAME_SCORE_BUFFER_HEIGHT; i++)
	{
		gotoxy(40, 2 + i);

		for (int j = 0; j < GAME_SCORE_BUFFER_WIDTH; j++)
		{
			if (j == 0 || j == 29)
				printf("|");

			else if ((j == 14 || j == 15) && (i >= 1 && i <= 5))
				printf("|");

			else if ((i == 0 || i == 6) && (j >= 1 && j <= 28))
				printf("-");

			else if (i == 2 && (j >= 1 && j <= 28))
				printf("=");

			else if (i == 1 && (j >= 5 && j <= 9))
			{
				if (j == 5)
					printf("S");

				else if (j == 6)
					printf("C");

				else if (j == 7)
					printf("O");

				else if (j == 8)
					printf("R");

				else if (j == 9)
					printf("E");
			}

			else if (i == 1 && (j >= 20 && j <= 24))
			{
				if (j == 20)
					printf("L");

				else if (j == 21)
					printf("E");

				else if (j == 22)
					printf("V");

				else if (j == 23)
					printf("E");

				else if (j == 24)
					printf("L");
			}

			else if (i == 4 && (j >= 5 && j <= 9))
				printf("0");

			else if (i == 4 && j == 22)
				printf("0");

			else
				printf(" ");
		}
	}
}

void render_keep_form()
{
	for (int i = 0; i < GAME_KEEPPATTRN_BUFFER_HEIGHT; i++)
	{
		gotoxy(56, 10 + i);

		for (int j = 0; j < GAME_KEEPPATTRN_BUFFER_WIDTH; j++)
		{
			if (j == 0 || j == 13)
				printf("|");

			else if ((i == 0 || i == 9) && (j >= 1 && j <= 12))
				printf("-");

			else if (i == 2 && (j >= 1 && j <= 12))
				printf("=");

			else if ((i >= 3 && i <= 8) && (j >= 1 && j <= 6))
				printf("□");

			else if (i == 1 && (j >= 5 && j <= 8))
			{
				if (j == 5)
					printf("    K");

				else if (j == 6)
					printf("E");

				else if (j == 7)
					printf("E");

				else if (j == 8)
					printf("P    ");
			}
		}
	}
}

void render_next_form()
{
	for (int i = 0; i < GAME_NEXTPATTRN_BUFFER_HEIGHT; i++)
	{
		gotoxy(40, 10 + i);

		for (int j = 0; j < GAME_NEXTPATTRN_BUFFER_WIDTH; j++)
		{
			if (j == 0 || j == 13)
				printf("|");

			else if ((i == 0 || i == 9) && (j >= 1 && j <= 12))
				printf("-");

			else if (i == 2 && (j >= 1 && j <= 12))
				printf("=");

			else if ((i >= 3 && i <= 8) && (j >= 1 && j <= 6))
				printf("□");

			else if (i == 1 && (j >= 5 && j <= 8))
			{
				if (j == 5)
					printf("    N");

				else if (j == 6)
					printf("E");

				else if (j == 7)
					printf("X");

				else if (j == 8)
					printf("T    ");
			}
		}
	}
}

void render_information_form()
{
	for (int i = 0; i < GAME_INFORMATION_BUFFER_HEIGHT; i++)
	{
		gotoxy(40, 23 + i);

		for (int j = 0; j < GAME_INFORMATION_BUFFER_WIDTH; j++)
		{
			if ((j == 0) || (j == GAME_INFORMATION_BUFFER_WIDTH - 1))
			{
				printf("|");
			}

			else if ((j == (GAME_INFORMATION_BUFFER_WIDTH / 2)) && (i > 0 && i < GAME_INFORMATION_BUFFER_HEIGHT))
			{
				printf(":");
			}

			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}

	gotoxy(43, 23);
	printf("----------- INFORMATION -----------");

	gotoxy(42, 26);
	printf("Move - A, D");

	gotoxy(42, 29);
	printf("Down - S");

	gotoxy(42, 32);
	printf("Rotate - O, P");

	gotoxy(62, 26);
	printf("Keep - L");

	gotoxy(62, 29);
	printf("Pause - T");
}

void render_ending_form()
{
	int ending_map[6][48] = { 0, };

	int** G = Alphabet_kind[2];
	int** A = Alphabet_kind[0];
	int** M = Alphabet_kind[4];
	int** E = Alphabet_kind[1];
	int** O = Alphabet_kind[5];
	int** V = Alphabet_kind[9];
	int** R = Alphabet_kind[6];

	system("cls");

	char* temp = malloc(sizeof(int) * 30);

	strcpy_s(temp, 30, "mode con cols=98 lines=32");
	system(temp);

	free(temp);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 92; j++)
		{
			if (j > 0 && j < 6)
			{
				ending_map[i][j] = G[i][j - 1];
			}

			else if (j > 6 && j < 12)
			{
				ending_map[i][j] = A[i][j - 7];
			}

			else if (j > 12 && j < 18)
			{
				ending_map[i][j] = M[i][j - 13];
			}

			else if (j > 18 && j < 24)
			{
				ending_map[i][j] = E[i][j - 19];
			}

			else if (j > 24 && j < 30)
			{
				ending_map[i][j] = O[i][j - 25];
			}

			else if (j > 30 && j < 36)
			{
				ending_map[i][j] = V[i][j - 31];
			}

			else if (j > 36 && j < 42)
			{
				ending_map[i][j] = E[i][j - 37];
			}

			else if (j > 42 && j < 48)
			{
				ending_map[i][j] = R[i][j - 43];
			}
		}
	}

	//////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 98; i++)
	{
		gotoxy(i, 8);
		printf("-");

		gotoxy(i, 22);
		printf("-");
	}

	gotoxy(44, 19);
	printf("SCORE : %d", now_score);

	gotoxy(44, 20);
	printf("LEVEL : %d", now_level);

	for (int i = 0; i < 6; i++)
	{
		gotoxy(0, 13 + i);

		for (int j = 0; j < 48; j++)
		{
			if (ending_map[i][j] == 1)
			{
				printf("□");
			}

			else
			{
				printf("  ");
			}
		}

		printf("\n");
	}

	int temp_count = 0;

	while (TRUE)
	{
		if (_kbhit())
		{
			exit(0);
		}

		//////////////////////////////////////////////////////////////////

		for (int i = 0; i < 6; i++)
		{
			gotoxy(0, 13 + i);

			for (int j = 0; j < 48; j++)
			{
				if (temp_count % 2 == 0)
				{
					if (ending_map[i][j] == 1)
					{
						if (j > 0 && j < 6)
						{
							printf("□");
						}

						else if (j > 6 && j < 12)
						{
							printf("■");
						}

						else if (j > 12 && j < 18)
						{
							printf("□");
						}

						else if (j > 18 && j < 24)
						{
							printf("■");
						}

						else if (j > 24 && j < 30)
						{
							printf("□");
						}

						else if (j > 30 && j < 36)
						{
							printf("■");
						}

						else if (j > 36 && j < 42)
						{
							printf("□");
						}

						else if (j > 42 && j < 48)
						{
							printf("■");
						}
					}

					else
					{
						printf("  ");
					}
				}

				else
				{
					if (ending_map[i][j] == 1)
					{
						if (j > 0 && j < 6)
						{
							printf("■");
						}

						else if (j > 6 && j < 12)
						{
							printf("□");
						}

						else if (j > 12 && j < 18)
						{
							printf("■");
						}

						else if (j > 18 && j < 24)
						{
							printf("□");
						}

						else if (j > 24 && j < 30)
						{
							printf("■");
						}

						else if (j > 30 && j < 36)
						{
							printf("□");
						}

						else if (j > 36 && j < 42)
						{
							printf("■");
						}

						else if (j > 42 && j < 48)
						{
							printf("□");
						}
					}

					else
					{
						printf("  ");
					}
				}
			}

			printf("\n");
		}

		temp_count++;

		Sleep(500);
	}
}

void render_nextpattrn_ani()
{
	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		gotoxy(43, 14 + i);

		for (int j = 0; j < PATTRN_SIZE; j++)
		{
			if (NEXT_PATTRN[i][j] == 0)
			{
				printf("□");
			}

			else if (NEXT_PATTRN[i][j] == 1)
			{
				printf("■");
			}
		}
	}
}

void render_keeppattrn_ani()
{
	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		gotoxy(59, 14 + i);

		for (int j = 0; j < PATTRN_SIZE; j++)
		{
			if (KEEP_PATTRN[i][j] == 0)
			{
				printf("□");
			}

			else if (KEEP_PATTRN[i][j] == 1)
			{
				printf("■");
			}
		}
	}
}

void render_score_ani()
{
	if (now_score < 1000)
	{
		gotoxy(47, 6);
		printf("%d", now_score);
	}

	else if (now_score >= 1000 && now_score < 10000)
	{
		gotoxy(46, 6);
		printf("%d", now_score);
	}

	else
	{
		gotoxy(45, 6);
		printf("%d", now_score);
	}
}

void render_level_ani()
{
	gotoxy(62, 6);
	printf("%d", now_level);
}

/*---------------------------------------------------------------------*/

void Realease()
{
	/////////////////////////////////////////////////////////////////////////
	/* init_buffer realease */
	/////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < GAME_BOARDPLAY_BUFFER_HEIGHT; i++)
	{
		free(BOARD_BUFFER[i]);
		free(HIDING_BUFFER[i]);
	}

	free(BOARD_BUFFER);
	free(HIDING_BUFFER);



	/////////////////////////////////////////////////////////////////////////
	/* init_struct realease */
	/////////////////////////////////////////////////////////////////////////

	Buffer_value buffer_realease = Struct_kind[0];

	free(buffer_realease.main_spot.x);
	free(buffer_realease.main_spot.y);
	free(buffer_realease.dx);
	free(buffer_realease.dy);

	/*---------------------------------------------------------------------*/

	int** pattrn_realease;

	pattrn_realease = Pattrn_kind[0];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);


	pattrn_realease = Pattrn_kind[1];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);


	pattrn_realease = Pattrn_kind[2];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);


	pattrn_realease = Pattrn_kind[3];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);


	pattrn_realease = Pattrn_kind[4];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);


	pattrn_realease = Pattrn_kind[5];

	for (int i = 0; i < PATTRN_SIZE; i++)
	{
		free(pattrn_realease[i]);
	}

	free(pattrn_realease);

	/*---------------------------------------------------------------------*/

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		free(Alphabet.A[i]);
		free(Alphabet.E[i]);
		free(Alphabet.G[i]);
		free(Alphabet.I[i]);
		free(Alphabet.M[i]);
		free(Alphabet.O[i]);
		free(Alphabet.R[i]);
		free(Alphabet.S[i]);
		free(Alphabet.T[i]);
		free(Alphabet.V[i]);
	}

	free(Alphabet.A);
	free(Alphabet.E);
	free(Alphabet.G);
	free(Alphabet.I);
	free(Alphabet.M);
	free(Alphabet.O);
	free(Alphabet.R);
	free(Alphabet.S);
	free(Alphabet.T);
	free(Alphabet.V);

	/*---------------------------------------------------------------------*/


}

/*---------------------------------------------------------------------*/

int switch_global_signal(int input)
{
	switch (input)
	{
	case 's':
	{
		return 1;
	}

	case 'a':
	{
		return 2;
	}

	case 'd':
	{
		return 3;
	}

	case 'l':
	{
		return 4;
	}

	case 'o':
	{
		return 5;
	}

	case 'p':
	{
		return 6;
	}

	case 't':
	{
		return 7;
	}
	}
}

void gotoxy(int x, int y)
{
	COORD Pos;

	Pos.X = x;
	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}