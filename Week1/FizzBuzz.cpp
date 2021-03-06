/*
Problem:
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and 
for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.

Notes:
I was considering using a check where
if  num is multiple of 3 then add Fizz then
if num is multiple of 5 then add Buzz which 
I feel would have been great for cout the results
but since I am making a vector if results instead I decided
to focus on speed so if FizzBuzz is the right word then the 
num must be divisible by 15 since 3*5=15 
*/

//Acording to LeetCode at the time on 6/22/2019
/Runtime: 8 ms, faster than 81.23% of C++ online submissions for Fizz Buzz.
//Memory Usage: 10.4 MB, less than 31.08% of C++ online submissions for Fizz Buzz.

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int num=1; num<=n;num++)
        {
            if((num%15)==0)
            {
                result.push_back("FizzBuzz");
            }
            else if(num%5==0)
            {
                   result.push_back("Buzz");
            }
            else if(num%3==0)
            {
                   result.push_back("Fizz");
            }
              else
            {
                 result.push_back(to_string(num));
            }
             
             
        }
        return result;
        
    }
};
