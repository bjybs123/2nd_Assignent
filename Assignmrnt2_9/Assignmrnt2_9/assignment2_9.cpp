
#include <iostream>
#include <cstring>`

using namespace std;


class Mystring {

    char* str;      //문자  메모리 공간 할당하는 포인터
    int len;        //문자열 길이 저장 변수

public:
    Mystring()                  //기본 생성자
    {
        len = 0;
        str = NULL;
    }

    ~Mystring()                 //소멸자
    {
       // cout << "소멸\n";
        delete[] str;

    }

    void my_strcpy(char* from, const char* to)
    {
        int i = 0;
        while ((from[i] = to[i]) != '\0')
            i++;
    }

    char* my_strcat(char* intergrated, const char* strAddition)
    {
        char* p = intergrated;
        while (*intergrated)
            intergrated++;
        while (*strAddition)
            *intergrated++ = *strAddition++;
        *intergrated = '\0';
        return p;
    }


    Mystring(const char* newStr)
    {
        len = 0;
        const char* p = newStr;
        while (*p++ != '\0')
            ++len;
        str = new char[len + 1];
        my_strcpy(str, newStr);
    }



    Mystring(const Mystring& my)
    {
        len = strlen(my.str);               //문자열의 길이 계산
        str = new char[len + 1];            //널문자를 위해  + 1
        my_strcpy(str, my.str);             //my_strcpy함수를 이용해 문자열 복사
    }


    Mystring& operator = (const char* p)
    {                                               
        my_strcpy(str, p);                      //매개변수로 받은 문자열의 주소를 str에 복사한다
        return *this;                           //해당 문자열의 주소 반환
    }

    Mystring& operator + (const Mystring& my)
    {
        len = strlen(str) + strlen(my.str) + 1;          
        char* temp = new char[len];                       //임시 문자열을 두 문자열의 길이  + 1만큼 동적으로 할당한다.
        my_strcpy(temp, this->str);                       //임시 문자열에 해당 객체의 str을 복사한다.
        delete[] this->str;                                 
        str = new char[len];                             //len 길이 만큼의 str을 동적으로 할당한다
        my_strcpy(str, temp);                             //str에 임시 문자열을 복사한가
        delete[] temp;                                    
        my_strcat(str, my.str);                          //str문자열에 my.str을 뒤에 이어복사한다.

        return *this;
    }

    Mystring& operator = (const Mystring& total)
    {

        len = strlen(total.str) + 1;                                   //널문자를 위해 1을 더해준다.
        str = new char[len];                                        //str에 len만큼 메모리 할당
        my_strcpy(str, total.str);                                  
        return *this;
    }




    friend ostream& operator<<(ostream& out, const Mystring& totalstr);          //전역함수를 사용하기 위해서는 friend로 접근
};


ostream& operator<<(ostream& cout, const Mystring& totalstr)
{
    cout << totalstr.str;                                     
    return cout;                                         
}

void main()
{
    Mystring my_str;
    Mystring my_str2("문의는 :");
    my_str = my_str2 + "bjybs123@outlook.com으로 주세요\n";

    cout << my_str;


    //cout << " 함수 끝\n";
    return;
}
