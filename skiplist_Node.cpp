#include <fstream>
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

template<typename K, typename V>
class Node {
public:
    Node() {}

    Node(K k, V v, int);

    ~Node();

    K get_key() const;

    V get_value() const;

    void set_value(V);

    Node<K, V> **forward;
    int node_level;
private:
    K key;
    V value;
};

template<typename K, typename V>
Node<K, V>::Node(const K k, const V v, int level) {
    this->key = k;
    this->value = v;
    this->node_level = level;
    this->forward = new Node<K, V> *[level + 1];
    memset(this->forward, 0, sizeof(Node<K, V> *) * (level + 1));
}

template<typename K, typename V>
Node<K, V>::~Node() {
    delete[] forward;
};

template<typename K, typename V>
K Node<K, V>::get_key() const {
    return key;
}

template<typename K, typename V>
V Node<K, V>::get_value() const {
    return value;
}

template<typename K, typename V>
void Node<K, V>::set_value(V val) {
    this->value = val;
}

template<typename K, typename V>
class skiplist {
public:
    int get_random_level();

private:
    int _max_level;
    int _skip_list_level;//当前层数
    Node<K, V> *_header;
    int _element_count;
    std::ofstream _file_writer;  // 文件写入器
    std::ifstream _file_reader;  // 文件读取器
};

template<typename K, typename V>
int skiplist<K, V>::get_random_level() {
    int k = 1;
    while (rand() % 2) {
        k++;
    }
    k = (k < _max_level) ? k : _max_level;

    return k;
}