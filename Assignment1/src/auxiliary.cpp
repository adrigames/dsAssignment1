#include "auxiliary.h"

std::string convertToString(long int i)
{
	std::string* str = new std::string();
    int lastPos = countDigits(i)-1, length = lastPos+1, index = lastPos, modulus = 0;
	char buffer[length];
    
        while (index>=0)
        {
            modulus = i%10;
            i = i/10;
            buffer[index] = (char)(modulus+0x30);
            std::cout<<buffer[index]<<std::endl;
            index--;
            }
        str->replace(0, lastPos, buffer);
        str->resize(length, ' ');
	return *str;
}

int countDigits(long int number)
{
    int counter = 0;
    while(number>0)
    {
        counter++;
        number /= 10;
        }
    return counter;
    }