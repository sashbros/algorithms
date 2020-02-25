#include<stdio.h>
#include<string.h>

int max(int a, int b) {if (a>b) return a; return b; }

int main() {
    
    char n1[200], n2[200];
    scanf("%s", n1);
    scanf("%s", n2);

    int l1, l2;
    for (l1=0; n1[l1]!='\0'; ++l1);
    for (l2=0; n2[l2]!='\0'; ++l2);

    int n = max(l1, l2);
    int arr[n][n], thres, i, j;
    if (n==l1) {
        thres = n-l2;
    }
    else {
        thres = n-l1;
        char tmp[200];
        strcpy(tmp, n1);
        strcpy(n1, n2);
        strcpy(n2, tmp);
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (j<thres)
                arr[i][j]=0;
            else {
                arr[i][j] = (n1[i] - '0') * (n2[j-thres] - '0');
            }
        }
    }
   

    char ans[400];
    int carry=0, it=0;

    int sum = 0;
    for (i=n-1; i>=0; i--) {
        sum=0;
        int fi = n-1;
        for (j=i; j<=n-1; j++) {
            sum += arr[fi][j];
            fi--;
        }
        ans[it] = (sum + carry)%10;
        carry = (sum + carry)/10;
        it++;
    }

    for (i=n-2; i>=0; i--) {
        sum=0;
        int fi = i;
        for (j=0; j<=i; j++) {
            sum += arr[fi][j];
            fi--;
        }
        ans[it] = (sum + carry)%10;
        carry = (sum + carry)/10;
        it++;
    }

    int stop;
    for (i=it-1; i>=0; i--) {
        if (ans[i]!=0)
            break;
    }
    stop = i;


    if (carry != 0)
        printf("%d", carry);
    for (i=stop; i>=0; i--) {
        printf("%d", ans[i]);
    }


    return 0;
}