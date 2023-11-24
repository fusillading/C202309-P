#include <string.h>

class ChatGPT
{
    public:
        explicit ChatGPT(const string& token);
        ChatCompletion askChatGPT(const string& role, const string& content);
    priavte:
        string m_token;
        string m_link;
};   