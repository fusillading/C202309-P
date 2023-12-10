# C프로그래밍및실습 Repository

## 1. 개요
pure C로 ChatGPT와 통신하여 메세지를 생성하는 프로젝트를 구현했습니다.

## 2. 구현
### 2.1. ChatGPT와 통신
ChatGPT와 통신하기 위해 curl을 사용했습니다. curl은 C로 구현된 라이브러리로, HTTP 통신을 쉽게 구현할 수 있도록 도와줍니다. curl을 사용하기 위해선 curl.h 헤더파일을 include해야 합니다. curl을 사용하기 위해선 다음과 같은 순서로 진행해야 합니다. (visual studio 2022 기준)

1. https://curl.se/download.html 에서 curl-8.5.0.zip을 다운받고 압축을 풉니다.
2. curl-8.5.0\projects\Windows\VC14.30 으로 이동하여 curl-all.sln을 실행합니다.
3. DLL Debug - DLL Windows SSPI, x64를 선택하고 빌드합니다.
4. 빌드 결과는 curl-8.5.0\build\Win64\VC14.30\DLL Debug에서 확인할 수 있습니다.
5. repository 내의 Source/curl 폴더를 curl-8.5.0\include\curl 폴더로 덮어씁니다.
6. repository 내의 Source/lib 폴더를 생성하고 curl-8.5.0\build\Win64\VC14.30\DLL Debug\libcurld.lib 파일을 lib 폴더로 복사합니다.
7. 프로젝트 실행 경로에 curl-8.5.0\build\Win64\VC14.30\DLL Debug\libcurld.dll 파일을 복사합니다.

8. 프로젝트 속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리에 $(ProjectDir)\include를 추가합니다.
9. 프로젝트 속성 -> 구성속성 -> C/C++ -> 전처리기 -> 전처리기 정의에 CURL_STATICLIB를 추가합니다.
10. 프로젝트 속성 -> 구성속성 -> 링커 -> 일반 -> 추가 라이브러리 디렉터리에 $(ProjectDir)\lib를 추가합니다.
11. 프로젝트 속성 -> 구성속성 -> 링커 -> 입력 -> 추가 종속성에 libcurld.lib를 추가합니다.

버전은 조금 다르지만 [이 사이트](https://velog.io/@yeonji/C-Curl-%EB%B9%8C%EB%93%9C-%EB%B0%8F-Visual-Studio-2019-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%A0%81%EC%9A%A9)를 참고하시면 이미지와 함께 진행 할 수 있습니다.
