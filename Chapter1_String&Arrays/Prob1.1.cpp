#include <iostream>
#include <string>
using namespace std;
bool Unique(string s);
bool isUnique(string s);

int main(){
    //cout << "Hello World" << endl;
    string s = "abcdefghijklmnoq";
    if(isUnique(s)){
        cout << " Unique String " << endl;
    }
    else{
        cout << "Not unique String" << endl;
    }
    return 0;
}

//1.1
//Good Solution. O(n)
//1st optimize if string is longer than available chars to select from, its not unique
//create bool array to store if a char has occured
//check if char in ascii string is in array, if it is, return false
//set occurance to true of that char in the bool array
//if reaches the end, it means that a second occurance was not found, and string is unique
bool isUnique(string s){
    if(s.length() > 128) return false; //checks if string > unique # of chars
    bool char_set[256]; //array to store occurance of char
    for(int i = 0; i< s.length(); i++)
    {
        int value = s.at(i); //extract current ascii char
        if(char_set[value]){ //if char already exists in the array
            return false; //not unique
        }
        char_set[value] = true; //that char exists in array
    }
    return true; //unique string
}

