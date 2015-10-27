#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <windows.h>

void insertInStructure(long int i, Stack* odd, Queue* even, Queue* negative)
//Determines apropiate structure and inserts data
{
    std::cout<<"Input: "<<i<<std::endl;             //Print inputted number
    if(i<0)                                         //If negative
        negative->enqueue(i);                       //Insert in negative queue
    else if (i%2==0)                                //If positive and even
        even->enqueue(i);                           //Insert in even queue
    else                                            //If positive and odd
        odd->push(i);                               //Insert in stack
    }

void parseLine(std::string line, Stack* odd, Queue* even, Queue* negative)
//This function process each line found in the input file
{
    int i=0, index = 0;
    bool isNumber = false, isNegative = false;
    long int *lineArray = new long int[line.length()/2];                                //Define length of array
                for(i=0; i<(int)line.length(); i++)                                     //Iterate through line
                {
                    index += parse(line[i], lineArray, index, &isNumber, &isNegative);  //Convert char to number
                    }
                for(i=0; i<index; i++)                                                  //Iterate through array
                {
                    insertInStructure(lineArray[i], odd, even, negative);               //Insert in structure
                    }
    }

std::string convertNumber(long int i, bool isEmpty)                                     //Convert number to string
{
    std::string rtrn = "";
    std::ostringstream convert;
    convert<<i;                 //Insert int in stream
    rtrn += convert.str();      //Add stream to string
    convert.str("");            //Clear stream
    convert.clear();
    if(!isEmpty)                //Is next is not null
        {
            rtrn+=',';          //Add ',' to string
            }
        else                    //If it is
        {
            rtrn+='.';          //Add '.' to string
            }
    return rtrn;                //Return string
    }

std::string createStackString(Stack* odd)
//This function creates a string from the stack
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
    std::string line; 
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
    delete(odd);
    delete(even);
    delete(negative);
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
//Once option is captured, process and execute it.
{
    switch(option)
    {
        case 1: processNumber(odd, even, negative);             //Option 1: insert a new number
                break;
        case 2: try{                                            //WARNING: Exceptions may occur
                std::cout<<odd->pop()<<std::endl;               //Print the result of poping the stack
                    }catch(std::runtime_error r)                //Handle the exception
                    {
                        std::cout<<"Stack is empty."<<std::endl;//Show error message
                        }
                break;
        case 3: showEven(even);                                 //Show contents of even queue
                break;
        case 4: showNegative(negative);                         //Show contents of negative queue
                break;
        case 5: Exit(exit, odd, even, negative);                //Exit program
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
    while(!exit)        //Execution cycle
        drawMenu(&exit, odd, even, negative);
	return 0;
}
