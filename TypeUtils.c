#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Types.h"



void addFloatVariable(struct Float v, char * name, float num)
{
    printf("%s is the string and %f is the number ", name, num);
    struct Float temp ; 
    temp.Name = name;
    temp.Type =  "Float";
    temp.value = num;

    if (FloatVariableStackCounter + 1 >= MAX_SLOT)
    {
        printf("Memory full");
    }
    else
    {
        FloatVariableTable[FloatVariableStackCounter++] = v;

    }
    return;
}

int getFloatValuePosition(char *variableName)
{
    printf("variable name %s", variableName);
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