#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;

char word[20];
int lenw;
int lena;
int cnt;
int first = -1;
char article[maxn];
char word2[maxn];
int idx,word_2_start;
// idx word2里存的字符的数量


void to_lower(char * s,int size){
    for(int i =0;i<size;i++)
        if( s[i] >='A' && s[i] <='Z')
        {
            s[i] = s[i]-'A' + 'a';
        }
}

bool is_equal() {
    for(int i =0;i<lenw;i++) {
        if( word[i] != word2[i])
            return false;
    }
    return true;
}


int main() {
    cin.getline(word,100); //读第一行
    cin.getline(article,maxn); // 读取第二行
    lenw = strlen(word); // 求长度
    lena = strlen(article);

    to_lower(word,lenw); // 全部转小写
    to_lower(article,lena);

    // 遍历article每个字符
    for(int i = 0 ;i< lena;i++) {
        if( article[i] == ' ')
        {
            if( idx != 0 && idx == lenw && is_equal() ) {
                if( first == -1) first = word_2_start;
                cnt++;
            }
            idx = 0;
        }
        else
        {
            if( idx == 0) word_2_start = i; // 遇到了单词的开头,记录单词的开始位置
            word2[idx++] = article[i]; // 存入word2里
        }
    }
    if( cnt == 0)
        cout << -1;
    else
        cout << cnt << " " << first;

    return 0;
}
