#include "RosettaStone.h"
#include "GUI/SimpleTest.h"
#include "error.h"
#include <cmath>
#include "priorityqueue.h"
#include <string>
using namespace std;

Map<string, double> kGramsIn(const string& str, int kGramLength) {
    if(kGramLength<=0){
        error("ERROR: kGramLength should be positive.");
    }
    if(kGramLength > str.length()){
        return {};
    }
    Map<string, double> frequencyMap;
    for(int i=0;i <= str.length()-kGramLength; i++){
        frequencyMap[str.substr(i,kGramLength)]++;
    }
    return frequencyMap;
}

Map<string, double> normalize(const Map<string, double>& input) {
    if(input.isEmpty()){
        error("ERROR: input should contain at least one nonzero value.");
    }
    Map<string, double> mapNormalized;
    double sum =0;
    double f=0;
    for(string s : input){
        f=input[s];
        sum+=pow(f,2);
    }
    if(sum==0){
        error("ERROR: input should contain at least one nonzero value.");
    }
    sum=sqrt(sum);
    for(string s : input){
        mapNormalized.put(s,input[s]/sum);
    }
    return mapNormalized;
}

Map<string, double> topKGramsIn(const Map<string, double>& source, int numToKeep) {
    if(numToKeep < 0){
        error("ERROR: numToKeep should not be negative.");
    }
    else if(numToKeep==0){
        return {};
    }
    PriorityQueue<string> pq;
    Map<string, double> map;
    for(string s : source){
        pq.enqueue(s,-source[s]);
    }
    if(numToKeep>source.size()){
        numToKeep=source.size();
    }
    for(int i=0;i<numToKeep && !pq.isEmpty();i++){
        double pri = pq.peekPriority();
        string str = pq.dequeue();
            map.put(str,-pri);
    }
    return map;
}

double cosineSimilarityOf(const Map<string, double>& lhs, const Map<string, double>& rhs) {
    double result=0;
    for(string s: lhs){
        if(rhs.containsKey(s)){
            result+=lhs[s]*rhs[s];
        }
    }
    return result;
}

string guessLanguageOf(const Map<string, double>& textProfile,
                       const Set<Corpus>& corpora) {
    if(corpora.isEmpty()){
        error("ERROR: corpora is empty.");
    }
    PriorityQueue<string> pq;
    double sim;
    for(Corpus c : corpora){
        sim=cosineSimilarityOf(textProfile,c.profile);
        pq.enqueue(c.name,-sim);
    }
    return pq.peek();
}
