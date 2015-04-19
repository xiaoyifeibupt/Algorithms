/**
*Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

*Only one letter can be changed at a time
*Each intermediate word must exist in the dictionary
*For example,

*Given:
*start = "hit"
*end = "cog"
*dict = ["hot","dot","dog","lot","log"]
*Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*Note:
*All words have the same length.
*All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        if(start == end) return result;
		dict.insert(end);
        unordered_map<string,int> len;
        unordered_map<string,string> pre;
        len[start] = 1;
        pre[start] = "";
        queue<string> ladder;
        ladder.push(start);
        while(!ladder.empty()) {
            string word = ladder.front();
            ladder.pop();
            int step = len[word] + 1;
            string preword = word;
            for(int i = 0; i < word.size(); ++i) {
                char tem = word[i];
                for(int c = 'a'; c <= 'z'; ++c) {
                    if(word[i] != c){
                        word[i] = c;
                        if((dict.find(word) != dict.end()) && (len.find(word) == len.end())) {                           
                            if(word == end) {
								unordered_map<string,int>::const_iterator clen = len.cbegin();
								for(; clen != len.end(); ++clen){
									if(clen->second == step - 1){
										vector<string> vec;
										vec.push_back(end);
										string pre_word = clen->first;
										vec.push_back(pre_word);
										while(pre[pre_word] != "") {
											pre_word = pre[pre_word];
											vec.push_back(pre_word);
										}
										reverse(vec.begin(),vec.end());
										result.push_back(vec);
									}
								}
							return result;
							}
							ladder.push(word);
                            len.insert(make_pair(word,step));
                            pre[word] = preword;
                        }
                        word[i] = tem;
                    }
                }
            }
        }
		return result;
    }
};
