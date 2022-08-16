// 필요한 라이브러리 추가
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// toCopy의 내용을 깊은 복사하여 반환한다. 
// Input: String to be copied / Output: Pointer of copied String
char *dynamic_strcpy(const char *toCopy) {
    // 1. sizeof(char)*destCopy 즉 dest_size가 '\0'을 만나기 전까지
    // 2. toCopy가 '\0'이 아닐때까지 + index가 destCopy의 사이즈 전까지
    // 2.1 => index < sizeof(char)*destCopy && toCopy[index] != '\0'
    // 3. if in while destCopy[index] = toCopy[index]; index++;
    // 3.1 when while done, destCopy[index] = '\0'; string finished
    // 4. return destCopy;
    // warning : 이 떄 ptr to ptr이 아닌 실제 값을 가져와야 한다.
    // 5. malloc으로 동적 할당을 해주면 heap에서 메모리를 사용한다.
    // 6. 일반 변수는 stack에서 메모리 사용
    char* destCopy = (int*)malloc(sizeof(char));    // Dynamic Memory assign
    int index = 0;

    while( index < (int)(sizeof(char)*sizeof(destCopy)) && toCopy[index] != '\0')
    {
        destCopy[index] = toCopy[index];
        index++;
    }
    destCopy[index] = '\0';

    free(destCopy); // Dynamic Memory Free

    return destCopy;

}

// str1와 str2의 내용을 그대로 이어붙인 새로운 문자열을 반환한다.
// Input: Two String to be concatenated / Output: Pointer of concatenated String
char *dynamic_strcat(const char *str1, const char *str2) {

    // 1. toString에 str1을 먼저 넣어주고 '\0'을 만난다면 '\0'부터 다시 str2를 넣어준다.
    // 2. str1[index] != '\0' && str2[index] != '\0'
    // 3. 이 문제는 toString의 배열 사이즈까지 고려를 하는 문제인가..? 만약 그렇다면
    // 4. (int)sizeof(toString) -1 > mystrlen(str1)+mystrlen(str2)까지 고려해줘야할 듯..?
    // when while done, toString[index] ='\0'; 해서 끝맺음
    // 2가 먼저냐, 4가 먼저냐, 동시냐를 생각해보자.
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int len_amount = str1_len + str2_len;
    int index=0;
    char* toString;
    while( len_amount < (int)sizeof(toString)-1  )
    {
        toString[index] = str1[index];
        if(str1[index] == '\0')
        {
            toString[index] = str2[index2];
            index2++;
        }
        index++;
    }
    toString[index] = '\0';

    return toString;
}

int main() {
    // dynamic_strcpy의 입력값이 될 문자열
    char *toCopy = "What'll you do when you get lonely";

    // dynamic_strcat의 입력값이 될 문자열 2개
    char *str1 = "And nobody's waiting by your side?";
    char *str2 = "You've been running and hiding much too long";

    // dynamic_strcpy와 dynamic_strcat을 각각 실행하고 출력하며 검증 등의 기타 필요한 작업을 진행한다.

    return 0;
}