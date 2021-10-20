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
 * 朴素字符串匹配法(native-string-matcher)实现strstr()
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
    return (0);
  }

  uint16_t haystack_len   = strlen(haystack);
  uint16_t needle_len     = strlen(needle);
  uint16_t haystcak_index = 0, needle_index = 0;

  /* 从左至右扫描 haystack */
  while (haystcak_index < haystack_len) {
    /* 逐字符匹配 */
    if (haystack[haystcak_index] == needle[needle_index]) {
      /* 判断是否匹配至子串最后一个字符 */
      if (needle_index == (needle_len - 1)) {
        /* 子串全部匹配成功，返回下标 */
        return (haystcak_index - needle_index);
      } else {
        /* 未至子串最后一个字符，继续向右匹配 */
        haystcak_index++;
        needle_index++;
      }
    } else {
      /**
       * 遇到失配字符：
       *  1.当子串索引为零时，主串索引向右移动，子串索引不动；
       *  2.当子串索引不为零时，主串索引回退至上个相等点后一个元素，然后复位子串索引；
       */
      if (needle_index == 0) {
        haystcak_index++;
      } else {
        /* 此处仅 needle_index >=2 时，haystcak_index 值才会更新 */
        haystcak_index = haystcak_index - needle_index + 1;
        needle_index   = 0;
      }
    }
  }

  /*未找到，返回 -1*/
  return (-1);
}
// @lc code=end

/**
 * Test case:
 * "hllllelellelllleoleello"\n"lell"\n
 */
