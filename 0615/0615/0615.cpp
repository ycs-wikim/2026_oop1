// 0615.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <windows.h>


/// 함수의 오버로딩 : 인수/매개변수의 차이
/*
int add(int a, int b){}
float add(float a, float b) {}
*/


/// 템플릿 프로그래밍 : 형식을 만드는 프로그래밍 방식
template <typename T>
T add(T a, T b)
{
    T c;
    T d;
    c = a + b;
    d = c * 10;
    std::cout << d << std::endl;
    return c;
}

/// namespace는 논리적인 코드 묶음
namespace ASDF
{
    int g_x;

    void asdf()
    {
        printf("asdf\n");
    }
}

namespace ASDF
{
    class CTest
    {
    public:
        int m_x;
    };
    void bbb()
    {
        printf("bbb\n");
    }
}


/// 스레드 함수 : 형식이 고정
DWORD WINAPI pig(LPVOID param)
{
    for (int i = 0; i < 100; i++)
    {
        printf("i = %d\n", i);
        Sleep(100);
    }

    ExitThread(0);
    return 0;
}


int main()
{
    /// 스레드 생성
    CreateThread(NULL, 0, pig, NULL, 0, NULL);
    /// 20초간 대기
    Sleep(20000);

    using namespace ASDF;
    asdf();
    bbb();
    ASDF::asdf();
    CTest a;

    std::cout << add(355, 877) << std::endl;
    //std::cout << add(355, 877.9) << std::endl;
    std::cout << add('3', '8') << std::endl;
    std::cout << add(355.87, 8.77) << std::endl;
    std::cout << "Hello World!\n";
}
