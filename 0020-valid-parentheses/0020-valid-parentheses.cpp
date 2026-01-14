class Solution {
public:
    bool isValid(string s) {
        vector<char> openBrackets;
        vector<char> closeBrackets;
        unordered_map<char,char> brackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'} 
            };
        for(char c : s){
            if(brackets.count(c)){
                openBrackets.push_back(c);
            }
            else{
                closeBrackets.push_back(c);
                if(openBrackets.empty()) return false;
                char back = openBrackets.back();
                if(brackets[back] == c){
                    openBrackets.pop_back();
                    closeBrackets.pop_back();
                }
            }
        }
        if(openBrackets.empty() && closeBrackets.empty()) return true;
        return false;
    }
};