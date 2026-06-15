// 0615_game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
/// 랜덤 함수 사용을 위한 헤더
#include <stdlib.h>
/// 시간 획득 함수 - 랜덤 시드 값 변경
#include <time.h>


int main()
{
    const char* game[3][3] = {
        "비겼다", "졌다", "이겼다",
        "이겼다", "비겼다", "졌다",
        "졌다", "이겼다", "비겼다"
    };


    /// 시드 값 변경
    srand(time(NULL));

    int user;
    int com;
    /// 사용자 입력
    cout << "가위(0), 바위(1), 보(2) : ";
    cin >> user;


    /// 컴퓨터 값 : 랜덤 값 획득
    com = rand() % 3;
    printf("com : %d - user - %d : %s\n", com, user, game[user][com]);

    std::cout << "Hello World!\n";
}
