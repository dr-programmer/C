#include <stdio.h>
int lengthOfLongestSubstring(char *);

int main(void) {
  char str[] = "daddfs";
  int result = lengthOfLongestSubstring(str);
  printf("%d", result);

  return 0;
}

int lengthOfLongestSubstring(char * s){
    int startpos = 0, curpos = 0, maxlen = 0;
    int positions[256];
    for (int i = 0; i < 256; i++) positions[i] = -1;
    while (s[curpos] != '\0') {
        char curchar = s[curpos];
        if (positions[curchar] != -1) {
          int len = curpos - startpos;
          if (len > maxlen) maxlen = len;
          startpos = positions[curchar] + 1;
        }

        positions[curchar] = curpos;
        curpos++;
    }
    int len = curpos - startpos;
    if (len > maxlen) maxlen = len;
    return maxlen;
}