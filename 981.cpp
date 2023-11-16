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

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> kvt;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        kvt[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        vector<pair<string, int>>& tmp = kvt[key];
        int l = 0, r = tmp.size(), res = -1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (tmp[m].second <= timestamp) {
                res = m;
                l = m + 1;
            }
            else r = m;
        }
        return res == -1 ? "" : tmp[res].first;
    }
};

int main(){
    map<int, int> m;
    m.insert({1, 1});
    cout << m[1] << endl;


    return 0;
}