#include "Queue.hpp"
#include <iostream>
#include <limits>
#include <windows.h>

void Exit(bool* exit)
{
    *exit = true;
    return;
    }

void executeOption(int option, bool* exit)
{
    switch(option)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            std::cout<<"Not yet implemented."<<std::endl;
            break;
        case 5: Exit(exit);
                break;
        default: std::cout<<"Invalid option.\nInsert new option."<<std::endl;
        }
    }

void drawMenu(bool* exit)
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
        executeOption(option, exit);
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
    while(!exit)        //Execution cycle
        drawMenu(&exit);
	return 0;
}
