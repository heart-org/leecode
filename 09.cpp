#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        int number = 0;
        if (x < 0 || (x%10 == 0 && x != 0))
            return false;

        while(x != 0)
        {
            number = number * 10 + x % 10;
            x = x / 10;
        }
        if(y == number)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution().isPalindrome(121);
    return 0;
}