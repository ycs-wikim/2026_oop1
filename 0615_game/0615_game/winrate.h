#pragma once

/// 승률에 관련된 정보와 기능을 담당
/// => 12전 7승 3무 2패
class winrate
{
private:
	int m_winCnt;
	int m_loseCnt;
	int m_drawCnt;
public:
	winrate();

	/// get/set 메서드

	/// set 메서드들 : private 멤버의 값을 외부에서
	///					접근할 수 있도록 제공된 인터페이스
	void addWinCnt();
	void addLoseCnt();
	void addDrawCnt();

	/// get 메서드들 : private 멤버 값을 외부에서 받을 수 있도록
	///					제공되는 인터페이스
	int getWinCnt();
	int getLoseCnt();
	int getDrawCnt();
};

