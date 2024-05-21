#include <memory>
#include <mutex>
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
#include <atomic>


using namespace std;

template<typename T>
class animal {
public:
    animal() = default;

    animal(T *data) : m_data(data) {}

    ~animal() {


    }

private:
    int m_data;
};

class dog {
public:
    dog() = default;

    dog(int d_age) : age(d_age) {
        cout << " 创建对象 ！！" << endl;
    }

    ~dog() {
        cout << "析构！！" << endl;
    }

private:
    int age;
};

class book {
public:
    book() : book(0) {}

    book(int a) : book(a, 0.) {}

    book(float b) : book(0, b) {}

    book(int a, float b) : a_(a), b_(b) {}

private:
    int a_;
    float b_;
};

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    unique_ptr<int> d1(new int(10));
    unique_ptr<int> d2(new int(20));
    unique_ptr<int> d3(move(d1));
    d1.get();
    d2.get();


    shared_ptr<dog> do1(new dog);
    shared_ptr<dog> do2(do1);
    shared_ptr<dog> do3 = make_shared<dog>();

    auto ptr1 = make_shared<int>(10);
    auto ptr2(ptr1);
    shared_ptr ptr3 = make_shared<book>();
    cout << ptr1.get() << endl;
    cout << ptr1.use_count() << endl;
    std::mutex mtx1;
    unique_lock<std::mutex> lock(mtx1);
    lock.lock();
    lock.unlock();

    std::atomic<bool> flag(false);
    std::atomic<int> value0(10);
    std::atomic<int> value1 = 10;
    

    return 0;
}