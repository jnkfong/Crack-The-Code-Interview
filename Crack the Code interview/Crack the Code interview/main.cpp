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

void question_1_1(string line) {
    cout << "is Unique: "<< isUnique(line) << "\n";
    cout << "is Unique Without Data Structure: "<< isUniqueWithoutDS(line) << "\n";
}


bool question1_2(string line1, string line2){
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

int main(int argc, const char * argv[]) {
  
    return 0;
}
