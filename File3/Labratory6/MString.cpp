#include "MString.h"

using namespace std;

MString::MString(int max_length) : MArray(max_length, 255){ this->length = max_length; }

int MString::get_length(){ return this->length; }

void MString::write_MString()
{
    MString* ob;
    unsigned char n;
    ob = &(*this);
    for (int index = 0; index < this->get_length(); index++)
    {
        cin >> n;
        (*ob)[index] = n;
    }
}

MString MString::operator+(MString &in_arr)
{
    MString ret(this->get_length() + in_arr.get_length());
    MString* ob;
    ob = &(*this);
    for (int index = 0; index < ret.get_length(); index++)
    { ret[index] = (index + 1 <= this->get_length()) ? (*ob)[index] : in_arr[index - this->get_length()]; }
    return ret;
}

MString::~MString(void){}

// 0x1F - в шестнадцатиричную СИ - это про идеи хранения в unsigned char.

int main()
{
    MString test1(2), test2(3);
    test1.write_MString();
    test2.write_MString();
    MString test3 = test1 + test2;
    cout << test3;
    return 0;
}
