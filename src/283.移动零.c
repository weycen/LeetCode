/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.90%)
 * Likes:    1286
 * Dislikes: 0
 * Total Accepted:    526.2K
 * Total Submissions: 822.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 示例:
 *
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 说明:
 *
 *
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
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
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
 * 快慢指针法
 *
 * @param {int*} nums 给定数组
 * @param {int} numsSize 数组长度
 * @return {*} None
 */
void moveZeroes(int* nums, int numsSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numsSize: %d \n", numsSize);
#endif /* DEBUG_ENABLE */

  if (numsSize < 2) {
    return;
  }

  int slow = 0, fast = 0;
  int tmp;
  while (fast < numsSize) {
    if (nums[fast] != 0) {
      if (slow != fast) {
        nums[slow] = nums[fast];
        nums[fast] = 0;
      }
      slow++;
    }
    fast++;
  }
}

// @lc code=end

/**
 * Test cases:
 *
 * [0]\n
 * [1]\n
 * [1,0]\n
 * [0,1]\n
 * [0,1,0,3,12]\n
 */
