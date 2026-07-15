bool hpmHelper( Map<string, Set<string>>& allLinks, Map<string, Set<string>>& paired,int n,Set<Pair>& matching){
    if(paired.size() == n){
        return true;
    }
    
    string chosen1=allLinks.firstKey();
    if(!paired.contains(chosen1)){
        paired.add(chosen1,allLinks.get(chosen1));
        allLinks.remove(chosen1);        
        string chosen2 = allLinks.get(chosen1).first();            
        if(!paired.contains(chosen2)){
            paired.add(chosen2,allLinks.get(chosen2));
            allLinks.remove(chosen2);                      
            Pair greek(chosen1,chosen2);
            matching += greek;
            if(hpmHelper(allLinks,paired,n,matching)) return true;
            matching -= greek;
            allLinks.add(chosen1,paired.get(chosen2));            
            paired.remove(chosen2);
        }
        allLinks.add(chosen1,paired.get(chosen1));
        paired.remove(chosen1);
                
    }


    return false;

}
