
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn], t[maxn];
int p[maxn];

int main(){
    while(~scanf("%s", s)){
        int l = strlen(s), len = 0;
        t[len++] = '$';
        t[len++] = '#';
        for(int i = 0; i < l; ++i){
            t[len++] = s[i];
            t[len++] = '#';
        }
        t[len] = '&';

        int center = 0, max_right = 0;
        for(int i = 1; i < len; ++i){
            int i_mirror = 2 * center  - i;
            if(max_right > i){
                p[i] = min(max_right - i, p[i_mirror]);
            }
            else {
                p[i] = 0;
            }
            while(t[i - 1 - p[i]] == t[i + 1 + p[i]])
                ++p[i];

            if(i + p[i] > max_right){
                center = i;
                max_right = i + p[i];
            }
        }

        int max_len = 0;

        for(int i = 1; i < len; ++i)
            if(max_len < p[i]){
                max_len = p[i];

            }
        printf("%d\n", max_len);
    }
    return 0;
}