
//pointer

#include <stdio.h>

int main(){

    int *nptr;
    int num1 = 10;

    nptr = &num1;   //num1 Memory address pointer에 저장

    printf("%p\n", nptr);

    printf("%p\n", &num1);

    return 0;
}