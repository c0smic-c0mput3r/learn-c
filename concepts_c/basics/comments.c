#include <stdio.h>

//this is a single line comment in c 


/* this is a multi line comment in c,
 it can span across lines, useful for
 long explanation */
 
int main(){

    int edge = 4; // edge length of cube 
    int fa = 4* /* face area of cube with side */ 4;
     /* volume of cube */ int vol = 4 * 4 * 4 ;
    printf("cube of edge length: %d units, has\nface area: %d sq units\nvolume: %d cubic units\n", edge, fa, vol);

    printf("executed succesfully\n");
    return 0;
}

/* comments can be written b4,after,in between the instruction statements beacuse during compilation they are ignored by the compiler;
   however to avoid redundancy use them stragetically to reason behind complex logic or to comment out lines of code for testing; */

 


 
