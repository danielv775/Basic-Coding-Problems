#include <iostream>
#include <string>
using namespace std;
string compression(string s);
string compression2(string s);
int countCompression(string s);
int setChar(char* array1, char c, int index, int count);

int main(){
    string s = "aabcccccaaa";
    //cout << compression(s) << endl;
    cout << compression2(s) << endl;
}

int setChar(char* array1, char c, int index, int count)
{
    array1[index] = c;
    index++;
    //convert count to string and then to array of chars
    
    //make char buffer for string to be changed
    string count2 = to_string(count);
    
    char cnt[20];
    strncpy(cnt, count2.c_str(), sizeof(cnt));
    
    //copy char from biggest digit to smallest
    for(int i = 0; i< strlen(cnt); i++)
    {
        array1[index] = cnt[i];
        index++;
    }
    return index;
}

//count size of compressed string, and return its size
int countCompression(string s)
{
    if(s == "0" || s.empty())
    {
        return 0;
    }
    char last = s.at(0);
    int size = 0;
    int count = 1;
    for(int i  = 1; i<s.length(); i++)
    {   
        //count for repeated chars
        if(s.at(i) == last)
        {
            count++;
        }
        else
        {   
            //not repeated char, change current char
            //count the size, which is 1 for the char, and then the string
            //length of its count
            last = s.at(i);
            size += 1 + to_string(count).length();
            count = 1;
        }
    }
    size += 1 + to_string(count).length();
    return size;
}

//Book solution, works but for some reason getting random additional chars at end
string compression2(string s)
{
    //check if compression would result in larger string
    int size = countCompression(s);
    if(size >= s.length())
    {
        return s;
    }
    char array1[size];
    int index = 0;
    char last = s.at(0);
    int count = 1;
    for(int i = 1; i< s.length(); i++)
    {
        if(s.at(i) == last)
        {
            count++;
        }
        else
        {
            index = setChar(array1, last, index, count);
            last = s.at(i);
            count = 1;
        }
    }
    index = setChar(array1, last, index, count);
    string str(array1);
    return str;
}

//1st solution, somewhat inefficient because string concatenation take O(n^2)
string compression(string s)
{
    int count = 1;
    string s2 = "";
    for(int i = 0; i < s.length()-1;i++)
    {
        if(s[i] == s[i+1])
        {
            count++;
        }
        if(s[i] != s[i+1])
        {   
            //debug
            //cout << s[i] << "..." << count << endl;
            
            s2 = s2 + s[i] + to_string(count);
            count = 1;
        }
        if(i == s.length() -2)
        {
            //debug
            //cout << s[i] << "..." << count << endl;
            s2 = s2 + s[i] + to_string(count);
        }
        
    }
    
    if(s2.length() < s.length())
    {
        return s2;
    }
    else
    {
        return s;
    }
}