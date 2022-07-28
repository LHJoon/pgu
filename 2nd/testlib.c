#include "testlib.h"
#include "project1.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// test Program
bool sl(const char* toTest) {
    static int testnum = 0;
    testnum++;
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
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest12, original1, my_array_len(dest12)));
    if (strcmp(dest11, dest12) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }
    // 2nd - normal case 빡빡하게
    char original2[] = "Do me a wrong, you're a bringer of evil";
    size_t len_2 = strlen(original2);
    char dest21[len_2+1];
    char dest22[len_2+1];

    printf("||| 2 번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original2);
    printf("||| strcpy:[%s]\n", strcpy(dest21, original2));
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest22, original2, my_array_len(dest22)));
    if (strcmp(dest21, dest22) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }
    // 3rd - Buffer overflow case
    char original3[] = "The devil is never a maker";
    size_t len_3 = strlen(original3);
    char dest3[len_3-1];
    char answer3[] = "The devil is never a mak";

    printf("||| 3번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original3);
    printf("||| 의도한 문자열: [%s]\n", answer3);
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest3, original3, my_array_len(dest3)));
    if (strcmp(dest3, answer3) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 4th - Buffer overflow case
    char original4[] = "The less that you give, you're a taker";
    size_t len_4 = strlen(original4);
    char dest4[len_4];
    char answer4[] = "The less that you give, you're a take";
    printf("||| 4번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original4);
    printf("||| 의도한 문자열: [%s]\n", answer4);
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest4, original4, my_array_len(dest4)));
    if (strcmp(dest4, answer4) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 5th - Buffer overflow case
    char original5[] = "So it's on and on and on, it's Heaven and Hell";
    char dest5[5];
    char answer5[] = "So i";
    printf("||| 4번째 테스트 결과\n");
    printf("||| 원래 문자열:[%s]\n", original5);
    printf("||| 의도한 문자열: [%s]\n", answer5);
    printf("||| my_strcpy:[%s]\n", my_strcpy(dest5, original5, my_array_len(dest5)));
    if (strcmp(dest5, answer5) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    return true;
}

bool test_strcat() {
    printf("*** 5회 strcat 동작을 테스트합니다.\n");
    // 1st - normal case
    char str111[100] = "Every time that I look in the mirror";
    char str112[100] = "Every time that I look in the mirror";
    char str12[] = "All these lines on my face getting clearer";
    printf("||| 1번째 테스트 결과\n");
    printf("||| 원래 문자열: [%s], [%s]\n", str111, str12);
    printf("||| 의도한 문자열: [%s]\n", strcat(str111, str12));
    printf("||| my_strcat: [%s]\n", my_strcat(str112, str12, my_array_len(str112)));
    if (strcmp(str111, str112) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 2nd - normal case
    char str211[100] = "The past is gone";
    char str212[100] = "The past is gone";
    char str22[] = "Oh, it went by like dusk to dawn";
    printf("||| 2번째 테스트 결과\n");
    printf("||| 원래 문자열: [%s], [%s]\n", str211, str22);
    printf("||| 의도한 문자열: [%s]\n", strcat(str211, str22));
    printf("||| my_strcat: [%s]\n", my_strcat(str212, str22, my_array_len(str212)));
    if (strcmp(str211, str212) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 3rd - Buffer overflow case
    char str31[25] = "Isn't that the way?";
    char str32[] = "Everybody's got their dues in life to pay, oh, oh, oh";
    char ans3[] = "Isn't that the way?Every";
    printf("||| 3번째 테스트 결과\n");
    printf("||| 원래 문자열: [%s], [%s]\n", str31, str32);
    printf("||| 의도한 문자열: [%s]\n", ans3);
    printf("||| my_strcat: [%s]\n", my_strcat(str31, str32, my_array_len(str31)));
    if (strcmp(str31, ans3) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 4th - Buffer overflow case
    char str41[20] = "I know nobody knows";
    char str42[] = "Where it comes and where it goes";
    char ans4[] = "I know nobody knows";
    printf("||| 4번째 테스트 결과\n");
    printf("||| 원래 문자열: [%s], [%s]\n", str41, str42);
    printf("||| 의도한 문자열: [%s]\n", ans4);
    printf("||| my_strcat: [%s]\n", my_strcat(str41, str42, my_array_len(str41)));
    if (strcmp(str41, ans4) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 5th - Buffer overflow case
    char str51[35] = "I know it's everybody's sin";
    char str52[] = "You got to lose to know how to win";
    char ans5[] = "I know it's everybody's sinYou got";
    printf("||| 5번째 테스트 결과\n");
    printf("||| 원래 문자열: [%s], [%s]\n", str51, str52);
    printf("||| 의도한 문자열: [%s]\n", ans5);
    printf("||| my_strcat: [%s]\n", my_strcat(str51, str52, my_array_len(str51)));
    if (strcmp(str51, ans5) != 0) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }
    return true;
}

bool test_strcmp() {
    printf("*** 6회 strcmp 동작을 테스트합니다.\n");
    // 1st - 0이 나오게
    char a1[] = "There's a lady who's sure all that glitters is gold";
    char b1[] = "There's a lady who's sure all that glitters is gold";
    printf("||| 1번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a1, b1);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a1, b1));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a1, b1));
    if (strcmp(a1, b1) != my_strcmp(a1, b1)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 2nd - 0 이하가 나오게
    char a2[] = "And she's buying a stairway to heaven";
    char b2[] = "When she gets there she knows, if the stores are all closed";
    printf("||| 2번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a2, b2);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a2, b2));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a2, b2));
    if (strcmp(a2, b2) != my_strcmp(a2, b2)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 3rd - 0 이상이 나오게
    char a3[] = "With a word she can get what she came for";
    char b3[] = "Ooh, ooh, and she's buying a stairway to heaven";
    printf("||| 3번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a3, b3);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a3, b3));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a3, b3));
    if (strcmp(a3, b3) != my_strcmp(a3, b3)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 4th - 0이 나오게
    char a4[] = "\tThere's a sign on the wall, but she wants to be sure\n'Cause you know sometimes words have two meanings";
    char b4[] = "\tThere's a sign on the wall, but she wants to be sure\n'Cause you know sometimes words have two meanings";
    printf("||| 4번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a4, b4);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a4, b4));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a4, b4));
    if (strcmp(a4, b4) != my_strcmp(a4, b4)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 5th - 0 이상이 나오게
    char a5[] = "In a tree by the brook, there's a songbird who sings ";
    char b5[] = "In a tree by the brook, there's a songbird who sings";
    printf("||| 5번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a5, b5);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a5, b5));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a5, b5));
    if (strcmp(a5, b5) != my_strcmp(a5, b5)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 6th - 0 이하가 나오게
    char a6[] = "Sometimes all of our thoughts are misgiveN";
    char b6[] = "Sometimes all of our thoughts are misgiven";
    printf("||| 6번째 테스트 결과\n");
    printf("||| 비교 문자열: [%s], [%s]\n", a6, b6);
    printf("||| 의도한 strcmp 값: [%d]\n", strcmp(a6, b6));
    printf("||| my_strcmp: [%d]\n", my_strcmp(a6, b6));
    if (strcmp(a6, b6) != my_strcmp(a6, b6)) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    return true;
}

bool test_strchr() {
    printf("*** 3회 strchr 동작을 테스트합니다.\n");

    // 1th
    char a1[] = "When evening falls";
    char b1 = 'e';
    printf("||| 1번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%c]\n", a1, b1);
    char *c1 = strchr(a1, b1);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c1, c1);
    char *d1 = my_strchr(a1, b1);
    printf("||| my_strchr: [%p], [%s]\n", d1, d1);
    if (c1 != d1) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 2nd
    char a2[] = "She'll run to me\nLike whispered dreams";
    char b2 = '\n';
    printf("||| 2번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%c]\n", a2, b2);
    char *c2 = strchr(a2, b2);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c2, c2);
    char *d2 = my_strchr(a2, b2);
    printf("||| my_strchr: [%p], [%s]\n", d2, d2);
    if (c2 != d2) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 3rd
    char a3[] = "Your eyes can see";
    char b3 = 'p';
    printf("||| 3번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%c]\n", a3, b3);
    char *c3 = strchr(a3, b3);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c3, c3);
    char *d3 = my_strchr(a3, b3);
    printf("||| my_strchr: [%p], [%s]\n", d3, d3);
    if (c3 != d3) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }
    return true;
}

bool test_strstr() {
    printf("*** 3회 strstr 동작을 테스트합니다.\n");

    // 1th
    char a1[] = "And disciplinary remains mercifully";
    char b1[] = "rem";
    printf("||| 1번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%s]\n", a1, b1);
    char *c1 = strstr(a1, b1);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c1, c1);
    char *d1 = my_strstr(a1, b1);
    printf("||| my_strstr: [%p], [%s]\n", d1, d1);
    if (c1 != d1) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 2nd
    char a2[] = "Yes and um, I\'m with you Derek, this star nonsense";
    char b2[] = "\'m";
    printf("||| 2번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%s]\n", a2, b2);
    char *c2 = strstr(a2, b2);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c2, c2);
    char *d2 = my_strstr(a2, b2);
    printf("||| my_strstr: [%p], [%s]\n", d2, d2);
    if (c2 != d2) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }

    // 3rd
    char a3[] = "Yes, yes";
    char b3[] = "yest";
    printf("||| 3번째 테스트 결과\n");
    printf("||| 검색 문자열, 문자: [%s], [%s]\n", a3, b3);
    char *c3 = strstr(a3, b3);
    printf("||| 의도한 포인터값 및 문자열: [%p], [%s]\n", c3, c3);
    char *d3 = my_strstr(a3, b3);
    printf("||| my_strstr: [%p], [%s]\n", d3, d3);
    if (c3 != d3) {
        printf("||| 결과: 실패!\n\n");
        return false;
    }
    else {
        printf("||| 결과: 성공!\n\n");
    }
    return true;
}
