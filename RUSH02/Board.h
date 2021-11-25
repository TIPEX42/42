#ifndef BOARD_H
#define BOARD_H

enum CellState : int
{
	Empty, Other, Us
}

class Board
{
public:
	inline static int	*board;

	inline static void	Initialize(int width, int height);
	inline static int GetCell(int x, int y);

}

#endif