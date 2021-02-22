/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (46.30%)
 * Likes:    1038
 * Dislikes: 0
 * Total Accepted:    268.8K
 * Total Submissions: 580.7K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */

// @lc code=start


#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define DEBUG_ENABLE 0

/**
 * 比较函数，作为qsort()的输入，供qsort()判断大小
 */
int cmp(const int **a, const int **b) {
  /* a >= b返回值 >= 0 */
  return **a - **b;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * @param {int} **intervals 输入二维数组
 * @param {int} intervalsSize 二维数组行数
 * @param {int} *intervalsColSize 二维数组列数
 * @param {int} *returnSize 返回二维数组行数
 * @param {int} **returnColumnSizes 返回一个一维数组，元素即为返回的二维数组每行的列数
 * @return {*} 返回二维数组
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
  /* 首先对二维数组快速排序 */
  qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);

#if DEBUG_ENABLE
  printf("\n");
  printf("intervalsSize: %d, *intervalsColSize: %d \n", intervalsSize, *intervalsColSize);
  printf("after qsort, **intervals: [");
  for (int i = 0; i < intervalsSize; i++) {
    printf("[%d,%d],", intervals[i][0], intervals[i][1]);
  }
  printf("]\n");
#endif /* DEBUG_ENABLE */

  /* 为返回的区间指针申请空间, 每元素指向一个一维数组 */
  int **ret = (int **)malloc(intervalsSize * sizeof(int *));

  ret[0] = (int *)malloc(sizeof(int[2]));

  /* 加载第一个区间 */
  ret[0][0] = intervals[0][0];
  ret[0][1] = intervals[0][1];

  /* 进行重叠区间的合并 */
  (*returnSize) = 0;
  for (int i = 1; i < intervalsSize; i++) {
    /* 下一个区间的左边界小于等于当前区间的右边界即为重叠 */
    if (intervals[i][0] <= ret[*returnSize][1]) {
      /* 两个区间有重叠时，更新当前区间右边界为二者中较大者 */
      if (intervals[i][1] > ret[*returnSize][1]) {
        ret[*returnSize][1] = intervals[i][1];
      }
    } else {
      /**
       * 下一个区间与当前区间无重叠时，将该区间追加到返回区间尾部，
       * 为新追加的区间申请空间，并将返回指针中的下一个元素指向改空间。
       */
      (*returnSize)++;
      ret[*returnSize]    = (int *)malloc(sizeof(int[2]));
      ret[*returnSize][0] = intervals[i][0];
      ret[*returnSize][1] = intervals[i][1];
    }
  }

  /* 按合并后的实际区间数来申请空间 */
  (*returnSize)++;
  *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
  for (int i = 0; i < *returnSize; i++) {
    (*returnColumnSizes)[i] = 2;
  }

#if DEBUG_ENABLE
  printf("*returnSize: %d \n", *returnSize);

  printf("**returnColumnSizes: [");
  for (int i = 0; i < *returnSize; i++) {
    printf("%d,", (*returnColumnSizes)[i]);
  }
  printf("]\n");

  printf("**ret: [");
  for (int i = 0; i < *returnSize; i++) {
    printf("[%d,%d],", ret[i][0], ret[i][1]);
  }
  printf("]\n");
#endif /* DEBUG_ENABLE */

  return ret;
}
// @lc code=end

