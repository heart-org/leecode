#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
//      [1,3,5,2,7,9,2,5,5]
        for (const auto &num: nums) {
            m[num]++;
        }
        vector<pair<int, int>> pairs;
        pairs.reserve(m.size());
        for (const auto &p: m) {
            pairs.emplace_back(p);
        }
        sort(pairs.begin(), pairs.end(), [&](pair<int, int> pari1, pair<int, int> pari2) {
            return pari1.second > pari2.second;
        });
        for(int i = 0; i < k; i++){
            ans.push_back(pairs[i].first);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    s.topKFrequent(nums, k);

    return 0;
}