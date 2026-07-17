bool hpmHelper(Map<string, Set<string>>& allLinks, Set<Pair>& matching,
            Set<string> paired,int n){
    if(paired.size() == n){
        return true;
    }
    //choose first person
    string chosen1;
    for(string s : allLinks){
        if(!paired.contains(s)){
            chosen1 = s;
            break;
        }
    }
    //choose second person
    string chosen2;
    for(string s : allLinks.get(chosen1)){
        if(!paired.contains(s)){
            chosen2 = s;
            //choose
            paired += chosen1;
            paired += chosen2;
            Pair greek(chosen1,chosen2);
            matching += greek;
            //explore
            if(hpmHelper(allLinks,matching,paired,n)){
                return true;
            }
            //unchoose
            paired -= chosen1;
            paired -= chosen2;
            matching -= greek;
        }
    }
    return false;

}

bool hasPerfectMatching(const Map<string, Set<string>>& possibleLinks, Set<Pair>& matching) {
    Map<string, Set<string>> allLinks = possibleLinks;
    Set<string> paired {};
    int n = allLinks.size();
    return hpmHelper(allLinks,matching,paired,n);
}
