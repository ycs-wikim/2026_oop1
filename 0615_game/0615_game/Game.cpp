#include "Game.h"

#include <iostream>

int Game::normalGame(int v)
{
	return m_rnd.getRandomValue(v);
}


void Game::printGame(int user, int com)
{
	printf("»ç¶÷[ %s ] ÄÄÇ»ÅÍ[ %s ] : °á°ú[ %s ]\n", 
		m_games[ user ], m_games[ com ],
		m_winlose[ getGameResult(user, com) ]);
}


void Game::printGameInfo()
{
	printf("%dÀü %d½Â %d¹« %dÆÐ [ ½Â·ü : %1.lf %% ]\n",
		getWinCnt() + getLoseCnt() + getDrawCnt(),
		getWinCnt(), getDrawCnt(), getLoseCnt(),
		(float)getWinCnt() / (getWinCnt() + getLoseCnt() + getDrawCnt()) * 100
	);
}
