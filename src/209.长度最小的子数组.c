/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (47.32%)
 * Likes:    794
 * Dislikes: 0
 * Total Accepted:    203K
 * Total Submissions: 428.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
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
 * 找出数组中满足和大于等于目标值的最小连续子数组的长度
 * 采用滑动窗口法
 *
 * @param {int} target 目标值
 * @param {int*} nums 输入数组
 * @param {int} numsSize 数组长度
 * @return {*} 返回子数组长度
 */
int minSubArrayLen(int target, int* nums, int numsSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numsSize: %d \n", numsSize);
#endif /* DEBUG_ENABLE */

  uint32_t cnt_min = UINT32_MAX;
  int      sum     = 0;
  int      start = 0, end = 0;
  while (end < numsSize) {
    sum += nums[end];
    while (sum >= target) {
      if (end - start + 1 < cnt_min) {
        cnt_min = end - start + 1;
      }
      sum -= nums[start];
      start += 1;
    }
    end++;
  }

#if DEBUG_ENABLE
  printf("cnt_min: %d \n", cnt_min);
#endif /* DEBUG_ENABLE */

  return cnt_min == UINT32_MAX ? 0 : cnt_min;
}
// @lc code=end

/**
 * Test cases:
 *
 * 7\n[2,3,6,2,4,4]\n
 */
