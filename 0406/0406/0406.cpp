// 0406.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void asdf(int** ptr__)
{
    *ptr__ = (int*)malloc(sizeof(int));
}

void bbb(int* ptr__)
{
    *ptr__ = 9999;
}

int g_x;

int main()
{
    int* ptr = nullptr;

    if (0)
    {
        /// return;
    }
    asdf(&ptr);
    *ptr = 33;
    printf("ptr : %d\n", *ptr);
    bbb(ptr);
    printf("ptr : %d\n", *ptr);
    free(ptr);

    /// void 자료형 : 크기를 지정할 수 없다.
    char a;     /// 메모리 1byte를 할당한다.
    //void v;     /// 불완전한 자료형. 크기가 없기 때문.

    /// void 포인터 : 예제 5-11
    char c;
    int i;
    double d;
    /*
    /// 동일한 자료형으로만 주소를 받을 수 있다.
    /// 포인터의 자료형으로 메모리를 접근하기 때문.
    int* i1 = &c;
    char* c1 = &d;
    double* d1 = &i;
    */

    /// void*의 용도 : 주소만을 가리키는 용도 : 범용 포인터
    void* p1 = &c;
    void* p2 = &i;
    void* p3 = &d;
    /// void*는 자료형의 크기가 없어서 연산자체가 불가능!
    //*p1 = 3;
    //*p1++;

    /// 다중 포인터
    /// *의 개수의 의미 : 주소를 몇번 거쳐야 하는지
    int iii = 0;
    int* p = &iii;          /// int* = &int
    int* p11 = p;           /// int* = int*
    int** pp = &p;          /// int** = &int*
    int** p12 = pp;         /// int** = int**
    int*** ppp = &pp;       /// int*** = &int**
    ///int*** p3 = &iii;
    int**** pppp = &ppp;    /// int**** = &int***

    printf("g_x : %p\n", &g_x);
    printf("iii 주소: %p\n", &iii);
    printf("p 주소: %p %p\n", &p, p);
    printf("pp 주소: %p %p %p\n", &pp, *pp, pp);
    printf("ppp 주소: %p %p %p %p\n", &ppp, **ppp, *ppp, ppp);
    printf("pppp 주소: %p %p %p %p %p\n", &pppp, ***pppp, **pppp, *pppp, pppp);


    iii = 9;
    printf("iii : %d\n", iii);
    *p = 99;                /// *p == iii
    printf("iii : %d - %d\n", iii, *p);
    **pp = 999;             /// **pp == iii
                            /// *pp == p
    printf("iii : %d - %d - %d\n", iii, *p, **pp);
    ***ppp = 9999;
    printf("iii : %d - %d - %d - %d\n", iii, *p, **pp, ***ppp);
    ****pppp = 99999;
    printf("iii : %d - %d - %d - %d - %d\n", iii, *p, **pp, ***ppp, ****pppp);


    /// 참조 타입(reference)
    /// 포인터가 너무 어려운 경우 주소를 활용하는 자료형
    /// 포인터와 동일하게 동작한다.
    int aaa = 999;
    /// 참조 타입 변수 선언 : 자료형 &변수명
    int& aaap = aaa;
    /// 주의점 : 선언과 동시에 변수로 초기화
    /*
    int& aaaa;
    int& aaa3 = 8;
    int& aaaa1 = nullptr;
    int& aaaa2 = NULL;
    */

    aaap = 111;
    printf("aaa/p : %d %d\n", aaa, aaap);

    /// 배열(변수명 == 주소값) == 포인터
    /// 배열과 포인터의 결정적인 차이점
    ///  ==> 배열 변수명이 갖는 특징 : 상수화
    int array[5] = { 11, 22, 33, 44, 55 };
    int* pptr = array;  /// int* == &int*(=> int**)

    //array = pptr; /// 상수 값 대입 불가
    
    int* aptr = nullptr;
    aptr = (int*)malloc(sizeof(int) * 5);
    aptr[0] = 99;
    *(aptr + 1) = 9;
    aptr[2] = 999;
    *(aptr + 3) = 9999;
    aptr[4] = 9900;
    printf("Aptr : %d %d %d %d %d\n",
        aptr[0], aptr[1], aptr[2], aptr[3], aptr[4]);
    printf("Aptr : %d %d %d %d %d\n",
        *(aptr + 0), *(aptr + 1), *(aptr + 2),
        *(aptr + 3), *(aptr + 4));
    free(aptr);
    
    printf("array : %d %d %d %d %d\n",
        array[0], array[1], array[2], array[3], array[4]);
    printf("array : %d %d %d %d %d\n",
        *(array + 0), *(array + 1), *(array + 2),
        *(array + 3), *(array + 4));

    printf("pptr : %d %d %d %d %d\n",
        pptr[0], pptr[1], pptr[2], pptr[3], pptr[4]);
    printf("pptr : %d %d %d %d %d\n",
        *(pptr + 0), *(pptr + 1), *(pptr + 2),
        *(pptr + 3), *(pptr + 4));

    /// 배열 : 동일한 특성과 값을 갖는 변수들을 한꺼번에 선언할 수 있다.
    //int sub1_1, sub1_2, ..., sub1_40;
    //int sub2_1, sub2_2, ..., sub2_40;
    /// 특성(과목 점수), 값(0~100점)
    int sub1[40] = { 78, 22, };

    //sub1[55] = 99;

    /// 구조체 Vs. 배열
    /// 서로 다른 자료형을 한꺼번에 선언한다.
    /// 구조체 선언 : 예약어 구조체이름
    /// { 자료형 선언1; 자료형 선언2; ... 
    /// } ;
    struct character
    {
        char name[20];          /// 내 캐릭터 이름
        int level;              /// 나의 레벨
        int hp;                 /// 나의 체력
        char pat_name[20];      /// 펫 이름
    } myC;

    /// 구조체 연산자
    /// 1. . 연산자(직접 멤버 연산자) : 일반 구조체 변수
    /// 2. -> 연산자(간접 멤버 연산자) : 포인터 변수
    myC.level = 99;

    /// 구조체 변수 선언
    /// C언어 스타일의 구조체 변수 선언 방법
    struct character myCC;
    /// C++언어 스타일의 구조체 변수 선언 방법
    character myCD;

    /// typedef A B ==> 앞으로 A를 B로 사용한다.
    typedef
    /// A의 시작 위치
    struct my_information_for_game_ground
    {
        int a;
        int b;
        int c;
    }
    /// A의 끝
    MYINFO,         /// B
    *PMYINFO        /// B
    ;
    MYINFO mi;
    MYINFO mmm;
    mmm = mi;

    MYINFO* mip = &mi;
    mip->a = 10;
    PMYINFO pip = &mi;
    pip->a = 20;
    printf("myinfo : %d %d %d\n", mi.a, mip->a, pip->a);



    std::cout << "Hello World!\n";
}
