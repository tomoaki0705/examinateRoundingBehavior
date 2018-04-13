#include <iostream>
#include <iomanip>
#include <limits>

typedef union fp32int32
{
    int i;
    unsigned int u;
    float f;
} fp32int32;

int main(int argc, char** argv)
{
    int previousResult = 0;
    fp32int32 previousValue;
    previousValue.u = 0;
    for(long long value = (long long)(int)0xc7000010;value < 0;value--)
    {
        fp32int32 t;
        t.i = value;
        int result = (int)t.f;
        if(result != previousResult)
        {
            std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << previousValue.u << ' ';
            std::cout << std::dec << std::setw(11) << std::setfill(' ') << previousResult << ' ';
            std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << t.u << ' ';
            std::cout << std::dec << std::setw(11) << std::setfill(' ' ) << result << ' ';
            std::cout << std::scientific << previousValue.f << ' ';
            std::cout << std::scientific << t.f << std::endl;
            previousResult = result;
            previousValue.i = value;
        }
        //std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << (int)value << std::dec << "\t" << previousResult << "\t" << result << std::endl;
    }
    for(long long value = 0;value < 0x47000010;value++)
    {
        fp32int32 t;
        t.i = value;
        int result = (int)t.f;
        if(result != previousResult)
        {
            std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << previousValue.u << ' ';
            std::cout << std::dec << std::setw(11) << std::setfill(' ') << previousResult << ' ';
            std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << t.u << ' ';
            std::cout << std::dec << std::setw(11) << std::setfill(' ' ) << result << ' ';
            std::cout << std::scientific << previousValue.f << ' ';
            std::cout << std::scientific << t.f << std::endl;
            previousResult = result;
            previousValue.i = value;
        }
    }
    return 0;
}

//(long long)std::numeric_limits<int>::min();
