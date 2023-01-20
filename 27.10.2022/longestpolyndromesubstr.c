#include <stdio.h>

char * longestPalindrome(char * s);

int main(void) {
  char input[10] = "ebabad";
  char * result = longestPalindrome(input);
  printf("%s\n", result);
}

char * longestPalindrome(char * s){
   
    int len = 0;
    while(s[++len]);
    
    int resultstartindex = 0;
    int max = 1;
    
    for (int startindex = 0; len - startindex > max; startindex++) {
        for (int lastindex = len - 1; lastindex-startindex+1 > max; lastindex--) {
            char ispolyndrome = 1;
            int checkstartindex = startindex;
            int checklastindex = lastindex;
            while (checkstartindex <= checklastindex) {
                if (s[checkstartindex] != s[checklastindex]) {
                    ispolyndrome = 0;
                    break;
                }
                checkstartindex++;
                checklastindex--;
            }
            if (ispolyndrome) {
                resultstartindex = startindex;
                max = lastindex - resultstartindex + 1;
            }
        }
    }
    
    for (int i = 0; i < max; i++) {
        s[i] = s[i+resultstartindex];
    }    
    s[max] = '\0';
    return s;
}