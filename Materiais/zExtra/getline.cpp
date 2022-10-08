#include <bits/stdc++.h>
using namespace std;
// Sempre usar cin.ignore() entre um cin e um getline
int main() {

    string s1; cin>>s1;
    cin.ignore();
    while (true) {
        string s; getline(cin, s);
        if (s == "PARO") break;
        cout<<"A"<<endl;
    }
    string s2; cin>>s2;
    cin.ignore();
    while (true) {
        string s3; getline(cin, s3);
        if (s3 == "PARO") break;
        cout<<"A"<<endl;
    }
}