#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

// 응답을 바로 출력하지 않고 저장하기 위해 선언한 함수
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

  //HTTPS 통신을 위해 선언한 CURL 구조체
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  // curl이 정상적으로 시작 되었을 때
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://api.openai.com/v1/chat/completions");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    // 응답을 저장하고 있을 문자열
    char *response_data = NULL;

    //api 통신을 위해 구성요소를 만드는 부분
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(
        headers,
        "Authorization: Bearer "
        "api-key"); // 이부분에 api key를 입력한다.
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 요청을 보낼 때 어떤 응답을 받을 것인지 결정하는 가장 중요한 부분
    char data[1000]=
        "{\"model\": \"gpt-3.5-turbo\", "
        "\"messages\": [{\"role\": \"system\",\"content\": \"you are message "
        "generator using given words\"}, "
        "{\"role\": \"user\",  \"content\": \"generate message using ";
    // 사용자가 입력한 키워드가 요청 안에 들어갈 수 있도록  strcat_s 함수 이용
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
    // 응답 데이터가 response_data 안에 저장되도록 함
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    res = curl_easy_perform(curl);

    // 실패했을 경우의 알림 메세지
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    // 응답 데이터에서 필요한 부분을 파싱하는 부분
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

    // curl 변수를 메모리 해제시켜줌
    curl_global_cleanup();

    // 파싱된 부분을 반환함
    return ret;
  }

  curl_global_cleanup();
  return "error occured!";
}
