int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> qu;
        
        qu.push({startWord, 1});
        st.erase(startWord);
        
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            
            string word = it.first;
            int steps = it.second;
            
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        if(word == targetWord) return steps + 1;
                        qu.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }