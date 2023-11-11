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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            sort(matrix[i].begin(),matrix[i].end());
            for (int j = 0; j < matrix[i].size(); ++j) {
                int left = 0;
                int right = matrix[i].size() - 1;
                while(left <= right){
                    int mid = (right - left) / 2 + left;
                    if (matrix[i][mid] > target)
                        right = mid - 1;
                    else if (matrix[i][mid] < target)
                        left = mid + 1;
                    else
                        return true;
                }
            }
        }
        return false;
    }
};

int main(){

    return 0;
}