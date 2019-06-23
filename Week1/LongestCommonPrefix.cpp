/*Had a bit of issue with this one.
The problem was just the order I was testing when the vector or a string was empty
According to LeetCode
Runtime: 4 ms, faster than 97.64% of C++ online submissions for Longest Common Prefix.
Memory Usage: 15.1 MB, less than 5.06% of C++ online submissions for Longest Common Prefix.
*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool isSame{true};
        int index=0;
        char letter;
        string prefix="";
         if(strs.empty())
        {
            return "";
        }
        if((strs[0].empty()))
        {
            return "";
        }
       
       //cout<<strs.size();
        while(isSame)
        {
            //cout<<index;
            letter=strs[0][index];
            //cout<<letter;
            for(string word:strs)
            {
                //cout<<word[index];
              
                //cout<<word<<"\n";
                if((index)>= word.size())
                {
                    //cout<<word.size()<<"\n";
                    isSame=false;
                    break;
                }
                else
                {
                    //cout<<word.size()<<"\n";
                    if(letter!=(word[index]))
                    {
                        isSame=false;
                        break;
                    }
                }  
            }
              //cout<<"cyr";
            if (isSame)
            {
            prefix+=letter;
            index++;
            }
            
        }
        return prefix;
        
    }
};
