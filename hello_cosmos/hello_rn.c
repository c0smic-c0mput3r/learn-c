#include <stdio.h>
#include <time.h>

int main(){
    time_t now = time(NULL); //this gives no of seconds since unix epoch (jan 1, 1970, 00:00:00 UTC)
    char *readable = ctime(&now); // converts now into human readable local time (string format ends with \n)
    printf("hello!, rosette nebula\n"); 
    printf("cosmic hello succesfully launched at %slocal earth time\n",readable); 
    printf("type: emission nebula\n");
    printf("located: constellation monoceros(the unicorn)\n");
    printf("dist from earth: 5,219 light years\n");
    printf("core: young star cluster(NGC 2244)\n");
    return 0;
}
