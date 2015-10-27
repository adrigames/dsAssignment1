#include "Queue.hpp"

Queue::Queue()
{
    //Initialize front and rear pointers
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
}

bool Queue::empty(void)
{
    bool flag = false;
    if(front==rear && front == NULL)        //Check if front = rear = NULL
    {
        flag = true;                        //If so, set flag to true
    }
    return flag;                            //Whatever the case, return flag
}

void Queue::makenull(void)
{   try{
    while(!this->empty()){      //While there are elements left
        this->dequeue();        //take elements out
        }
    }catch(std::runtime_error r){    //If an error happens,
        return;                 //exit.
        }
}

void Queue::enqueue(long int newElement)
{
    cellType* aux = new cellType;
    aux->value = newElement;
    if(this->empty()){                      //If queue is empty
        front=aux;                          //Make aux the first element
        }
    else                                    //If not
        {
            rear->next = aux;               //Make the previous one point to aux
            }
    aux->next = NULL;
    rear = aux;                             //In any case, rear will point to aux
    }

long int Queue::dequeue(void)
{
    cellType* aux = NULL;
    int value = 0;
    if(this->empty())                                                   //If there are no elements
        throw std::runtime_error(std::string("This queue is empty!\n"));//Throw exception
    aux = front;                                                        //Else, copy reference to current front
    value = aux->value;                                                 //Keep value
    front=front->next;                                                  //Move front
    delete(aux);                                                        //Remove former front
    return value;                                                       //Return value
    }

std::string Queue::list(void)
{
    std::string* str = new std::string();   //String that will be returned
    std::ostringstream convert;             //String stream to convert int
    if(!empty()){                           //If it is not empty
    cellType* aux = front;                  //Aux points to the front
    while(aux != NULL)                      //Stop loop when aux points to NULL
        {
            convert<<aux->value;            //Convert to string
            *str+=convert.str();                   //Append value
            convert.clear();
            convert.str("");
            if(aux->next != NULL)           //Check for end of queue
                {
                    *str+=',';               //If not end, append ','
                    }
            else
                {
                    *str+='.';               //If end, append '.'
                    }
            aux = aux->next;                //Iterate
            }
    }
    else                  //Check if string is empty
        *str = "The queue is empty";         //If so, write error message
    return *str;                             //Return the string
    }