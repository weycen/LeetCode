/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.55%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    171K
 * Total Submissions: 229.8K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 *
 *
 *
 * 示例：
 *
 * 输入："Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
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
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序
 *
 * @param {char *} s 给定字符串
 * @return {*} 返回翻转后的字符串
 */
char* reverseWords(char* s) {
#if DEBUG_ENABLE
  printf("\n");
  printf("s: %s \n", s);
#endif /* DEBUG_ENABLE */

  int  left = 0, right = 0;
  int  len = strlen(s);
  char tmp;

  while (left < len) {
    right++;
    if ((right < len) && (s[right] != ' ')) {
      continue;
    }

    int left_tmp = left, right_tmp = right - 1;
    while (left_tmp < right_tmp) {
      tmp          = s[left_tmp];
      s[left_tmp]  = s[right_tmp];
      s[right_tmp] = tmp;

      left_tmp++;
      right_tmp--;
    }

    right++;
    left = right;
  }

  return s;
}
// @lc code=end
