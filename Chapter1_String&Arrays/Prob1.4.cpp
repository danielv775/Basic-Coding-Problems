#include <iostream>
#include <string> 
using namespace std;
string replace(string s);
void replaceSpaces(char str[], int length);

int main(){
   string s = "a b  c      ";
   char str[] = "a b  c      ";
   int length =  6;
    //length is the 'true length' does not inclue the spaces at the end
    //when i was putting the whole length, I got the error trap abort 6, because
    //I was iterating in memory I did not have access to
   //cout << replace(s) << endl;
    replaceSpaces(str, length);
    cout << str << endl;
    
}

//Book solution, replace ' ' with %20
void replaceSpaces(char str[], int length)
{
    int spaceCount = 0;
    int newlength;
    int i;
    for(i = 0; i < length; i++)
    {
        if(str[i] == ' ')
        {
            spaceCount++;
        }
    }
    newlength = length + spaceCount*2;
    str[newlength] = '\0';
    
    for(i = length - 1; i>= 0; i-- )
    {
        if(str[i] == ' ')
        {
            str[newlength - 1] = '0';
            str[newlength - 2] = '2';
            str[newlength - 3] = '%';
            newlength = newlength - 3;  
        }
        if(str[i] != ' ')
        {
            str[newlength-1] = str[i];
            newlength = newlength - 1;
        }
    }
}

string replace(string s)
{       
    //do not want end of string to be filled with %20
    //must find sudo length
    int count = 0;
    int length2 = s.length();
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            count++;
        }
        if(s[i] != ' ')
        {
            count = 0;
        }
        if(s[i] == ' ' && (i == s.length() - 1) )
        {
            length2 -= count;
        }
        cout << length2 << endl;
    }
    
    string s2 = "";
    for(int i = 0; i<length2;i++)
    {
        if(s[i] == ' ')
        {
            s2 += "%20";
        }
        if(s[i] != ' ')
        {
            s2 += s[i];
        }
    }
    return s2;
}