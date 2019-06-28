/*International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, 
as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
For example, "cba" can be written as "-.-.-...._", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".

    The length of words will be at most 100.
    Each words[i] will have length in range [1, 12].
    words[i] will only consist of lowercase letters.
    
    Notes: This was straighforward and just required the use of a set and array
    
    According to LeetCode on 6/28/2019
    
    Runtime: 4 ms, faster than 91.29% of C++ online submissions for Unique Morse Code Words.
    Memory Usage: 8.8 MB, less than 94.14% of C++ online submissions for Unique Morse Code Words.
    
*/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //First have a array or set of all the letters in Morse code
        if(words.empty())
        {return 0;}
        string morseLetters[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> morseWords;
        
        for (string word: words)
        {
            string morseTransf="";
            for(char letter: word)
            {
                //Since we know all the letters are lowercase we can use letter-a to find
                //its location in morseLeetr. Eg a-a=0 so morseL[0] or a in MCode would be accesed
                morseTransf+= morseLetters[letter-'a'];
                
            }
            morseWords.insert(morseTransf);
        }
        return morseWords.size();
    }
};
