// 0413.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>

using namespace std;

/// typedef A B ==> 앞으로 A는 B의 자료형 사용된다.
typedef
/// A의 시작
struct STag
{
    /// 구조체의 멤버 변수는 다양한 자료형을 지원
    int m;
    char str1[4];
    const char* str2;
}
/// A의 끝
SType;

typedef struct ASDF
{
    char aa;
    int x;
    int dddd;
    char b[1024];
    int* ptr;
    ASDF* ad;
    SType st;
    int y;
    int z;
    char c;     /// 패딩이 발생하여 4byte로 변경
                /// CPU 연산 때문에 패딩을 수행
    char t[1024];
} InT;


/**
* 함수 == 기능
* 언어에서는 다양한 사용자 정의 함수를 만들고 사용 가능
* 사용자 정의 함수를 선언하는 방법
* 반환값자료형 함수이름(매개변수1, 인수2, ...)
* {
*   /// 함수가 수행할 내용 ==> 기능(구현 내용)
* }
* 
* 반환값자료형 : 처리가 완료된 다음 알아야 하는 정보
*       알아야 하는 정보가 없는 경우 void 반환 값 설정
*       반환 값이 void라면 실패하지 않는다.
* 
* 함수 이름 : 기능을 설명하는 내용으로 구성
* 
* 인수1~인수N : 기능 수행을 위해 필요한 정보
* 
* 구현 내용 : 기능을 그대로 코드로 작성한 것
* 
* 함수 호출 3가지 방법
* 1. Call By Value : 값 복사에 의한 호출
* 2. Call By Reference : 참조에 의한 호출
* 3. Call By Address : 주소에 의한 호출
* 
* 위의 구조체를 이용해서 3가지 방식을 모두 호출해보는 예제
* 
* ***** 함수 호출 방식은 인수/매개변수에 따라 달라진다.
*   + 함수의 기능이 필요한 방식에 따라 매개변수가 결정된다.
*/

/// 1. Call By Value : 값을 복사하여 기능 수행
///     ==> 원본에는 영향이 없다!
/// INT asdf = a;
void callByValue(InT asdf)
{
    printf("%s: %p[ %lld ]\n", __FUNCTION__, &asdf, sizeof(asdf));
    asdf.x = 9;
    asdf.y = 99;
    asdf.z = 999;
}

/// 2. Call By Reference : 참조에 의한 호출
///     reference 변수 : 선언 시 즉시 초기화
///                 일반 변수와 동일하게 사용 가능
///     컴파일러가 내부에서 주소를 동일하게 설정해준다.
/// InT& a = a;
void callByReference(InT& a)
{
    printf("%s: %p[ %lld ]\n", __FUNCTION__, &a, sizeof(a));
    a.x = 9;
    a.y = 99;
    a.z = 999;
}


/// 3. Call By Address 호출
/// InT* a = &a;
void callByAddress(InT* a)
{
    printf("%s: %p[ %lld ]\n", __FUNCTION__, a, sizeof(a));
    a->x = 1;
    a->y = 11;
    a->z = 111;
}

/// 4. Call By Mixed
void callByMixed(int a, int& b, int* c)
{
    a = 19;
    b = 119;
    *c = 1119;
}


void functionCall()
{
    InT a;         /// 구조체 변수 선언
    /// 구조체 멤버 초기화
    a.x = 10;
    a.y = 20;
    a.z = 30;
    printf("%s: %d %d %d\n", __FUNCTION__, a.x, a.y, a.z);
    /// 1. Call By Value 호출 : 값 변경이 불가능!!!
    callByValue(a);
    printf("%s: %d %d %d\n", __FUNCTION__, a.x, a.y, a.z);
    /// 2. Call By Reference 호출 : 값 변경 가능!!!
    callByReference(a);
    printf("%s: %p : %lld\n", __FUNCTION__, &a, sizeof(a));
    printf("%s: %d %d %d\n", __FUNCTION__, a.x, a.y, a.z);
    /// 3. Call By Address 호출 : 값 변경 가능!!!
    callByAddress(&a);
    printf("%s: %d %d %d\n", __FUNCTION__, a.x, a.y, a.z);
    /// 4. Call By Mixed 호출
    callByMixed(a.x, a.y, &a.z);
    printf("%s: %d %d %d\n", __FUNCTION__, a.x, a.y, a.z);

}


void lif(LARGE_INTEGER& lia)
{
    lia.LowPart = 33;
    lia.HighPart = 99;
    printf("L[ %d ] H[ %d ]\n", lia.LowPart, lia.HighPart);
    lia.QuadPart = 9999;
    printf("L[ %d ] H[ %d ]\n", lia.LowPart, lia.HighPart);
}


int main()
{
    LARGE_INTEGER lia;
    lif(lia);

    SType s1;
    s1.m = 2017;
    memcpy(s1.str1, "C++", 4);
    s1.str2 = "World";

    SType s2;
    /// 동일한 구조체의 변수끼리는 대입 연산이 가능!!!
    s2 = s1;

    cout << s2.m << " " << s2.str1 << " " << s2.str2 << endl;
    /// 예제 7-4 완료

    /// 구조체 변수의 선언
    ASDF asdf, bbb;
    /// 구조체형 포인터 변수 선언
    ASDF* pp = &asdf;
    /// 구조체를 가리킬 포인터를 선언
    int* ppp = (int*) & asdf;   /// 명시적 형변환

    printf("ASDF [ %p ] x[ %p ]\n", &asdf, &asdf.x);

    /// 구조체 멤버의 초기 값 설정
    /// 구조체 메모리는 배열과 같이 직선상에 놓여 있다.
    asdf.x = 10;
    *(ppp + 0) = 99;
    asdf.y = 20;
    ppp[1] = 999;
    asdf.z = 30;
    *(ppp + 2) = 9;

    pp->x = 11;
    pp->y = 111;
    pp->z = 1111;

    /// 동일한 구조체 변수는 대입 연산이 가능!!!
    bbb = asdf;
    //bbb == asdf;    /// 비교 연산 불가 : 비교 자체 불가능
    if (bbb.z == asdf.y);
    if (bbb.x > asdf.y);

    printf("ASDF size: %lld\n", sizeof(asdf));
    printf("X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    functionCall();

    std::cout << "Hello World!\n";
}
