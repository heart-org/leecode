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
#include "chrono"

using namespace std;

int main() {
    auto time = chrono::system_clock::now();
    std::time_t now_time = chrono::system_clock::to_time_t(time);
    cout << std::ctime(&now_time) << endl;


    return 0;
}