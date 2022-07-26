#include "testlib.h"
#include "project1.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// test Program
bool sl(const char* toTest) {
    static int testnum = 1;
    int result_original = strlen(toTest);
    int result_mine = my_strlen(toTest);
    printf("||| %d 번째 테스트 결과\n", testnum);
    printf("||| strlen: %d\n", result_original);
    printf("||| my_strlen: %d\n", result_mine);
    printf("||| 결과: ");
    if (result_original == result_mine) {
        printf("통과! \n\n");
        return true;
    }
    else {
        printf("실패! \n\n");
        return false;
    }
}

bool test_strlen() {
    printf("*** 5회 strlen 동작을 테스트합니다.\n\n");
    char* len1 = "Psychic spies from China try to steal your mind's elation";
    char len2[100] = "And little girls from Sweden dream of silver screen quotation";
    char len3[100] = "And if you want these kind of dreams it's Californication";
    char len4[100] = "\tIt's the edge of the world \\and all of Western civilization";
    char len5[200] = "The sun may rise in the East at least it's settled in a final location\nIt's understood that Hollywood sells Californication";

    if(!sl(len1)) return false;
    if(!sl(len2)) return false;
    if(!sl(len3)) return false;
    if(!sl(len4)) return false;
    if(!sl(len5)) return false;
    return true;
}

bool test_strcpy() {
    printf("*** 5회 strcpy 동작을 테스트합니다.\n");

    // 1st - normal case 여유롭게
    char original1[50] = "Sing me a song, you're a singer";
    char dest11[50];
    char dest12[50];

    printf("||| 1 번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original1);
    printf("||| strcpy:[%s]\n", strcpy(dest11, original1));
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest12, original1));
    if (strcmp(dest11, dest12) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
        return true;
    }
    // 2nd - normal case 빡빡하게
    char original2[] = "Do me a wrong, you're a bringer of evil";
    size_t len_2 = strlen(original2);
    char dest21[len_2+1];
    char dest22[len_2+1];

    printf("||| 2 번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original2);
    printf("||| strcpy:[%s]\n", strcpy(dest21, original2));
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest22, original2));
    if (strcmp(dest21, dest22) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
        return true;
    }
    // 3rd - Buffer overflow case
    char original3[] = "The devil is never a maker";
    size_t len_3 = strlen(original3);
    char dest31[len_3-1];
    char dest32[len_3-1];

    printf("||| 3번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original3);
    printf("||| strncpy_s: [%s]\n",)

    // 4th - Buffer overflow case
    char original4[] = "The less that you give, you're a taker";

    // 5th - Buffer overflow case
    char original5[] = "So it's on and on and on, it's Heaven and Hell";

    return false;
}

bool test_strcat() {
    printf("*** 5회 strcat 동작을 테스트합니다.\n");
    // 이정원 바보
    
    // 1st - normal case

    // 2nd - normal case

    // 3rd - Buffer overflow case

    // 4th - Buffer overflow case

    // 5th - Buffer overflow case

    return false;
}

bool test_strcmp() {
    printf("*** 6회 strcmp 동작을 테스트합니다.\n");

    // 1st - 0이 나오게

    // 2nd - 0 이상이 나오게

    // 3rd - 0 이하가 나오게

    // 4th - 0이 나오게

    // 5th - 0 이상이 나오게

    // 6th - 0 이하가 나오게
    return false;
}

bool test_strchr() {
    printf("*** strchr 동작을 테스트합니다.\n");

    return false;
}

bool test_strstr() {
    printf("*** strstr 동작을 테스트합니다.\n");
    return false;
}
