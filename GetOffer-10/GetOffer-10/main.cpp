//
//  main.cpp
//  GetOffer-10
//
//  Created by liweiye on 2020/6/11.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n <= 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int sum = 0, i = 2;
        int a = 1, b = 2;
        while (i < n) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
            i++;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
