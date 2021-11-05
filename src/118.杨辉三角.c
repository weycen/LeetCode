/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (73.12%)
 * Likes:    621
 * Dislikes: 0
 * Total Accepted:    228K
 * Total Submissions: 311K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
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
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= numRows <= 30
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * 生成杨辉三角的前numRos行
 *
 * @param {int} numRows 指定生成的行数
 * @param {int*} returnSize 返回数组的个数(每行一个数组)
 * @param {int**} returnColumnSizes 返回数组的列数(每行的长度)
 * @return {*} 返回二维数组
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
#if DEBUG_ENABLE
  printf("\n");
  printf("numRows: %d \n", numRows);
#endif /* DEBUG_ENABLE */

  /* 申请内存，指针数组 */
  int** array = (int**)malloc(numRows * sizeof(int*));

  /* 申请内存，存放数组长度 */
  *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

  /* 生成杨辉三角第 3 - numRows 行 */
  for (int i = 0; i < numRows; i++) {
    array[i] = (int*)malloc((i + 1) * sizeof(int));

    /* 第 i 行有 i 个元素*/
    (*returnColumnSizes)[i] = i + 1;

    array[i][0] = 1;
    array[i][i] = 1;

    for (int j = 1; j < i; j++) {
      array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
    }
  }

  *returnSize = numRows;

  /* 返回数组指针 */
  return array;
}
// @lc code=end
