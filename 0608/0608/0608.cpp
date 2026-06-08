// 0608.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/// 연산자의 구분
/// +, -, *, /, % : 이항 연산자
/// 이항 연산자의 형태 : 피연산자 연산자 피연산자
/// 증감 연산자 : ++, -- => 단항 연산자
///     변수++, ++변수

class CMember
{
public:
    int m_value;
    int m_mmmm;
    int m_mmmmmmmmm;
};

class CTest
{
private:
    CMember m_member;
public:
    int m_Value = 0;
    
    /// 복사 생성자와 비슷한 형태인 복사 대입 연산자
    /// 단독으로 사용되거나 상속이 되거나 상관 없이
    /// =(대입) 연산이 발생하면 항상 호출된다.
    CTest& operator = (const CTest& obj)
    {
        m_Value = 3;
        return *this;       /// 보통 자신의 객체 값을 전달
    }

    /// -> 연산자를 적용한 경우에는 반드시 현재 객체를 포인터로
    /// 사용하면 안된다.
    CMember* operator -> ()
    {
        return &m_member;
    }

    CTest& operator ++ ()
    {
        cout << "Prefix: ";         /// "++객체" 연산 지원 함수

        m_Value++;          /// 내 멤버 변수의 값이 증가
        return *this;       /// 자기 자신을 반환
    }

    const CTest operator ++ (int)
    {
        cout << "Postfix: ";        /// "객체++" 연산 지원 함수

        CTest t = *this;    /// 임시 변수를 생성하고, 자신을 대입
        m_Value++;          /// 내 멤버 변수의 값이 증가
        return t;           /// 값이 증가하지 않은 이전 정보 반환
    }
};


class CTT
{
public:
    int m_Value;
    /// 선언과 동시에 초기화가 필요한 멤버 변수가 있는 클래스에서
    /// 대입 연산이 발생하는 경우에는 반드시!!! 복사 대입 연산자 함수가
    /// 필요하다!!!
    const int m_const = 1;
    int& m_ref = m_Value;

    CTT& operator = (const CTT& obj)
    {

    }
};


class CCC
{
private:
    int m_private = 3;
protected:
    int m_protected = 2;
public:
    int m_public = 1;
    void func()
    {
        m_private++;
        m_protected++;
        m_public++;
    }
};

/// 상속 시에 사용되는 권한은 인스턴스화 된 시점 이후로 사용된다.
class DDD : private CCC
{
public:
    void fff()
    {
        //m_private++;
        m_protected++;
        m_public++;
    }
};


int main()
{

    CTT t5, t6;
    t5 = t6;

    CTest tt1;
    tt1.m_Value = 1;        /// public 멤버에 1을 할당

    CTest tt2, tt3;
    tt3 = tt2 = tt1;        /// tt2 = tt1; => 임시 객체
                            /// tt3 = 임시 객체; => 임시 객체

    cout << tt1.m_Value << tt2.m_Value << tt3.m_Value << endl;
    return 0;

    CTest t1, t2;
    t1->m_mmmm;             /// -> 재정의로 CMember의 접근 가능
    CTest* ptr = &t1;       /// 주소로 받은 경우, ->로 접근 가능한 멤버
    ptr->m_Value;           /// CTest의 멤버만 접근 가능
                            /// CTest를 포인터로 사용하면 CMember는 접근 불가능!
    CTest& ppp = t1;

    cout << (++t1).m_Value << endl;
    cout << (t2++).m_Value << endl;
    cout << t2.m_Value << endl;

    std::cout << "Hello World!\n";
}
