#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"


void addFloatVariable(struct Float v)
{
    printf("%s is the string and %f is the number \n", v.Name, v.value);
    /*
    struct Float temp ; 
    temp.Name = name;
    temp.Type =  "Float";
    temp.value = num;
    */

    if (FloatVariableStackCounter + 1 >= MAX_SLOT)
    {
        printf("Memory full \n");
    }
    else
    {
        FloatVariableTable[FloatVariableStackCounter++] = v;

    }
    return;
}

int getFloatValuePosition(char *variableName)
{
    printf("Variable name %s \n", variableName);
    for (int i = 0; (i < MAX_SLOT && i <= FloatVariableStackCounter); i++)
    {
        char *name = FloatVariableTable[i].Name;
        if (name != NULL && strcmp(name, variableName) == 0)
        {
            return i;
        }
    }
    printf("exited at position, reached end at %d \n ", FloatVariableStackCounter);
    return -1;
}

void updateFloatVariable(char *variableName, float newValue)
{
    int index = getFloatValuePosition(variableName);
    if (index != -1)
    {
        FloatVariableTable[index].value = newValue;
        printf("Variable %s successfully updated \n", FloatVariableTable[index].Name);
    }
    else
    {
        printf("Variable \'%s\' not found \n", variableName);
    };
    return;
}


float getFloatVariableValue(char *variableName)
{
    int index = getFloatValuePosition(variableName);
    if (index != -1)
    {
        return FloatVariableTable[index].value;
    }
    else
    {
        printf("Variable \'%s\' not found \n", variableName);
    };
    return 0;
}



// stack for control flow logic 

void push(int status){
    if(stackPosition>=MAX_SLOT) {
        printf("Stack Overflow \n");
        return;
    }
    printf("Pushed onto stack %d \n", status);
    stack[stackPosition++] = status; 
}

void printStack(){
    printf(" => ");
    for (int i = 0; i < MAX_SLOT ; i++)
    {
        if(stack[i]!=-1)
            printf(" %d",stack[i]);
        else
        {   if(i==0) printf("Stack Empty");
            break;
        }
        
    }
    printf(" \n ");
}

void pop(){
    if(stackPosition==-1){
        printf("Stack Empty \n");
        return;
    }
    int status = stack[stackPosition-1];
    printf("Popped from stack %d \n",status);
    stack[stackPosition--] = -1; 
}

int top(){
    if(stackPosition == -1) {
        printf("Top of the stack is %d and the stack position is %d \n", -1, stackPosition);
        return -1;
    };
    int temp = stack[stackPosition-1];
    printf("Top of the stack is %d and the stack position is %d \n", temp,  stackPosition );
    return temp;
}


// additional checks 

int isIF(char *name){
    if(strcmp(name, "if")==0){
        return 1;
    }
    return 0;
}

int isELSEIF(char *name){
    if(strcmp(name, "else if")==0){
        return 1;
    }
    return 0;
}