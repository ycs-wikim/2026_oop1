// 0511.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/**
* 클래스 선언
* 예약어 클래스이름 [ : 권한 클래스이름, 권한 클래스이름 ]
* {
*       멤버 변수;
* C++의 경우 : 실수로 주요 정보 노출을 막기 위해
*       int cpp;            /// private
* JAVA의 경우 : 멤버마다 모두 설정하기 귀찮을 때를 위해
*       int java1;          /// public
*       public int java2;
* 
* 접근 지정자:   // 권한(3P)
*       public : 공용, 누구나 접근 및 사용이 가능
*       protected : 관계가 있으면 접근 및 사용이 가능
*       private : 나(클래스)만! 접근 및 사용이 가능
*       멤버 변수;
*       멤버 함수(메서드);
* } ;
*/

class AAB{};
class BBA{};

/// JAVA는 반드시 무조건 항상 단일 상속만 지원
/// C++은 다중 상속을 지원
class AAA : public AAB, public BBA
{
public:
    int x;
    int y;
    int z;
private:
    int x1;
};

/// C++에서는 class == struct(정보체)

/// CFmaliy 클래스 선언부
class CFamily
{
/// protected : 관계가 있는 클래스에서 접근 및 사용 가능
///     일반적으로 외부에서는 protected 멤버는 보이지 않는다.
///     외부에서는 protected == private
///     관계 == 상속
protected:
    const char* m_FamilyName;
    void fn(){}

public:
    /// SetName("Kim")
    /// "Kim"의 자료형 : const char*
    /// "Kim"의 위치 : Data 영역
    void SetFamilyName(const char* arg)
    {
        m_FamilyName = arg;
    }
};


/// CName 클래스 선언부
/// 상속이 동반되어 있음.
/// 상속 : 클래스 선언부에 클래스이름 뒤에 : 을 붙이고
///         권한과 상속할 클래스이름을 나열
class CName : public CFamily
{
/// 클래스 내부/외부
private:
    const char* m_Name;
    void aaa(){}

public:
    int yyy;
    /// 클래스의 메서드도 선언부와 구현부을 분리할 수 있다.
    /// SetName( ) 메서드의 선언부
    void SetName(const char* arg);
    void ShowName()
    {
        /// m_FamilyName을 바로 사용 가능한 이유
        /// 1. 권한이 protected 이다.
        /// 2. CName 클래스가 CFamliy 클래스를 상속 받아서
        cout << m_FamilyName << " " << m_Name << endl;
    }
};

/// 멤버 함수의 외부 구현 방법
/// 1. 함수의 원형을 그대로 가지고 온다.
/// 2. ; 삭제 후, {, }를 만들어 준다.
/// 3. 누구 소속인지를 알려준다. => 클래스이름::
/// 4. 내용을 작성한다.

/// SetName( ) 메서드의 구현부
void CName::SetName(const char* arg)
{
    m_Name = arg;
}


/**
* static 예약어
* C언어
*   변수 선언 : static int x = 15;
*       => 한번만 초기화되는 x 전역 변수에 15를 대입
*   함수 선언 : static int aaa(){ ... }
*       => 함수가 선언된 파일 외부에서 호출 불가능한
*           내부 전용 호출 함수로 정의
* 
* C++언어
*   클래스의 멤버 변수 선언 : static int m_x;
*   클래스의 멤버 함수 선언 : static void aaa(){ .. }
*       ==> 공유
*       ==> 클래스의 인스턴스화와 관계 없이 메모리에
*           변수나 함수를 적재할 수 있도록 만드는 키워드
*       ==> 프로그램 시작하는 즉시 메모리에 static 관련
*           멤버 변수와 함수를 메모리에 적재
*       ==> 단, 한개의 변수와 함수만! 존재하는 상태
*/


int main()
{
    /// 인스턴스화 : 인스턴스를 메모리에 적재하는 상태
    /// 인스턴스 : 클래스가 메모리에 적재되어 있는 상태
    CName name;     /// 인스턴스화가 발생했다.

    /// CFamily 클래스의 public 메서드를 사용 가능한 이유
    /// 상속되었고, 상속 권한이 public이기 때문이다.
    name.SetFamilyName("Kim");
    name.SetName("WoniL");
    name.ShowName();
    std::cout << "Hello World!\n";
}
