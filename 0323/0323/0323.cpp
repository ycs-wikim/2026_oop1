// 0323.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/// 매크로 함수 : 절대 사용하지 말것!!!
/// 전처리기 : 매크로 함수 => 해당 위치의 코드를 단순 교체
/// 단순 교체 : 이후의 다양한 문제 해결이 어려워진다!
#define SWAP(a, b)  { a ^= b; b ^= a; a ^= b; }


int Add(int a, int b)
{
    return a + b;
}


int main()
{
    /// 특정 예약어를 사용하는 문장 구조의 특징
    /// 예약어( ... ) ==> 바로 뒤 한문장만 예약어가 갖는다.
    /// if( 조건식 ) ... ;
    int a = 0;
    int b = 1;

    if (0)              /// if의 조건식은 거짓
    {
        SWAP(a, b);
    }
    /*
        a ^= b;
    b ^= a;
    a ^= b;
    */

    cout << a << " " << b << endl;

    /// switch ~ case 문장
    /// 구조 : switch( 변수 ) { case 상수: ... default: break; }
    switch (a)
    {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        default:        /// 생략해도 된다라고 알려준다!!!
                        /// 최근 형상 관리 도구에서는 생략시 오류 처리!!!
            break;
    }
    /// switch~case 문장은 QA/QC 쪽에서 매우 싫어하는 코드 작성법.
    /// 1. 의도 확인이 어려움.
    /// 2. 코드 양의 증가가 발생 (if를 썼을 때 대비 몇배나 코드 증가)
    /// 3. 코드 양이 증가하면 느려짐.
    Add(1, 2);
    Add(1, 2);
    Add(1, 2);

    switch (Add(1, 2))
    {
        case 0:     // if( (t == 0) || (t == 1) || (t == 2) ... )
        case 1:
        case 2:
        case 3:
            a = 3;
            b = 7;
            if (1)
                cout << Add(a, b) << endl;
        case 4:
            a = 30;
            b = 70;
            if (1)
                cout << Add(a, b) << endl;
    }

    /// 여러 문장들을 반복하고자 하는 경우 반드시 필요한 3가지 구성요소
    /// 초기식, 조건식, 제어식(증감식) 3가지 존재해야만 반복이 가능하다!
    /// 생략이 가능한 구성 요소 : 초기식, 조건식, 제어식
    /// 생략 예 ) for(;;){}    ==> 무한 반복
    
    for(int i = 0; i < 10; i++) { }

    int i = 0;                  /// 초기식
    for (; i < 10;)             /// 조건식
    {
        /*
        if (i == 8)             /// 조건식
            break;
        else
            i++;                /// 제어식
        */
        i++;                    /// 제어식
    }
    /// 위의 for문 구조를 다른 형식으로 표현하면
    while (i < 10)
    {
        i++;
    }

    /// for : 정확한 횟수를 반복해야 하는 경우.
    /// while : 무한반복인 경우.
    /// do~while : 조건 확인을 위해 사용
    /*  do~while을 별도로 만드는 방법 예제
    while (true)
    {
        int r = Add(3, 5);
        if (r == 3)
            break;
    }
    */

    /// 여러분들이 게임을 합니다. 역대급 이벤트 발생~
    /// 조건 5개를 만족하면 전설 퀘스트를 받을 수 있는 이벤트.
    int event[5] = { 1, 0, 0, 0, 0 };   /// 조건 값이 1이면 이미 진행. 0이면 안 진행

    int f = 0;
    do
    {
        if (event[0] == 0)
            break;
        if (event[1] == 0)
        {
            f = 1;
            break;
        }
        if (event[2] == 0)
            break;
        if (event[3] == 0)
            break;
        if (event[4] == 0)
            break;
        /// 이 위치에 도달했다. ==> 조건을 만족했다.
        printf("옛다 전설 퀘스트~\n");
        return 0;

    } while (true);
    /// 조건을 만족하지 못하였다.
    printf("넌 아직 준비가 안됐다[ %d ] ~\n", f);

    for (int i = 5; i < 10; i++)
    {
        for (int j = 6; j < 10; j++)
            cout << i << " * " << j << " = " << i * j << endl;
        cout << endl;
    }

    /// break : 반복문에서 가장 가까운 반복 루프를 빠져나간다.
    /// continue : 반복문에서 가장 가가운 반복의 시작 위치로 이동한다.
    /// 가장 가깝다 ==> 나를 포함하고 있는 바로 위의 반복문
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            continue;   /// for( int j = 0; ... ) 이 반복문의 시작 위치로 이동.
            break;      /// for( int j = 0; ... ) 이 반복문을 빠져나간다.
        }
        continue;       /// for (i = 0; ... ) 위치로 이동
        break;          /// for (i = 0; ... ) 빠져나간다.
    }

    /// 과제 관련한 소스
    for (int k = 0; k < 5 ; k++)      /// 라인 수를 계산하는 반복문
    {
        for (int j = 0; j < 5 - k; j++)
            printf("*");
        printf("\n");
    }


    std::cout << "Hello World!\n";
}
