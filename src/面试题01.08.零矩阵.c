/*
 * lc app=leetcode.cn id=48 lang=c
 *
 * 面试题 01.08. 零矩阵
 *
 * https://leetcode-cn.com/problems/zero-matrix-lcci/
 *
 *
 * 
 * 
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 
示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

 * 
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



#define DEBUG_ENABLE 0



/**
 * @param {int**} matrix 矩阵
 * @param {int} matrixSize 矩阵行数
 * @param {int*} matrixColSize 矩阵列数
 * @return {*}
 */
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
#if DEBUG_ENABLE
    printf("matrixSize:    %d \n", matrixSize);
    printf("matrixColSize: %d \n", *matrixColSize);
#endif /* DEBUG_ENABLE */

  uint8_t *row = (uint8_t *)malloc(matrixSize);      /* 记录每行是否有0 */
  uint8_t *col = (uint8_t *)malloc(*matrixColSize);  /* 记录每列是否有0 */

  if((row == NULL) || (col == NULL)){
    return;
  }

  /* 清零数组 */
  memset(row, matrixSize, 0);
  memset(col, *matrixColSize, 0);

  /* 逐行扫描 */
  for(int i = 0; i < matrixSize; i++){
    for(int j = 0; j < *matrixColSize; j++){
      if(matrix[i][j] == 0){
        row[i] = 1;
        col[j] = 1; /* 在行扫描时提前标记列 */
        break;
      }
    }
  }

  /* 逐列扫描 */
  for (int j = 0; j < *matrixColSize; j++) {
    /* 若该列已标识为待清零，则跳过 */
    if (col[j] != 1) {
      for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][j] == 0) {
          col[j] = 1;
          break;
        }
      }
    }
  }

  /* 清零含0的行 */
  for(int i = 0; i < matrixSize; i++){
    if(row[i] == 1){
      for(int j = 0; j < *matrixColSize; j++){
        matrix[i][j] = 0;
      }
    }
  }

  /* 清零含0的列 */
  for(int j = 0; j < *matrixColSize; j++){
    if(col[j] == 1){
      for(int i = 0; i < matrixSize; i++){
        matrix[i][j] = 0;
      }
    }
  }

  /* 释放内存 */
  free(row);
  free(col);
}