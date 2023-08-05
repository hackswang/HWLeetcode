#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map <int, int> hash_map;
        for (int i=0; i<jewels.size(); i++) {
            hash_map[jewels[i]] = 1;
        }
        int result = 0;
        for (int i=0; i<stones.size(); i++) {
            if (hash_map.find(stones[i]) != hash_map.end()) {
                result ++;
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.numJewelsInStones("aA", "aAAbbbb");
        cout << endl;
    }
    {
        int result = solution.numJewelsInStones("z", "ZZ");
        cout << endl;
    }
    cout << "end";

    return 0;
}