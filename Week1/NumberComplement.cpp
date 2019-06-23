/*Instead of repeatedly trying to get the binary representation, I used bistset and stripped out the leading
//zeroes as a string then used stoi tor convert it to a int after getting the complement.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
Memory Usage: 8.3 MB, less than 38.02% of C++ online submissions for Number Complement.
*/
class Solution {
public:
    int findComplement(int num) {
        string binary=bitset<32>(num).to_string();
        size_t firstNonZero=binary.find("1");
        if(firstNonZero==string::npos)
        {
            return 0;
        }
       else{
           binary=binary.substr(firstNonZero);
       }
        
        for (auto &digit:binary)
        {
            
            if( (digit) ==('1'))
            {
                digit='0';
            }
            else
            {
                digit='1';
            }
        }
        
      return stoi(binary,nullptr,2);  
    }
};
