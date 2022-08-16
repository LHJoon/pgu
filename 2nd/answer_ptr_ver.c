#include "project1.h"
#include <stdio.h>
// ---------------------------
// --------- 안내 사항 ---------
// 아래 함수들의 빈 칸에 내용을 채워넣으시오
// 단, C언어를 기준으로 작성
// 반드시 my_strlen만을 사용하여 길이를 측정한다.
// 그 외, str함수들이 필요하다면 본인이 작성한 함수만을 활용한다.
// 처음 써있는 return 값들은 오류 없이 컴파일하기 위함이므로 본인이 함수를 작성할 때 삭제하도록 한다.

// strlen 만들기
size_t my_strlen(const char* str) {
    // read string until meeting null, and return the number counted until there
    char *p = (char *)str; // 수정 불가능한 str을 수정하기 위해 형변환 후 포인터에 넣어준다.

    while(*(p++)) {}    //p는 while이 끝난 시점에서 str내부에서 '\0'+1에 위치함.

    return (size_t)(p - str - 1);
    // str == str[0] 즉 0, p는 '\0'을 포함한 길이
    // p-1은 '\0'직전까지의 길이, str은 단지 0
    // p - str - 1 == str길이(널문자포함) - 0 - 1 == 널 문자 직전까지의 str 길이.
}

// strcpy 개량판 만들기
char* my_strcpy(char *dest, const char *origin, const int dest_len) {
    // copy the contents of origin to dest
    // if the size of origin is bigger than dest, then stop at the dest_len, and fill dest[dest_len-1] with \0
    char *origin_p = (char *) origin;
    char *dest_p = dest;    // 인덱스를 건드려주기 위함
    // dest[index]
    // *(p + index*(sizeof(char))
    while(*origin_p && (dest_p - dest) < dest_len - 1) {    // origin_p가 '\0'인지 아닌지 check
        *(dest_p++) = *(origin_p++);    // 역참조해서 값 건드려서 origin을 dest에 넣어주고 ++해줌
    }                                   // while이 끝날 당시 각 값은 '\0'이 위치해야하는 곳임
    *dest_p = '\0';                     // origin이 dest에 다 들어가고 ++가 되어서 p는 '\0'의 위치에 멈춰있음
                                        // 때문에 마지막에 '\0'을 넣어줌

    return dest;    // 지금까지 역참조로 dest의 주소에 접근해 값을 건드렸으니 dest를 리턴하면 됨.
}

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // copy the contents of origin at the end of dest
    // if the size of dest+origin is bigger than dest, then stop at the dest_len and fill dest[dest_len-1] with \0
    char *origin_p = (char *) origin;   // origin 원본에 변화를 주지않고, 건드리기 위함
    char *dest_p = dest;    // dest를 원본에 변화를 주지않고, 건드리기 위함

    // go to the \0 of dest position
    while (*(++dest_p)) {}  // dest의 '\0'위치까지 무한동작, ++이 앞에있기 때문에 '\0'위치에서 멈춘다.

    // copy the origin to dest
    while(*origin_p && (dest_p - dest) < dest_len -1) { //origin과 dest_p-dest < 배열 전체크기보다 1작아야함
        *(dest_p++) = *(origin_p++);    //역참조로 dest의 '\0'위치부터 origin의 '\0'이전까지 할당해주고 ++되었음
    }
    *dest_p = '\0'; // 배열의 마지막에 '\0' 문자를 할당해서 문자열 구분

    return dest;
}

// strcmp 만들기
int my_strcmp(const char* str1, const char* str2) {
    // compare one character by one character, and if the character is different, then outputs the difference of their ascii code
    char *p1 = (char *) str1;   //str1을 원본에 변화를 주지않고, 건드리기 위함
    char *p2 = (char *) str2;   //str2 원본에 변화를 주지않고, 건드리기 위함

    // compare until at least one of them reaches \0
    while(*p1 || *p2) { // p1 or p2가 '\0'인지 아닌지를 판별하는 조건식입니다.
        // if different, stop and return output
        if (*(p1++) != *(p2++)) return (int)(*(--p1) - *(--p2));
    }   //만약 str1, str2가 다르다면 (++하고 끝난 상태니까), --한 str1, str2를 반환
    return 0; //만약 str1, str2가 같다면 0을 반환
}

// strchr 만들기
char* my_strchr(const char* str, int c) {
    // read str one character by one character, and if c is found for the first time, return its pointer
    char *p = (char *) str; // str을 원본에 변화를 주지않고, 건드리기 위함

    while(*p) {     //p가 '\0'을 만나는 순간 false
        if (*(p++) == c) {  // 만약 str++ == c라면 (p는 ++하고 끝났음)
            return --p;     // ++하고 끝났기 때문에 --p해줘서 리턴.
        }
    }
    return NULL;        // 만약 찾지 못했다면, NULL을 리턴
}

// strstr 만들기
char* my_strstr(const char* str1, const char* str2) {
    // read str one character by one character, and if part of str1 is the same as first character of str2, then check the continuous characters and return the pointer of first character
    char *p = (char *) str1;    // str1을 원본에 변화를 주지않고, 건드리기 위함
    while(*p) {                 // p가 '\0'을 만나면 false가 됩니당.
        if (*(p++) == *str2) {  // 만약 str1[index]가 == str2[index]라면
            char *p1 = p;       // str1[index] 즉, 해당위치의 포인터를 저장합니다.
            char *p2 = (char *) str2;   //str2[index] 즉, 해당 위치의 포인터를 저장합니다.
            int isSame = 0; //if 0, the same, if 1, different
            // Check the rest
            while (*(++p2)) {   //++p2가 '\0'을 만나면 false
                if (*p1++ != *p2) { // str1++이 != str2라면
                    isSame++;       // isSame++ => isSame이 1이상이면 다른 문자열
                    break;          // 달라졌으니까 해당 while문을 박차고 나옴
                }
            }
            if(isSame == 0) return --p; //isSame ==0이면 --된 p를 리턴, 90 또는 96줄에서 ++되었으니까
        }
    }
    return NULL;
}
