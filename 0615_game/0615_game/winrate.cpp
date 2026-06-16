#include "winrate.h"

winrate::winrate()
{
	m_winCnt = 0;
	m_loseCnt = 0;
	m_drawCnt = 0;
}

void winrate::addWinCnt()
{
	m_winCnt++;
}

void winrate::addLoseCnt()
{
	m_loseCnt++;
}

void winrate::addDrawCnt()
{
	m_drawCnt++;
}

int winrate::getWinCnt()
{
	return m_winCnt;
}

int winrate::getLoseCnt()
{
	return m_loseCnt;
}

int winrate::getDrawCnt()
{
	return m_drawCnt;
}

