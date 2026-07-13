string Converter(Vector<string> v){
    string s;
    for(int i=0;i<v.size();i++){
        s.append(v[i]);
    }
    return s;
}

void aHelper(Vector<string>& v,Vector<string>& chosen,Set<string>& set){
    if(v.isEmpty()){
        set.add(Converter(chosen));
        return ;
    }
    else{
        for(int i=0;i<v.size();i++ ){
            string temp=v[i];

            if(!isalpha(v[i][0])){
                chosen+=v[i];
                v.remove(i);
                aHelper(v,chosen,set);
                v.insert(i,temp);
                chosen.remove(chosen.size()-1);

            }
            else{

                chosen+=toLowerCase(v[i]);
                v.remove(i);
                aHelper(v,chosen,set);
                v.insert(i,temp);
                chosen.remove(chosen.size()-1);


                chosen+=toUpperCase(v[i]);
                v.remove(i);
                aHelper(v,chosen,set);
                v.insert(i,temp);
                chosen.remove(chosen.size()-1);
            }
        }
    }
   // return set;
}

Set<string> allEmphasesOf(const string& sentence) {
    Vector<string> v = tokenize(sentence);
    Set<string> set;
    Vector<string> chosen;
    aHelper(v,chosen,set);
    return set;

}
