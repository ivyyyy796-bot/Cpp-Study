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
