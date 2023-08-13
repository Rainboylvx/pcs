#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char word[20],article[maxn];
int lenw,lena,cnt,first = -1,idx,word_2_start;
int main() {
    cin.getline(word,100); //读第一行
    cin.getline(article,maxn); // 读取第二行
    lenw = strlen(word); // 求长度
    lena = strlen(article);
    for(int i =0;i<lenw;i++) if( word[i] >='A' && word[i] <='Z') word[i] = word[i]-'A' + 'a';
    for(int i =0;i<lena;i++) if( article[i] >='A' && article[i] <='Z') article[i] = article[i]-'A' + 'a';
    for(int i = 0 ;i< lena;i++) { // 遍历article每个字符
        if( article[i] == ' ') {
            if( idx != 0 && idx == lenw && strncmp(word,article+word_2_start,lenw) == 0 ) {
                if( first == -1) first = word_2_start;
                cnt++;
            }
            idx = 0;
        }
        else if( idx == 0) // 遇到了单词的开头,记录单词的开始位置
            word_2_start = i,idx++;
    }
    if( cnt == 0) cout << -1;
    else cout << cnt << " " << first;
    return 0;
}
