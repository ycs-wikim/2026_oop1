#pragma once

#define GAME_WIN            0
#define GAME_LOSE           1
#define GAME_DRAW           2

#define GAME_SCISSORS       0
#define GAME_ROCK           1
#define GAME_PAPER          2

#define STRING_WIN          "이겨따"
#define STRING_LOSE         "져따"
#define STRING_DRAW         "비겨따"

#define STRING_SCIS         "가위"
#define STRING_ROCK         "바위"
#define STRING_PAPER        "보"


class board
{
private:
    int m_board[3][3];

public:
    board();
    int getGameResult(int user, int com);
/*
    const char* game[3][3] = {
    "비겼다", "졌다", "이겼다",
    "이겼다", "비겼다", "졌다",
    "졌다", "이겼다", "비겼다"
    };
*/

};

