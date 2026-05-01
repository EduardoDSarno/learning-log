/*3-10: Two strings X and Y are anagrams if the letters of X can be rearranged
to form Y. For example, silent/listen, and incest/insect are anagrams. Give an
eﬃcient algorithm to determine whether strings X and Y are anagrams.*/
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

/*I think the most efficent one will be creating a set with the chars of one word and
 checking all the other chars of the other word with it if any fails return false*/
int isAnagram(string x, string y)
{

    unordered_set<char> first;

    for (char i : x) 
    {
        first.insert(i);
    }

    for (char i : y) 
    {
        auto it = first.find(i);

        if(it == first.end()) // not found
        {
            return 0;
        }
    }
    return 1;
}
int main(void){

    const string x = "silent";
    const string y = "listen";
    int result = isAnagram(x,y);

    (result == 1) ? cout << "Yes" : cout << "No";
    cout << '\n';

    return 0;
}