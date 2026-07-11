string aSequenceOfOrder(int n) {
    if(n<0) error("ERROR");
    if(n==0){
        return "A";
    }
    else{
        return aSequenceOfOrder(n-1)+bSequenceOfOrder(n-1);
    }
}

string bSequenceOfOrder(int n) {
    if(n<0) error("ERROR");
    if(n==0){
        return "B";
    }
    else{
        return bSequenceOfOrder(n-1)+aSequenceOfOrder(n-1);
    }
}
