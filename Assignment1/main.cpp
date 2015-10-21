#include "Queue.hpp"
#include <iostream>
#include <limits>
#include <windows.h>

void Exit(bool* exit)
{
    *exit = true;
    return;
    }

void insertInStructure(int i, Queue* even, Queue* negative)
//Determines apropiate structure and inserts data
{
    std::cout<<"Input: "<<i<<std::endl;
    if(i<0) 
        negative->enqueue(i);
    else if (i%2==0)
        even->enqueue(i);
    else
    std::cout<<"Not yet implemented."<<std::endl;
    }
    
void processNumber(Queue* even, Queue* negative)
//Process number function
{
    int input = 0;
    do
    {
        if(std::cin.fail())
        {
            std::cout<<"Invalid input detected.\nPlease, insert number."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        std::cout<<"Enter number: "<<std::endl;
        std::cin>>input;
        }while(std::cin.fail());
        insertInStructure(input, even, negative);
    }

void showEven(Queue* even)
{
    std::cout<<even->list()<<std::endl;
    }

void showNegative(Queue* negative)
{
    std::cout<<negative->list()<<std::endl;
    }

void executeOption(int option, bool* exit, Queue* even, Queue* negative)
{
    switch(option)
    {
        case 1: processNumber(even, negative);
                break;
        case 2: std::cout<<"Not yet implemented."<<std::endl;
                break;
        case 3: showEven(even);
                break;
        case 4: showNegative(negative);
                break;
        case 5: Exit(exit);
                break;
        default: std::cout<<"Invalid option.\nInsert new option."<<std::endl;
        }
    }

void drawMenu(bool* exit, Queue* even, Queue* negative)
//This function draws the user menu and parses user's selection
{
    system("cls"); //Clean screen 
    int option = -1;
    std::cout<<'\t'<<(char)201<<(char)205<<(char)187<<\
    "Please, select an option:"<<std::endl;
    std::cout<<'\t'<<(char)186<<1<<(char)186<<\
    "PROCESS NUMBER"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<2<<(char)186<<\
    "QUERY STACK"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<3<<(char)186<<\
    "LIST EVEN QUEUE"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<4<<(char)186<<\
    "LIST NEGATIVE QUEUE"<<'\t'<<std::endl;
    std::cout<<'\t'<<(char)186<<5<<(char)186<<\
    "EXIT"<<"\t\t\t"<<std::endl;
    std::cout<<'\t'<<(char)200<<(char)205<<(char)188<<std::endl<<std::endl;
    std::cout<<"\t\tOption: ";
    if(std::cin>>option)
        executeOption(option, exit, even, negative);
    else
    {
        std::cout<<"INPUT ERROR: INVALID INPUT"<<std::endl; //Throw error
        //Clean buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    system("pause");
    }

int main(int argc, char **argv)
{
    bool exit = false;
    Queue* even = new Queue();
    Queue* negative = new Queue();
    while(!exit)        //Execution cycle
        drawMenu(&exit, even, negative);
	return 0;
}
