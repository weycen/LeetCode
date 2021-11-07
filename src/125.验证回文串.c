/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (47.29%)
 * Likes:    429
 * Dislikes: 0
 * Total Accepted:    288.9K
 * Total Submissions: 611.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 解释："amanaplanacanalpanama" 是回文串
 *
 *
 * 示例 2:
 *
 *
 * 输入: "race a car"
 * 输出: false
 * 解释："raceacar" 不是回文串
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 2 * 1^5
 * 字符串 s 由 ASCII 字符组成
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
 * 给定一个字符串，验证它是否是回文串，
 * 只考虑字母和数字字符，可以忽略字母的大小写，忽略空格、标点符号等
 *
 * 双指针法
 *
 * @param {char *} s 给定字符串
 * @return {*} 返回 true 或 false
 */
bool isPalindrome(char* s) {
#if DEBUG_ENABLE
  printf("\n");
  printf("size: %s \n", s);
#endif /* DEBUG_ENABLE */

  int left = 0, right = strlen(s) - 1;
  while (left < right) {
    while ((left < right) && !isalnum(s[left])) {
      left++;
    }

    while ((left < right) && !isalnum(s[right])) {
      right--;
    }

    if (left < right) {
      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }
  }

  return true;
}
// @lc code=end

/**
 * Test cases:
 *
 * "0P"\n
 */
