#include <stdio.h>

/* variables are stored in RAM(stack,heap); 
   variables declared within functions/methods are allocated in stacks(scope bound, automatic management,limited size,faster access,CMA);
   global variables, dynamically allocated memory are stored in heaps(flexible size, manual management, slower access, NCMA); */

/* a real life analogus to it is thinking of hotel:RAM; hotel rooms:var; room name/type:var name,datatype; guest:value stored in the variable; 
   every room has a unique room id:memory address */

/* since C is statically typed, once declared/initialised the datatype cant be changed in the runtime;
   however we can explicitly typecast by assigning it to another var */

/* type var_name; (the syntax for variable declaration; it creates a storage with a unique address of name var_name of a specifc size acc to type;)
   the declared var will have garbage(random) value unless you initialised; */

// type var_name = value; ( the syntax for variable initialisation; the value will be stored in the storage;) 

/* identifier naming conventions; can't start with a number; can use a-z, A-Z, 0-9, _; can't use keywords as identifers; case sensitive in c;
   use meaningful names( unlike a,x use names which signifies what it means) */

int age = 14; // this var is initialised globally hence stored in heap and has a global scope



int main(){
    
    int max_score = 100;
    float temp_celsius = 25.75; // genrally have 6 digit floating precision; while printing you can use %.nf as fs to print only n decimal digit
    char grade = 'A'; // assigned in single quotes; stored in memory as its corresponding ASCII value in binary format; in this case 1000001(65);
    int score;
    score = 41;
    // you can print these var by using their respective format specifiers
    printf("max_score:%d\n",max_score);
    printf("temp_celsius:%f\n",temp_celsius);
    printf("grade:%c\n",grade);
    return 0;
}

/* type *ptr = &var_name; (the & amperstand operator fetch the unique memory address of the var_name and its initialised in ptr(pointer var); 
   (the * derefernce operator refers to the value stored in the memory address stored in ptr variable);
   *ptr refers to the value stored in the memory address in ptr var; */


