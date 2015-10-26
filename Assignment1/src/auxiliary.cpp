#include "auxiliary.h"



using namespace std;

int parse(char c, long int* v, int index, bool* prevIsNumber, bool* negative)
{
    int temp = 0;
    if (*prevIsNumber){
        temp=v[index]*10;
        }
    if(*negative)
    {
        temp *= -1;
        }
    if(c!=','&&c!='.'&&c!='-')
    {
        temp += c-48;
        v[index]=temp;
        if(*negative)
            {
                v[index] *= -1;
                }
        *prevIsNumber = true;
        return 0;
        }
    else{
        switch(c){
            case ',': *prevIsNumber=false;
                      *negative=false;
                        index++;
                        break;
            case '.': *prevIsNumber=false;
                      *negative = false;
                        break;
            case '-': *negative = true;
                      *prevIsNumber = false;
                        return 0;
            }
        }
    return 1;
    }