#include <stdio.h>
#include <string.h>

// strstr(대상 문자열, 검색할 문자열);
// char *strstr(char * const _String, char const * const _SubString);
// 문자열 찾았으면, 문자열로 시작하는 문자열의 포인터를 반환(?), 문자열 없으면 NULL 반환

//strchr은 문자 찾기였음, strstr은 문자열 찾기



int main(){

    char s1[40] = "Damn fucking king dom cooking";
    
    char *pt = strstr(s1, "king");
    //char *pt = strstr(s1, "King");  //대소문자 구별을 하기 때문에 잘못된 값으로 시작하면 null만 출력됨

    printf("%s\n", pt);  //king 이후의 문자열들을 출력
    //printf("%s\n", pt + 1);  이렇게 하면 king의 첫 시작점인 k에서 +1 주소가 되어서
    // ing king dom cooking으로 출력 됨

    return 0;
}

// 중복된 문자열이 있다면 첫번째 문자열이 선택됨

// 딱 알았음!
// 배열에 문자열을 집어넣어주고
// 그 문자열에 맞는 형태에 포인터를 지정해서 strstr함수로 조건에 맞는거 검색해서 *pt
// 즉 pt의 포인터에 그 값을 할당해줌!
// 그러고 나서 pt를 출력하면 그 값이 나오는거임!
// 하지만 단점은 얘도 chr과 동일하게 NULL값이 나올떄까지 진행하기 떄문에 
// 필요한 문자열만 딱 잘라서 사용이 안됨. => 단점

/*

int main(){
    char s1[100] = "A Garden Diary A Garden Diary A Garden Diary";

    char *ptr = strstr(s1, "den");     // den으로 시작하는 문자열 검색, 포인터 반환

    while (ptr != NULL)                // 검색된 문자열이 없을 때까지 반복
    {
        printf("%s\n", ptr);           // 검색된 문자열 출력
        ptr = strstr(ptr + 1, "den");  // den 포인터에 1을 더하여 e부터 검색
    }
}

*/

// while을 사용하면 중복된 문자열이 없을 때까지 반복해서 찾아준다.
// 중복의 문제를 해결할 수 있음
// but 이렇게하면 하나만 콕 찝어서 출력은 못하겠네
// 예를들어 중간에 있는 중복 문자열만 선택하는 건 불가능