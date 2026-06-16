// 0615_game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
/// 랜덤 함수 사용을 위한 헤더
#include <stdlib.h>
/// 시간 획득 함수 - 랜덤 시드 값 변경
#include <time.h>

#include "Game.h"


int main()
{
    Game game;
    int user;
    int com;

    for (int i = 0; i < 5; i++)
    {
        /// 사용자 입력
        cout << "가위(0), 바위(1), 보(2) : ";
        //cin >> user;
        user = game.normalGame(3);

        /// 값의 범위 확인
        if ((user < GAME_SCISSORS) || (user > GAME_PAPER))
        {
            printf("잘못 입력했음: %d\n", user);
            return -9;
        }

        /// 컴퓨터 값 : 랜덤 값 획득
        com = game.normalGame(3);

        int res = game.getGameResult(user, com);

        /// 승패를 확인
        switch (res)
        {
        case GAME_WIN:
            game.addWinCnt();
            break;
        case GAME_LOSE:
            game.addLoseCnt();
            break;
        case GAME_DRAW:
            game.addDrawCnt();
            break;
        }

        game.printGame(user, com);
    }
    game.printGameInfo();

    std::cout << "Hello World!\n";
}
