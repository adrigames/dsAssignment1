#include "auxiliary.h"



using namespace std;

int parse(char c, long int* v, int index, bool* prevIsNumber, bool* negative)
//Converts characters to integers
{
    int temp = 0;                   //Temporary integer
    if (*prevIsNumber){             //Check if there is another character in the number
        temp=v[index]*10;           //If so, temp is 10*its value
        }
    if(*negative)                   //Check if it is negative
    {
        temp *= -1;                 //Make positive
        }
    if(c!=','&&c!='.'&&c!='-')      //If character is number
    {
        temp += c-48;               //Add converted character
        v[index]=temp;              //Store in its corresponding place
        if(*negative)               //Check if number is negative
            {
                v[index] *= -1;     //If so, restore negative sign
                }
        *prevIsNumber = true;       //Register as number
        return 0;                   //Do not move cursor (index)
        }
    else{
        switch(c){                  //If c isn't number, check value
            case ',': *prevIsNumber=false;  //If ',', previous is not number
                      *negative=false;      //Number is not negative anymore
                        break;              //Don't modify value
            case '.': *prevIsNumber=false;  //If '.', same as ','
                      *negative = false;
                        break;
            case '-': *negative = true;     //If '-', number is negative
                      *prevIsNumber = false;//This character isn't a number
                        return 0;           //Do not move cursor (index)
            }
        }
    return 1;                               //Move cursor (index)
    }