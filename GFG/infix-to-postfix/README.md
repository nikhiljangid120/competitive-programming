# Infix to Postfix

- **Platform:** GFG
- **Language:** C++

## Solution

```cpp
class Solution {
  public:
    int order(char ch){
        int value = -1;
        switch(ch){
            case '^': value = 3; break;
            case '/': value = 2; break;
            case '*': value = 2; break;
            case '+': value = 1; break;
            case '-': value = 1; break;
            default : value = -1; break;
        }
        return value;
    }
      string infixToPostfix(string& s) {
          string str = "";
          stack<char>st;
          for(auto it: s){
              if(it != '+' && it != '-' && it != '/' 
                      && it != '*' && it != '(' && it != ')' && it != '^'){
                  str += it;
              }
              else{
                  if(it == '(') st.push(it);
                  else if(it == ')'){
                      while(!st.empty() && st.top() != '('){
                          str += st.top();
                          st.pop();
                      }
                      st.pop();
                  }
                  else{
```
