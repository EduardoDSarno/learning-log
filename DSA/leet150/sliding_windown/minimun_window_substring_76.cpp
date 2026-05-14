#include <cctype>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int left = 0,right = 0, min_windon = INT_MAX;
        string result = "";
        unordered_set<int> t_letters_idx;

        // cover both upper and lowercase
        int freqt[52]  = {0};
        int freq2[52] = {0};

        for (char c : t) 
        {
            increment_freq_array(c, freqt);
            t_letters_idx.insert(charIndex(c));
        }

        while(right < s.size())
        {
            int idx = charIndex(s[right]);
 
            freq2[idx]++; // insert
            bool covers = true;
            while(covers)
            {
            
                // this loops hardcore checks if it is valid meaning all frequecnies in freqt
                // are covered in freq2. Because if their count is bigger they are covered
                for (int i: t_letters_idx)
                {
                    if (freq2[i] < freqt[i]) 
                    { 
                        covers = false;
                        break; 
                    }
                }
                if (!covers) break;
                // if we cover all the characters, windown is valid
                // so we shrink to find where it is the minimun valid
                int window = right - left + 1;
                if(window < min_windon) 
                {
                    min_windon = window;
                    result = s.substr(left, min_windon);
                    //cout << result << '\n';
                }
                // since we only insert in freq2 the character that are in t
                // if they are not there we don't need to decrement
                // making it follow the same rule
                int idx = charIndex(s[left]);
                if (freqt[idx] > 0) freq2[idx]--;
                left++;
            }
        
            right++;
        }
        cout << result << '\n';
        return result;
    }
    /* this is a helper to calcualte index for 52 item frequency array*/
    void increment_freq_array(char c, int *freq)
    {
        int idx = charIndex(c);
        freq[idx]++;
    }
    int charIndex(char c)
    {
        int idx;
        if ('a' <= c && c <= 'z')
        {
            idx = c - 'a';
        }
        else
        {
            idx = c - 'A' + 26;
        }
        return idx;
    }
};

int main(void)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;

    solution.minWindow(s, t);
}