/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (59.65%)
 * Likes:    1062
 * Dislikes: 0
 * Total Accepted:    283.6K
 * Total Submissions: 474.6K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n
 * 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[0]
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 *
 *
 */

// @lc code=start

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_ENABLE 0

/**
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *                  left    right
 * 双指针分界法：0 0 0 | 1 1 1 | 2 2 2
 *
 * @param {int*} nums 给定数组
 * @param {int} numsSize 数组长度
 * @return {*}
 */
void sortColors(int* nums, int numsSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numsSize: %d \n", numsSize);
#endif /* DEBUG_ENABLE */

  if (numsSize < 2) {
    return numsSize;
  }

  int left = 0, right = numsSize - 1;
  int index = 0;
  int tmp;

  /* 注意结束条件为：index <= right */
  while (index <= right) {
    if (nums[index] == 0) {
      tmp         = nums[left];
      nums[left]  = nums[index];
      nums[index] = tmp;
      left++;
      index++;
    } else if (nums[index] == 2) {
      tmp         = nums[right];
      nums[right] = nums[index];
      nums[index] = tmp;
      right--;
    } else {
      index++;
    }
  }
}
// @lc code=end

/**
 * Test cases:
 *
 * [2,0,1]\n
 */
