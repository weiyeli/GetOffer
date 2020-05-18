//
//  main.cpp
//  GetOffer-24
//
//  Created by liweiye on 2020/5/18.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// 双指针法简洁版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};

// 递归法
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};

// 双指针升级版
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* cur = head;
        while (head->next != NULL) {
            ListNode* temp = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = temp;
        }
        return cur;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
