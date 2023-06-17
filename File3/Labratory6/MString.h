#include "MArray.h"

using namespace std;

class MString : public MArray
{
    int length;

    public:
        MString(int max_length);
        int get_length();
        void write_MString();
        virtual MString operator+(MString &in_arr);
        ~MString(void);
};
