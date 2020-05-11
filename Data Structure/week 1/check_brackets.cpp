#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}



    char type;
    int position;
};

 bool Matchc(char type, char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

int main() {
    std::string text;
    getline(std::cin, text);
    bool t = true;
    std::stack <pair<char,int>> brackets;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            brackets.push(make_pair(next,position+1));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(brackets.empty()){
               t = false;
               cout<<position+1<<endl;
               break;
            }
            else{
               char top = brackets.top().first;
               if(Matchc(top,next))
               {
               brackets.pop();
               }
               else{
               t = false;
               cout<<position+1<<endl;
               break;
               }

               }
        }
    }

    if(t && brackets.empty())
        cout<<"Success"<<endl;
    else if(t && !brackets.empty())
        cout<<brackets.top().second<<endl;

    // Printing answer, write your code here



    return 0;
}
