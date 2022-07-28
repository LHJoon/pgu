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
    // 1. 배열을 포인터 변수에 넣었다면 그건 어떻게 읽어야 하는지?
    // 1.1 배열도 메모리, 포인터도 메모리주소, 즉 메모리주소+1씩 해주면 똑같겠지?
    // 그럼 결국 배열 읽는식으로 가면될 것 같은데
    // char *str +n; n+=1 해주면 되는거 아님?

    // 2. 배열과 읽는 방식이 같다면 +=1 해주면서 NULL 만나면 멈추고 printf 해줘야지.
    // !! char형 포인터는 메모리를 1개씩 갖는다.
    //
    // strlen => NULL을 만나기 전까지 정수형 변수에 +=1 해주고, 출력
    char *str;
    int n = 0;  //포인터 주소 조절할 변수 선언
    while ((str+n) != NULL ) // str에 있는 NULL을 만나기 전까지
    {
        n += 1;     //n을 1씩 더해준다.
    }
    printf("%d\n", d);      // n = str에 있는 NULL을 만나기 전까지의 개수
    // 하지만 저건 char의 경우에만 해당
    // type이 다를 경우도 고려해줘야함
    // if 자료형 = int
    // if 자료형 = char 이런 방식도 있나..? 
    // 일단 자료형이 다를 경우는 배제하고 코딩해보면 위와같이 나옴 암튼 그럼
    // 포인터는 자료형마다 한개당 배정되는 비트수가 다름
    // ex) char = 1, int = 4, double = 8 like that
    // 포인터 주소로 이동을 해주려면 char의 경우엔 1씩, int의 경우엔 4씩임
    // 그럼 포인터가 선언된 자료형마다 저 숫자를 다르게 해줘야함
    // 암튼 배제하고 해보자 내가 포인터를 잘 못 이해한걸수도 있으니까 라는 희망을 품고..!
    /*
    int num = 0;
    char str[] = {0, };     //배열의 요소를 모두 0으로 초기화해주면,, 다른 함수에서 사용할 때 문제가 생김
    while ( str != NULL)    //문자열의 끝까지 array를 돌려줌
    {
        num +=1;
        //printf("%d\n", num);
    }
    printf("%d\n", num);    //문자열 길이만큼 더해진 Num을 출력
    */

    return 0;
}

// strcpy 개량판 만들기 => 취약점 고치기
char* my_strcpy(char *dest, const char *origin) {
=======
// strcpy 개량판 만들기
char* my_strcpy(char *dest, const char *origin, const int dest_len) {
>>>>>>> aa230cb1baf43c718021f78c6737324d1a9a3235
    // 함수 내용 작성
    // 복-붙 => 복붙하다가 몇번쨰까지 했는지 쓰다가 배열 최대치에 도착하면 NULL넣고 끝
    // flexible한 배열크기의 dest, origin 선언
    char dest[] = "";
    char origin[] = "";
    // origin을 dest에 복붙하다가 dest 배열 최대치에 도착하면 NULL을 넣어야함
    // 그러려면,,, NULL만나기 -2까지 갖다 붙이고, -1에 NULL을 넣고 코드 종료
    // 배열간 복사를 어떻게 하는지? 배뎔 최대치에 도착한 것을 어떻게 아는지?
    // 배열 최대치 : NULL을 만난 곳
    // 경우를 정해보자.
    // 만약 origin이 더 크다면? 크기 비교해서 그 크기만큼 -1한 뒤  마지막에 NULL넣어주면 됨
    // 만약 origin이 더 작다면? 전에 있던거 다 지우고 그대로 넣으면 됨
    // 만약 동일하다면? 그냥 다 지우고 넣으면 됨
    // 배열도 꼭 다 지워야하는지 알아보도록 하고, 배열은 어떻게 넣는것인지 알아봐야할 듯
    if (dest = NULL)    //배열 최대치
    {
        NULL-1 //시스템 메모리상에서 NULL-1을 어떻게..? 찾지
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
    return NULL;
}

// strcat 개량판 만들기 => 취약점 고치기
char* my_strcat(char* dest, const char* origin) {
    // 함수 내용 작성 복붙하다가 마지막칸에 NULL
=======
// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // 함수 내용 작성
>>>>>>> aa230cb1baf43c718021f78c6737324d1a9a3235
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
