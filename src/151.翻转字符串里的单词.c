/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (48.41%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    173.1K
 * Total Submissions: 357.4K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 *
 * 请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
 *
 * 说明：
 *
 *
 * 输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
 * 翻转后单词间应当仅用一个空格分隔。
 * 翻转后的字符串中不应包含额外的空格。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：输入字符串可以在前面或者后面包含多余的空格，但是翻转后的字符不能包括。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，将翻转后单词间的空格减少到只含一个。
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "  Bob    Loves  Alice   "
 * 输出："Alice Loves Bob"
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "Alice does not even like bob"
 * 输出："bob like even not does Alice"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 *
 *
 *
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 请尝试使用 O(1) 额外空间复杂度的原地解法。
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
 * @param {char *} s 给定字符串
 * @return {*} 返回翻转单词后的字符串
 */
char* reverseWords(char* s) {
#if DEBUG_ENABLE
  printf("\ns: %s \n", s);
#endif /* DEBUG_ENABLE */

  /* 申请空间存储翻转后的字符串 */
  uint16_t str_len = strlen(s);
  char*    reverse = (char*)malloc((str_len + 1) * sizeof(char));

  uint16_t word_len = 0;
  uint16_t index    = 0;
  for (int i = str_len - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      if (word_len != 0) {
        for (uint16_t n = 0; n < word_len; n++) {
          reverse[index++] = s[i + 1 + n];
        }

        /**
         * 每个单词尾部添加空格
         * note: 若这是翻转后的字符串中的最后一个单词，则最后需删除此空格。
         */
        reverse[index++] = ' ';

        /* 清零 word_len */
        word_len = 0;
      }
    } else {
      word_len++;
    }
  }

  /* 字符串首个单词 */
  if (word_len != 0) {
    for (uint16_t n = 0; n < word_len; n++) {
      reverse[index++] = s[0 + n];
    }

    /**
     * 每个单词尾部添加空格
     * note: 这是最后一个单词，尾部可以无需添加此空格，
     * 但为和上面保持一致此处仍添加空格，最后统一去除。
     */
    reverse[index++] = ' ';
  }

  /* 翻转后的字符串删除尾部空格并添加空白符 '\0' */
  reverse[--index] = '\0';

#if DEBUG_ENABLE
  printf("index: %d \n", index);
  printf("strlen(reverse): %d, reverse:%s\n", strlen(reverse), reverse);
#endif /* DEBUG_ENABLE */

  return reverse;
}
// @lc code=end
