#include <iostream>

using namespace std;

class MArray
{
    const static int MAX;
    unsigned char* arr = nullptr;
    int len;

    public:
        MArray(int n, int max_val = MAX);
        virtual ~MArray(void);

        int length(){ return len; }
        
        unsigned char& operator[](int index);
        virtual MArray operator+(MArray &in_arr);
        friend ostream& operator<<(ostream &out, MArray &a);
};

class IncorrectArraySize
{
    public:
        string message = "An exception(IncorrectArraySize) was thrown! Your size exceeds the maximum!\n";
};
