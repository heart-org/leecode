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
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles[piles.size() - 1];
        int speed = 0;
        while(left < right){
            int time = 0;
            speed = (right - left) / 2 + left;
            for (int i = 0; i < piles.size(); ++i) {
                time += piles[i] / speed + (piles[i] % speed == 0 ? 0 : 1);
            }
            if (time <= h)
                right = speed;
            else
                left = speed + 1;
        }
        return right;
    }
};

int main(){
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    Solution s;
    s.minEatingSpeed(piles, h);



    return 0;
}