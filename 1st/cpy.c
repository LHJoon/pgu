// #define _CRT_SECURE_NO_WARNINGS //  보안 경고 컴파일 에러 방지
#include <stdio.h>
#include <string.h> //strcpy 등, str* 함수가 선언된 헤더 파일

// strcpy(대상 문자열, 원본 문자열);
// ex) char *strcpy(char *_Dest, char const *_Source); 
//     대상 문자열의 포인터를 반환하는 것
// array 두개 선언해서 값 넣은다음에 포인터를 반환하는지 확인할 것
int main(){

    char s1[11] = "assignment";
    char s2[11];            //아무것도 안들어있는 배열
    char s3[11] = "test";
    //strcpy(s2, s1); //s1 문자열 s2로 복사
    strcpy(s3, s1); //기존 문자열이 할당되어있는 배열에 복사 test
    printf("%s\n", s2);

    printf("%s\n", s3);     //기존에 있던 test가 지워지고 s1이 그대로 복사 됨 (덮어쓰기)
                            //이 경우 실수로 기존에 들어있는 배열의 값을 지워버릴 수 있다. (위험)
    return 0;

}

// 문자열길이 +1 만큼 배열길이를 지정해주고 나니, 코드 정상 작동.
// C에서는 문자열 마지막에 NULL값이 들어가기 떄문에 항상 문자열 길이보다 +1만큼의 배열길이를 지정해주어야 함
// 메모리 상에서 null 값으로 각 데이터를 구분하는 것 같은데 추측이니 정확한 이유를 찾아볼 것

// C에서 NULL(\0)은 문자열의 끝을 나타냄.
// printf는 문자열 출력할 때 문자열을 계속 출력하다가 NULL 에서 출력을 끝낸다.

//우선 복사가 될 배열의 길이마저도 +1 (NULL값때문에) 해주는 것을 생각해주어야 함.
// 

/*

#include <stdio.h>
#include <string.h>    // strcpy 함수가 정의된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    char *s1 = "hello";                      // 문자열 포인터
    char *s2 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

    strcpy(s2, s1);        // s1의 문자열을 s2로 복사

    printf("%s\n", s2);    // Hello

    free(s2);    // 동적 메모리 해제

    return 0;
}
이건 코딩도장 예제
문자열 포인터에 문자열을 복사하기 위해
malloc 함수로 메모리 할당한 뒤 문자열 복사한 것
*/
