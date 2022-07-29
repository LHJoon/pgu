#include <stdio.h>

/*
// strlen 구현 완-료

int main()
{ 
    char *s1 = "Hello";
    int i = 0;
    while(s1[i] != (char)0)    //str[i]가 NULL을 만나기 전까지 세어준다
    {
        i +=1;          // NULL만나기 전까지 COUNT
    }
    printf("%d\n", i);

    return 0;
}
*/

//strcpy(char *dest, const char* origin, const int dest_len)
int main(){

    // const char *origin을 char* dest에 그대로 갖다 넣어주면 된다.
    // 이 때, dest의 크기에 맞춰서 진행해야 한다.
    // dest_len의 크기가 origin보다 작다면, origin[count]가 '\0'를 만났을 때 멈춰주면 된다.
    int count = 0;

    while(dest[count] != '\0')  //dest[count]가 NULL을 만나기 전까지
    {
        dest[count] = origin[count];    //origin을 순차적으로 dest에 넣는다.
        /*if(dest_len < mystrlen(origin)) //만약 dest_len의 크기가
        {
            while(origin[count] != '\0')
            {

            }
        }
        */
       return dest;
    }

}