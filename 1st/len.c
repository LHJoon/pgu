#include <stdio.h>
#include <string.h>

// strlen == 문자열 길이 반환
// ex) size_t strlen(const *_Str);
// strlen(문자열포인터);
// strlen(문자배열);
int main(){

    char *s1 = "strlen1";    //pointer
    char s2[7] = "Strlen";     // Size 6 array (NULL제외하면)
    char s3[10] = "Blah";       // 배열 길이 넉넉하게 주고 test

    printf("%lu\n", strlen(s1));    //s1의 주소에 있는 문자열의 길이 구함
    printf("%lu\n", strlen(s2));    //s2 array의 문자열 길이 구함
    printf("%lu\n", strlen(s3));    //s3 array "
    return 0;

}

// 7, 6, 4 출력
// 주소로 불렀을 때에는 NULL값을 고려 안해줘도 됨.
// 왜? 그것이 포인터니까.
// array로 불렀을 때 NULL값은 문자열의 길이에 포함되지 않음.
// s3의 경우 배열 크기는 10이지만 안에 들어있는 문자열의 길이는 4니까 문자열 4만 출력
// 배열의 크기는 따지지 않고, 문자열의 길이만 구하게되니까 배열의 크기를 알 수 없는 문제점이 존재하는 듯
// 배열의 크기를 최적화하는게 시스템 메모리상에서의 낭비를 줄일 수 있으니까.

// strlen으로 사이즈를 구할 때 실제 배열은 최소 +1되어있다는 사실을 생각해주어야할 듯
//