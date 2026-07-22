#include "GUI/SimpleTest.h"
#include "Combine.h"
#include "vector.h"
using namespace std;

Vector<DataPoint> combine(const Vector<Vector<DataPoint>>& sequences) {
    if(sequences.size()==0){
        return {};
    }
    if(sequences.size()==1){
        return sequences[0];
    }
    Vector<Vector<DataPoint>> left = sequences.subList(0,sequences.size()/2);
    Vector<Vector<DataPoint>> right = sequences.subList(sequences.size()/2, sequences.size()-left.size());

    Vector<DataPoint>sortedleft = combine(left);
    Vector<DataPoint>sortedright = combine(right);

    int i1 =0;
    int i2 =0;
    Vector<DataPoint> v;
    while (i1 < sortedleft.size() || i2 < sortedright.size()){
        if(i2 >= sortedright.size()
            || (i1 < sortedleft.size() && sortedleft[i1].weight <= sortedright[i2].weight)){
            v.add(sortedleft[i1]);
            i1++;
        }else {
            v.add(sortedright[i2]);
            i2 ++;
        }
    }

    return v;
}

