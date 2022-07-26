
#include <stdio.h>
#include <string.h>

//strcmp(문자열1, 문자열2);
// int strcmp(const *_Str1, char const *_str2);
// 문자열 비교 결과 반환

int main(){

    char s1[12] = "assign";
    char *s2 = "ment";
    
    int boolean = strcmp(s1, s2);

    printf("%d\n", boolean);

    return 0;
}

// -1 = ASCII 기준 s2가 더 큼
// 0 = " 기준 같음
// 1 = " 기준 s1이 더 큼

//ASCII 기준이라 ASCII 표를 대략적으로라도 알고 있어야 비교했을 떄 결과를 분석할 수 있어서 불-편
// -1, 0, 1만 출력되어야 하는데 문자열의 수가 좀 길어지거나 하면 갑자기 -12, -11 같은 값이 출력됨
// 위와 같은 상황은, 리눅스, OS X에서 ASCII code값의 차이를 반환함.
// 때문에 이 때 반환값을 판단하려고 할 때는 if 조건문을 사용해야 한다는 단점이 존재
// 양수일 땐 s1이 더 크고, 음수일 땐 s2가 더 큰 것.
// so, ASCII 표에서의 차이가 얼마나 되는지를 알고 싶을때는 유용하지만
// 단순 문자열 비교에서는 오히려 too much한 느낌, string이 조합되다보면
// 서로다른 ascii값이 난무하기 때문에 쓸모 없어보인다.


// linux에서 ASCII코드 값의 차이를 출력하기 떄문에 해결하기 위해선 아래와 같은 조건문을 달아주면 됨
/*

#include <stdio.h>
#include <string.h>    // strcmp 함수가 선언된 헤더 파일

int main()
{
    char s1[20];
    char s2[20];

    printf("문자열 두 개를 입력하세요: ");
    scanf("%s %s", s1, s2);

    int ret = strcmp(s1, s2);    // 입력된 문자열 비교
    printf("반환값: %d\n", ret);

    // 리눅스와 OS X에서는 ASCII 코드값의 차이를 반환하므로
    // if 조건문으로 판단
    if (ret == 0)
    {
        printf("두 문자열이 같음\n");
    }
    else if (ret > 0)    // 양수일 때
    {
        printf("%s보다 %s가 큼\n", s2, s1);
    }
    else if (ret < 0)    // 음수일 때
    {
        printf("%s보다 %s가 큼\n", s1, s2);
    }

    return 0;
}

*/