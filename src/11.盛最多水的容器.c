/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (62.72%)
 * Likes:    2907
 * Dislikes: 0
 * Total Accepted:    562.7K
 * Total Submissions: 900K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线
 * i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 示例 2：
 *
 *
 * 输入：height = [1,1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：height = [4,3,2,1,4]
 * 输出：16
 *
 *
 * 示例 4：
 *
 *
 * 输入：height = [1,2,1]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
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
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线
 * i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 双指针法，每次移动较小值
 *
 * @param {int*} height 给定数组
 * @param {int} heightSize 数组长度
 * @return {*} 返回最大水容积值
 */
int maxArea(int* height, int heightSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("heightSize: %d \n", heightSize);
#endif /* DEBUG_ENABLE */

  int left = 0, right = heightSize - 1;
  int area_max = 0;
  int tmp      = 0;
  while (left < right) {
    tmp      = height[left] < height[right] ? height[left] * (right - left) : height[right] * (right - left);
    area_max = tmp > area_max ? tmp : area_max;
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return area_max;
}
// @lc code=end
