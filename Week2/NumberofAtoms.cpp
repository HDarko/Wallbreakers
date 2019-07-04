/*
*Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. 
If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. 
For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.
For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: 
the first name (in sorted order), followed by its count (if that count is more than 1),
followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:

Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.

Example 2:

Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:

Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

My Notes:
Ok this has taken a while to think through.
First we have the numbers of an element. he number will either
be 1 or higher. so we can set 1 as the default number unless changed.

Then we have an element name that can either be a single capital
like H or something like Mg. One way to tell between the two is either 
always check the next charater after a Capital or work backwards.
If we work backwards then we know that any Capital we see means the end 
of an element name and we can ship what ever name we have stored at that point.
We need a map then to update the counter per element.

We will need to deal with brackets as well since the number after a bracket 
multplies everything inside. So we also need to know the number of brackets since that can eThe good news is that if we work backwards then we will know
the number that multiples everything in bracket.
Brackets require a bit more thinking. How can we store them. how can we tell between
O2(O2)2 and (O(O4)4)2
We need to both increase and decrease our multiplier based on number of brackets
which can change dynamically.
For example: 
(())
Goes from 1), 2)) ,1(, 0((
Maybe an simple int will work?
-Later-
Need to know the last number used for multiplier so I can divide it.(Will add the number to vector) Also I dont think
I need to keep count of the Parentheses .
(OH)2S
remember that if we reach the capital letter of an element then refresh the numofElem to 1.
Working on the getting the number of elements was slightly irritating cos I assumed the 
elements would be from 0-9 and changing that to account for higher number had some ripple effects.

*/
class Solution {
public:
    string countOfAtoms(string formula) {
        if(formula.empty()){return "";}
        //Since an element is either 2 or 1 letter
        //This variable keeps track of the lowercase letter if
        //one exists else its empty.\0 represents an empty character
        char elemSecondLetter='\0';
        //Vecotr to keep track of the element numbers so 
        //we can pop them off as we closethe brackets they effect
        vector<int> lastNumberOfElem;
        //Multiplier for anything inside the parentheses
        int multiplyInParen=1;
        //string to hold larger digits like 10 and above
        //counter to take care of number per element
        string number;
        int numOfElem=1;
        //Map to keep track of Elements and frequ
        map<string,int> elementFreq;
        //String to hold result
          string result;
        //Moving backwards
        //Initiallize the vector with a 1
        lastNumberOfElem.push_back(1);
        for(int index=(formula.size()-1);index>=0;index--)
        {
            //Firs to thing to search for is ')' which increases
            //our opened but not closed nbrackets counter and updates
            //our modifier by our current Element number
            if(formula[index]==')')
            {
                //update the multplier by curNumofElem which is 1 or higher
                //then reset number of elem to 1
                lastNumberOfElem.push_back(numOfElem);
                multiplyInParen*=numOfElem;  
                
                numOfElem=1;
            }
            else if(formula[index]=='(')
            {
                //Now we divide the mulplier by the last number effecting it
                // and remove the last number in the vector
                 //if(lastNumberOfElem.empty())
                
        
                 multiplyInParen/=lastNumberOfElem.back();
                 lastNumberOfElem.pop_back();     
            }
            //If its a number then 
            else if (isdigit(formula[index]))
            {
                //Need to loop backwards to get rest of digits if they exist
                //since we change the index we need to return that to skip
                index=FindNumber(number, index,formula);

              
                 //add the number to the vector of last seen Elment numbers
                //this number is the new numofElment.
                
                numOfElem=(stoi(number));
                number="";
            }
           // if lowercase then update second letter container
            else if(islower(formula[index]))
            {
               elemSecondLetter= formula[index];
            }
            //If upper then enter the current name and elemCount*multiplier into map
            //then reset the elemSeconLetter and numofElem
            else if (isupper(formula[index]))
            {
                 string name;
                 name.push_back(formula[index]);
                if(elemSecondLetter!='\0')
                {
                    name.push_back(elemSecondLetter);
                    elementFreq[name]+= (numOfElem*multiplyInParen);     
                }
                else
                {
                    //cout<<name<<multiplyInParen<<"\n";
                  elementFreq[name]+= (numOfElem*multiplyInParen);  
                }
                
                elemSecondLetter='\0';
                numOfElem=1;
            }
                
        }
         for(auto &elemCount:elementFreq)
            {
                result+=elemCount.first;
                result+= (elemCount.second>1? to_string(elemCount.second): "");
            }
             
          return result;
}
                      
       int FindNumber(string& numberHolder, int curIndex,string& formula)
                      {
                         while(isdigit(formula[curIndex]))
                        {
                        numberHolder=formula[curIndex]+numberHolder;
                          curIndex--;
                        }
                        //We want to return the first digit index so
                        
                               return curIndex+1;
                      }
};
       

        
