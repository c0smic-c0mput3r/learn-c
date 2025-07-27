#include <stdio.h>
#include <time.h>

int main(){
    time_t now = time(NULL);
    char *readable = ctime(&now);
    printf("hello!, rosette nebula\n");
    printf("cosmic hello succesfully launched at %slocal earth time\n",readable);
    printf("type: emission nebula\n");
    printf("located: constellation monoceros(the unicorn)\n");
    printf("dist from earth: 5,219 light years\n");
    printf("core: young star cluster(NGC 2244)\n");
    return 0;
}
