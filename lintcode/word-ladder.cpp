/**
*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

*Example*
*
Given:*
*start* = *"hit"*
*end* = *"cog"*
*dict* = *["hot","dot","dog","lot","log"]*
*
*
As one shortest transformation is *"hit" -> "hot" -> "dot" -> "dog" -> "cog"*,*
return its length *5*.
*

*Note*
*Return 0 if there is no such transformation sequence.*All words have the same length.*All words contain only lowercase alphabetic characters.*
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if(start == end) return 0;
        unordered_map<string,int> len;
        len[start] = 1;
        queue<string> ladder;
        ladder.push(start);
        while(!ladder.empty()){
            string word = ladder.front();
            ladder.pop();
            int step = len[word] + 1;
            for(int i = 0; i < word.length(); ++i) {
                for(int c = 'a'; c <= 'z'; ++c) {
                    if(word[i] != c) {
                        char tem = word[i];
                        word[i] = c;
                        if(word == end)
                                return step;
                        if((dict.find(word) != dict.end()) && (len.find(word) == len.end())){
                            ladder.push(word);
                            len.insert(make_pair(word,step));
                        }
                        word[i] = tem;
                    }
                }
            }
        }
    return 0;
    }
};
