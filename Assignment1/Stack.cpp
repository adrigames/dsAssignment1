#include "Stack.hpp"

Stack::Stack()
{
    top= NULL;
}

Stack::~Stack()
{
}

void Stack::push(long int newElement) //This function puts an element in the stack
{
    cellType* newCell = new cellType; //Create the celltype
    newCell->value = newElement; //Intialize the values
    newCell->next = top; // Make the new cell point to the top element
    top = newCell; //Change top to new cell
}

long int Stack::pop(void) //This function takes out an element of the stack 
{
    if(this->empty()){
         throw std::runtime_error(std::string("This stack is empty!\n")); //if the stack is empty, error
    }
    else{
        cellType* aux = NULL; //aux variable
        int value = 0;
        aux= top;
        value = aux->value; //save the value 
        top=top->next; // change top 
        delete(aux); //free memory
        return value; //return value
    }
}

bool Stack::empty(void) // This function checks if the stack is empty
{
    if (top==NULL){
        return true; //If the stack is empty, true
    }
    else {
        return false; //If not, false
    }
}

void Stack::makenull(void) //This function makes the stack empty
{   
    while(!this->empty()){ //Take all the elements out
        this->pop();
    }
    return;
}