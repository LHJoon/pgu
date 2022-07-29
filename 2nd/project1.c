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
    /*

    while(dest[count] != '\0')  // dest_len의 길이 미만까지 origin을 붙여. if(mystrlen(origin) < dest_len) { 복붙이 끝나면 '\0'을 넣어주면 됨}
                                // dest[dest_len -2] 까지 붙이고, [dest_len-1]에 '\0'을 넣어주면 됨
                                //1. while문에서는 origin을 dest에 하나하나 넣어주는 작업을 함
                                //2. if origin이 dest보다 크다면 dest_len의 -2까지 count해서 넣어줌 => count < (dest_len-1)
                                //3. else origin이 dest보다 작다면, origin이 다 들어가고 나서 '\0'을 넣어주고 끝남. => origin[count] != '\0'
                                //4. (23종합) => ( count < (dest_len-1) ) && ( origin[count] != '\0' )
                                // dest[count] = '\0';

    {
        count++;
        dest[count] = origin[count];
    }
    */
   while ( (count < (dest_len-1) ) && (origin[count] != '\0') )     // count < dest_len-1 즉 '\0'전까지 다 쓰여졌을 때 and origin이 '\0'이 아닐때까지
                                                                    // 1. origin이 dest에 들어가야함 (dest는 빈공간일 수도 있다)
                                                                    // 2. origin을 dest에 다 넣고나서, '\0'문자를 마지막에 넣어주고 끝내면 됨
                                                                    // 3. 하지만 만약 dest에 공간이 부족하다면? dest의 마지막인덱스-1 == dest_len의 -2까지 다 넣어주고
                                                                    // 3.1 마지막에 '\0'을 넣어주면 됨
                                                                    // 즉 조건은 count < dest_len-1 and origin[count] != '\0' , while문이 끝난 직후 dest[count] = '\0'
                                                                    // count가 dest_len-1 까지 다 쓰여졌을 때, origin이 널이 아닐떄까지 해주고 dest[dest_len+count] = 널 해봐
   {
        dest[count] = origin[count];
        count++;
   }
    dest[count] = '\0';     // final count에 '\0'을 넣어 문자열을 끝맺음
    
    return dest;            //copy된 Dest return
}

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // 함수 내용 작성
    // 1. strcat은 dest에 origin을 덧붙여 주는 것이다.
    // 2. dest_len의 길이 미만까지 dest + origin을 붙여.
    // 3. dest[dest_len -2]까지 붙이고, [dest_len-1]에 널 넣어.
    // => while문은 어떠한 조건이 될 때 까지 쭉 돌려주는 작업을 함
    // => while문에서 dest[dest_len -2]부터 origin을 붙임. [dest_len-1]에 널을 넣으면 됨.
    // 근데 len은 단순히 어떠한 사이즈의 배열 안에 있는 개수를 읽는거지 그 사이즈를 알 수 있는건 아님
    // 그럼 cpy는 어떻게 된거지 씨123발
    // 아 씨123발 나란 병신
    // 공백은 '\0'이 아니다 just blank fuck that shit poor little puppy.
    // 그럼 일단 dest를 dest_len까지 읽어, 그리고 NULL을 만나지 않았다면 NULL을 만날떄까지 origin을 갖다 박아
    // 그래도 NULL을 안만났으면 origin을 다 넣고 '\0'을 갖다 박아주고 함수를 끝내.

    // 정리해보자
    // int count =0;
    // 조건 1. dest[count] != '\0'
    // 조건 2. origin[count] != '\0'
    // while이 끝난 뒤 dest[count] = '\0';
    // dest의 전체 크기가 dest+origin[count]보다 작다면
    // dest[전체크기-2]까지 origin을 갖다 박고, dest[전체크기-1]에 널을 갖다 박고 끝내

    // 처음부터 다시
    // while문에서는 dest안에 들어있는 dest[ (dest_len-1) + count](NULL이 있는곳)을 시작점으로 origin[count]를 넣어줄거야 그리고 count를 ++해나가겠지 count의 초기값은 0으로 줘야한다.
    // 1. 하지만 dest의 전체 사이즈가 기존에 있던 dest[dest_len-1 +count]보다 작다면
    // 2. 우리는 dest의 전체 사이즈. 즉, dest[size_len-2]까지만 origin[count]를 넣어주고 dest[size_len-1]에는 널 문자를 넣을거야 맞아. 나도 이제 뭐가 뭔지 모르겠어.
    // 3. 내가 무언가를 단단히 착각하고 있는 것 같아.
    // 4. 그냥 그렇게 dest에 origin을 넣으면서 가다가 만약 dest가 널 문자를 만나면 넣는걸 멈추고, 만약 origin을 다 넣었는데도 NULL을 못 만났다면 origin을 다 넣고나서 NULL을 넣어주면 되잖아?
    // 그럼 dest [dest_len +count] !='\0' => dest에 원래있던 애 + count 즉 origin에서 넣은 애가 널을 만나기 전까지.
    // 혹은 origin의 len-1까지 다 넣고나서 그 다음에 NULl을 넣어주던강몰라씨발ㄹㅇ좆같네
    // dest[dest_len] 부터 origin[count]였네 씨발ㅋㅋpoor little HJ
    // 그럼 이제 좀 쉬고나서 while문 조건 생각하고, while문 빠져나왔을 때 어떻게 해야하는지 다시 생각해라 poor little HJ
    int count=0;
    while ((dest[count] != '\0') && (origin[count] != '\0') )
    {
        dest[dest_len + count] = origin[count];
        count++;
    }
    dest[dest_len + count] = '\0';

    return dest;
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
