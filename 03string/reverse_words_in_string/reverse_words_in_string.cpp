/*
Reverse Words in a String:
https://leetcode.com/problems/reverse-words-in-a-string

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.


Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.

Could the input string contain leading or trailing spaces?Yes. 
However, your reversed string should not contain leading or 
trailing spaces.

How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

By checking the clarifications, the programming is straightforward, 
here provides a simple version which uses buffer strings:
(1)Loop from start to the end of the string:
          (a) if current char is space and word string is empty, continue.
          (b) if current char is space but word string is NOT empty, 
          which means we meet the end of word, then output the word, r
          eset the word, continue.
          (c) if current char is non-space char, add this char to the word 
          string, continue

(2)Handle the last word:
      (a) if the last word is empty, which means the input is empty, 
      or the input has only spaces, or the last char/chars are spaces.  
      Then just remove the last space in the output string and return.
      (b) if the last word is not empty, add the last word to the front 
      of the output string, then remove the last space in the output 
      string and return.


*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string word; //tmp string to store each word
        string res; // result string

        int i=0;

        while (i<s.size()){
            if (char(s[i]) == ' ' && word.empty()){
                i++;
                continue;
            } //multiple spaces
            
            if (char(s[i]) == ' ' && !word.empty()){ //first space after a word
                res = word + " " + res; //store the word
                word= ""; //reset the word
                i++; 
                continue;
            }

            if (char(s[i])!=' '){
                word = word + char(s[i]);
                i++; 
                continue;
            } //non-space chars 
        }
         
        if (!word.empty()){ //last word
            s = word + " " + res;
        } else {
            s = res;
        }

        s = s.substr(0, s.size() - 1); //eliminate the last space

        cout << "s is: " << s << endl;
    }
};

int main() {

    Solution s;
    string string("   Hello String");
    cout << "S is: " <<  string << endl;
    s.reverseWords(string);

    return 0;
}
