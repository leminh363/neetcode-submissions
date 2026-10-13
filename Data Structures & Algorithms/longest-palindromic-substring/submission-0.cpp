#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<char> arr_s;
        for(char c:s) {
            arr_s.push_back(c);
        }
        
        string res;
        int resLen = 0 ;
        int len;
        int start = 0;

        for(int i =0 ; i< arr_s.size(); i++) { 
            
            len = -1;
            int left = i;
            int right = i;

            while(left >= 0 && right < arr_s.size() && arr_s[left] == arr_s[right]) {
                left -= 1;
                right += 1;
                len += 2;
                if (len > resLen) {
                    resLen = len;
                    start = left + 1;
                }
            }

            len = 0;
            left = i;
            right = i+1;
            while(left >= 0 && right < arr_s.size() && arr_s[left] == arr_s[right]) {
                left -= 1;
                right += 1;
                len += 2;
                if (len > resLen) {
                    resLen = len;
                    start = left + 1;
                }
            }
        }
        return s.substr(start, resLen);
    }
};
