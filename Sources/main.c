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

// Ű���带 �Է¹ް�, �Է¹��� Ű������ ������ ��ȯ�Ѵ�.
int input_keywords(KEYnMES keynmes) {
  // �� ���� Ű���尡 �ִ��� ������ ����
  int keyword_count = 0;
  printf(
      "�ִ� %d ������ ���� Ű���带 �Է��ϼ���. (�Է��� ��ġ���� !�� �Է��ϼ���)\n",
      MAX_KEYWORD_SIZE);
  for (int i = 0; i < MAX_KEYWORD_COUNT; i++) {
    printf("%d��° Ű����: ", i + 1);
    scanf_s("%s", keynmes.keyword[i], MAX_KEYWORD_SIZE);

    if (keynmes.keyword[i][0] == '!') {
      keyword_count = i;
      printf("Ű���� �Է��� �������ϴ�.\n\n");
      break;
    }
  }

  printf("�Է��Ͻ� Ű����� �� %d�� �Դϴ�.\n", keyword_count);
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
  // �޽����� ������ ����ü�� �����Ҵ�, �ʱ�ȭ
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

  // �޼����� ����, Ű������ ������ ������ ����
  int message_count = 0;
  int keyword_count = 0;

  // ������ �޴��� ������ ����
  int menu = 0;

  printf("**********�ڵ� �޼��� ������**********\n\n");

  while (1) {
    printf("---------�޴��� �����ϼ���----------\n");
    printf("1. Ű����� �޼��� �����ϱ�\n");
    printf("2. �޼��� ����ϱ�\n");
    printf("3. �޼��� ������ϱ�\n");
    printf("4. �޼��� �����ϱ�\n");
    printf("5. ������ �޼��� ���Ϸ� �����ϱ�\n");
    printf("6. �����ϱ�\n");
    scanf_s("%d", &menu);
    // break;

    if (menu == 1) {
      // Ű���带 �Է¹ް� ������ ������ �����Ѵ�.
      keyword_count = input_keywords(keynmess[message_count]);
      // chatgpt api�� �̿��ؼ� Ű���带 ���� �޼����� �ۼ��Ѵ�.
      keynmess[message_count].message =
          chatGPT(keynmess[message_count].keyword, keyword_count);
      // �ۼ��� �޼����� Ȯ���ϱ� ���� ����غ���.
      printf("%s\n\n", keynmess[message_count].message);
      message_count++;
    }

    else if (menu == 2) {
      printf("����� �޼����� ��ȣ�� �����ϼ��� (%d ~ %d) ", 1, message_count);
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
      printf("������� �޼����� ��ȣ�� �����ϼ��� (%d ~ %d) ", 1, message_count );
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
      printf("������ �޼����� ��ȣ�� �Է��ϼ��� (%d ~ %d) ", 1, message_count);
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
      printf("�����Ǿ����ϴ�.\n");
      message_count--;
        
    } else if (menu == 5) {
      printf("������� ������ ������ �̸��� �Է��ϼ���: ");
			char filename[128];
			scanf_s("%s", filename, 128);
      strcat_s(filename, sizeof(filename), ".txt");
      FILE *fp;
      fopen_s(&fp, filename, "w");
			for (int i = 0; i < message_count; i++) {
				fprintf(fp, "%d��° �޼���: %s\n", i + 1, keynmess[i].message);
			}
			fclose(fp);
			printf("����Ǿ����ϴ�!\n");
    }

    else if (menu == 6) {
      printf("���α׷��� �����մϴ�.\n");
      break;
    } 
    else {
      printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
    }
  }
}