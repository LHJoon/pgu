#include "project1.h"
#include <stdio.h>

// ---------------------------
// --------- 안내 사항 ---------
// 아래 함수들의 빈 칸에 내용을 채워넣으시오
// 단, C언어를 기준으로 작성
// 반드시 my_strlen만을 사용하여 길이를 측정한다.
// 그 외, str함수들이 필요하다면 본인이 작성한 함수만을 활용한다.
// 처음 써있는 return 값들은 오류 없이 컴파일하기 위함이므로 본인이 함수를 작성할 때 삭제하도록 한다.
// Warning! string.h에 들어있는 함수 쓰지 말고 필요하다면 직접 만들어서 사용할 것!

// ---------------------------
// --------- 개인 주석 ---------
/*
    1. 포인터와 문자열을 다루는것을 이해해야 과제를 수행할 수 있을 것 같음.
    2. 함수를 다룰 줄 과제를 수행할 수 있음.
    3. 배열 또는 문자열? 메모리상에서 한 비트단위씩 서로 비교하는 과정이 계속 필요함
    4. 배열이라면 배열의 최대크기를 알 수 있어야 한다. => 방법 강구
    5. (int)(sizeof(a) / sizeof(type));     배열의 최대크기를 알 수 있다.
    5.1 코딩도장 예재로 sizeof(numArr) / sizeof(int) 해줘도 되는듯 하다
    6. 우선 strlen을 해결하면 나머지는 좀 할만할... 듯? strlen을 최우선으로 해보도록 하자!
    strlen은 NULL을 만나기 전까지 개수를 계속 +=1 하면서 세어주고
    만약 NULL을 만난다면 멈추고, 개수를 출력해주면 된다.
    char *str;
    while (str != NULL)이 어떻게 작동되는지 알아볼 것
    만약 str 메모리에 있는 문자열을 메모리 처음부터 읽는 방식이라면 str != NULL이 작동할 것이고
    아니라면 int i=0; str[i]해서 i+=1; 해줘야할 것이니까
*/
// ---------------------------
// --------- 개인 주석 ---------
// strlen 만들기
size_t my_strlen(const char* str) {
    // 함수 내용 작성
    int count = 0;  // 카운트해줄 정수형 변수 선언
    while (str[count] != '\0')   //문자열이 NULL값을 만날 때 까지 실행
    {
        count +=1;                  // 문자열 개수 COUNT
    }
//    printf("%d\n", count);

    return count;
}

// strcpy 개량판 만들기
char* my_strcpy(char *dest, const char *origin, const int dest_len) {

    // 함수 내용 작성
    int count = 0;

    while(dest[count] != '\0')
    {
        dest[count] = origin[count];
    }
    //dest = origin;
    //if(dest)

    /*
    origin이 더 크다고 했을 떄
    배열 dest, origin 있다고 가정해보자
    char dest[] = "";   // destination
    char origin[] = ""; // origin
    if (strlen(dest) < strlen(origin))  //만약 dest보다 origin이 더 클 때

    char 를 세어주려면
    for (int i=0; i<dest[]; i++)    //i는 destination의 크기보다 1작을 때까지 
                                    //dest[i] = origin[i]하면서 i += 1; 해주고
                                    // if (i ==dest[max])
                                    {
                                        dest[max] = NULL;
                                    } 
                                    이러면 하나씩 넣어주는 꼴이 되고, 마지막은 강제로 NULL
                                    그럼 dest[max]를 어떻게 쓰는지만 알면 될 듯
    {
        if (dest[i] = NULL)    // 만약 dest[i]가 NULL에 도달했다면
        {
            b[i-1] = NULL   // NULL
        }
    }
    
    // dest가 더 크거나 같을 때
    char dest[] = "";
    char origin[] = "";
    if (strlen(dest) >= strlen(origin))
    {
        for (int i=0; i<=dest[max]; i++)
        {
            dest[i] = origin[i];
        }
    }
    // 포인터를 반환하는 거니까
    // return *dest 이렇게 해주면될 것 같음.
    // 크거나 같을때는 조건 동일하니까 한 번에 묶어주자
    */
    return dest;
}

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // 함수 내용 작성

    return NULL;
}

// strcmp 만들기
int my_strcmp(const char* str1, const char* str2) {
    // 함수 내용 작성 
    return 0;
}

// strchr 만들기
char* my_strchr(const char* str, int c) {
    // 함수 내용 작성 문자를 찾으면 멈추고 포인터를 반환
    return NULL;
}

// strstr 만들기
char* my_strstr(char* str1, const char* str2) {
    // 함수 내용 작성 문자열을 찾으면 문자열의 첫번째 문자에서 멈추고 포인터를 반환
    return NULL;
}
