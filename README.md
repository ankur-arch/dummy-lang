# SIMPle-Lang
## A primitive implementation of c function parser using lex, yacc and c

#### Getting Started

To build the program you can run the following command in terminal
``` 
make all
```
Then you can run the code written on a **text file** ( see  text.txt, test2.txt, test3.txt ) 
``` 
./calc < textfilename.txt
```
And you should see the desired output ( if the feature exists ) in the terminal 

#### Features

1. #### Supports Arithmetic Operators
   - [x] +
   - [x] -
   - [x] *
   - [x] /
   - [x] %
   - [x] ()
   - [x] - negation
   
   Input
   
   ```
   // example [ don't forget the semi-colons at the end of the lines ] 
   float x = 2+2-4+(-2)/4*3 ; 
   display x ; 
   ```
 
   Output
   
   ```
   printed 1.500
   ```
   
2. #### Supports Conditional Operators
   - [x] ==
   - [x] !=
   - [x] >
   - [x] >=
   - [x] <
   - [x] <=
   - [x] ||
   - [x] && 
   - [x] !
   
   Input 
   
   ```
   // example [ don't forget the semi-colons at the end of the lines ] 
   display 2>=2 && 4<=4 ; 
   display (3==3 && 3==1 || 2==2 && !(3==3) ); 
   ```
   
   Output
   
   ```
   printed 1.00
   printed 0.00
   ```

3. #### Supports shorthand operators
   - [x] +=
   - [x] -=
   - [x] *= 
   - [x] /=
   - [x] %=
   - [x] *variableName*++
   - [x] *variableName*--
   - [x] ++*variableName* 
   - [x] --*variableName* 
   
   Input 
   
   ```
   float x = 100 ; 

   display x++;
   display x;

   display ++x;
   display x;

   float y = 100 ; 

   display y--;
   display y;
   display --y;
   display y;
   ```
   
   Output
   
   ```
   Variable x successfully updated 
 
   printed  : 100.000000 
 
   printed  : 101.000000 
   Variable x successfully updated 
 
   printed  : 102.000000 
 
   printed  : 102.000000 
   Variable y successfully updated 
 
   printed  : 100.000000 
 
   printed  : 99.000000 
   Variable y successfully updated 
 
   printed  : 98.000000 
 
   printed  : 98.000000 
   ```
   
4. #### Supports Variable Declaration 
   As of now the **only types is float**,
   however the **grammar for int** is recognized
   
   example of supported variable declarations ( uninitialized variables throw error and will result in the termination of the program ) 
   
   Input 
   
   ```
   int v1, v2 , v3 ; // has to end line with semicolon 
   int v1, v2 = 10 ; // v2 has a value of 10.0 however v1 is uninitialized
   float v1=1.0, v2, v3=101.0; // v2 is uninitialized
   
   // the action below is supported aswell 
   float y = 100, z = 500; 
   float x =  y + z  ; // now x will have a value of 600.0 
   \\ trying to use undeclared variables will result in the termination of the program 
   ```
   
5. #### if-elseif-else and if-elseif-else nested support
   
   Basic Syntax Rules
   - **must be in these format** if(c){} or if(c){}else{} or if(c){}elseif(c){}else{} braces without semicolon in the end
   - **c means**  conditional statement of any length
   
   Input
   
   ```
        if(2<2){
            return 1 ;
        }
        else if(3==4){
            return 2;
        }
        else{
            display 3;
            if(2==2){
                display 3.25; 
                if(3!=3){
                    display 3.5;
                }
                else if(4==2){
                    display 3.75;
                }
                else{
                    display 3.95;
                }
            }
        }
        
   ```
   
   Output
   
   ```
    printed  : 3.000000 
    printed  : 3.250000 
    printed  : 3.950000 
   ```
   
