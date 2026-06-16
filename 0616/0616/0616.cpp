// 0616.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

#include <stack>
#include <vector>

/// 배열의 특징 : 연속 메모리, 포인터, 주소, 상수, 개수가 고정
//int arr[8000] = { 0, };


/// STL(Standard Template Library)
///  - 사용할 줄 안다. : 이제 조금 C++을 해봤구나... 정도
///  - 구현을 해봤어요 : 중급
///  - C++ 표준

class CTest
{
public:
    int m_x;
    int m_y;
};

/// 스택 선언
stack<CTest> g_stack;
vector<CTest> g_vec;


int main()
{
    CTest c1;
    c1.m_x = 99;
    c1.m_y = 88;
    g_stack.push(c1);
    g_vec.push_back(c1);

    CTest c2;
    c2.m_x = 11;
    c2.m_y = 22;
    g_stack.push(c2);
    g_vec.push_back(c2);

    int cnt = g_stack.size();
    for (int i = 0; i < cnt; i++)
    {
        CTest cc = g_stack.top();
        printf("%d : %d - %d\n", i + 1, cc.m_x, cc.m_y);
        g_stack.pop();
    }

    for (int i = 0; i < g_vec.size(); i++)
    {
        CTest cc = g_vec[i];
        printf("%d : %d - %d\n", i + 1, cc.m_x, cc.m_y);
        printf("%d : %d - %d\n", i + 1, g_vec[i].m_x, g_vec[i].m_y);
    }

    std::cout << "Hello World!\n";
}
