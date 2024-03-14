#include <stdio.h>
#include <stdlib.h>

void start_rapl(char* id);
void stop_rapl(char* id);

// test method (our own implementation)
unsigned int fibb(unsigned int a){
    if (a <= 1){
        return a;
    }
    return fibb(a-1) + fibb(a-2);
}

int main(int argc, char *argv[]) {
    unsigned int fibParam = atoi(argv[1]);

    start_rapl("ay");
    unsigned int result = fibb(fibParam);
    stop_rapl("ay");

    // stopping compiler optimization
    if (result < 42){
        printf("%u\n", result);
    }
    return 0;
}
