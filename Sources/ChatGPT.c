#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// ������ �ٷ� ������� �ʰ� �����ϱ� ���� ������ �Լ�
size_t write_callback(void *contents, size_t size, size_t nmemb,
                      char **output) {
  size_t realsize = size * nmemb;

  *output = realloc(*output, realsize + 1);
  if (*output) {
    memcpy(*output, contents, realsize);
    (*output)[realsize] = '\0';
  }

  return realsize;
}

char* chatGPT(char** keywords, int keyword_count) {

  //HTTPS ����� ���� ������ CURL ����ü
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  // curl�� ���������� ���� �Ǿ��� ��
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://api.openai.com/v1/chat/completions");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    // ������ �����ϰ� ���� ���ڿ�
    char *response_data = NULL;

    //api ����� ���� ������Ҹ� ����� �κ�
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(
        headers,
        "Authorization: Bearer "
        "api-key"); // �̺κп� api key�� �Է��Ѵ�.
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // ��û�� ���� �� � ������ ���� ������ �����ϴ� ���� �߿��� �κ�
    char data[1000]=
        "{\"model\": \"gpt-3.5-turbo\", "
        "\"messages\": [{\"role\": \"system\",\"content\": \"you are message "
        "generator using given words\"}, "
        "{\"role\": \"user\",  \"content\": \"generate message using ";
    // ����ڰ� �Է��� Ű���尡 ��û �ȿ� �� �� �ֵ���  strcat_s �Լ� �̿�
    for (int i = 0; i < keyword_count; i++) {
      //printf("%d %d", strlen(data), strlen(keywords[i]));
      strcat_s(data, sizeof(data), keywords[i]);
      if (i != keyword_count - 1)
        strcat_s(data, sizeof(data), ", ");
      else
        strcat_s(data, sizeof(data), "\"");
    }
    strcat_s(data, sizeof(data),"}], \"temperature\": 0.2, \"max_tokens\": 50}");


    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    // ���� �����Ͱ� response_data �ȿ� ����ǵ��� ��
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    res = curl_easy_perform(curl);

    // �������� ����� �˸� �޼���
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    // ���� �����Ϳ��� �ʿ��� �κ��� �Ľ��ϴ� �κ�
    char *temp = strstr(response_data, "content");
    int quot_cnt = 0;
    int ret_length = 0;

    for (int i = 0; i < strlen(response_data); i++){
      if (temp[i] == '\"') {
        quot_cnt++;
      }
      if (quot_cnt == 3) {
        ret_length = i;
        break;
      }
    }

    char *ret = (char *)malloc(ret_length-10);
    for (int i = 0; i < ret_length-11; i++) {
      ret[i] = temp[i+11];
    }
    ret[ret_length-11] = '\0';

    // curl ������ �޸� ����������
    curl_global_cleanup();

    // �Ľ̵� �κ��� ��ȯ��
    return ret;
  }

  curl_global_cleanup();
  return "error occured!";
}
