#define MAX_SLOT 100
typedef struct Float
{
    char *Name;
    char *Type;
    float value;
    int isInteger; 
    int isIntitialized; 
} Number;

extern int FloatVariableStackCounter;
Number FloatVariableTable[MAX_SLOT];
void addFloatVariable(Number v);
int getFloatValuePosition(char *variableName);
void updateFloatVariable(char *variableName, float newValue);
Number getFloatVariableValue(char *variableName);
int parentAllowed();
int stack[MAX_SLOT];
extern int stackPosition;
int top();
void push(int status);
void pop();
void printStack();
int isIF(char *name);
int isELSEIF(char *name);