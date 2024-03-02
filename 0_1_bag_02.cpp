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
#include "array"
#include "cctype"
#include "list"

using namespace std;

class Solution {
public:
    void solve() {
        init_bag();
        vector<int> dp(bag_weight + 1, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = bag_weight; j >= weight[i]; --j) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[bag_weight];
    }

private:
    int n;
    int bag_weight;
    vector<int> value;
    vector<int> weight;

    void init_bag() {
        cout << "input n:" << endl;
        cin >> n;
        cout << "input bag_weight:" << endl;
        cin >> bag_weight;

        value.resize(n);
        weight.resize(n);

        cout << "input value:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> value[i];
        }
        cout << "input weight:" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> weight[i];
        }
    }
};

int main() {
    Solution s;
    s.solve();

    return 0;
}