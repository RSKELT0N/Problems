#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> lettersMag;
unordered_map<char, int> lettersRan;

bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.size() == 1 && magazine.size() == 1)
        if(magazine[0] != ransomNote[0])
            return false;

    if (magazine.size() < ransomNote.size())
        return false;

    for (char a : magazine) {
        if (lettersMag.find(a) == lettersMag.end())
            lettersMag.insert({a, 1});
        else
            lettersMag.insert({a, lettersMag.at(a)++});
    }

    for (char a : ransomNote) {
        if (lettersRan.find(a) == lettersRan.end())
            lettersRan.insert({a, 1});
        else
            lettersRan.insert({a, lettersRan.at(a)++});
    }
    for (pair<char, int> element : lettersMag) {
        try {
            if (element.second < lettersRan.at(element.first)) {
                return false;
            }
        } catch (exception e) {
        }
    }

    for (pair<char, int> element : lettersRan) {
        try {
            if (element.second > lettersMag.at(element.first)) {
                return false;
            }
        } catch (exception e) {
            return false;
        }
    }

    return true;
}


bool canConstruct1(string ransomNote, string magazine) {
    vector<int> count(128);
    for(auto c : ransomNote) {
        ++count[c];
    }

    for(auto c : magazine) {
        --count[c];
    }

    return none_of(cbegin(count),
                    cend(count),
                    [](int x) { return x > 0; });
}

int main() {
    cout << canConstruct1("a", "b");
    return 0;
}
