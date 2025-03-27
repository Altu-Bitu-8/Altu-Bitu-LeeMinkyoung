#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void alphabetCount(int &ans, const vector<int> &first_word_alphabet, const vector<string> &words, int n, string first_word) {
    n--;
    while (n--) {
        vector<int> alphabet(26,0);
        for(char ch : words[n]) {
            alphabet[ch - 'A']++;
        }
        int diff = 0;
        for(int i = 0; i<26; i++) {
            diff += abs(first_word_alphabet[i] - alphabet[i]);
        }
        if(diff == 1 || diff == 0) {
            ans++;
        }
        else if(diff == 2 && words[n].length() == first_word.length()) {
            ans++;
        }
    }


}

void getWords(int n, vector<string> &words) {
    --n;
    while (n--) {
        string word;
        cin >> word;
        words.push_back(word);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    int n;
    cin >> n;
    string first_word;
    cin >> first_word;
    vector<string> words;
    vector<int> first_word_alphabet(26, 0);
    int ans = 0;

    //연산
    for (char ch : first_word) {
        first_word_alphabet[ch - 'A']++;
    }

    getWords(n, words);
    alphabetCount(ans, first_word_alphabet, words, n, first_word);

    //출력
    cout << ans;

    return 0;
}
