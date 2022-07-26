#include <stdio.h>
#include <string.h>

// strchr(대상 문자열, 검색할 문자);
// char *strchr(char ( const_String, int const _ CH);
// 문자 찾았으면 문자로 시작하는 문자열 포인터 반환(?), 문자가 없으면 NULL 반환

int main(){
    
    char s1[20] = "A ssignmenta LHJ";

    char *ptr = strchr(s1, 'A');    // 's'로 시작하는 문자열 검색, 포인터 반환
    //char *ptr = strchr(s1, ' '); 얘도 A랑 똑같이 나옴
    //char *ptr = strchr(s1, 'ss'); 문자만 검색 가능, 문자열은 검색이 안됩니다.
    while (ptr !=  NULL)    //검색된 문자열이 없을 떄까지 반복 (문자열의 끝에는 NULL이 있으니까 NULL을 만나면 실행끝!)
    {
        printf("%s\n", ptr);    //검색된 문자열 출력
        //ptr = strchr(ptr + 1, 's');     // 포인터에 +1해서 그 다음 문자열부터 검색
        ptr = strchr(ptr +1, 'g');
    }
    return 0;
}

// 내가 만든 array안에 들어가있는 string의 포인터(주소)를 찾아서 그걸 반환하는 것
// 그 다음 while문으로 문자열을 찾아서 출력한다.
// 그런 뒤 포인터 주소를 직접 건드려서 다시 검색할 수 있게 해주는 코드
// 말 그대로 대상 문자열의 포인터를 검색하는건데 단점은 ssignment 처럼 동일한 문자가 연속될 때는
// 첫번째 문자가 검색됨, 두번 째 문자를 처음부터 찾을수는 없을 것 같은데..?
// 문자열은 검색이 안되고, 문자만 검색이 가능하기 때문에 동일한 문자가 연속될 때는 문제 발생
// 첫번째 문자열의 포인터를 찾아 +1 해주는 방식으로 찾을수는 있겠지만 세상 번거로운게 단점이 아닐까 싶다.
// 대소문자를 구분하기 때문에 A와 a를 한번에 찾을 수 없다. ex) ASCII

//A로 시작하는 문자열을 검색하고
// while문 안에서는 a를 찾아보니 아래와 같이 출력됨
//A ssignmenta LHJ
//a LHJ

/*
A로 시작하는 문자열 검색,
포인터에 +1 해서 's'부터 검색하니
A ssignmenta LHJ    //1. A로 시작하는 문자열
ssignmenta LHJ      //2. A포인터에 +1한 문자열
signmenta LHJ       //3. 포인터에 +1하고 's'를 만난 문자열부터 검색한 결과
위와 같이 출력. but 2의 문자열 끝에서 이미 while문은 NULL을 만났을 텐데 어째서 무시하고 3까지 갔는지 모르겠다. 
==> s가 문자열 내에 총 2개 있기때문에 위와같이 두 번 while문이 돌아간 모습을 확인할 수 있다..!
*/