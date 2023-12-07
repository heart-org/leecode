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
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1;
        int ans,k = 0;
        while(i < j){
            k = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            if (k > ans)
                ans = k;
            if (height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height);

    return 0;
}