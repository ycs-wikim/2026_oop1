// 0420.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 가변 인자 사용을 위해 필요한 헤더 파일
#include <stdarg.h>

using namespace std;


void addFunc(int,int);
/// 함수 선언 : 함수의 선언부 + 함수의 구현부

/// 함수의 선언부 : 함수의 원형, 프로토타입, 시그니처
///     만드는 방법 : 반환값 함수이름( 인수 리스트 ) ;
///         인수 리스트에 변수 이름을 생략할 수 있다.
///     위치에 관계 없이 호출하는 위치에서 알 수만 있으면 된다.

/// 함수 원형이 필요한 이유. 컴파일러의 번역을 돕기 위해 존재
void asdf();        /// 어딘지 모르겠지만... asdf( ) 함수가 있어~
void asdf1();       /// 반환 값은 void(없고), 인수도 없는 이름이
void asdf2();       /// asdf()인 함수가 어딘가 있다라는 정보 제공
void asdf3();       /// 존재하니까 걱정하지 말고~ 번역해라~

/// 함수의 구현부 : 함수의 선언부 + 구현 내용
/// 함수 선언부와 마찬가지로 어디에 구현되어 있던 관계 없음.


/// 기본 인자의 함수 원형에는 반드시 기본 인자 정보를 표시!!!
void bbb(int digit, int bioReferenceDefaultValue = 9);

/// default 인자(기본 인자)
/// 함수 선언부에 초기화 값을 미리 설정해 두는 것
/// 인수로 값을 전달하지 않는 경우, 미리 설정한 값으로 초기화 되는 인수
/// 인수에 추가하려면, 오른쪽부터 추가해야 한다.
/// 실인수 : 반드시 인수 값을 전달해야 하는 인수
/// 기본 인수 : 값을 줄 수도 있고, 안 줄수도 있다.
/// 기본 인자의 함수 구현부에는 기본 인자에 대한 정보를 제거해야 한다.
void bbb(int digit, int bioReferenceDefaultValue)
{
    printf("%s : %d %d\n", __FUNCTION__, digit, bioReferenceDefaultValue);
}


/// 가변인자 함수
/// 실 인자(인수/매개변수) : 반드시 값을 주어야 하는 인자
///         -> arg1, arg2
/// 가변인자 : 반드시 값을 주지 않아도 되는 인자
///         -> 실인자 뒤에 오는 인자들( ...에 해당)
void VFFunc(int arg1, int arg2, ...)
{
    /// 실제 자료형 : char* (1byte씩 접근). 단순 선언
    va_list arg_ptr;
    /// va_start( ) 호출 후에 가변 인수 시작 위치를 가리킴
    /// 2번째 실인수인 arg2를 전달하는 이유
    ///     : 가변 인수 시작 위치를 획득하기 위한 함수
    va_start(arg_ptr, arg2);
    /// va_arg( ) 함수 : 3번째 자료형만큼 데이터를 반환하고,
    ///         자료형만큼 포인터를 이동해라.
    double varg3 = va_arg(arg_ptr, double);
    char varg4 = va_arg(arg_ptr, char);
    char* varg5 = va_arg(arg_ptr, char*);
    /// va_end( ) 함수 : 가변인수 탐색을 종료.
    va_end(arg_ptr);

    cout << arg1 << endl;
    cout << arg2 << endl;
    cout << varg3 << endl;
    cout << varg4 << endl;
    cout << varg5 << endl;
}

/// C++언어에서 함수를 만들어보자~
/// C언어와 다르게 함수 이름의 중복을 허용
/// 인수의 자료형, 인수의 개수가 다르다면 중복을 허용한다.
/// 반환 값은 함수 중복과 관계가 없다.

/*
* 함수 이름 중복 선언 시점에
* int&와 int는 동일한 자료형으로 취급된다.
void addprint(int& a, int& b)
{
    printf("0: a + b = %d\n", a + b);
}
*/

void addprint(int a, int b)
{
    printf("1: a + b = %d\n", a + b);
}

void addprint(int a, double b)
{
    printf("2: a + b = %lf\n", a + b);
}

void addprint(double a, int b)
{
    printf("3: a + b = %lf\n", a + b);
}

void addprint(double a, double b)
{
    printf("4: a + b = %lf\n", a + b);
}

int main()
{
    int a = 10, int b = 20;
    addprint(a, b);
    addprint(3, 5);
    addprint(3, 5.78);
    addprint(6.23, 87);
    addprint(78.2323, 712.67);

    VFFunc(1, 2, 3.5, 65, "Heeeeeeeeey~");
    VFFunc(3, 5);

    asdf();
    asdf1();
    asdf2();
    asdf3();
    addFunc(3, 5);

    bbb(103, 3);
    bbb(10);
    bbb(3);

    std::cout << "Hello World!\n";
}


void asdf()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}

void asdf1()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}

void asdf2()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}



void asdf3()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}

