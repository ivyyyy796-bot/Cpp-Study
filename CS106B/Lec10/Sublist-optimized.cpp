void sublistHelper(Vector<string>& v,Vector<string>& chosen){
    if(v.isEmpty()){
        //base case
        cout<<chosen<<endl;
    }
    else{
        string s =v[0];
        //choose (with s) and explore
        v.remove(0);
        sublistHelper(v,chosen);
        //choose (without s) and explore
        chosen.add(s);
        sublistHelper(v,chosen);
        //un-choose
        v.insert(0,s);
        chosen.remove(chosen.size()-1);
    }

}
void sublist(Vector<string> v){
    Vector<string> chosen ;
    sublistHelper(v,chosen);
}
