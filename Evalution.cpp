#include <bits/stdc++.h>
using namespace std;

int main() {
    stack <int> st;

   char s[]="231*+9-" ;

    for(int i=0;i<7;i++){

        if (isdigit(s[i])){
            st.push((int)s[i]);

        }
        else{
            float val1,val2;
            val1=st.top();
            st.pop();
            val2=st.top();
            st.pop();
           switch (s[i])
            {
             case '+': st.push( val2 + val1); break;
             case '-': st.push(val2 - val1); break;
             case '*': st.push( val2 * val1); break;
             case '/': st.push( val2/val1);   break;

            }
        }

    }int m=st.top();
    cout<<m;