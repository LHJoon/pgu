
/*

#include <stdio.h>
#include <string.h>

//str cat(최종 문자열, 붙일 문자열);
// ex) char *strcat(char *_Destination, char const*_Source);
// 최종 문자열의 포인터를 반환

int main(){

    char s1[10]= " lwj";
    char s2[10]= "lhj";
    char s3[5] = "test";
    //strcat(s2, s1); //s2 뒤에 s1 붙임
    strcat(s3, s2);     //s3 뒤에 s2 붙임
    //printf("%s\n", s2);
    printf("%s\n", s3);

    return 0; 
}

*/

// 공백 삽입 가능
// s3에 s2를 붙인다고 가정했을 떄, s2의 배열 사이즈와 무관하게 
// s3 배열 사이즈가 부족하다면, 컴파일 에러가 발생함
// s3의 배열 사이즈를 뒤에 붙일 string의 크기에 맞춰서 생각해줘야 하는 점이 단점이라고 생각함.

// 배열 형태로 된 문자열과 문자열 포인터는 다름
// 배열 형태로 된 문자열은 붙일 수 있지만 문자열 포인터는 엑세스 에러가 발생함
// Why? => 읽기 전용 메모리라서.
// 해결하려면 malloc 함수로 동적 메모리 할당, 공간 넉넉하게 해주면 됨

#include <stdio.h>
#include <string.h>    // strcat 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    char *s1 = "boss is good";      // 문자열 포인터
    char *s2 = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당
    //malloc 함수 => 동적 메모리 할당하는 함수 stdlib.h에 존재함

    strcpy(s2, "This ");   // strcpy로 s2에 문자열 복사

    strcat(s2, s1);       // 문자열 포인터 s2 뒤에 문자열 포인터 s1을 붙임

    printf("%s\n", s2);   // Helloworld

    free(s2);    // 동적 메모리 해제

    return 0;
}

// 메모리가 할당된 문자열 포인터에서는 = 로 직접 할당 불가능
// => strcpy 함수를 사용해서 s2에 This를 복사한 것.