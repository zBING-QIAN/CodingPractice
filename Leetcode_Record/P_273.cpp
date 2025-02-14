#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string numberToWords(int num) {
        static const std::vector<std::string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        static const std::vector<std::string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        static const std::string hundred = "Hundred";
        static const std::string thousand = "Thousand";
        static const std::string million = "Million";
        static const std::string billion = "Billion";
        if (num == 0) {
            return "Zero";
        } else if (num < 20) {
            return belowTwenty[num];
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 ? " " + belowTwenty[num % 10] : "");
        } else if (num < 1000) {
            return belowTwenty[num / 100] + " " + hundred + (num % 100 ? " " + numberToWords(num % 100) : "");
        } else if (num < 1000000) {
            return numberToWords(num/1000) + " " + thousand + (num % 1000 ? " " + numberToWords(num % 1000) : "");
        } else if (num < 1000000000) {
            return numberToWords(num / 1000000) + " " + million + (num % 1000000 ? " " + numberToWords(num % 1000000) : "");
        } else if (num >= 1000000000) {
            return numberToWords(num/1000000000) + " " + billion + (num % 1000000000 ? " " + numberToWords(num % 1000000000) : "");
        }
        return "";
    }
    
};