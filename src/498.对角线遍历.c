/*
 * @lc app=leetcode.cn id=498 lang=c
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (46.90%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    44K
 * Total Submissions: 93.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 *
 *
 * 示例 2：
 *
 *
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
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
 * @param {int**} mat 输入的矩阵
 * @param {int} matSize 矩阵行数
 * @param {int*} matColSize 矩阵列数
 * @param {int*} returnSize 返回数组长度
 * @return {*} 返回数组
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
  /* 申请存放所有元素所需空间 */
  *returnSize = matSize * (*matColSize);
  int* array  = (int*)malloc((*returnSize) * sizeof(int));
  if (array == NULL) {
    return NULL;
  }

  /* 遍历所有元素 */
  int     i = 0, j = 0; /* 行列坐标 */
  uint8_t dir = 1;      /* 对角线方向, 为1时自左下向右上, 为0时反之 */
  for (uint32_t n = 0; n < *returnSize; n++) {
    array[n] = mat[i][j];

#if DEBUG_ENABLE
    printf("\narray[%d] = mat[%d][%d]", n, i, j);
#endif /* DEBUG_ENABLE */

    /**
     * 自左下向右上时, 只要 j 不达右边界, 则 j 一定增 1；
     * 自右上向左下时, 只要 i 不达下边界, 则 i 一定增 1；
     */
    /* dir为1时, 自左下向右上 */
    if (dir == 1) {
      if (j + 1 <= *matColSize - 1) {
        /* j 未抵达右边界, j 增 1 */
        j += 1;

        /* i 未抵达上边界时则减 1，否则保持不变 */
        if (i >= 1) {
          i -= 1;
        } else {
          /* i 抵达上边界，换向 */
          dir = 0;
        }
      } else {
        /* j 抵达右边界，j 不变，换向 */
        dir = 0;

        /**
         * note: 若此时 i 也同时抵达下边界, 则说明已遍历至矩阵右下角最后一个元素,
         * 此处 i 是否抵达下边界可免判, i 直接增 1 也可。
         */
        /* i 未抵达下边界时增 1，否则保持不变 */
        if (i + 1 <= matSize - 1) {
          i += 1;
        }
      }
    } else {
      if (i + 1 <= matSize - 1) {
        /* i 未抵达下边界，i 增 1 */
        i += 1;

        /* j 未抵达左边界时减 1，否则保持不变 */
        if (j >= 1) {
          j -= 1;
        } else {
          /* j 抵达左边界，j 不变，换向 */
          dir = 1;
        }
      } else {
        /* i 抵达下边界，i 保持不变，换向 */
        dir = 1;

        /**
         *  note: 若此时 j 也同时抵达右边界, 则说明已遍历至矩阵右下角最后一个元素,
         *  此处 j 是否抵达右边界可免判，j 直接增 1 也可。
         */
        /* j 未抵达右边界时增 1，否则保持不变 */
        if (j + 1 <= *matColSize - 1) {
          j += 1;
        }
      }
    }
  }

  return array;
}
// @lc code=end
