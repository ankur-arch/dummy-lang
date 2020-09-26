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
   ```
   // example [ don't forget the semi-colons at the end of the lines ] 
   float x = 2+2-4+(-2)/4*3 ; 
   display x ; // outputs => printed 1.500
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
   
   ```
   // example [ don't forget the semi-colons at the end of the lines ] 
   display 2>=2 && 4<=4 ; // outputs => printed 1.000 => meaning true
   display (3==3 && 3==1 || 2==2 && !(3==3) ); // outputs => printed 0.00 => meaning false
   ```
   
3. #### Supports Variable Declaration 
   As of now the **only types is float**,
   however the **grammar for int** is recognized
   
   example of supported variable declarations ( uninitialized variables throw error and will result in the termination of the program ) 
   ```
   int v1, v2 , v3 ; // has to end line with semicolon 
   int v1, v2 = 10 ; // v2 has a value of 10.0 however v1 is uninitialized
   float v1=1.0, v2, v3=101.0; // v2 is uninitialized
   
   // the action below is supported aswell 
   float y = 100, z = 500; 
   float x =  y + z  ; // now x will have a value of 600.0 
   \\ trying to use undeclared variables will result in the termination of the program 
   ```
   
   
   
