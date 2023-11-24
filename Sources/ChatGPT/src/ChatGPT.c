#include "../include/ChatGPT.h"
#include <stdio.h>

ChatGPT::ChatGPT(const string& token): m_token{token}, m_link{"https://api.openai.com/v1/chat/completions"}) {

}

ChatGPT::askChatGPT(const std::string& role, const std::string& content)
{

    //TODO: 메세지 생성하는 기능 구현
    string messege;
    return messege;
}
