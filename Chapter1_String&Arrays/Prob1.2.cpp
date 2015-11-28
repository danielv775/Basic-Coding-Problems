#include <iostream>
#include <string>
using namespace std;
void reverse(string s);
void reverse2(char *str);
void reverse3(char *str);

int main(){
    char s[] = "abcd\0";
    reverse3(s);
    for(int i = 0; i< strlen(s); i++)
    {
        cout << s[i] << endl;
    }
}

//1st basic string c++ implementation O(n)
void reverse(string str){
    string rev = "";
    for(int i = str.length()-1;i>=0;i--){
        rev+=str[i];
    }
    cout << rev << endl;
}

//C implementation with char*
//Book solution
void reverse2(char *str){
    char* end = str;
    char tmp;
    if(str){
        while(*end){
            ++end;
        }
        --end;
        //end now points to last char in string, right before NULL terminator
        //now swap from both sides starting pointer and ending pointer
        while(str < end){
            tmp = *str;
            *(str++) = *end;
            *(end--) = tmp;
        }
    }
    //post inc/dec, value is stored and after, the pointer is shifted
}
//C implementation version2 different way of setting pointer on both ends
void reverse3(char *str)
{
    char *start = str;
    char *end = str+strlen(str)-1;
    char tmp;
    //set pointers to start and end
    while(start < end)
    {
        tmp = *start;
        *(start++) = *end;
        *(end--) = tmp;
    }
}