vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> qu;
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<string> ds;
        vector<vector<string>> res;
        vector<string> toDelete;
        int level = 0;
        
        ds.push_back(beginWord);
        toDelete.push_back(beginWord);
        qu.push(ds);
        
        
        while(!qu.empty()){
            vector<string> temp = qu.front();
            qu.pop();
            
            if(temp.size() > level){
                level++;
                
                for(string s : toDelete){
                    st.erase(s);
                }
                toDelete.clear();
            }
            
            string word = temp.back();
            
            if(word == endWord){
                res.push_back(temp);
            }
            
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        temp.push_back(word);
                        toDelete.push_back(word);
                        qu.push(temp);
                        temp.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        
        return res;
    }