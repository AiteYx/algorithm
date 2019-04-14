#include <bits/stdc++.h>
using namespace std;

const int maxLen = 1000;
char str[maxLen];
char str_new[maxLen * 2];
int p[maxLen * 2];
int len_new;

int main()
{
    scanf("%s", &str);

    str_new[0] = '$';
    str_new[1] = '#';
    len_new = 2;
    for (int i = 0; i< strlen(str); i++)
    {
        str_new[len_new ++] = str[i];
        str_new[len_new ++] = '#';
    }

    int id, mx = 0, ans = 0;
    for (int i = 2; i < len_new; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        
        while (str_new[i + p[i]] == str_new[i - p[i]])
            p[i] ++;
        
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
    
    cout << "最长回文串长度是" << ans << endl;
    return 0;
}