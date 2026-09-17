#include <vector>
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(!stack.empty() && s[i] == ')' && stack[stack.size() - 1] == '('){
                stack.pop_back();
            }
            else if( !stack.empty() && s[i] == ']' && stack[stack.size() - 1] == '['){
                stack.pop_back();
            }
            else if(!stack.empty() && s[i] == '}' && stack[stack.size() - 1] == '{'){
                stack.pop_back();
            }
            else{
                stack.push_back(s[i]);
            }
        }

        return stack.empty();
    }
};