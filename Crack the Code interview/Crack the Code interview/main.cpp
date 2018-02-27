//
//  main.cpp
//  Crack the Code interview
//
//  Created by James Fong on 2018-02-21.
//  Copyright © 2018 James Fong. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;

//Question 1.1
bool isUnique(string line){
    unordered_set<char> unique_char;
    for(int i = 0; i< line.length(); i++){
        char c = line.at(i);
        unordered_set<char>::iterator finder = unique_char.find(c);
        if(finder == unique_char.end()){
            unique_char.insert(c);
        } else {
            return false;
        }
    }
    return true;
}

bool isUniqueWithoutDS(string line){
    for(int x = 0; x< line.length(); x++){
        char c = line.at(x);
        for(int y = x+1 ; y < line.length(); y++){
            if( c == line.at(y)) return false;
        }
    }
    return true;
}

//question 1.2
bool checkPermutation(string line1, string line2){
    map<char,int> permutedTable;
    string permutedString = (line1.length() > line2.length()) ? line1 : line2;
    string checkString =(line1.length() <= line2.length()) ? line1 : line2;
    for(int x = 0; x< permutedString.length(); x++){
        char c = permutedString.at(x);
        permutedTable[c] = (permutedTable.find(c) == permutedTable.end()) ?  1:  permutedTable.at(c) + 1;
    }
    for(int y = 0; y< checkString.length(); y++){
        char s = checkString.at(y);
        if(permutedTable.find(s) != permutedTable.end()){
            permutedTable[s] = permutedTable[s] - 1;
            if(permutedTable[s] == 0){
                return false;
            }
        }
        else {
            return false;
        }
    }
    return true;
}


//question 1.3
string URLify(string line){
    int i = 0;
    //trim
    while(i<line.length() && isspace(line[i])){
        i++;
    }
    line = line.substr(i, line.length() - i);
    i = (int)line.length() - 1;
    while(i>=0 && isspace(line[i])){
        i--;
    }
    line = line.substr(0,i+1);
    string output = "";
    bool added = false;
    for(int x=0; x<line.length(); x++){
        if(isspace(line[x]) && !added){
            output += "%20%";
            added = true;
        }
        else if(!isspace(line[x])){
            added = false;
            output+= line[x];
        }
    }
    return output;
}

//question 1.4
bool palindromePermutation(string line){
    map<char,int> permutedTable;
    for(int x = 0; x< line.length(); x++){
        if(!isspace(line[x])){
            permutedTable[line[x]] = (permutedTable.find(line[x]) == permutedTable.end()) ?  1:  permutedTable.at(line[x]) + 1;
        }
    }
    bool allowance = true;
    for(map<char,int>::iterator i = permutedTable.begin(); i!=permutedTable.end(); i++){
        if(i->second % 2 == 1){
            if(allowance){
                allowance = false;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

//question 1.5
bool oneAway(string line1, string line2){
    if(line1.length() - 1 > line2.length() || line1.length() + 1 < line2.length()) return false;
    bool flag = false;
    int j = 0;
    for(int i = 0; i < line1.length(); i++){
        if(line1[i] != line2[j]){
            if(flag){
                return false;
            }
            else if(line1.length() == line2.length() + 1){
                j--;
            }
            else if(line1.length() == line2.length() - 1){
                j++;
            }
            flag = true;
        }
        j++;
    }
    return true;
}
//question 1.6
string stringCompression(string line){
    
    return "";
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
