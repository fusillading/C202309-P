#include <stdio.h>

#define MAX_KEYWORD_SIZE 128
#define MAX_KEYWORD_COUNT 20
#define MAX_MESSEGE_SIZE 256
#define MAX_MESSEGE_COUNT 256

// Ű���带 �Է¹ް�, �Է¹��� Ű������ ������ ��ȯ�Ѵ�.
int input_keywords(char keywords[MAX_KEYWORD_COUNT][MAX_KEYWORD_SIZE]) {
  // �� ���� Ű���尡 �ִ��� ������ ����
  int keyword_count = 0;
  printf(
      "�ִ� %d ������ Ű���带 �Է��ϼ���. (�Է��� ��ġ���� !�� �Է��ϼ���)\n",
      MAX_KEYWORD_SIZE);
  for (int i = 0; i < MAX_KEYWORD_COUNT; i++) {
    printf("%d��° Ű����: ", i + 1);
    scanf_s("%s", keywords[i], MAX_KEYWORD_SIZE);

    if (keywords[i][0] == '!') {
      keyword_count = i;
      printf("Ű���� �Է��� �������ϴ�.\n\n");
      break;
    }
  }

  printf("�Է��Ͻ� Ű����� �� %d�� �Դϴ�.\n", keyword_count);
  for (int i = 0; i < keyword_count; i++) {
    printf("%s", keywords[i]);
    if (i < keyword_count - 1) {
      printf(", ");
    } else {
      printf("\n");
    }
  }

  return keyword_count;
}

int main() {
  // �޽����� ������ �迭
  char messeges[MAX_MESSEGE_COUNT][MAX_MESSEGE_SIZE];
  // Ű���带 ������ �迭
  char keywords[MAX_MESSEGE_COUNT][MAX_KEYWORD_COUNT][MAX_KEYWORD_SIZE];

  // �޼����� ����, Ű������ ������ ������ ����
  int messege_count = 0;
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
    printf("5. �����ϱ�\n");
    scanf_s("%d", &menu);

    if (menu == 1) {
      // Ű���带 �Է¹ް� ������ ������ �����Ѵ�.
      keyword_count = input_keywords(keywords[messege_count]);

      // TODO. �޼��� �����ϴ� ��� �߰�
    }

    else if (menu == 2) {
      // TODO. �޼��� ����ϴ� ��� �߰�
		}

		else if (menu == 3) {
			// TODO. �޼��� ������ϴ� ��� �߰�
		}

		else if (menu == 4) {
			// TODO. �޼��� �����ϴ� ��� �߰�
		}

		else if (menu == 5) {
			printf("���α׷��� �����մϴ�.\n");
			break;
  }
}