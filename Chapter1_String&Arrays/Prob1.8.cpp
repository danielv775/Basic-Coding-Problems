#include <iostream>
#include <string>
using namespace std;
bool isRotation(string s1, string s2);
bool isRotation2(string s1, string s2);
bool isSubstring(string s1, string s2);


int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    if(isRotation2(s1,s2))
    {
        cout << "The Strings are rotations of each other" << endl;
    }
    else
    {
        cout << "The Strings are not rotations of each other" << endl;
    }
}

//find if s2 is a rotation of s1
bool isRotation(string s1, string s2)
{   
    //lengths must be equal
    int length1 = s1.length();
    if(length1 == s2.length() && length1 > 0)
    {   
        //xy =s1, yx = s2, x and y two parts
        //s2 is always a substring of s1s1
        //so we can check for rotation using this knowledge
        string s1s1 = s1 + s1;
        if(s1s1.find(s2) != string::npos)
        {
            return true;
        }
    }
    return false;
}

//same as above except using custom substring function
bool isRotation2(string s1, string s2)
{   
    //lengths must be equal
    int length1 = s1.length();
    if(length1 == s2.length() && length1 > 0)
    {   
        //xy =s1, yx = s2, x and y two parts
        //s2 is always a substring of s1s1
        //so we can check for rotation using this knowledge
        string s1s1 = s1 + s1;
        if(isSubstring(s1s1, s2))
        {
            return true;
        }
    }
    return false;
}

//What if I have to implement my own substring function?
bool isSubstring(string s1, string s2)
{   
    int j = 0;
    int count = 0;
    for(int i = 0; i< s1.length(); i++)
    {
        if(s1[i] == s2[j])
        {
            count++;
            j++;
            if(count == s2.length())
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
