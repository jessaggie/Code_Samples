#include <iostream>
#include <string>
#include <vector>

//compilation instructions: g++ -std=c++11 longest_common_prefix.cpp -o longest_common_prefix
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        //find the longest common prefix of a list of words
     
        //idea:
        //get i when the i'th letter of all the strings does not match. return the string up to i

        //only care about going through the length of the first string
        //need a way to check all of them at once 
        //use an 'all of' function to check each str in list
        //for same letter i
        //throw flag if they are not equal
        //if flag, break;
        //return up to i


        std::string longestPrefix = "";
        //iterate through the first word
        for(int i = 0; i< strs[0].length(); i++)
        {
            
            //run a lambda on each string in the list of strings, comparing the i'th position
            //if i'th position does not match for all, raise flag
            bool letterSame = std::all_of(strs.begin(), strs.end(), [&](const std::string& str) 
            { return str.size() > i && str[i] ==strs[0][i]; });

            //check flag
            if (!letterSame)
            {
                //set longest prefix to point at which flag is raised
                longestPrefix = strs[0].substr(0,i);
                break;
            } 
            else
            {
                longestPrefix = strs[0];
            }     
        }
        //check for adverse conditions where the list is only 1 word long
        if (strs.size() == 1)
        {
            longestPrefix = strs[0];
        }
        return longestPrefix;
    }
};


int main() {
  Solution solute;
  std::vector<std::string> strings = {"flower", "flow", "flight", "flip"};

  std::cout << solute.longestCommonPrefix(strings);

}