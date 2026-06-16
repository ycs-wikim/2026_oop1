#pragma once

#include "board.h"
#include "Random.h"
#include "winrate.h"


class Game : public board, public winrate
{
private:
	const char* m_winlose[3] = { STRING_WIN, STRING_LOSE, STRING_DRAW };
	const char* m_games[3] = { STRING_SCIS, STRING_ROCK, STRING_PAPER };
	Random m_rnd;
public:
	int normalGame(int v);
	void printGame(int user, int com);
	void printGameInfo();
};

