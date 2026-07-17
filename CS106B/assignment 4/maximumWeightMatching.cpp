// **1. 无需手动清零val2； 2. pairing-explore-unchoose 必须在已选择chosen2的基础上进行

void mwmHelper(const Map<string, Map<string, int>>& allLinks,Set<string>& paired,
                    Set<Pair>& matching, int& val1,int& val2,Stack<Set<Pair>>& stack){
    if(paired.size() == allLinks.size()){
        if(val2 > val1){
            val1 = val2;
            stack.push(matching);
        }
        return ;
    }
    string chosen1;
    string chosen2;
    Pair greek;
    for(string s1 : allLinks){
        if(!paired.contains(s1)){
            chosen1 = s1;
            break;
        }
    }
    paired += chosen1;
    mwmHelper(allLinks,paired,matching,val1,val2,stack);
    paired -= chosen1;

    for(string s2 : allLinks.get(chosen1)){
        if(!paired.contains(s2)){
            chosen2 = s2;
        //pairing
        Pair greek(chosen1,chosen2);
        matching += greek;
        paired += chosen1;
        paired += chosen2;
        val2 += allLinks[chosen1][chosen2];
        //explore
        mwmHelper(allLinks,paired,matching,val1,val2,stack);
        //unchoose
        paired -= chosen1;
        paired -= chosen2;
        matching -= greek;
        val2 -= allLinks[chosen1][chosen2];
        }
    }
    return;
}


Set<Pair> maximumWeightMatching(const Map<string, Map<string, int>>& possibleLinks){
    //Map<string, Map<string, int>> allLinks;
    int val1=0;   int val2=0;
    Set<Pair> matching;
    Set<string> paired;
    Stack<Set<Pair>> stack;
    mwmHelper(possibleLinks,paired,matching,val1,val2,stack);
    if(!stack.isEmpty())
        return stack.pop();
    return {};
}
