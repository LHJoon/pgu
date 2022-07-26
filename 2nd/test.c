#include "testlib.h"
#include <stdio.h>

int main() {
    printf(" - - - 테스트 프로그램 - - - \n");
    printf(" 테스트는 strlen, strcpy, strcat, strcmp, strchr, strstr 순서대로 진행됩니다.\n");
    printf(" 앞선 테스트를 통과하지 못한다면, 뒷 테스트 역시 진행되지 않습니다.\n\n");
    if(!test_strlen()) return 1;
    if(!test_strcpy()) return 1;
    if(!test_strcat()) return 1;
    if(!test_strcmp()) return 1;
    if(!test_strchr()) return 1;
    if(!test_strstr()) return 1;
    return 0;
}
