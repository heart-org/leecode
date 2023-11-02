#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "algorithm"
#include "cstring"
#include "cmath"
#include "set"
#include "map"
#include "numeric"
#include "unordered_set"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }

};

int main() {
    vector<int> numbers = {5, 25, 75};
    int target = 100;
    Solution().twoSum(numbers, target);


    return 0;
}