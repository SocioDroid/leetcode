/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (28.44%)
 * Likes:    1477
 * Dislikes: 3677
 * Total Accepted:    236K
 * Total Submissions: 829.8K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer num to its English words representation.
 * 
 * 
 * Example 1:
 * Input: num = 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 * Input: num = 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 * Input: num = 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * Example 4:
 * Input: num = 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution:
    
    
    def hundred(self,num):
        units = {  
            0: "",
            1: "One ",
            2: "Two ",
            3: "Three ",
            4: "Four ",
            5: "Five ",
            6: "Six ",
            7: "Seven ",
            8: "Eight ",
            9: "Nine ",
            10: "Ten ",
            11: "Eleven ",            
            12: "Twelve ",            
            13: "Thirteen ",            
            14: "Fourteen ",
            15: "Fifteen ",            
            16: "Sixteen ",            
            17: "Seventeen ",
            18: "Eighteen ",            
            19: "Nineteen ",
            20: "Twenty ",
            30: "Thirty ",
            40: "Forty ",
            50: "Fifty ",
            60: "Sixty ",
            70: "Seventy ",
            80: "Eighty ",
            90: "Ninety "
        }
        num_str = str(num)
        word = ""
        if len(num_str)==1:
            word = units[int(num_str)]
        elif len(num_str)==2:
            if num_str[0] == '1':
                word = units[int(num_str)]
            else:
                word = units[int(num_str[0])*10] + units[int(num_str[1])]
        elif len(num_str)==3:
            if num_str[1] == '1':
                word = units[int(num_str[0])] + "Hundred "+ units[int(num_str[1:])]
            else:
                word = units[int(num_str[0])] + "Hundred "+ units[int(num_str[1])*10] + units[int(num_str[2])]
        
        return word
    
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        conv = [
            "",
            " Thousand ",
            " Million ",
            " Billion ",
        ]
        
        string = ""        
        count = 0
        
        while(num):
            tnum = num%1000
            num = num//1000
            if tnum:
                string = self.hundred(tnum).strip()+ conv[count] + string
            count+=1
            
        return string.strip()
            
        
        
// @lc code=end

