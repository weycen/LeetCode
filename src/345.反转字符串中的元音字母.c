/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (53.93%)
 * Likes:    229
 * Dislikes: 0
 * Total Accepted:    110.9K
 * Total Submissions: 205.6K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 *
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "hello"
 * 输出："holle"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "leetcode"
 * 输出："leotcede"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 *
 *
 */

// @lc code=start

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_ENABLE 0

char vowel[] = "aeiouAEIOU";

bool isVowel(char ch) {
  for (int i = 0; vowel[i]; i++) {
    if (vowel[i] == ch) {
      return true;
    }
  }

  return false;
}

/**
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串
 *
 * @param {char *} s
 * @return {*}
 */
char* reverseVowels(char* s) {
#if DEBUG_ENABLE
  printf("\n");
  printf("size: %s \n", s);
#endif /* DEBUG_ENABLE */

  char tmp;
  int  left = 0, right = strlen(s) - 1;
  while (left < right) {
    while ((left < right) && !(isVowel(s[left]))) {
      left++;
    }

    while ((left < right) && !(isVowel(s[right]))) {
      right--;
    }

    if (left < right) {
      /* 反转元音字母 */
      tmp      = s[left];
      s[left]  = s[right];
      s[right] = tmp;

      /* left右移，right左移 */
      left++;
      right--;
    }
  }

  return s;
}
// @lc code=end
