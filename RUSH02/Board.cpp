#include "Board.h"

void	Board::Initialize(int width, int height)
{
	board = new int[width * height];
	for (int i = 0; i < width * height; i++)
	{
		board[i] = Empty;
	}
}

int		Board::GetCell(int x, int y)
{
	
}