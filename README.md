# SIMPle-Lang 
## A primitive implementation of c function parser using lex, yacc and c

### Description 
This is the course project for Compiler Construction, Summer 2020. It uses a stack to implement control flow rather than using an **AST**  

- **Student Name** :Ankur Datta
- **ID** : 1720130

#### Getting Started

To build the program you can run the following command in terminal
```console 
make all
```

Then you can run the code written on a **text file** ( see the attached test.txt, test2.txt, test3.txt files in the root dir )  

```console
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
   
   ```c
   // example [ don't forget the semi-colons at the end of the lines ] 
   float x = 2+2-4+(-2)/4*3 ; 
   display x ; 
   ```
 
   Output
   
   ```console
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
   
   ```c
   // example [ don't forget the semi-colons at the end of the lines ] 
   display 2>=2 && 4<=4 ; 
   display (3==3 && 3==1 || 2==2 && !(3==3) ); 
   ```
   
   Output
   
   ```console
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
   
   ```c
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
   
   ```console
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
   
   ```c
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
   
   ```c
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
   
   ```console
    printed  : 3.000000 
    printed  : 3.250000 
    printed  : 3.950000 
   ```
   
6. #### Supports Function Declaration  
   As of now the **only return types are float, void and int**,
    
   - **void types cannot** return a value
   - **int or float types must** return a value
   
   Input - 1 
   
   ```c
   void foo(){}
   ```
   
   
   Input - 2 
   
   ```c
   int foo(){}
   ```
   
   
   Input - 3 
   
   ```c
   int foo()
        { 
          return 2+2;
        }
   ```
   
   Output 
   
   ```console
                                                // output for input 1
      Error Function does not return any value  // output for input 2
      returned : 4                              // output for input 3      
   ```
 
7. #### Output
   
   The **display command** can be used to output results 
   - as of now it **only supports printing numbers**
   
   Input 
   ```c
   display 2 + 2;
   int x = 4;
   display x+4;
   display 1/2;
   ```
   
   Output 
   ```console
   4.0000
   8.0000
   0.5000
   ```
   
