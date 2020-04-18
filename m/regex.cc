#include <iostream>
#include <regex>
#include <string>

using namespace std;

void testRegx()
{
    regex regx("h(.+?)llo", regex::icase);
    string str = "hello world!hollo world....hallo1  heello2";

    bool remr = regex_match(str, regx); //regex_match全字符串匹配
    if (remr) {
        cout << "matched" << endl;
    } else {
        cout << "not matched" << endl;
    }

    smatch mch;
    string newStr = str;
    while (regex_search(newStr, mch, regx)) { //regex_search查找子字符串
        cout << "searched:" << mch.str() << endl;
        newStr = mch.suffix().str();
    }

    std::cout << std::regex_replace(str, regx, "hi-$1") << endl;

    cout << str << endl;
}
int main()
{
    testRegx();
    return 0;
}