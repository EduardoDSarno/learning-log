#include <cctype>
#include <cstddef>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        size_t length = s.length();
        int cleaned_count = 0;

        string cleaned = "";

        for(char c : s){
            if(isalnum(c)){
                cleaned += tolower(c);
            }
        }

        int index_front = 0;
        int index_end = cleaned.length() - 1;
        while(index_front <= index_end){

            if(cleaned[index_front] != cleaned[index_end]){
                return false;
            }

            index_front++;
            index_end--;
        }

        return true;
    }
};