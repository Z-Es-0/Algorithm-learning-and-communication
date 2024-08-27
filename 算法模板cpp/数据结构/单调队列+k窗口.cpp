#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
#define lowbit(x) (x&(-x))


//维护固定长度为k区间的区间最小值；
class MonotonicQueue {
public:
    void push(int val) {
        while (!dq.empty() && dq.back() > val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }

    void pop(int val) {
        if (!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
    }

    int min() const {
        return dq.front();
    }

    void clear() {
        dq.clear();
    }

private:
    deque<int> dq;
};

class SlidingWindow {
public:
    SlidingWindow(int k) : k(k) {}

    void add(int val) {
        if (window.size() >= k) {
            mq.pop(window.front());
            window.pop_front();
        }
        window.push_back(val);
        mq.push(val);
    }

    int getMin() const {
        return mq.min();
    }

    void clear() {
        window.clear();
        mq.clear();
    }

private:
    int k;
    deque<int> window;
    MonotonicQueue mq;
};