
#include "project1.h"
#include <stdio.h>

int main()
{
    char str[] = "Hello"; 
    char *s1 = "Hello";
    int i = 0;
    while(s1[i] != (char)0)    //str[i]가 NULL을 만나기 전까지 세어준다
    {
        i +=1;          // NULL만나기 전까지 COUNT
    }
    printf("%d\n", i);

    return 0;
}

/*
 mystrlen == const char* str의 길이를 읽어서 그 길이를 정수로 프린트해주는 함수
    str[] = "Hello"; 
    int i = 0;
    while(str[i]!=\0)    //str[i]가 NULL을 만나기 전까지 세어준다
    {
        i +=1;          // NULL만나기 전까지 COUNT
    }
    printf("%d\n", i);
    return 0;

*/

/*

size_t my_strlen(const char* str) {

    str = &str;
    // 1. 배열을 포인터 변수에 넣었다면 그건 어떻게 읽어야 하는지?
    // 1.1 배열도 메모리, 포인터도 메모리주소, 즉 메모리주소+1씩 해주면 똑같겠지?
    // 그럼 결국 배열 읽는식으로 가면될 것 같은데
    // char *str +n; n+=1 해주면 되는거 아님?

    // 2. 배열과 읽는 방식이 같다면 +=1 해주면서 NULL 만나면 멈추고 printf 해줘야지.
    // !! char형 포인터는 메모리를 1개씩 갖는다.
    //
    // strlen => NULL을 만나기 전까지 정수형 변수에 +=1 해주고, 출력
    printf("%d\n", (int)str);
    
    return 0;
}

*/