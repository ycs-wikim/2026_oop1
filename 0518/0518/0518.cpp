// 0518.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


class CTest
{
public:
    /// 멤버 변수. 초기화되지 않은 상태이기 때문에 인스턴스화되면
    /// m_x가 갖는 값은 쓰레기 값을 갖는다. 반드시 인스턴스 생성 후에
    /// m_x의 값을 초기화해서 사용하거나 생성자에서 초기화 필수!
    int m_x;
    /// 초기화를 수행한 멤버 변수이기 때문에 별도의 초기화 필요 없다.
    int m_I = 1;
    /// 멤버 상수는 반드시 선언하지 마자 초기화를 수행해야 한다.
    const int m_CI = 2;             /// O
    //const int m_ccc;                /// X

    /// 정적 멤버 변수. 클래스의 인스턴스화와 관계 없이 메모리에 존재.
    /// 프로그램 실행 즉시 메모리에 적재가 되어 있는 상태.
    /// 클래스의 인스턴스화 없이 정적 멤버 접근 방법
    ///     ==> "클래스이름::정적멤버변수이름" 형태로 접근 및 사용
    /// 정적 멤버 변수는 반드시 초기화해야만 사용이 가능해진다!!!
    /// 정적 멤버 변수의 초기화 위치는 클래스 내부에서 이루어질 수 없다.
    ///     ==> 클래스 외부에서 초기화를 수행해야 한다.
    /// 정적 멤버 변수는 클래스 내부에서 초기화가 불가능!
    static int s_I;
    /// const가 static보다 우선하기 때문에 선언 시에 초기화 가능!
    /// 변수의 성질을 const가 결정하여 상수가 되므로 #define과 동일!
    static const int s_CI = 4;
    /// JAVA에서의 상수 선언
    //final int asdf = 99;
    /// C#에서의 상수 선언
    //readonly int asdf = 99;

    double m_D = 1.1;
    const double m_CD = 2.2;
    static double s_D;
    static const double s_CD;

    int value;
    /// this 키워드 : 항상 자기 자신(인스턴스)을 가리키는 상수 포인터
    ///         인스턴스화 되었을 때, 자기 자신의 시작 위치를 갖는다.
    ///         클래스 내부에서만 사용이 가능한 예약어
    ///         클래스의 멤버를 정확하게 지칭할 때 주로 사용
    void print(int value)
    {
        value = 999;        /// 인수/매개변수의 값을 변경
        this->value = 888;  /// 멤버 변수 value에 값을 변경
        //this = &value;      /// 상수 포인터이기 때문에 할당 불가능
        printf("%p :: value[ %d ] member[ %d ]\n", this, value, this->value);
    }

    /// 정적 멤버 함수 : 인스턴스화와 관계 없이 메모리에 이미 존재하는 상태.
    ///         내부에서는 클래스의 일반 멤버 변수 접근이 불가능!
    ///         내부에서 사용 가능한 멤버 변수는 정적 멤버만 가능!
    static void sFunc(int value)
    {
        /// 정적 멤버 함수 내부에서 this 사용 불가능 : 인스턴스와 관계 없어서
        //this->value;
        /// m_x는 일반 멤버 변수이므로 정적 멤버 함수와 혼용 불가능!
        /// 일반 멤버 변수가 인스턴스화 되지 않았을 수 있다.
        //m_x = value;
        value = 99;
        /// 정적 멤버 변수는 접근 및 사용 가능
        s_I = value;

        //printf("%p\n", this);
    }


    /// const 멤버 함수 : 함수 내부에서 멤버 변수의 값 변경 불가능!
    ///         모든! 멤버 변수는 const 멤버 함수 내부에서 읽기 전용(상수)이 된다.
    ///         const 키워드가 함수 원형 뒤에 존재해야 정확하게 인식된다.
    const int test(int param) const
    {
        /// 내부에서 선언된 변수, 인수/매개변수는 관계 없이 사용 가능!
        int kkk = 999;
        kkk = m_x + 90;
        param = param * 10;

        printf("1. m_x[ %d ]\n", m_x);
        /// const 멤버 함수 내부에서 일반 멤버 변수 변경 불가!
        //m_x = param;
        printf("2. m_x[ %d ]\n", m_x);
        //m_x = param + 15;
        printf("3. m_x[ %d ]\n", m_x);
        return 0;
    }

};

/// 정적 멤버 변수를 외부에서 초기화하는 방법
/// 1. 코드를 그대로 가지고와서 외부에서 붙여 넣는다.
/// 2. static 키워드를 삭제한다.
/// 3. 클래스의 멤버임을 알린다.
/// 4. 초기화 값을 입력한다.
int CTest::s_I = 88;

/// 상속 클래스의 메모리 구조
/// 클래스의 메모리 적재 시, 메모리에는 멤버 변수만! 존재한다.
class CParent
{
private:
    int m_pri;
    void aaa()
    {
        m_pro = m_pri;
    }
protected:
    int m_pro;
    void bbb()
    {
        m_pro += m_pri;
    }

public:
    int m_value;
    
    void m_parent(int x)
    {
        int xx = 0;
        char arr[1000];
        //m_pro = m_value * 2 + m_pri;
    }
};

/// 상속을 받은 클래스는 인스턴스화 될 때,
/// 모든 상위 클래스의 모든 멤버 변수를 가지고 인스턴스화가 된다.
///     ==> 상위 클래스의 메서드 사용 시에 상위 클래스의 멤버가 사용되서
///         멤서드가 정상적으로 동작하게 만들기 위해서
class CChild : public CParent
{
public:
    int m_value;
};


int main()
{
    CChild cc;

    printf("CP[ %lld ] CC[ %lld ]\n", sizeof(CParent), sizeof(CChild));
    printf("cc[ %p ] pmv[ %p ] cmv[ %p ]\n",
        &cc, &cc.CParent::m_value, &cc.m_value);

    /// 1번 case
    CTest ct, c1, c2, c3;
    //ct.s_I = 99;
    printf("CT: %p\n", &ct);
    ct.print(234);
    ct.test(333);
    //CTest::print(123);

    /// 2번 case
    //CTest::s_I = 99;

    std::cout << "Hello World!\n" << CTest::s_CI << endl;
    std::cout << "Hello World!\n" << ct.s_I << endl;
    CTest::s_I = 888;
    std::cout << "Hello World!\n" << ct.s_I << " " << CTest::s_I << endl;
}
