#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        //
        unordered_map<int, int> cache;
        unordered_map<int, int> cursor;
        //
        for (int i=0; i<chars.size(); i++) {
            if (cache.find(chars[i]) == cache.end()) {
                cache[chars[i]] = 1;
            } else {
                cache[chars[i]]++;
            }
        }
        //
        for (int i=0; i<words.size(); i++) {
            cursor = cache;
            bool success = true;
            for (int j=0; j<words[i].size(); j++) {
                if (cursor.find(words[i][j]) == cursor.end() || cursor[words[i][j]] <= 0) {
                    success = false;
                    break;
                } else {
                    cursor[words[i][j]]--;
                }
            }
            if (success) {
                result += words[i].size();
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<string> input = {"cat","bt","hat","tree"};
        int result = solution.countCharacters(input, "atach");
        cout << endl;
    }
    {
        vector<string> input = {"hello","world","leetcode"};
        int result = solution.countCharacters(input, "welldonehoneyr");
        cout << endl;
    }
    cout << "end";

    return 0;
}