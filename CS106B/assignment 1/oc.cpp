string oChelper(string& phrase, int i,string res){
    char x=phrase[i];
    if(i>=phrase.size())    return res;
    if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'|| !isalpha(x)){
        i++;
    }
    else{
        res.append(phrase.substr(i,1));
    }
    oChelper(phrase, i+1, res);

    return res;
}


string onlyConnectize(string phrase) {
    int i=0;
    string res;
    phrase=toUpperCase(phrase);
    return oChelper(phrase, i,res);
}
