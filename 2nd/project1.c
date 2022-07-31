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
    // strlen, strcpy, strcat 전부 그림 그리면서 정리 한 번 해보고 나서 cmp 시작할 것.
    // strcmp => 문자열 비교결과 반환 => linux에서는 차이값 반환 => 
    // 1. cmp는 비트단위로 비교, 첫번째 비트가 동일하다면 '\0'을 만나기전 까지 한 비트별로 차이가 있는지 계산해준다
    // 2. 차이가 생기는 지점 즉 str2와 str1의 값이 동일하지 않은 지점까지만 프로그램이 진행되면 된다.   
    // 3. ASCII값으로 비교하고, 차이가 있다면 ASCII값으로 내보내준다
    // 4. 1과2의 조건 => str1[count] != '\0' && str2[count] != '\0' && str2 != str1
    // 5. 널을 만나기 전. 이 떄 굳이 두개가 같아야하나?
    // 6. str1과 str2의 길이를 비교하고, 더 긴 쪽이 '\0'을 만나기 전까지 해준다면? 몰라 일단 이거 배제하고 스타트 해보자.
    int count = 0;
    int gap = 0;   // str1과 str2의 차이값을 저장할 변수
    // int len1 = my_strlen(str1);
    // int len2 = my_strlen(str2);
    // 

    // str1, str2의 차이값을 diff에 넣는다. 만약 diff가 0이면 다음걸로 진행하면 되겠지, 그리고 둘 중 하나가 '\0'을 만날떄까지 진행하면 된다.
                                            // 1.만약 str1이나 str2가 '\0'을 만나지 않았는데 gap이 0이 아니게된다면 프로그램이 끝나야지
                                            // 2.str1,2가 '\0'을 만날때까지 gap이 그대로라면 gap을 반환, st1,2가 '\0'을 만나지 않았는데 gap이 그대로라면 멈추고 gap을 반환
                                            // 이 떄 각 문자열의 len의 길이가 중요한가? 는 일단 PASS해보고 앞선거부터 해보자.
                                            // 아냐 일단 while안에걸 보고 저게 멈춰야할 조건
                                            // 일단 선행되어야 할 조건은 '\0'을 만날때까지 str1과 str2를 돌리는 것
                                            // 그 다음 조건은 gap이 만약 0이 아니라면 멈추고 그 차이값을 반환하는 것 

    while ( str1[count] != '\0' && str2[count] != '\0' )     // 이 조건 일단 배제하고 while 내부부터 구성해보자
    {
        if(gap != 0)        //만약 gap이 0이 아니라면 while문을 멈춘다.
        {
            break;
        }
        gap = str1[count] - str2[count];    // gap에 str1과 str2의 차이값을 넣어준다.
        count++;
    }
    // 현재 문자열의 길이가 다를 때 한 쪽이 먼저 '\0'을 만나서 계산이 되기전에 계산이 끝나버렸다.
    // 처음 배제했던 문자열의 길이를 비교해야함
    // => mystrlen의 크기가 더 큰 쪽이 '\0'을 만날때까지만 계산하는 것으로 고려해주고, 더 짧은쪽이 '\0'을 만났을 때 while문이 중지되는 것을 없애주어야 함
    // int len1 = my_strlen(str1);
    // int len2 = my_strlen(str2);
    // if (str2 < str1)
    // else if (str2 < str1)    
    // else (str2 == str1)  // 같을때는 알빠아님
    //어느 한 쪽이 더 큰게 문제니까 어느 한 쪽이 더 크면 그 사이즈에 맞춰서 해주면 됨. 예를들어
    // if(len2 < len1) len1이 더 크다면 while문에서 str1이 '\0'을 만날떄까지
    // 반대로 len2가 더 크다면 str2가 '\0'을 만날때까지
    return gap;     // gap 반환
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
