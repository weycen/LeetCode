/*
 * @lc app=leetcode.cn id=48 lang=c
 *
 * [48] 旋转图像
 *
 * https://leetcode-cn.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (73.53%)
 * Likes:    1024
 * Dislikes: 0
 * Total Accepted:    226.5K
 * Total Submissions: 308K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[1]]
 * 输出：[[1]]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [[1,2],[3,4]]
 * 输出：[[3,1],[4,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * matrix.length == n
 * matrix[i].length == n
 * 1 
 * -1000 
 * 
 * 
 */

// @lc code=start

#include <stdint.h>
#include <stdio.h>


#define DEBUG_ENABLE 0


/**
 * @param {int**} matrix 要旋转的矩阵(二维数组)
 * @param {int} matrixSize 矩阵大小
 * @param {int*} matrixColSize 矩阵列宽
 * @return {*}
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
  uint8_t ring_num = ((uint8_t)(*matrixColSize)) / 2; /* 总圈数 */
  uint8_t colsize  = (uint8_t)(*matrixColSize);       /* 每圈边长 */
  int     tmp      = 0;

  /* 由最外圈向内按圈遍历 */
  for (uint8_t ring = 0; ring < ring_num; ring++) {
#if DEBUG_ENABLE
    printf("ring: %d / %d \n", ring + 1, ring_num);
#endif /* DEBUG_ENABLE */

    /* (colsize - 1)轮交换 */
    uint8_t exchange_num = colsize - 1;
    for (uint8_t i = 0; i < exchange_num; i++) {
#if DEBUG_ENABLE
      printf("i: %d / %d \n", i + 1, exchange_num);
      printf("tmp          = matrix[%d][%d] \n", ring, ring + i);
      printf("matrix[%d][%d] = matrix[%d][%d] \n", ring, ring + i, ring + colsize - 1 - i, ring);
      printf("matrix[%d][%d] = matrix[%d][%d] \n", ring + colsize - 1 - i, ring, ring + colsize - 1,
             ring + colsize - 1 - i);
      printf("matrix[%d][%d] = matrix[%d][%d] \n", ring + colsize - 1, ring + colsize - 1 - i, ring + i,
             ring + colsize - 1);
      printf("matrix[%d][%d] = tmp \n", ring + i, ring + colsize - 1);
#endif /* DEBUG_ENABLE */

      /* 每轮交换4个像素 */
      tmp                                                = matrix[ring][ring + i];
      matrix[ring][ring + i]                             = matrix[ring + colsize - 1 - i][ring];
      matrix[ring + colsize - 1 - i][ring]               = matrix[ring + colsize - 1][ring + colsize - 1 - i];
      matrix[ring + colsize - 1][ring + colsize - 1 - i] = matrix[ring + i][ring + colsize - 1];
      matrix[ring + i][ring + colsize - 1]               = tmp;
    }

    /* 计算下一圈边长 */
    colsize -= 2;
  }
}
// @lc code=end

