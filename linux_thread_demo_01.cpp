//进程同步--互斥锁
#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

int tickets = 1000;
pthread_mutex_t mutex;//创建互斥量

void *sellticket(void *arg) {

    while (1) {
        pthread_mutex_lock(&mutex);

        if (tickets > 0) {
            usleep(1000);
            cout << pthread_self() << "正在卖第" << tickets << "张票" << endl;
            --tickets;
            pthread_mutex_unlock(&mutex);
        } else {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return nullptr;
}

int main() {
    pthread_t t1, t2, t3;
    //初始化互斥量
    pthread_mutex_init(&mutex, nullptr);
    //创建子线程
    pthread_create(&t1, nullptr, sellticket, nullptr);
    pthread_create(&t2, nullptr, sellticket, nullptr);
    pthread_create(&t3, nullptr, sellticket, nullptr);
    //回收子线程资源，阻塞
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);
    //退出主线程
    pthread_exit(nullptr);
    //释放互斥量资源
    pthread_mutex_destroy(&mutex);

    return 0;
}