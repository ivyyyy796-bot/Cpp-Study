bool hpmHelper( Map<string, Set<string>>& allLinks, Map<string, Set<string>>& paired,int n,Set<Pair>& matching){
    if(paired.size() == n){
        return true;
    }
    
    for(string chosen1 : allLinks){
        if(!paired.contains(chosen1)){
            for(string chosen2 : allLinks.get(chosen1)){
                if(!paired.contains(chosen2)){
                    paired += chosen1;
                    paired += chosen2;
                    Pair greek(chosen1,chosen2);
                    matching += greek;
                    if(hpmHelper(allLinks,paired,n,matching)) return true;
                    matching -= greek;
                    paired -= chosen1;
                    paired.remove(chosen2);
                }
            }
        }
    }

    return false;

}
