
//pointer

#include <stdio.h>

int main(){

    int *nptr;      //포인터 변수
    int num1 = 10;

    nptr = &num1;   //num1 Memory address pointer에 저장

    printf("%p\n", nptr);   //포인터 변수 값

    printf("%p\n", &num1);  //num1의 메모리 주소

    return 0;
}