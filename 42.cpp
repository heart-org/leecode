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
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;
        int h = 0;
        int width = 0;
        int left = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (!s.empty() && height[s.top()] < height[i]){
                while (!s.empty() && height[s.top()] < height[i]){
                    int mid = s.top();
                    s.pop();
                    if (!s.empty()){
                        left = s.top();
                        h = min(height[left], height[i]) - height[mid];
                        width = i - left - 1;
                        res += h * width;
                    }
                }
            }
            s.push(i);
        }
        return res;
    }
};

int main(){

    return 0;
}