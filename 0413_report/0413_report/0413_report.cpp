// 0413_report.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "add.h"
#include "minus.h"
#include "mul.h"


int main()
{
    int add = addFunc(3, 9);
    int minus = minusFunc(15, 5);
    int mul = mulFunc(45, 78);

    printf("ADD[ %d ]\n", add);

    std::cout << "Hello World!\n";
}
