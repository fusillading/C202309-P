#include <stdio.h>
#include <stdlib.h>
#include "ChatGPT.h"

#define MAX_KEYWORD_SIZE 128
#define MAX_KEYWORD_COUNT 20
#define MAX_MESSEGE_SIZE 256
#define MAX_MESSEGE_COUNT 256

typedef struct KEYnMES{
  int idx;
  int keyword_num;
  char** keyword;
  char *message;
}KEYnMES;

// 키워드를 입력받고, 입력받은 키워드의 개수를 반환한다.
int input_keywords(KEYnMES keynmes) {
  // 몇 개의 키워드가 있는지 저장할 변수
  int keyword_count = 0;
  printf(
      "최대 %d 글자의 키워드를 입력하세요. (입력을 마치려면 !를 입력하세요)\n",
      MAX_KEYWORD_SIZE);
  for (int i = 0; i < MAX_KEYWORD_COUNT; i++) {
    printf("%d번째 키워드: ", i + 1);
    scanf_s("%s", keynmes.keyword[i], MAX_KEYWORD_SIZE);

    if (keynmes.keyword[i][0] == '!') {
      keyword_count = i;
      printf("키워드 입력이 끝났습니다.\n\n");
      break;
    }
  }

  printf("입력하신 키워드는 총 %d개 입니다.\n", keyword_count);
  keynmes.keyword_num = keyword_count; 
  for (int i = 0; i < keyword_count; i++) {
    printf("%s", keynmes.keyword[i]);
    if (i < keyword_count - 1) {
      printf(", ");
    } else {
      printf("\n");
    }
  }

  return keyword_count;
}

int main() {
  // 메시지를 저장할 구조체를 동적할당, 초기화
  KEYnMES *keynmess =
      (KEYnMES *)malloc(MAX_MESSEGE_COUNT * (int)sizeof(KEYnMES));

  for (int i = 0; i < MAX_MESSEGE_COUNT; i++) {
    keynmess[i].idx = i + 1;
    keynmess[i].keyword =
        (char **)malloc(MAX_KEYWORD_COUNT * (int)sizeof(char *));
    for (int j = 0; j < MAX_KEYWORD_COUNT; j++) {
      keynmess[i].keyword[j] =
          (char *)malloc(MAX_KEYWORD_SIZE * (int)sizeof(char));
    }
    keynmess[i].message = (char *)malloc(MAX_MESSEGE_SIZE * (int)sizeof(char));
  }

  // 메세지의 개수, 키워드의 개수를 저장할 변수
  int message_count = 0;
  int keyword_count = 0;

  // 선택한 메뉴를 저장할 변수
  int menu = 0;

  printf("**********자동 메세지 생성기**********\n\n");

  while (1) {
    printf("---------메뉴를 선택하세요----------\n");
    printf("1. 키워드로 메세지 생성하기\n");
    printf("2. 메세지 출력하기\n");
    printf("3. 메세지 재생성하기\n");
    printf("4. 메세지 삭제하기\n");
    printf("5. 종료하기\n");
    scanf_s("%d", &menu);
    // break;

    if (menu == 1) {
      // 키워드를 입력받고 개수를 변수에 저장한다.
      keyword_count = input_keywords(keynmess[message_count]);

      // TODO. 메세지 생성하는 기능 추가
      keynmess[message_count].message =
          chatGPT(keynmess[message_count].keyword, keyword_count);
      printf("%s\n", keynmess[message_count].message);
    }

    else if (menu == 2) {
      // TODO. 메세지 출력하는 기능 추가
    }

    else if (menu == 3) {
      // TODO. 메세지 재생성하는 기능 추가
    }

    else if (menu == 4) {
      // TODO. 메세지 삭제하는 기능 추가
    }

    else if (menu == 5) {
      printf("프로그램을 종료합니다.\n");
      break;
    }
  }
}