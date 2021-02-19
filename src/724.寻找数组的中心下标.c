/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心下标
 *
 * https://leetcode-cn.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (45.33%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    126.6K
 * Total Submissions: 279.4K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * 给你一个整数数组 nums ，请计算数组的 中心下标 。
 *
 * 数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
 *
 * 如果中心下标位于数组最左端，那么左侧数之和视为 0
 * ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
 *
 * 如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1, 7, 3, 6, 5, 6]
 * 输出：3
 * 解释：
 * 中心下标是 3 。
 * 左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
 * 右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1, 2, 3]
 * 输出：-1
 * 解释：
 * 数组中不存在满足此条件的中心下标。
 *
 * 示例 3：
 *
 *
 * 输入：nums = [2, 1, -1]
 * 输出：0
 * 解释：
 * 中心下标是 0 。
 * 左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
 * 右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start

#include <stdint.h>


/**
 * @param {int*} nums 整数数组
 * @param {int} numsSize 数组长度
 * @return {*} 返回数组中心下标
 */
int pivotIndex(int* nums, int numsSize) {
  /* 数组长度 <=1 时不存在中心索引 */
  if (numsSize <= 1) {
    return (-1);
  }

  int leftValue = 0, rightValue = 0;

  /*首先计算右值, 注意从下标1开始  */
  for (uint32_t i = 1; i < numsSize; i++) {
    rightValue += nums[i];
  }

  /* 检查中心是否存在最左端 */
  if (0 == rightValue) {
    return (0);
  }

  /* 向右循环检查 */
  for (uint32_t i = 1; i < numsSize; i++) {
    leftValue += nums[i - 1];
    rightValue -= nums[i];

    if (leftValue == rightValue) {
      return (i);
    }
  }

  return (-1);
}
// @lc code=end
