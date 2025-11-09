#include <bits/stdc++.h>
using namespace std;


// recursion + memoization
class Solution {
    public:
        int t[1002][1002];
    
        int recur(string &s1, string &s2, int i, int j) {
            if (i >= s1.length() || j >= s2.length()) {
                return 0;
            }
    
            if (t[i][j] != -1) {
                return t[i][j];
            }
    
            if (s1[i] == s2[j]) {
                return t[i][j] = 1 + recur(s1, s2, i + 1, j + 1);
            } else {
                return t[i][j] = max(recur(s1, s2, i + 1, j), recur(s1, s2, i, j + 1));
            }
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            memset(t, -1, sizeof(t));
            return recur(text1, text2, 0, 0);
        }
    };

// bottom up 

class Solution {
    public:
        int longestCommonSubsequence(string s1, string s2) {
    
            int m=s1.length();
            int n=s2.length();
    
            vector<vector<int>>t(m+1,vector<int>(n+1));
    
    
            for(int row=0;row<m+1;row++)
            {
                t[row][0]=0;
            }
            for(int col=0;col<n+1;col++)
            {
                t[0][col]=0;
            }
    
    
            for(int i=1;i<m+1;i++)
            {
                for(int j=1;j<n+1;j++)
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        t[i][j]=1+t[i-1][j-1];
                    }else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
    
                }
            }
            return t[m][n];
        }
    };




    #include <stdio.h>
#include <string.h>

#define MAX 1001  

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char s1[], char s2[]) {
    int n = strlen(s1);
    int m = strlen(s2);

    int t[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int i = n, j = m;
    char lcs[MAX];
    int idx = 0;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[idx++] = s1[i - 1];
            i--;
            j--;
        } else if (t[i - 1][j] > t[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    lcs[idx] = '\0';

    for (int k = 0; k < idx / 2; k++) {
        char temp = lcs[k];
        lcs[k] = lcs[idx - 1 - k];
        lcs[idx - 1 - k] = temp;
    }

    printf("LCS: %s\n", lcs);
    return t[n][m];
}

int main() {
    char s1[MAX], s2[MAX];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int len = lcs(s1, s2);
    printf("Length of LCS: %d\n", len);

    return 0;
}
