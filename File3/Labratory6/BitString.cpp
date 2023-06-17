#include "BitString.h"

using namespace std;

Bitstring::Bitstring(int set_length) : MArray(set_length, 100){ this->length = set_length; }

int Bitstring::get_length(){return this->length;}

void Bitstring::write_BitString()
{
    Bitstring* ob;
    int n;
    // сначала берём значение текущего объекта а после ссылку на него.
    ob = &(*this);
    for (int index = 0; index < this->get_length(); index++)
    {
        cin >> n;
        (n >= 1) ? (*ob)[index] = '1' : (*ob)[index] = '0';
    }
}

Bitstring Bitstring::operator+(Bitstring &in_arr)
{
    int max_len = max(this->get_length(), in_arr.get_length());
    int min_len = min(this->get_length(), in_arr.get_length());
    Bitstring ret(max_len);
    Bitstring* ob;
    ob = &(*this);
    for (int index = 0; index < max_len; ++index)
    {
        if (index < min_len){ ret[index] = ((*ob)[index] == '1' || in_arr[index] == '1') ? '1' : '0'; }
        else
        { ret[index] = (min_len == get_length()) ? in_arr[index] : (*ob)[index]; }
    }
    return ret;
}

Bitstring::~Bitstring(void){}

int main()
{
    Bitstring test1(3), test2(5);
    test1.write_BitString();
    Bitstring test3 = test1 + test2;
    cout << test3 << endl;
    return 0;
}
