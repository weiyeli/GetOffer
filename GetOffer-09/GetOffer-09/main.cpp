//
//  main.cpp
//  GetOffer-09
//
//  Created by liweiye on 2020/6/2.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class CQueue {
    stack<int>s1;
    stack<int>s2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        // 如果 s2 不为空，直接取 s2.top
        // 如果 s2 为空，则把 s1 挪到 s2 中
        if(s2.empty()){
            if(s1.empty()){
                return -1;
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int head=s2.top();
        s2.pop();
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
