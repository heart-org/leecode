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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> m;
        stack<double> s;
        for (int i = 0; i < position.size(); ++i) {
            m.insert(pair<int, int>(position[i], speed[i]));
        }
        for (map<int,int>::iterator it = m.begin();it != m.end();it++){
            double time = double(target - it->first) / it->second;
            while(!s.empty() && s.top() <= time){
                s.pop();
            }
            s.push(time);
        }
        return s.size();
    }
};



int main(){
    double a = (8 - 5) / 2;
    double b = double(8 - 5) / 2;
    cout << a << endl;
    cout << b << endl;

    return 0;
}