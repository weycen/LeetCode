/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (58.68%)
 * Likes:    605
 * Dislikes: 0
 * Total Accepted:    304.1K
 * Total Submissions: 518.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 *
 * 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <=
 * answer[0] < answer[1] <= numbers.length 。
 *
 * 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
 *
 *
 * 示例 1：
 *
 *
 * 输入：numbers = [2,7,11,15], target = 9
 * 输出：[1,2]
 * 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：numbers = [2,3,4], target = 6
 * 输出：[1,3]
 *
 *
 * 示例 3：
 *
 *
 * 输入：numbers = [-1,0], target = -1
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers 按 非递减顺序 排列
 * -1000 <= target <= 1000
 * 仅存在一个有效答案
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @param {int*} numbers 输入顺序数组
 * @param {int} numbersSize 数组长度
 * @param {int} target 目标值
 * @param {int*} returnSize 返回数组长度
 * @return {*} 返回数组
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numbersSize: %d \n", numbersSize);
#endif /* DEBUG_ENABLE */

  int* ret    = (int*)malloc(sizeof(int) * 2);
  *returnSize = 2;

  int left = 0, right = numbersSize - 1;
  int sum = 0;
  while (left < right) {
    sum = numbers[left] + numbers[right];
    if (sum == target) {
      /* 返回 */
      ret[0] = left + 1, ret[1] = right + 1;
      return ret;
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  /* 未找到 */
  ret[0] = -1, ret[1] = -1;
  return ret;
}
// @lc code=end
