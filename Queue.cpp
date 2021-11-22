#include<iostream>
#include<queue>
using namespace std;
int main(){

    queue<string> q;
    q.push("India");
    q.push("Bangladesh");
    q.push("Bhutan");
    q.push("Nepal");
    q.push("Srilanka");
    q.push("Maldivs");

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;

}