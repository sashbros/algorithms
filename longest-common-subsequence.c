#include<stdio.h>
#include<string.h>

int max(int a, int b) {if (a>b) return a; return b; }

int main() {
    
    char s1[4000], s2[4000];
    scanf("%s", s1);
    scanf("%s", s2);
    int l1=strlen(s1), l2=strlen(s2);
    int dp[l1+1][l2+1], i, j;
    for (i=0; i<=l1; i++)
        dp[0][i]=0;
    for (i=1; i<=l2; i++)
        dp[i][0]=0;
    for (i=0; i<l1; i++) {
        for (j=0; j<l2; j++) {
            if (s1[i]==s2[j])
                dp[i+1][j+1] = 1 + dp[i][j];
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    printf("%d\n", dp[l1][l2]);
    int ansLen=dp[l1][l2];
    char ans[ansLen];
    i=l1, j=l2;
    int cnt = 0;
    while(1) {
        if (s1[i-1]==s2[j-1]){
            // printf("%c", s1[i-1]);
            ans[cnt]=s1[i-1];
            i=i-1;
            j=j-1;
            cnt++;
        }
        else{
            if (dp[i-1][j] > dp[i][j-1]) {
                i=i-1;
            }
            else {
                j=j-1;
            }
        }
        if (cnt==ansLen)
            break;
    }
    for (i=ansLen-1; i>=0; i--)
        printf("%c", ans[i]);
        
    return 0;
}