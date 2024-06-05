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

using namespace std;

/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                if (nums.size() < 2){
                    return false;
                }else{
                    int tmp1 = nums.top();
                    nums.pop();
                    int tmp2 = nums.top();
                    nums.pop();
                    if (tokens[i] == "+"){
                        nums.push(tmp2 + tmp1);
                    }else if (tokens[i] == "-"){
                        nums.push(tmp2 - tmp1);
                    }else if(tokens[i] == "*"){
                        nums.push(tmp2 * tmp1);
                    }else{
                        nums.push(tmp2 / tmp1);
                    }
                }
            }else
                nums.push(stoi(tokens[i]));
        }
        return nums.top();
    }
};
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s1.push(stoi(tokens[i]));
            }else{
                if (s1.size() <= 1){
                    return false;
                }else{
                    int res2 = s1.top();
                    s1.pop();
                    int res1 = s1.top();
                    s1.pop();
                    if (tokens[i] == "+")
                        s1.push(res1 + res2);
                    else if (tokens[i] == "-")
                        s1.push(res1 - res2);
                    else if (tokens[i] == "*")
                        s1.push(res1 * res2);
                    else
                        s1.push(res1 / res2);
                }
            }
        }
        return s1.top();
    }
};

int main(){
    cout << isalpha('G') << endl;
    cout << isalpha('g') << endl;
    cout << isalpha('9') << endl;
    cout << isalpha('+') << endl;
    cout << isalnum('G') << endl;
    cout << isalnum('g') << endl;
    cout << isalnum('9') << endl;
    cout << isalnum('+') << endl;


    return 0;
}