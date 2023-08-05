#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n <= 0) { return; }

        int point = 0;
        int index = 0;
        while (point < n) {
            //
            if (n - point == m + n - index) {
                nums1[index] = nums2[point];
                index ++;
                point ++;
                continue;
            }
            //
            while (nums1[index] <= nums2[point] && index < m + point) {
                index++;
            }
            if (index >= m + point) {
                continue;
            }
            // 
            nums1.insert(nums1.begin()+index, nums2[point]);
            nums1.erase(nums1.end()-1);
            point++;
        }
    }
};

int main() {
    Solution solution;

    vector<int> vec11 = {1,2,3,0,0,0};
    vector<int> vec12 = {2,5,6};
    solution.merge(vec11, 3, vec12, 3);

    // vector<int> vec11 = {1};
    // vector<int> vec12 = {};
    // solution.merge(vec11, 1, vec12, 0);

    // vector<int> vec11 = {0,0,0};
    // vector<int> vec12 = {1,2,3};
    // solution.merge(vec11, 3, vec12, 3);

    
    // cout << solution.climbStairs(2) << endl;
    // cout << solution.climbStairs(3) << endl; 
    // cout << solution.climbStairs(15) << endl; // 987
    // cout << solution.climbStairs(25) << endl; // 121393

    cout << "end";

    return 0;
}