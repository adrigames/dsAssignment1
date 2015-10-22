#include "auxiliary.h"



using namespace std;

int parse(char c, long int* v, int index, bool* prevIsNumber)
{
    int temp = 0;
    if (*prevIsNumber){
        temp=v[index]*10;
        }
    if(c!=','&&c!='.')
    {
        temp += c-48;
        v[index]=temp;
        *prevIsNumber = true;
        return 0;
        }
    else{
        switch(c){
            case ',': *prevIsNumber=false;
                        index++;
                        break;
            case '.': *prevIsNumber=false;
                        break;
            }
        }
    return 1;
    }

