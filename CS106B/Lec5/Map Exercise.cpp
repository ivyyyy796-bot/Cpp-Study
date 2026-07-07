#include <iostream>
#include "console.h"
#include <string>
#include <fstream>
#include "map.h"
#include "strlib.h"
using namespace std;
int main()
{
    ifstream input;
    input.open("data/poem.txt");

    Map<string,int> map;
    string word;
    while(input >> word){
        word=toLowerCase(word);
        if(!map.containsKey(word)){
            map[word]=1;
        }
        else{
            map[word]++;
        }
    }

    string key;
    cout << "Please enter a word to query: " << endl;
    cin >> key;
    key=toLowerCase(key);
    cout << map[key] << endl;

    input.close();
    return 0;
}
