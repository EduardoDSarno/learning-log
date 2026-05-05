// Skiena Book question 3-2 Exercise 3-10
#include <cstddef>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int valid_patenthesis_paris(const string s)
{

    stack<int> stack;
    size_t len = s.size();

    const char open = '(';
    const char close = ')';

    int num = 0;

    for (int i = 0 ; i < len; ++i) 
    {
        
        if (s[i] == open) 
        {
            stack.push(i);
        }
        else if (s[i] == close && !stack.empty()) 
        {
            num++;
            stack.pop();
        }
    }
    return num * 2;
}

int main(void){

    string test = ")()(())()()))())))(";

    printf("%d\n", valid_patenthesis_paris(test));
}