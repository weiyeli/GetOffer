//
//  main.cpp
//  GetOffer-40
//
//  Created by liweiye on 2020/6/1.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 最小堆
template<typename Item>
class MinHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k/2] < data[k]) {
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;
            // data[j] 是 data[2*k]和data[2*k+1]中的最大值
            if( j+1 <= count && data[j+1] < data[j] ) {
                j++;
            }
            if (data[k] <= data[j]) break;
            swap(data[k], data[j]);
            k = j;
        }
    }
public:
    // 构造函数，构造一个空堆，可以容纳 capacity 个元素
    MinHeap(int capacity) {
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    // 构造函数，通过一个给定数组创建一个最小堆
    // 该构造堆的过程，时间复杂度为O(n)
    MinHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;

        for (int i = 0; i < n; i++) {
            data[i+1] = arr[i];
        }
        count = n;

        // count / 2 是第一个非叶子结点的下标
        for (int i = count/2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    MinHeap(vector<int>& arr, int n) {
        data = new Item[n+1];
        capacity = n;

        for (int i = 0; i < n; i++) {
            data[i+1] = arr[i];
        }
        count = n;

        // count / 2 是第一个非叶子结点的下标
        for (int i = count/2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MinHeap() {
        delete[] data;
    }

    // 返回堆中的元素个数
    int size() {
        return count;
    }

    // 返回一个布尔值，表示堆中是否为空
    bool isEmpty() {
        return count == 0;
    }

    // 向最大堆中插入一个新的元素 item
    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        shiftUp(count + 1);
        count++;
    }

    // 获取最小堆中的堆顶元素
    Item getMin() {
        asset( count > 0 );
        return data[1];
    }

    // 从最小堆中取出堆顶元素，即堆中所存储的最小数据
    Item extractMin() {
        assert( count > 0 );
        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        MinHeap<int> minHeap = MinHeap<int>(arr, arr.size());
        for (int i = 0; i < k; i++) {
            res.push_back(minHeap.extractMin());
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
