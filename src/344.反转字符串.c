/*
 * @lc app=leetcode.cn id=344 lang=c
 *
 * [344] 反转字符串
 *
 * https://leetcode-cn.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (76.92%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    376K
 * Total Submissions: 488.6K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 *
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
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
 * @param {char*} s 给定字符串数组
 * @param {int} sSize 数组大小
 * @return {*}
 */
void reverseString(char* s, int sSize) {
#if DEBUG_ENABLE
  printf("\nsSize: %d \n", sSize);
  printf("s: %s \n", s);
#endif /* DEBUG_ENABLE */

  char tmp = 0;
  for (uint32_t left = 0, right = sSize - 1; left < right; left++, right--) {
    tmp      = s[left];
    s[left]  = s[right];
    s[right] = tmp;
  }
}
// @lc code=end
