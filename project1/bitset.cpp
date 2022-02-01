#include "bitset.hpp"

Bitset::Bitset()
{
    bitsize = 8;
    isValid = true;
    arr = new uint8_t[bitsize];
    for (int i = 0; i < bitsize; i++)
        arr[i] = 0;
}

Bitset::Bitset(intmax_t size)
{
    if (size <= 0)
    {
        isValid = false;
    }
    else
    {
        isValid = true;
        bitsize = size;
        arr = new uint8_t[bitsize];
        for (int i = 0; i < bitsize; i++)
            arr[i] = 0;
    }
}

Bitset::Bitset(const std::string & value)
{
    bitsize = value.size();
    arr = new uint8_t[bitsize];
    isValid = true;
    for(int i = 0; i < bitsize; i++)
    {
        int bit = std::stoi(value.substr(i, 1));
        if (bit != 0 && bit != 1)
        {
            isValid = false;
            break;
        }
        else
            arr[i] = bit;
    }
}

Bitset::~Bitset()
{
    delete [] arr;
    arr = nullptr;
}

intmax_t Bitset::size() const
{
    return bitsize;
}

bool Bitset::good() const
{
    return isValid;
}

void Bitset::set(intmax_t index)
{
    if (index >= 0 && index < bitsize)
        arr[index] = 1;
    else
        isValid = false;
}

void Bitset::reset(intmax_t index)
{
    if (index >= 0 && index < bitsize)
        arr[index] = 0;
    else
        isValid = false;
}

void Bitset::toggle(intmax_t index)
{
    if (index >= 0 && index < bitsize && arr[index] == 1)
        arr[index] = 0;
    else if (index >= 0 && index < bitsize && arr[index] == 0)
        arr[index] = 1;
    else
        isValid = false;
}

bool Bitset::test(intmax_t index)
{
    if (index >= 0 && index < bitsize && arr[index] == 1)
        return true;
    else if (index >= 0 && index < bitsize && arr[index] == 0)
        return false;
    else
    {
        isValid = false;
        return false;
    }
}

std::string Bitset::asString() const
{
    std::string str;
    for (int i = 0; i < bitsize; i++)
    {
        if (arr[i] == 0)
            str += "0";
        else
            str += "1";
    }
    return str;
}
