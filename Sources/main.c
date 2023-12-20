#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
      "최대 %d 글자의 영문 키워드를 입력하세요. (입력을 마치려면 !를 입력하세요)\n",
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
    printf("5. 생성된 메세지 파일로 저장하기\n");
    printf("6. 종료하기\n");
    scanf_s("%d", &menu);
    // break;

    if (menu == 1) {
      // 키워드를 입력받고 개수를 변수에 저장한다.
      keyword_count = input_keywords(keynmess[message_count]);
      // chatgpt api를 이용해서 키워드를 통해 메세지를 작성한다.
      keynmess[message_count].message =
          chatGPT(keynmess[message_count].keyword, keyword_count);
      // 작성된 메세지를 확인하기 위해 출력해본다.
      printf("%s\n\n", keynmess[message_count].message);
      message_count++;
    }

    else if (menu == 2) {
      printf("출력할 메세지의 번호를 선택하세요 (%d ~ %d) ", 1, message_count);
      int print = -1;
      while (1) {
        scanf_s("%d", &print);

        if (print < 1 || print > message_count) {
          continue;
        } else
          break;
      }
      printf("\n%s\n\n", keynmess[print-1].message);
    }

    else if (menu == 3) {
      printf("재생성할 메세지의 번호를 선택하세요 (%d ~ %d) ", 1, message_count );
      int remake = -1;
      while (1) {
        scanf_s("%d", &remake);

        if (remake < 1 || remake > message_count) {
          continue;
        } else
          break;
      }

      keynmess[remake-1].message =
          chatGPT(keynmess[remake-1].keyword, keyword_count);
      printf("\n%s\n\n", keynmess[remake - 1].message);
    }

    else if (menu == 4) {
      printf("삭제할 메세지의 번호를 입력하세요 (%d ~ %d) ", 1, message_count);
      int remove = -1;
      while (1) {
        scanf_s("%d", &remove);

        if (remove < 1 || remove > message_count) {
          continue;
        } else
          break;
      }
      for (int i = remove - 1; i < message_count - 1; i++) {
				keynmess[i] = keynmess[i + 1];
        keynmess[i].idx = i;
			}
      printf("삭제되었습니다.\n");
      message_count--;
        
    } else if (menu == 5) {
      printf("공백없이 저장할 파일의 이름을 입력하세요: ");
			char filename[128];
			scanf_s("%s", filename, 128);
      strcat_s(filename, sizeof(filename), ".txt");
      FILE *fp;
      fopen_s(&fp, filename, "w");
			for (int i = 0; i < message_count; i++) {
				fprintf(fp, "%d번째 메세지: %s\n", i + 1, keynmess[i].message);
			}
			fclose(fp);
			printf("저장되었습니다!\n");
    }

    else if (menu == 6) {
      printf("프로그램을 종료합니다.\n");
      break;
    } 
    else {
      printf("잘못된 입력입니다. 다시 입력해주세요.\n");
    }
  }
}