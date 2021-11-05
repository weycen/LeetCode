/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (66.77%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    152.2K
 * Total Submissions: 227.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= rowIndex <= 33
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
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
 * 返回杨辉三角的指定行的元素
 *
 * @param {int} rowIndex 给定的行标号
 * @param {int*} returnSize 返回数组长度
 * @return {*} 返回数组指针
 */
int *getRow(int rowIndex, int *returnSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("rowIndex: %d \n", rowIndex);
#endif /* DEBUG_ENABLE */

  /* 申请内存，数组 */
  int *array_pre = (int *)malloc((rowIndex + 1) * sizeof(int));
  int *array_cur = (int *)malloc((rowIndex + 1) * sizeof(int));

  int *tmp = NULL;

  // TODO: 进一步优化，只用哟个数组原地计算，倒序计算
  for (int i = 0; i < rowIndex + 1; i++) {
    array_cur[0] = 1;
    array_cur[i] = 1;
    for (int j = 1; j < i; j++) {
      array_cur[j] = array_pre[j - 1] + array_pre[j];
    }

    /* 用交换指针取代交换数据 */
    tmp       = array_pre;
    array_pre = array_cur;
    array_cur = tmp;

#if DEBUG_ENABLE
    printf("array_pre: [ ");
    for (int n = 0; n < i + 1; n++) {
      printf("%d, ", array_pre[n]);
    }
    printf(" ]\n");
#endif /* DEBUG_ENABLE */
  }

  *returnSize = rowIndex + 1;

  return array_pre;
}
// @lc code=end
