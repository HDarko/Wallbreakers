/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> unclosedBrackets;
        vector<char> opBracks{'(','{', '['};
        vector<char> closBracks{')','}', ']'};
        for( char &brac: s)
        {
            if(find(opBracks.begin(), opBracks.end(), brac)!= opBracks.end())
            {
                unclosedBrackets.push(brac);
            }
            else
            {
                //if we have a close but no open brack
                if (unclosedBrackets.empty()) {return false;}
                else
                {
                    auto topOpenBrac=find(opBracks.begin(), opBracks.end(),
                                          unclosedBrackets.top());
                        // take advatage that the brackets are in the same order in our vectors
                        if(brac==closBracks[topOpenBrac-opBracks.begin()])
                        {
                            unclosedBrackets.pop(); 
                        }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return (unclosedBrackets.empty());
        
    }
};
