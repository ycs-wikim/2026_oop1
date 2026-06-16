#include "board.h"

board::board()
{
	m_board[0][0] = GAME_DRAW;
	m_board[0][1] = GAME_LOSE;
	m_board[0][2] = GAME_WIN;

	m_board[1][0] = GAME_WIN;
	m_board[1][1] = GAME_DRAW;
	m_board[1][2] = GAME_LOSE;

	m_board[2][0] = GAME_LOSE;
	m_board[2][1] = GAME_WIN;
	m_board[2][2] = GAME_DRAW;
}

int board::getGameResult(int user, int com)
{
	return m_board[user][com];
}


