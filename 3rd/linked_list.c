#include <stdio.h>
#define MAX_NAME_SIZE 20
// 필요한 라이브러리 추가

// singly Linked List 구조체 선언
// singly Linked List란 다음 객체에 대한 정보만을 갖고 있는 Linked List를 뜻한다
// 이 구조체는 별칭이 sLinkedList야 한다
// 멤버로는 최대 20칸 문자열 name, 몇번째로 생성되었는지 말해주는 int id, 다음 노드를 가리키는 next가 있어야 한다.


// 새 노드 생성 함수
// 입력값: 이름
// 이 때 id는 매 호출시마다 1번부터 시작하여 하나씩 늘려가며 넣어준다.
sLinkedList *createNode(char *name) {

}

// 노드 추가 함수
// 입력값: 이전 노드 priorNode, 추가할 노드 newNode
void appendNode(sLinkedList *priorNode, sLinkedList *newNode) {

}

// 노드 삭제 함수
// 입력값: 삭제하고자 하는 노드 Node
void removeNode(sLinkedList *Node) {

}

// 전체 노드 삭제 함수
// 입력값: 1번째 노드
void removeAllNode(sLinkedList *firstNode) {

}

// 이름 기반 검색 함수
// 입력값: 1번째 노드, 검색할 이름
// 반환값: 해당 노드의 포인터 / 없으면 NULL
sLinkedList searchByName(sLinkedList *firstNode, char *toSearch) {

}

// id 기반 검색 함수
// 입력값: 1번째 노드, 검색할 id
// 반환값: 해당 노드의 포인터 / 없으면 NULL
sLinkedList searchById(sLinkedList *firstNode, int id) {
    
}

// 노드 출력 함수
// 입력값: 출력하고자 하는 노드 Node
// 부족한 곳을 채워넣으시오
void printNode(sLinkedList *Node) {
    printf("\n-|-|-| 노드 정보 출력 |-|-|-\n");
    printf("노드 이름: %s\n", );
    printf("생성 번호: %d\n", );
    if ( == NULL) printf("다음 노드: %p\n", );
    else printf("다음 노드: NULL\n", );
}

int main() {
    // 검증 - 아직 미완성 -
    return 0;
}