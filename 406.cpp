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

using vec_type = vector<int>;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), change_seq);//sort要求成员函数必须是静态或全局
        for (int i = 0; i < people.size(); ++i) {
            if (i != people[i][1]) {
                auto it = people.begin() + people[i][1];
                people.insert(it, people[i]);
                people.erase(people.begin() + i + 1);
            }
        }
        return people;
    }

private:
    static bool change_seq(vec_type &a, vec_type &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};

int main() {
    Solution s;

    return 0;
}