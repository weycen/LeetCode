/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (60.72%)
 * Likes:    269
 * Dislikes: 0
 * Total Accepted:    124.7K
 * Total Submissions: 205.4K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续 1 的个数。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：[1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 *
 *
 *
 *
 * 提示：
 *
 *
 * 输入的数组只包含 0 和 1 。
 * 输入数组的长度是正整数，且不超过 10,000。
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
 * 给定一个二进制数组， 计算其中最大连续 1 的个数
 *
 * @param {int*} nums 给二进制数组
 * @param {int} numsSize 数组长度
 * @return {*} 返回最大连续 1 的个数
 */
int findMaxConsecutiveOnes(int* nums, int numsSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numsSize: %d \n", numsSize);
#endif /* DEBUG_ENABLE */

  int cnt = 0, cnt_max = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 1) {
      cnt++;
    } else {
      if (cnt > cnt_max) {
        cnt_max = cnt; /* 更新 cnt_max */
      }
      cnt = 0;
    }
  }

  /* 最大值出现在数组末尾时需检查并更新 cnt_max */
  if (cnt > cnt_max) {
    cnt_max = cnt; /* 更新 cnt_max */
  }

  return cnt_max;
}
// @lc code=end

/**
 * Test cases:
 *
 * [1,0,1,1,0,1]
 * [1,1,0,1,1,1]
 */
