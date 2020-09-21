#define MAX_SLOT 100
struct Float
{
    char *Name;
    char *Type;
    float value;
};

extern int FloatVariableStackCounter;
struct Float FloatVariableTable[MAX_SLOT];
void addFloatVariable(struct Float v);
int getFloatValuePosition(char *variableName);
void updateFloatVariable(char *variableName, float newValue);
float getFloatVariableValue(char *variableName);

int stack[MAX_SLOT];
extern int stackPosition;
int top();
void push(int status);
void pop();
void printStack();