string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
  string res="";
  if(phrase.length()==1)
  { char x=phrase[0];
     if(isalpha(x))
         if(x!='a'&&x!='A'&&x!='e'&&x!='E'&&x!='i'&&x!='I'&&x!='o'&&x!='O'&&x!='u'&&x!='U')
             return toUpperCase(phrase);
         else return "";
      else return "";
  }
  res=onlyConnectize(phrase.substr(0,phrase.length()-1))
      +onlyConnectize(phrase.substr(phrase.length()-1,1));
  return res;
