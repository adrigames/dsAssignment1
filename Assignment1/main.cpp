#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <windows.h>

void insertInStructure(long int i, Stack* odd, Queue* even, Queue* negative)
//Determines apropiate structure and inserts data
{
    std::cout<<"Input: "<<i<<std::endl;
    if(i<0) 
        negative->enqueue(i);
    else if (i%2==0)
        even->enqueue(i);
    else
        odd->push(i);
    }

void parseLine(std::string line, Stack* odd, Queue* even, Queue* negative)
{
    int i=0, index = 0;
    bool isNumber = false, isNegative = false;
    long int *lineArray = new long int[line.length()/2];
                for(i=0; i<line.length(); i++)
                {
                    index += parse(line[i], lineArray, index, &isNumber, &isNegative);
                    }
                for(i=0; i<index; i++)
                {
                    std::cout<<lineArray[i]<<std::endl;
                    insertInStructure(lineArray[i], odd, even, negative);
                    }
    }

std::string convertNumber(long int i, bool isEmpty)
{
    std::string rtrn = "";
    std::ostringstream convert;
    convert<<i;
    rtrn += convert.str();
    convert.str("");
    convert.clear();
    if(!isEmpty)
        {
            rtrn+=',';
            }
        else
        {
            rtrn+='.';
            }
    return rtrn;
    }

std::string createStackString(Stack* odd)
{
    std::string text = "";
    int aux = 0;
    bool aux2 = false;
    while(!odd->empty())
    {
        aux = odd->pop();
        aux2 = odd->empty();
        text += convertNumber(aux, aux2);
        }
    return text;
    }

void saveData(Stack* odd, Queue* even, Queue* negative)
{
    std::ofstream output;
    std::cout<<"Converting stack..."<<std::endl;
    std::string data = createStackString(odd);
    std::cout<<"Finished converting."<<std::endl;
    data += '\n';
    std::cout<<"Converting even..."<<std::endl;
    data += even->list();
    std::cout<<"Finished converting."<<std::endl;
    data += '\n';
    std::cout<<"Converting negative..."<<std::endl;
    data += negative->list();
    std::cout<<"Finished converting."<<std::endl;
    data += '\n';
    std::cout<<"Opening file..."<<std::endl;
    output.open("output.numbers.txt");
    if(output.is_open())
    {
        std::cout<<"File succesfully opened."<<std::endl;
        std::cout<<"Writing data..."<<std::endl;
        output<<data;
        std::cout<<"Data successfully written."<<std::endl;
        output.close();
        }
    else
    {
        std::cout<<"ERROR: COULD NOT WRITE FILE"<<std::endl;
        system("PAUSE");
        }
    }
    
void loadData(Stack* odd, Queue* even, Queue* negative)
{
    std::ifstream input;
    std::string line;;
    input.open("input.numbers.txt");
    if(input.is_open())                 //Check for errors
    {
        while(getline(input, line))
            {
                parseLine(line, odd, even, negative);
                }
        input.close();
        }
    else
        {
            std::cout<<"ERROR: COULD NOT LOCATE INPUT FILE"<<std::endl;
            }
    }
void Exit(bool* exit, Stack* odd, Queue* even, Queue* negative)
{
    saveData(odd, even, negative);
    *exit = true;
    std::cout<<"Exiting program..."<<std::endl;
    return;
    }
    
void processNumber(Stack* odd, Queue* even, Queue* negative)
//Process number function
{
    long int input = 0;
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
        insertInStructure(input, odd, even, negative);
    }

void showEven(Queue* even)
{
    std::cout<<even->list()<<std::endl;
    }

void showNegative(Queue* negative)
{
    std::cout<<negative->list()<<std::endl;
    }

void executeOption(int option, bool* exit, Stack* odd, Queue* even, Queue* negative)
{
    switch(option)
    {
        case 1: processNumber(odd, even, negative);
                break;
        case 2: std::cout<<odd->pop()<<std::endl;
                break;
        case 3: showEven(even);
                break;
        case 4: showNegative(negative);
                break;
        case 5: Exit(exit, odd, even, negative);
                break;
        default: std::cout<<"Invalid option.\nInsert new option."<<std::endl;
        }
    }

void drawMenu(bool* exit, Stack* odd, Queue* even, Queue* negative)
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
        executeOption(option, exit, odd, even, negative);
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
    Stack* odd = new Stack();
    Queue* even = new Queue();
    Queue* negative = new Queue();
    loadData(odd, even, negative);
    system("PAUSE");
    while(!exit)        //Execution cycle
        drawMenu(&exit, odd, even, negative);
	return 0;
}
