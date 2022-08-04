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
    size_t index = 0;
    while(str[index] != '\0') {
        index++;
    }
    return index;
};

// strcpy 개량판 만들기
char* my_strcpy(char *dest, const char *origin, const int dest_len) {
    // copy the contents of origin to dest
    // if the size of origin is bigger than dest, then stop at the dest_len, and fill dest[dest_len-1] with \0
    int index = 0;

    while(origin[index] != '\0' && index < dest_len -1) {
        dest[index] = origin[index];
        index++;
    }
    dest[index] ='\0';

    return dest;
}

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len) {
    // copy the contents of origin at the end of dest
    // if the size of dest+origin is bigger than dest, then stop at the dest_len and fill dest[dest_len-1] with \0
    int dest_index = my_strlen(dest); // move dest index to the \0 of dest
    int origin_index = 0;

    while(origin[origin_index] != '\0' && dest_index < dest_len - 1) {
        dest[dest_index] = origin[origin_index];
        dest_index++;
        origin_index++;
    }
    dest[dest_index] = '\0';

    return dest;
}

// strcmp 만들기
int my_strcmp(const char* str1, const char* str2) {
    // compare one character by one character, and if the character is different, then outputs the difference of their ascii code
    int index = 0;
    while(str1[index] != '\0' || str2[index] != '\0') {
        if (str1[index] != str2[index]) break;
        index++;
    }
    return (int)(str1[index] - str2[index]);
}

// strchr 만들기
char* my_strchr(const char* str, int c) {
    // read str one character by one character, and if c is found for the first time, return its pointer
    int index = 0;
    while(str[index] != '\0') {
        if (str[index] == c) {
            return &str[index];
        }
        index++;
    }
    return NULL;
}

// strstr 만들기
char* my_strstr(const char* str1, const char* str2) {
    // read str one character by one character, and if part of str1 is the same as first character of str2, then check the continuous characters and return the pointer of first character
    int index = 0;
    while (str1[index] != '\0')
    {
        if (str1[index] == str2[0])
        {
            // 86~99 => strncmp => n글자만 비교 => str2의 길이만큼만 str1이랑 비교
            // 결과가 true면 str1의 index의 포인터를 return
            int isSame = 0;     // isSame == 0이면 같고 1이면 다르다.
            int i = 0;          // index를 변화시키지 않고, str1과 str2비교하는 변수
            while(str2[i] != '\0') {    //str2 다 읽기
                if (str1[index + i] != str2[i]) {   //만약 비교가 다르다면 isSame++해주고 break;
                    isSame++;
                    break;
                }
                i++;    //두개 값이 같으면 i++해주면서 다음 글자로 넘어갑니다.
            }
            if (isSame == 0) return &str1[index];   // 2번쨰 while을 돌고 나왔을 때 값이 전부 같으면 index ptr반환
        }                                           // 아니라면 첫번째 while문이 다시 돈다.
        index++;
    }
    return NULL;
}

/*
    !!strncmp를 완벽히 짰다고 가정하고
    
    char* my_strstr(const char* str1, const char* str2) {
    // read str one character by one character, and if part of str1 is the same as first character of str2, then check the continuous characters and return the pointer of first character
    int index = 0;
    while (str1[index] != '\0')
    {
        if (str1[index] == str2[0])
        {
            int isSame = strncmp(str1[index], str2, strlen(str2));
            if(isSame == 0) { return &str1[index] }
        }                                           
        index++;
    }
    return NULL;
}
*/