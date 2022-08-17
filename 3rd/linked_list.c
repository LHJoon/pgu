#include <stdio.h>
#define MAX_NAME_SIZE 20
// 필요한 라이브러리 추가
// 전체 통용 : 다음 node가 존재하지 않을 때에는, 그 다음 노드값은 NULL (NULL 포인터)이다.

// singly Linked List 구조체 선언
// singly Linked List란 다음 객체에 대한 정보만을 갖고 있는 Linked List를 뜻한다
// 이 구조체는 별칭이 sLinkedList야 한다
// 멤버로는 최대 20칸 문자열 name, 몇번째로 생성되었는지 말해주는 int id, 다음 노드를 가리키는 next가 있어야 한다.
/*
여기에 구조체 선언.
*/

// 새 노드 생성 함수
// 입력값: 이름
// 이 때 id는 매 호출시마다 1번부터 시작하여 하나씩 늘려가며 넣어준다.
// 노드 생성해서 초기화해주고, 포인터 반환해주면 됨 , 무조건 malloc

sLinkedList* createNode(char *name) {


}

// 노드 추가 함수
// 입력값: 이전 노드 priorNode, 추가할 노드 newNode 
// create한 놈을 임의의 노드 뒤에다가 이어주는 친구임. 링크드리스트 사진 찾아보고, 구조에 대해 고민해볼 것
void appendNode(sLinkedList *priorNode, sLinkedList *newNode) {

}

// 노드 삭제 함수
// 입력값: 삭제하고자 하는 노드 Node 구조에 대해 잘 생각해볼 것. 1234중 2가 삭제되면 134가 연결되어있어야함
void removeNode(sLinkedList *Node) {

}

// 전체 노드 삭제 함수
// 입력값: 1번째 노드   // 전체 노드를 그냥 전부 삭제하면 됨. 프로그램 종료 직전에 할거임. 여태까지 할당한 동적을 모두 free해주어야 함 (효율적으로 할 것)
void removeAllNode(sLinkedList *firstNode) {

}

// 이름 기반 검색 함수
// 입력값: 1번째 노드, 검색할 이름
// 반환값: 해당 노드의 포인터 / 없으면 NULL     // 첫번쨰 노드 포인터 넣어주면 그 다음노드부터 탐색하면서 찾아주는거
sLinkedList searchByName(sLinkedList *firstNode, char *toSearch) {

}

// id 기반 검색 함수
// 입력값: 1번째 노드, 검색할 id
// 반환값: 해당 노드의 포인터 / 없으면 NULL
sLinkedList searchById(sLinkedList *firstNode, int id) {
    
}

// 노드 출력 함수
// 입력값: 출력하고자 하는 노드 Node
// 부족한 곳을 채워넣으시오         //빈칸만 찾아 넣도록.
void printNode(sLinkedList *Node) {
    printf("\n-|-|-| 노드 정보 출력 |-|-|-\n");
    printf("노드 이름: %s\n", );
    printf("생성 번호: %d\n", );
    if ( == NULL) printf("다음 노드: %p\n", );
    else printf("다음 노드: NULL\n", );
}

int main() {    // 검증코드 미완성시 직접 짜서 확인해라 아그야
    // 검증 - 아직 미완성 -
    return 0;
}
