//
//  main.cpp
//  GetOffer-53
//
//  Created by liweiye on 2020/6/11.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class MaxQueue {
    queue<int> q;
    // 用来记录最大值
    deque<int> d;

public:
    MaxQueue() {}

    int max_value() {
        if (d.empty()) return -1;
        return d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int ans = q.front();
        if (ans == d.front()) d.pop_front();
        q.pop();
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
