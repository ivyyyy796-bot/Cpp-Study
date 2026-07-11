string oChelper(string phrase, int i){
    i=0;
    string res;
    for (char x : phrase) {
        i++;
        if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'|| !isalpha(x)){
            oChelper(phrase.substr(i,phrase.size()-1),i);
        }
        else res.append(phrase.substr(i-1,1));
    }
    return res;
}


string onlyConnectize(string phrase) {
    int i=0;
    phrase=toUpperCase(phrase);
    return oChelper(phrase, i);
}
