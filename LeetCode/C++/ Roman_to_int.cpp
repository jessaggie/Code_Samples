#include <iostream>
#include <string>
#include <map>

//Compilation Instructions: g++ -std=c++11 \ Roman_to_int.cpp -o Roman_to_int.out

class Solution {
public:
    int romanToInt(std::string s) {
        //Function to convert roman numerals to integers
        //Create Map of roman Numerals
        //Iterate over input string by index
        //compare char at current and next index
        //if current char's value is less than next char
        //multiply current char's value by -1
        //add to running total
        //after loop finishes, return running total

            //(i.e. IXC placed before VX, LC, DM)
            //if value is less than next, multiply it by -1
            //add values 
            //III, I, not less than -1, add to I, add to I
            //XCIX, x <C, means -x+c, I <X, means -I+x

       
        //init new variables
        int running_total = 0;
        int current_num = 0;
        //create map of roman numerals to their equiv int value
        std::map <char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        //iterate over input string
        for (int i = 0; i<s.length(); i++)
            {           
                //translate the roman numeral 
                //compare to that of next
                if (roman[s[i]] < roman[s[i+1]])
                {
                    //if less than, multiply my -1
                    current_num = roman[s[i]] * -1;
                }
                else
                {
                current_num =roman[s[i]];
                }

                running_total +=current_num;
            }
            return running_total;
    }
};


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <Roman numeral>" << std::endl;
        return 1;
    }
    
    std::string input = argv[1]; // Read the first command-line argument as the Roman numeral
    
    Solution solute;
    int output = solute.romanToInt(input);
    std::cout << output;
}