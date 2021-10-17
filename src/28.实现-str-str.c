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

  /* 如果不存在，则返回  -1 */
  int index = -1;

  /* 从左至右扫描 haystack */
  for (uint16_t i = 0, j = 0; i < haystack_len; i++) {
    if (haystack[i] == needle[j]) {
      j++;
      if (j == needle_len) {
        index = i - j + 1;
        break;
      }
    } else {
      /* 回退至上个相等点后一个元素 */
      if (j != 0) {
        i -= j;
      }
      j = 0;
    }
  }

  return index;
}
// @lc code=end

// "hllllelellelllleoleello"\n"lell"\n