#include "MArray.h"

using namespace std;

class Bitstring : public MArray
{
    int length = 0;
    public:
        Bitstring(int set_length);
        int get_length();
        void write_BitString();
        virtual Bitstring operator+(Bitstring &in_arr);
        virtual ~Bitstring(void);
};
