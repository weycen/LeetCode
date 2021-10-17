/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (41.01%)
 * Likes:    1817
 * Dislikes: 0
 * Total Accepted:    638K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
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
 * @param {char **} strs 字符串数组
 * @param {int} strsSize 数组长度
 * @return {*} 返回最长公共前缀，不存在则返回空字符串
 */
char* longestCommonPrefix(char** strs, int strsSize) {
#if DEBUG_ENABLE
  printf("\n");
  printf("strsSize: %d \n", strsSize);
  printf("strs: ");
  for (uint8_t i = 0; i < strsSize; i++) {
    printf("%s, ", strs[i]);
  }
  printf("\n");
#endif /* DEBUG_ENABLE */

  /* 数组中只有一个字符串时，则返回该字符串 */
  if (strsSize == 1) {
    return strs[0];
  }

  /* 申请空间, 用以存储最长公共字符串 */
  uint8_t lcp_len = strlen(strs[0]); /* 记录最长公共字符串长度 */
  char*   lcp     = (char*)malloc((lcp_len + 1) * sizeof(char));

  /* 将第一个字符串装载到lcp中 */
  strcpy(lcp, strs[0]);

  /* 遍历所有子串，注意下标从 1 开始 */
  for (uint8_t i = 1; i < strsSize; i++) {
    /* 任一字符串为空时, 返回空字符串 */
    if (strs[i][0] == '\0') {
      lcp_len = 0;
      break;
    }

    /* 逐字符对比 */
    for (uint8_t j = 0; j < lcp_len; j++) {
      if (((lcp[j] == '\0') || (strs[i][j] == '\0')) || (strs[i][j] != lcp[j])) {
        /**
         * 如果本次找到的公共串长度较之前记录更小，则更新lcp_len
         * note: 新找到的公共串不可能长于前面记录
         */
        if (j < lcp_len) {
          lcp_len = j;
        }

        break;
      }
    }
  }

  lcp[lcp_len] = '\0';

#if DEBUG_ENABLE
  printf("lcp_len: %d \n", lcp_len);
  printf("lcp: %s \n", lcp);
#endif /* DEBUG_ENABLE */

  return lcp;
}

// @lc code=end
