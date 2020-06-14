//
//  main.cpp
//  GetOffer-59
//
//  Created by liweiye on 2020/6/11.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  // 双指针
        vector<int> result;
        int sum, i = 0, j = nums.size()-1;
        while(i < j){
            sum = nums[i]+nums[j];
            if(sum == target){
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                break;
            }
            if(sum>target) j--;
            else i++;
        }

        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
