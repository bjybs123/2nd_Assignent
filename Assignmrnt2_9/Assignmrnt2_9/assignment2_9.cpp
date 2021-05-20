
#include <iostream>
#include <cstring>`

using namespace std;


class Mystring {

    char* str;      //����  �޸� ���� �Ҵ��ϴ� ������
    int len;        //���ڿ� ���� ���� ����

public:
    Mystring()                  //�⺻ ������
    {
        len = 0;
        str = NULL;
    }

    ~Mystring()                 //�Ҹ���
    {
       // cout << "�Ҹ�\n";
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
        len = strlen(my.str);               //���ڿ��� ���� ���
        str = new char[len + 1];            //�ι��ڸ� ����  + 1
        my_strcpy(str, my.str);             //my_strcpy�Լ��� �̿��� ���ڿ� ����
    }


    Mystring& operator = (const char* p)
    {                                               
        my_strcpy(str, p);                      //�Ű������� ���� ���ڿ��� �ּҸ� str�� �����Ѵ�
        return *this;                           //�ش� ���ڿ��� �ּ� ��ȯ
    }

    Mystring& operator + (const Mystring& my)
    {
        len = strlen(str) + strlen(my.str) + 1;          
        char* temp = new char[len];                       //�ӽ� ���ڿ��� �� ���ڿ��� ����  + 1��ŭ �������� �Ҵ��Ѵ�.
        my_strcpy(temp, this->str);                       //�ӽ� ���ڿ��� �ش� ��ü�� str�� �����Ѵ�.
        delete[] this->str;                                 
        str = new char[len];                             //len ���� ��ŭ�� str�� �������� �Ҵ��Ѵ�
        my_strcpy(str, temp);                             //str�� �ӽ� ���ڿ��� �����Ѱ�
        delete[] temp;                                    
        my_strcat(str, my.str);                          //str���ڿ��� my.str�� �ڿ� �̾���Ѵ�.

        return *this;
    }

    Mystring& operator = (const Mystring& total)
    {

        len = strlen(total.str) + 1;                                   //�ι��ڸ� ���� 1�� �����ش�.
        str = new char[len];                                        //str�� len��ŭ �޸� �Ҵ�
        my_strcpy(str, total.str);                                  
        return *this;
    }




    friend ostream& operator<<(ostream& out, const Mystring& totalstr);          //�����Լ��� ����ϱ� ���ؼ��� friend�� ����
};


ostream& operator<<(ostream& cout, const Mystring& totalstr)
{
    cout << totalstr.str;                                     
    return cout;                                         
}

void main()
{
    Mystring my_str;
    Mystring my_str2("���Ǵ� :");
    my_str = my_str2 + "bjybs123@outlook.com���� �ּ���\n";

    cout << my_str;


    //cout << " �Լ� ��\n";
    return;
}
