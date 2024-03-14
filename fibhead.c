#include <stdio.h>
#include <stdlib.h>

void start_rapl(char* id);
void stop_rapl(char* id);

int a = 0;

// test method (our own implementation)
unsigned int fibb(unsigned int a){
    if (a <= 1){
        return a;
    }
    return fibb(a-1) + fibb(a-2);
}

int main(int argc, char *argv[]) {
    unsigned int fibParam = atoi(argv[1]);

    // Start benchmarking how long the fibb method takes
    int start = clock();

    unsigned int result = fibb(fibParam);

    // End benchmarking how long the fibb method takes
    int end = clock();
    printf("Time: %d\n", end - start);

    printf("a: %d\n", a);

    // stopping compiler optimization
    if (result < 42){
        printf("%u\n", result);
    }
    return 0;
}

void __attribute__((no_instrument_function)) __cyg_profile_func_enter(void *func,  void *caller)
{
  start_rapl("enter");
  //printf("enter %p\n", func);
}

void __attribute__((no_instrument_function)) __cyg_profile_func_exit (void *func,  void *caller)
{
  stop_rapl("exit");
  //printf("exit %p\n", func);
}
