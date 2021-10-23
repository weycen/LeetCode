/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (40.57%)
 * Likes:    1075
 * Dislikes: 0
 * Total Accepted:    480.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 *
 *
 *
 * 说明：
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 *
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 *
 *
 * 示例 3：
 *
 *
 * 输入：haystack = "", needle = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack 和 needle 仅由小写英文字符组成
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
 * KMP算法 prefix 表构造函数
 *
 * @param {char*} str 给定字符串
 * @param {int*} prefix prefix表地址
 * @param {int} len 字符串长度
 * @return {*} None
 */
void kmp_build_prefix_table(char* str, int* prefix, int len) {
  int m = 0, n = -1; /* m > n */
  prefix[0] = -1;

  while (m < len - 1) {
#if DEBUG_ENABLE
    printf(" ----- m: %d ----- \n", m);
#endif /* DEBUG_ENABLE */
#if DEBUG_ENABLE
    printf("if(n:%d < 0) || (str[ m:%d ] == str[n:%d]) \n", n, m, n);
#endif /* DEBUG_ENABLE */
    if ((n < 0) || (str[m] == str[n])) {
      m++;
      n++;

      /* n < 0 进来时，prefix[m] 始终为 0 */
      prefix[m] = n;
#if DEBUG_ENABLE
      printf("{ m++, n++, m:%d, n:%d, prefix[m:%d] = n:%d } \n", m, n, m, n);
#endif /* DEBUG_ENABLE */
    } else {
#if DEBUG_ENABLE
      printf(" else { n = prefix[n=%d] } \n", n);
#endif /* DEBUG_ENABLE */
      n = prefix[n];
    }
  }
}

/**
 * KMP算法实现strstr()
 *
 * @param {char*} haystack 给定主字符串
 * @param {char*} needle 给定子字符串
 * @return {*} 返回子串在主串中第一次出现的位置，不存在则返回-1
 */
int strStr(char* haystack, char* needle) {
#if DEBUG_ENABLE
  printf("\nhaystack: %s \n", haystack);
  printf("needle: %s \n", needle);
#endif /* DEBUG_ENABLE */

  /* 当 needle 是空字符串时我们应当返回 0 */
  if (needle[0] == '\0') {
    return 0;
  }

  uint16_t haystack_len = strlen(haystack);
  uint16_t needle_len   = strlen(needle);

  int* prefix = (int*)malloc(needle_len * sizeof(int));
  kmp_build_prefix_table(needle, prefix, needle_len);
#if DEBUG_ENABLE
  for (int i = 0; i < needle_len; i++) {
    printf("prefix[%d] = %d \n", i, prefix[i]);
  }
#endif /* DEBUG_ENABLE */

  int index           = -1; /* 如果不存在，则返回  -1 */
  int hackstack_index = 0, needle_index = 0;

  /* 从左至右扫描 haystack */
  while (hackstack_index < haystack_len) {
    if ((needle_index == -1) || (haystack[hackstack_index] == needle[needle_index])) {
      hackstack_index++;
      needle_index++;
      if (needle_index == needle_len) {
        /* 找到，计算下标索引 */
        index = hackstack_index - needle_index;
        break;
      }
    } else {
      /* 只子串索引 needle_index 往前回溯，主串索引 hackstack_index 不动 */
      needle_index = prefix[needle_index];
    }
  }

  /* 释放 prefix 表空间 */
  free(prefix);

  return (index);
}
// @lc code=end

/**
 * Test cases
 *
 * "hllllelellelllleoleello"\n"lell"\n
 * "actgpactgkactgpacy"\n"actgpacy"\n
 * "bacbababaabcbab"\n"ababaca"\n
 * "bacbababaabcbab"\n"acabaca"\n
 * "bacbababaabcbab"\n"abababacc"\n
 * "bacbababaabcbab"\n"abcdefgabcdrty"\n
 * "bacbababaabcbab"\n"aaaaefgaaaarty"\n
 */
