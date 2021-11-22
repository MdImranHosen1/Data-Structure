#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<string> s;
    s.push("India");
    s.push("Bangladesh");
    s.push("Bhutan");
    s.push("Nepal");
    s.push("Srilanka");
    s.push("Maldivs");

    while(!s.empty()){
        string x = s.top();
        cout<<x<<endl;
        s.pop();
    }
    return 0;

}