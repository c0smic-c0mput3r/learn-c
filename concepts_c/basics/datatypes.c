#include <stdio.h> 
#include <stdint.h> // ensure fixed bit width, cross platform complatibility 
#include <float.h>
#include <limits.h> // fetch the limits of fundamental integral datatypes
#include <math.h>

#define SIZE(type) printf("%-15s : %zu bytes\n", #type, sizeof(type)) 
/* macro function to stimulate repititive printing logic;
   #type is called stringizing macro which turns the type into string; eg.char -> "char" */

/* sizeof(type) to fetch the byte width of datatypes; returns a value of type size_t;
   which is env-dependent; on 32-bit env: du(4 bytes); on 64-bit env: lu/llu(8 bytes);
   format specifier 4 size_t is "%zu"; z is a modifier which tells the printf() to expected a size_t value */

//generally in broad classification data typed classfied into two types i.e, signed(both +,-)[default] and unsigned(only +)[have to mention];

/* the typedef keyword allows us to create type aliases or abbreviations for complex or 
long type declarations, improving code readability and maintainability."*/
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef long long ll;
typedef unsigned long u_long;
typedef unsigned long long u_ll;
typedef long double l_db;

int byte_width(){

   /* size_t charw = sizeof(char);
    printf("size of char: %zu byte\n",charw);
    printf("size of short: %zu bytes\n", sizeof(short) );
    printf("size of int: %zu bytes\n", sizeof(int));
    printf("size of long: %zu bytes\n", sizeof(long)); */
    
    // INSTEAD OF WRITING MULTIPLE LINES OF CODE LIKE ABOVE, YOU CAN YOU THE MACRO FUNCTION 

   printf("*(1 byte = 8 bits)*\n\n");
   printf("%-15s : SIZE\n","DATATYPE\0");
    SIZE(char); SIZE(u_char); SIZE(short); SIZE(u_short); SIZE(int); SIZE(u_int); 
    SIZE(long); SIZE(u_long); SIZE(ll); SIZE(u_ll); SIZE(float); SIZE(double); SIZE(l_db);
    printf("\n\n");
    return 0;
   /* the size of some types like long varries; for minGW on windows its 4 bytes; for GCC on linux its 8 bytes; 
      for cross platform compatibility use long long, u_ll instead of long, u_long; */
}

int range(){

   /* you can calculate range manually also using [-2**(n-1),2**(n-1)-1] for signed dt; [0,(2**n)-1] for unsigned dt; n = no. of bits;
      as in standard C, the signed dt are represented as 2's complement, the leftmost bit used as MSB(most significant bit)
      0 in MSB signifies non-negative no.; 1 in MSB signifies a negative no.; that's why we raise 2 to power (n-1); */

   // these are macros defined in <limits.h> and <float.h>

   printf("%-14s %-25s %-25s\n", "DATATYPE", "MIN", "MAX");
   printf("%-14s %-25hhd %-25hhd\n", "CHAR", CHAR_MIN, CHAR_MAX); // hh/h modifier 4 veryshort(1byte)/short(2bytes) respectively;
   printf("%-14s %-25hhu %-25hhu\n", "U_CHAR", 0, UCHAR_MAX);   
   printf("%-14s %-25d %-25d\n", "INT", INT_MIN, INT_MAX);
   printf("%-14s %-25u %-25u\n", "U_INT", 0, UINT_MAX);
   printf("%-14s %-25hd %-25hd\n", "SHORT", SHRT_MIN, SHRT_MAX); 
   printf("%-14s %-25hu %-25hu\n", "U_SHORT", 0, USHRT_MAX);
   printf("%-14s %-25ld %-25ld\n", "LONG", LONG_MIN, LONG_MAX); // l/ll modifier 4 long(4/8bytes)*OS dependent*/very long(guarantee 8bytes) respectively;
   printf("%-14s %-25lu %-25lu\n", "U_LONG", 0, ULONG_MAX);
   printf("%-14s %-25lld %-2lld\n", "LLONG", LLONG_MIN, LLONG_MAX);
   printf("%-14s %-25llu %-25llu\n", "U_LLONG", 0, ULLONG_MAX);     
   printf("%-14s %-25E %-25E\n", "FLOAT", FLT_MIN, FLT_MAX);     
   printf("%-14s %-25E %-25E\n", "DOUBLE", DBL_MIN, DBL_MAX);
   printf("%-14s %-25LE %-25LE\n", "LDOUBLE", LDBL_MIN, LDBL_MAX); // f 4 fixed-point notation; e/E 4 scientific notation; g/G automatically chooses b/w fpn/sc whichever is short
   printf("\n\n");
   return 0; 
}


 int precision(){

   /* [1.0 + ε != 1.0]; its the precision limit of the datatype; 
      epsilon gives the smallest significant difference between 1.0 and the next representable number in that data type */

   printf("FLT_EPSILON = %E\n", FLT_EPSILON);
   printf("FLT Decimal precision = ~%.1f digits\n\n", -log10f(FLT_EPSILON));

   printf("DBL_EPSILON = %E\n", DBL_EPSILON);
   printf("DBL Decimal precision = ~%.1f digits\n\n", -log10(DBL_EPSILON));

   printf("LDBL_EPSILON = %.LE\n", LDBL_EPSILON);
   printf("LDBL Decimal precision = ~%.1Lf digits\n\n", -log10l(LDBL_EPSILON));

   return 0;
 }

/* standard ASCII(0-127)[7-bits]; extended ASCII(128-255)[vendor-specific-8-bit-charecter-sets]; (-128,-1)are valid as signed char not ASCII charc */

int ou_flow(){
   // C standard says sdt_ou_flow is undefined behavior; some systems wrap around; some compilers optimize it away or assume it doesn't happen;
   int x = INT_MAX;                    
    printf("x b4 = %d\n", x);
    x = x + 1; 
    printf("x aftr = %d  *WRAPED AROUND TO INT_MIN*\n\n", x);
    char z = -128;
    printf("z b4 = %hhd\n", z);
    z = z - 1;
    printf("z after = %d\n\n",z);

   // usdt_ou_flow behavior is well-defined and follows modulo arithmetic.
    u_char y = 255; 
    printf("y b4 = %hhu\n",y);
    y += 1;
    printf("y aftr = %hhu *WRAPPED AROUND TO USIGNED MIN THAT IS 0*\n\n",y);
    u_char q = 0;
    printf("q b4 = %hhu\n",q);
    q = q - 1;
    printf("q aftr = %hhu *WRAPS AROUND TO 255*\n\n",q);
   return 0;
}

void builtin_types() {
    char a = 130;     // signed char might wrap or truncate depending on platform (130 - 256 = -126);
    unsigned int b = 4294967296; // exceeds 32-bit max, might truncate to (0);
    printf("Built-in types: a = %hhd, b = %u\n", a, b);
}

void stdint_types() {
    int8_t j = 130;           
    uint32_t k = 4294967296;  
    printf("Fixed-width types: j = %d, k = %u\n", j, k); 
}

int main(){

    byte_width();
    range();
    precision();
    ou_flow();
    builtin_types();
    stdint_types();
    return 0;
}
