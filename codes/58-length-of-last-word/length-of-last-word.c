int lengthOfLastWord(char* s) {
    int leng=strlen(s);
    int i=leng-1;
    int l=0;
    int wc=0;
    while(i>=0 && (l==0 || s[i]!=' ')){
        if(s[i]!=' '){
            wc++;
            l=-1;
        }
        i--;
    }
    return wc;
}