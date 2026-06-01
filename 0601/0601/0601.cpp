// 0601.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/**
* 생성자 : 클래스가 인스턴스화(메모리에 적재)되는 시점에
*       외부에서 자동으로 호출되는 함수
*       특징 : 함수의 오버로딩 지원 => 다수개를 작성할 수 있다.
*   생성자 함수 만들기
*       1. 함수의 반환 값이 없다.
*       2. 생성자 함수의 이름은 클래스 이름과 동일하다.
*           ==> 외부에서 참조가 가능해야 하기 때문.
*       3. 초기화에 관련된 작업들을 수행
*       4. 권한은 반드시 public 이어야 한다.
*           ==> 외부에서 접근이 가능해야 하기 때문.
*       5. 자동으로 적재 후 단 한번만 호출
*       6. 생성자를 함수 오버로딩을 지원하기 때문에 다수개 작성 가능
* 
* 소멸자 : 인스턴스가 메모리에서 해제되는 시점에 외부에서
*       자동적으로 단 한번만 호출되는 함수
*   소멸자 함수 만들기
*       1. 함수의 반환 값이 없다.
*       2. 소멸자 함수의 이름은 클래스 이름과 동일하다.
*           ==> 외부 참조를 위해
*       3. 해제와 정리에 대한 작업들을 수행
*       4. 권한은 반드시 public 이어야 한다.
*       5. 함수 이름 앞에 반드시 "~"를 붙여야 한다.
*       6. 메모리 해제 시에 단 한번만 호출
*       7. 단 한개만 존재할 수 있다.
*/


class CTest
{
    int m_x;

protected:
    void that()
    {
        /// 뭔가 아주 중요한 일을 함.
        printf("%s 뭔가 아주 중요한 일을 했음\n", __FUNCTION__);
    }
public:
    ~CTest()
    {
        printf("%s 소멸자 호출\n", __FUNCTION__);
    }

    /// 생성자의 선처리 영역
    /// 생성자 인수가 끝나는 ) 부터 { 사이 구간

    const int m_c = 88;
    int& mmm;

    /// 인수가 없는 생성자 ==> 기본 생성자
    /// CTest t1;
    CTest()
        /// 선처리 영역 시작
        : m_c(0), mmm(m_x)
        /// 선처리 영역 종료
    {
        m_x = 0;
        printf("%s 1번 생성자 호출\n", __FUNCTION__);
    }

    /// 인수가 있는 생성자의 호출
    /// 인스턴스 뒤에 함수 호출처럼 (, ) 사이에 인수를 입력
    /// CTest t2(5); 
    CTest(int a)
        : m_c(a), mmm(m_x), m_x(99)
    {
        m_x = a;
        printf("%s 2번 생성자 호출\n", __FUNCTION__);
    }

    /// CTest t3(t1, 3, 77);
    CTest(CTest& o, int a, int c)
        : m_c(a), mmm(c)
    {
        m_x = c;
        printf("%s 3번 생성자 호출\n", __FUNCTION__);
    }
};


class Child : public CTest
{
public:

    /// 복사 생성자 : 원본과 동일한 복제본을 만들기 위한 생성자
    /// 복사 생성자 원형
    ///     클래스이름(const 클래스이름& 인수이름)
    Child(const Child& obj)
    {
        this->m_xx = obj.mmm + obj.m_c * obj.m_xx;
        printf("Child 복사 생성자\n");
    }

    int m_xx;
    Child()
    {
        that();
        printf("Child 생성자\n");
    }

    ~Child()
    {
        that();
        printf("Child 소멸자\n");
    }
};

class TTTT
{
public:
    int m_x;
    /// 암시적 생성자/소멸자 : 선언이 안되어 있는 경우.
    /// 내용이 없는 생성자와 소멸자를 작성해서 입력.
    //TTTT() {}
    //~TTTT(){}
};


class Cnumber
{
public:
    /// 클래스의 객체 연산자 정의

    int m_value;

    int operator + (Cnumber arg)
    {
        return 9;
    }

    int operator - (int arg){}
    int operator - (Cnumber arg) {}
    int operator - (CTest arg) {}

    int operator * (int arg) {}
    int operator / (int arg) {}
    int operator % (int arg) {}
    int operator ^ (int arg) {}
    int operator & (int arg) {}
    int operator && (int arg) {}
    int operator | (int arg) {}
    int operator || (int arg) {}
    int operator . (int arg) {}
    int operator -> (int arg) {}
    int operator ! (int arg) {}
    int operator ? (int arg) {}
    int operator = (int arg) {}
    int operator @ (int arg) {}
    int operator # (int arg) {}
    int operator >> (int arg) {}
    int operator << (int arg) {}



    int operator + (int arg)
    {
        return m_value - arg;
    }
};


int main()
{
    int a = 2;
    int b = 3;
    int c = a + b;

    Cnumber c1;
    Cnumber c2;
    c1.m_value = 1;
    c2.m_value = 3;
    Cnumber c3;
        c1 + c2;

    TTTT t1;
    TTTT t2(t1);        /// 컴파일러가 만들어서 넣어주는 복사 생성자
    TTTT t3 = t2;       /// 컴파일러가 만들어서 넣어주는 복사 생성자

    int x = 9;
    int y(x + 3);       /// == int y = x;
    int cc = x + y;
    printf("%x + %x = %d\n", x, y, cc);

    Child c;
    Child d(c);     /// 복사 생성자 호출
    Child e = d;    /// 복사 생성자 호출

    return 0;

    CTest t1;
    CTest t2(5);
    CTest t3(t1, 3, 77);

    CTest* ptr = new CTest();       // 동적 메모리 할당

    {
        CTest t4;
    }
    std::cout << "Hello World!\n";

    /*
    /// 공통 특징 : 동적 메모리를 할당받는다.
    /// 어떤 상황이던 관계 없이 무조건 요청한 크기만큼 할당
    malloc();
    /// 배열처럼 메모리를 할당받는 함수
    calloc();
    /// 재할당 => 크기를 조절하는 경우
    realloc();
    */
    /// 동적 메모리 할당은 직접 해제를 해야 함.
    delete ptr;
}
