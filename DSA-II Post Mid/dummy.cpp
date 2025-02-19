#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "heap";
    string b = "pea";
    string c = "ea";
    string s = "";

    for (char ch : a) {
        if (c.find(ch) == string::npos) {
            s += ch;
        }
    }

    cout << s << endl;
string k="Hello World";
size_t pos = k.find(' ');

    string i = k.substr(0,pos);
    string j = k.substr(pos+1);
    cout<<i<<endl;
cout<<j<<endl;



}
