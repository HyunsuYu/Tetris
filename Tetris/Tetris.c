#include "Tetris.h"

void Tetris(void)
{
	Init();

	if (Render(true, false, 0, 0) == 0)
	{
		Update(true, false, 0);
		Render(true, false, 1, 0);

		while (true)
		{
			if (_kbhit())
			{
				int input = _getch();

				Update(false, false, switch_global_signal(input));
				Render(false, false, 1, switch_global_signal(input));

			}

			Update(false, false, 0);
			Render(false, false, 1, 0);

			Update(false, true, 0);
			Render(false, true, 1, 0);

			Sleep(190);
		}
	}

	else
	{
		Render(true, false, 2, 0);
		Realease();
	}
}