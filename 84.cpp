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

/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] == 0)
                continue;
            int left = 0;
            int right = 0;
            int now_res = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (heights[j] >= heights[i]){
                    left++;
                }else
                    break;
            }
            for (int k = i + 1; k < heights.size(); ++k) {
                if(heights[k] >= heights[i]){
                    right++;
                }else
                    break;
            }
            now_res = (left + right + 1) * heights[i];
            if (now_res > res)
                res = now_res;
        }
        return res;
    }
};
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        for (int i = 0; i < heights.size(); ++i) {
            if(!s.empty() && heights[i] >= heights[s.top()]){
                s.push(i);
            }else{
                while(!s.empty() && heights[i] < heights[s.top()]){
                    int mid = s.top();
                    s.pop();
                    if (!s.empty()){
                        int left = s.top();
                        int right = i;
                        int h = heights[mid];
                        int width = right - left - 1;
                        res = max(h * width, res);
                    }
                }
                s.push(i);
            }
        }
        return res;
    }
};


int main(){
    vector<int> height = {2, 1, 3, 5, 6, 2, 3};
    Solution s;
    s.largestRectangleArea(height);

    return 0;
}