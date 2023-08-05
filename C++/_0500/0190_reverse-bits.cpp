#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i=0; i<32; i++) {
            result *= 2;
            result += n % 2;
            n /= 2;
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        uint32_t result = solution.reverseBits(43261596);
        cout << endl;
    }
    {
        uint32_t result = solution.reverseBits(4294967293);
        cout << endl;
    }
    cout << "end";

    return 0;
}