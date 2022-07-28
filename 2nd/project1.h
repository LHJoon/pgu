#ifndef PROJECT_1
#define PROJECT_1
#include <stdio.h>

#define my_array_len(x) (int)(sizeof(x)/sizeof(char))

// strlen 만들기
size_t my_strlen(const char* str);

// strcpy 개량판 만들기
char* my_strcpy(char *dest, const char *origin, const int dest_len);

// strcat 개량판 만들기
char* my_strcat(char* dest, const char* origin, const int dest_len);

// strcmp 개량판 만들기
int my_strcmp(const char* str1, const char* str2);

// strchr 만들기
char* my_strchr(const char* str, int c);

// strstr 만들기
char* my_strstr(char* str1, const char* str2);

#endif // !PROJECT_1
