bool helper(const Map<string, Set<string>>& roadNetwork,
            int numCities, int total,
            Set<string>& supplyLocations,
            Set<string>& covered,
            Set<string>& uncovered) {
    if(numCities <= 0 && covered.size() < total){
        return false;
    }
    if (covered.size() == total){
        return true;
    }
    string s1 = "";
    for(string s : uncovered){
        if(!supplyLocations.contains(s1)){
            s1 = s;
        }
    }
    // put in the city
    supplyLocations += s1;
    Set<string> newinput1 = (Set<string>({ s1 }) + roadNetwork.get(s1)) - covered;
    covered += newinput1;
    uncovered -= newinput1;
    //explore
    if(!newinput1.isEmpty()){
        if(helper(roadNetwork,numCities - 1, total, supplyLocations, covered, uncovered)){
            return true;
        }
    }
    //unchoose
    supplyLocations -= s1;
    covered -= newinput1;
    uncovered += newinput1;
    newinput1 = {};
    
    for(string s2 : roadNetwork.get(s1)){
        if(!supplyLocations.contains(s2)){
            //put in the adjacent city
            supplyLocations += s2;
            Set<string> newinput2 = (Set<string>({ s2 }) + roadNetwork.get(s2)) - covered;
            covered += newinput2;
            uncovered -= newinput2;
            //explore
            if(!newinput2.isEmpty()){
                if(helper(roadNetwork,numCities - 1, total, supplyLocations, covered, uncovered )){
                    return true;
                }
            }
            //unchoose
            supplyLocations -= s2;
            covered -= newinput2;
            uncovered += newinput2;
            newinput2 = {};

        }
    }
    return false;
}

bool canBeMadeDisasterReady(const Map<string, Set<string>>& roadNetwork,
                            int numCities,
                            Set<string>& supplyLocations) {
    if(numCities < 0){
        error("ERROR: numCities cannot be negative.");
    }
    Set<string> covered;
    Set<string> uncovered;
    for (string city : roadNetwork) {
        uncovered += city;
    }
    int total = roadNetwork.size();
    return helper(roadNetwork, numCities, total, supplyLocations,covered,uncovered);
}
