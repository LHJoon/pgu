#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    const char* str = "Hi1";
    char* p = (char *)str;

    while(*(p++)) {}

    printf("%s\n", *p);
    printf("%s\n", str);

    return 0;
}