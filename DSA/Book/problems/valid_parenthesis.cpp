// Skiena Book question 3-1 Exercise 3-10
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(std::string s) {
    
    // for each open braquet I need one after to close it
    const char open = '(';
    const char close = ')';
    vector<int> stack;
    size_t str_s = s.size();
    bool status = true;
    int pos = -1;
    

    for (int i = 0; i < str_s ; ++i) {
        

        if(s[i] == open)
        {
            stack.push_back(i); // pushin postion where happend
        }
        else 
        {
            if(!stack.empty()) 
            {
                stack.pop_back();
            }
            else 
            {
                pos = i;
                return false;
            }
        }
    }

    if(!stack.empty()) 
    {
        status = false;
        pos = stack.back();
    }
    cout << pos << '\n' << '\n';
    return status;
}

int main(void)
{
    vector<string> inputs = {
        "((())())()",
        "()()()",
        "",
        ")",
        "(",
        "())(",
        "(()",
        "((())",
        "(()))(",
        "()("
    };
    
    for (string s: inputs)
    {
        bool result = isValid(s);
        cout << result << '\n'  ;
    }
    
}