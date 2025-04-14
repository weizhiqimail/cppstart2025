#include <iostream>
#include <vector>

using namespace std;

/*
 * 二分查找 - 使用 while 循环（迭代）
 * 前提：nums 必须是升序排列的数组
 * 时间复杂度：O(log n)
 */
int binarySearchForLoop(vector<int> &nums, int target) {
    // 初始化双闭区间 [0, n-1]，即 i, j 分别指向数组首元素、尾元素
    int i = 0, j = nums.size() - 1;
    // 循环，当搜索区间为空时跳出（当 i > j 时为空）
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target) {
            // target 在区间 [m+1, j] 中
            i = m + 1;
        } else if (nums[m] > target) {
            // target 在区间 [i, m-1] 中
            j = m - 1;
        } else {
            // 找到目标元素，返回其索引
            return m;
        }
    }
    // 未找到目标元素，返回 -1
    return -1;
}

/*
 * 二分查找 - 使用递归
 * 前提：nums 必须是升序排列的数组
 * 时间复杂度：O(log n)
 */
int binarySearchRecursive(vector<int> &nums, int low, int high, int target) {
    if (low > high) {
        // 搜索区间为空，返回 -1
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (target < nums[mid]) {
        // target 在区间 [low, mid-1] 中
        return binarySearchRecursive(nums, low, mid - 1, target);
    }
    // target 在区间 [mid+1, high] 中
    return binarySearchRecursive(nums, mid + 1, high, target);
}

int main() {
    vector<int> nums = {1, 4, 5, 9, 10, 12, 15, 18, 20};
    int target = 10;
    int index1 = binarySearchForLoop(nums, target);
    cout << "Index of " << target << " (using loop): " << index1 << endl;
    int index2 = binarySearchRecursive(nums, 0, nums.size() - 1, target);
    cout << "Index of " << target << " (using recursion): " << index2 << endl;
    return 0;
}