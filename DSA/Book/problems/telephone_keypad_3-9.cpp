/*3-9. [3] Write a function which, given a sequence of digits 2–9 and a dictionary of n
words, reports all words described by this sequence when typed in on a standard
telephone keypad. For the sequence 269 you should return any, box, boy, and
cow, among other words*/

#include <cstddef>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 1. For this I will need to first fetch the match letters from each number given
// 2. then for that latter fatch the word, this is definelty a map
int form_words(unordered_set<string> words,  string num_seq)
{

    // provided by model for testing
    unordered_map<char, char> letter_to_digit = 
    {
        {'a','2'},{'b','2'},{'c','2'},
        {'d','3'},{'e','3'},{'f','3'},
        {'g','4'},{'h','4'},{'i','4'},
        {'j','5'},{'k','5'},{'l','5'},
        {'m','6'},{'n','6'},{'o','6'},
        {'p','7'},{'q','7'},{'r','7'},{'s','7'},
        {'t','8'},{'u','8'},{'v','8'},
        {'w','9'},{'x','9'},{'y','9'},{'z','9'}
    };

    // a numbered can be the key for multiple words
    unordered_map<string, vector<string>> words_nums_word;
 
    /* Here we will loop through the words and create a new word from the mapping of the
        word using the map above (leeter_to_digit)*/
    for (string word: words)
    {
        string new_word;
        size_t word_size = word.size();

        for(int i = 0 ; i < word_size; ++i)
        {
            // iterator over the findings
            auto it = letter_to_digit.find(word[i]);
            if (it != letter_to_digit.end()) 
            {
                new_word += it->second;
            }
        }

        // add the word match with it's respective number
        words_nums_word[new_word].push_back(word);
    }

    // iterate through them to print all the words nicely
    auto iter = words_nums_word.find(num_seq);
    if(iter != words_nums_word.end())
    {
        // found
        for (string word : iter->second)
         {
            printf("word: %s\n", word.c_str());
        }
        return 1;
    }
    else 
    {
        printf("Nothing found\n");
        return 0;
    }
}


int main(void){
    // examples given by AI model to test algho
    // test passed

    string num_seq = "269";

unordered_set<string> words = {
    "any", "box", "boy", "cow", "cat", "bat", "dog", "fox",
    "ant", "bee", "ape", "owl", "eel", "elf", "ace", "act",
    "art", "arm", "arc", "ash", "ask", "axe", "bag", "ban",
    "bar", "bat", "bay", "bed", "bid", "big", "bit", "bog",
    "bow", "bud", "bug", "bus", "buy", "cab", "can", "cap",
    "cot", "cry", "cub", "cup", "cut", "day", "den", "dew",
    "did", "dig", "dim", "dip", "doe", "dot", "dry", "due",
    "dug", "ear", "eat", "egg", "end", "eye", "far", "fat",
    "few", "fig", "fin", "fit", "fix", "fly", "fog", "for",
    "fry", "fun", "fur", "gap", "gas", "get", "gum", "gun",
    "gut", "guy", "had", "ham", "has", "hat", "hay", "her"
};

    form_words(words, num_seq);

    return 0;
}
