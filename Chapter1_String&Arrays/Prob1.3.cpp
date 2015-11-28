#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPermutation(string shortString, string longString);
bool isPermutation2(string s1, string s2);

int main(){
    
    string shortString = "abcdef";
    string longString = "fedbca";
    if(isPermutation2(shortString,longString)){
        cout << "The short string is a permutation of the long one " << endl;
    }
    else{
        cout << "The short string is not a permuation of the long one " << endl;
    }
    
}

//Better Solution for Permutations
//1 sort the strings, and then compare.
//If different lengths, cannot be permutations as well
//If they are permutations, they have the same chars but in different order


bool isPermutation2(string s1, string s2)
{   
    //optimization, if strings not equal in length, not same amount of chars, cannot be permutations
    if(s1.length() != s2.length())
    {   
        return false;
    }
    //if sorted strings are equal they are permutations of each other
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << s1 << " " << s2 << endl;
    if( s1 == s2 )
    {
        return true; 
    }
    return false;
}

//Given 2 strings, return true if one is a permutation of the other
//1st argument is short string, 2nd argument is long string
//O(n) run time
bool isPermutation(string s1, string s2)
{
    int count = 0;
    int j = 0;
    for(int i = 0; i<s2.length(); i++)
    {
        if(s2[i] == s1[j])
        {
            count++;
            j++;
            if(count == s1.length())
            {
                return true;
            }
        }
        else
        {
            count = 0;
            j = 0;
        }
    }
    return false;
}

