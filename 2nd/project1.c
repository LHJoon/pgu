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
    size_t count = 0;  // 카운트해줄 정수형 변수 선언
    while (str[count] != '\0')   //문자열이 NULL값을 만날 때 까지 실행          char *s1= "hi" h +1, i 2, return 2, s1[2] = NULL
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
    /*
    1. origin이 '\0'을 만나기 전까지
    2. dest_len(dest의 array size -1 즉, '\0'을 만나기 전까지) count를 세주어야함
    3. count < dest_len -1 and origin[count] != '\0'
    4. dest[count] = origin[count];
    5. 만약 dest_len의 크기가 origin[count]보다 작으면 dest_len(dest의 array size -1 즉, '\0'을 만나기 전까지) count를 세주어야함
    6. 이후 while문 종료 시점에서 dest[count] = '\0'을 해주면 되겠군
    */
   while ( (count < (dest_len-1) ) && (origin[count] != '\0') )     // 1, 2의 조건을 합침
   {
        dest[count] = origin[count];                                // origin을 dest에 순차적으로 넣어준다
        count++;
   }
    dest[count] = '\0';     // final count에 '\0'을 넣어 문자열을 끝맺음
    
    return dest;            //copy된 Dest return
}

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // 함수 내용 작성
    // strcat => my_strlen(dest) -1
    // 1. while 내부 선 구성, 그 구성된 식을 갖고 while의 조건을 생각해주어야 한다.
    // 2. dest[len]부터 origin을 순차적으로 넣어주면 된다. => int count = 0; dest[len+count] = origin[count]; count++
    // 3. 2의 식이 끝나야할 조건 => origin[count] != '\0' and len + count < dest_len -1  (in idx)
    // 4. 만약 공간이 부족할 경우 3의 조건일 때, dest에 들어가다가 '\0'전에 멈췄을 거니까 while이 끝난 뒤 dest[len + count] = '\0';
    int count=0;    // count
    int len = my_strlen(dest);  //dest의 문자열 길이를 넣어둘 변수 (함수 중복호출 방지)
    while ( ( len + count < dest_len-1 ) && (origin[count] != '\0') )   // 
    {
        dest[ len + count ] = origin[count];                            // my_strlen()은 문자열의 NULL의 위치를 반환 => dest의 '\0'부터 origin count
        count++;
    }
    dest[len + count] = '\0';   // '\0'을 만나기 전에 종료되었으니 '\0'을 넣어서 문자열 읽기 종결

    return dest;
}

// strcmp 만들기
int my_strcmp(const char* str1, const char* str2) {
    // 함수 내용 작성 
    // str1, str2의 차이값을 diff에 넣는다. 만약 diff가 0이면 다음걸로 진행하면 되겠지, 그리고 둘 중 하나가 '\0'을 만날떄까지 진행하면 된다.
    // strcmp => 비트단위로 str1, str2를 비교, 비교 도중 차이가 생긴다면 차이값을 반환, 차이가 생기지 않는다면 0을 반환
    // str1, str2의 사이즈가 다를경우 한 쪽의 '\0'에서 차이가 발생하기 때문에 사이즈가 작은쪽이 '\0'을 만나도 while문은 진행해야한다.
    // while문이 돌아가는 도중 차이가 생긴다면 프로그램을 멈춰야한다. 
    int count = 0;
    int gap = 0;   // str1과 str2의 차이값을 저장할 변수

    while ( str1[count] != '\0' || str2[count] != '\0' )     // 둘 중 하나가 '\0'을 만나도 while문은 작동한다.
    {
        if(gap != 0)        //만약 gap이 0이 아니라면 while문을 멈춘다.
        {
            break;
        }
        gap = str1[count] - str2[count];    // gap에 str1과 str2의 차이값을 넣어준다.
        count++;
    }

    return gap;     // gap 반환
}

// strchr 만들기
char* my_strchr(const char* str, int c) {
    // 함수 내용 작성 문자를 찾으면 멈추고 포인터를 반환
    //char *re = NULL;
    int count = 0;  // str을 순차적으로 count해줄 변수
    int gap = 0;    // str, c의 차이를 저장할 변수
    int len = my_strlen(str);

    while( str[count] != '\0')  //str이 '\0'을 만나기 전까지 roop.
    {   
        gap = str[count] - c;   //gap이 멈출 조건 => str[count] != '\0' ,  gap이 0일때.
        

        if (gap == 0)           // str[count]와 c가 동일한 값일 때 str[count]를 반환해야하니 종료.
        {   
            //re = &str[count];
            //break;
            return &str[count];
        }
        count++;    // if절을 통과하고 나서 ++해주기.
    }
    //strchr은 문자열에서 문자를 찾다가 문자를 찾고 '\0'을 만나면 '\0'을 반환하고 끝내는 함수 즉 while이 끝난 뒤 '\0'을 넣어주어 구분지어야한다.
    
    //return re;    //return to str[count] address
    return NULL;
    // 만약 검색한 문자가 대상 문자열에 아예 존재하지 않는다면 '\0'을 반환해야함
    // 
}

// strstr 만들기
char* my_strstr(char* str1, const char* str2) {
    // 함수 내용 작성 문자열을 찾으면 문자열의 첫번째 문자에서 멈추고 포인터를 반환
    // str2를 읽고 그 문자와 길이가 똑같은 문자열을 str1에서 찾아야 함  => 메모리 상 같이 붙어있는 문자들이어야함 
    // str2를 먼저 읽은다음에 str1를 읽어주면 될 듯
    // 1. strstr => strchr과 비슷하지만 문자 하나가 아닌 문자열을 찾아서 포인터를 반환해야 함
    // 2. 문자열을 찾으려면 첫 번쨰 str1과 str2를 대조해주면서 읽어야 함
    // 3. str2 문자열의 길이만큼 str1을 순차적으로 읽어주면 될 듯
    // 4. 
    int count = 0;
    int gap = 0;
    char* s2;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    // 문자열의 길이가 같으면서 동시에 gap이 0이어야 한다라,,   str2와 탐색하고자 하는 str1의 길이가 같을동안 
    while()
    {
        if(gap == 0)
        {
            s2 =
        }
    }

    return NULL;
}
