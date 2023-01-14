#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> v;

bool is_server(string & s) {
    return  s[0] == 'S';
}

bool is_client(string & s){
    return !is_server(s);
}

int to_number(string &s ){
    int n = 0;
    for(int i =0; i < s.length() ;i++){
        n = n*10 + ( s[i]-'0');
    }
    return n;
}

bool _is_right____ (std::string & s ,int start){
    std::string num;
    int dot_num = 0;
    int mao_num = 0;
    for(int i= start ;i < s.length() ;i++){
        char c = s[i];
        if( c != '.' && c!= ':'){
            num += c;
        }
        else {
            if( c == '.')
                dot_num++;
            else if ( c == ':')
                mao_num++;

            if( num.length() == 0)
                return false;
            if( num[0] == '0' && num.length() > 1)
                return false;

            if( num.length() > 5)
                return 0;
            int number = to_number(num);
            if( number > 255 )
                return false;

            num = "";
        }
    }

    if( dot_num != 3 || mao_num != 1)
        return false;
    if( num.length() == 0)
        return 0;
    if( num[0] == '0' && num.length() > 1)
        return 0;
    if( num.length() > 5)
        return 0;
    int number = to_number(num);
    if( number > 65536 )
        return false;

    return true;
}

bool is_right_format(string & s){
    return _is_right____(s,7);
}

bool judge_from_7(string & s1,string & s2) {
    if( s1.length() != s2.length() )
        return 0;
    for(int i =7 ;i < s1.length() ;i++){
        if( s1[i] != s2[i] )
            return 0;
    }
    return 1;
}

int main(){
    v.reserve(2000);
    cin >> n;
    //std::cout << n << std::endl;

    string s;
    getline(cin, s);

    for(int i=1;i<=n;++i){
        string s;
        getline(cin, s);
        //std::cout << s << std::endl;
        v.push_back( std::move(s) );
        //v.push_back( s);
    }


    for(int i=0;i<n;++i){
        //std::cout << v[i] << std::endl;
        //std::cout << ( is_server(v[i])) << std::endl;
        //std::cout << v[i] << std::endl;
        if( is_server( v[i] )) {
            if( !is_right_format(v[i]) ) {
                std::cout << "ERR" << std::endl;
                continue;
            }

            bool flag = 0;
            for(int j = 0 ; j< i ;j++){
                if( is_server(v[j]) && v[j] == v[i])
                {
                    flag = 1;
                    break;
                }
            }
            if( flag )
                std::cout << "FAIL" << std::endl;
            else
                std::cout << "OK" << std::endl;
        }
        else {
            if( !is_right_format(v[i]) ) {
                std::cout << "ERR" << std::endl;
                continue;
            }
            bool flag  = 0;
            for(int j = 0 ;j< i;j++){
                if( is_server(v[j]) && judge_from_7(v[j], v[i]))
                {
                    std::cout << j+1 << std::endl;
                    flag = 1;
                    break;
                }
            }
            if( flag )continue;
            std::cout << "FAIL" << std::endl;
        }
    }



    return 0;
}
