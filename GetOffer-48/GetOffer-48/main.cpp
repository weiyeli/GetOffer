//
//  main.cpp
//  GetOffer-48
//
//  Created by liweiye on 2020/6/8.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int res = 0, tmp = 0;
        for (int j = 0; j < s.size(); j++) {
            int i = -1;
            if (map.find(s[j]) != map.end()) {
                i = map[s[j]];
            }
            map[s[j]] = j;
            // 滚动dp数组
            // j - i 的含义是s[j]字符到上一个与它相等的s[i]字符之间的距离
            // j - i > dp[j-1] 的含义是，两个相等字符中间不全是不重复的字符串，所以最长的不重复字符串只能是 dp[j-1] + 1
            // j - i <= dp[j-1] 的含义是，两个相等字符中间都是不重复的字符，那么最长的不重复字符串就是 j - i
            tmp = tmp < j - i ? tmp + 1 : j - i;
            res = max(tmp, res);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
