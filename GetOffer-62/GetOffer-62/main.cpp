//
//  main.cpp
//  GetOffer-62
//
//  Created by liweiye on 2020/5/3.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    // 环形链表法
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) return -1;
        int i = 0;
        list<int> numbers;
        for (i = 0; i < n; i++) {
            numbers.push_back(i);
        }
        list<int>::iterator current = numbers.begin();
        while (numbers.size() > 1) {
            for (int i = 1; i < m; i++) {
                current++;
                if (current == numbers.end())
                    current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if (next == numbers.end())
                next = numbers.begin();

            --current;
            numbers.erase(current);
            current = next;
        }
        return *current;
    }

    // 数学公式法
    // 题解: https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/
    // 参考文章: https://blog.csdn.net/u011500062/article/details/72855826
    // 每杀一个人，其实就是把这个数组向前移动了m位，那么反过来，每增加一个人就是向后移动m位，同时需要对n取模
    // 不难得出递推公式: f(n, m) = (f(n - 1) + m) % n
    int lastRemaining2(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int ans = s.lastRemaining2(0, 3);
    cout << ans << endl;
}
