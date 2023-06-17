#include "MArray.h"

const int MArray::MAX = 512;

MArray::MArray(int n, int max_val)
{
    try
    {
        if (n > max_val || max_val > MAX){ throw IncorrectArraySize(); }
        arr = new unsigned char[n];
        len = n;
        for (int index = 0; index < n; index++) arr[index] = '0';
        return;
    }
    catch (IncorrectArraySize e){ cout << e.message; exit(EXIT_FAILURE); }
}

MArray::~MArray(void)
{
    delete [] arr;
}

unsigned char& MArray::operator[](int index)
{
    // Генерирует предупреждение и это нормально в данном случае.
    // По задумке этот метод возвращает ссылку на объект типа unsigned char.
    // При несоответстыующем индексе метод обязан что-то вернуть.
    // Null вернуть нельзя, так как ссылка не может быть нулевой.
    // Приходится использовать подобные костыли.
    unsigned char ch = '\n';
    if (index < 0 || index > MAX) return ch;
    return arr[index];
}

MArray MArray::operator+(MArray &in_arr)
{
    int max_len = max(length(), in_arr.length());
    int min_len = min(length(), in_arr.length());
    MArray ret(max_len);
    for (int index = 0; index < max_len; index++)
    {
        ret[index] = (index < min_len) ? arr[index] + in_arr.arr[index] :
        ((min_len == length()) ? in_arr.arr[index] : arr[index]); 
    }
    return ret;
}

ostream &operator<<(ostream &out, MArray &a)
{
    out << "[";
    for (int index = 0; index < a.length() - 1; index++)
    {
        out << a.arr[index] << ",";
    }
    out << a.arr[a.length() - 1] << "]"<< endl;
    return out;
}
