/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (46.84%)
 * Likes:    987
 * Dislikes: 0
 * Total Accepted:    442.4K
 * Total Submissions: 944.4K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 请必须使用时间复杂度为 O(log n) 的算法。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 *
 * 示例 3:
 *
 *
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 *
 * 示例 4:
 *
 *
 * 输入: nums = [1,3,5,6], target = 0
 * 输出: 0
 *
 *
 * 示例 5:
 *
 *
 * 输入: nums = [1], target = 0
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 为无重复元素的升序排列数组
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start

/**
 * @param {int} *nums 排序数组
 * @param {int} numsSize 数组长度
 * @param {int} target 目标值
 * @return {*} 目标值存在返回其索引，否则返回其应插入位置
 */
int searchInsert(int *nums, int numsSize, int target) {
  /* 首先考虑边界 */
  if (target <= nums[0]) {
    /* 目标值小于等于右边界值 */
    return 0;
  } else if (target == nums[numsSize - 1]) {
    /* 目标值等于右边界值 */
    return (numsSize - 1);
  } else if (target > nums[numsSize - 1]) {
    /* 目标值大于右边界值 */
    return numsSize;
  }

  /* 二分查找 */
  uint16_t leftIndex = 0, rightIndex = numsSize - 1;
  uint16_t midIndex = 0;
  for (;;) {
    if (leftIndex > rightIndex) {
      return leftIndex;
    }

    midIndex = (leftIndex + rightIndex) / 2;
    if (target == nums[midIndex]) {
      return midIndex;
    } else if (target < nums[midIndex]) {
      /* target小于中间值，向左继续查找 */
      rightIndex = midIndex - 1;
    } else {
      /* target大于中间值，向右继续查找 */
      leftIndex = midIndex + 1;
    }
  }

  return (numsSize - 1);
}
// @lc code=end
