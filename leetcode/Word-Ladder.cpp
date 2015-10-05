/**
*
*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
*Only one letter can be changed at a time
*Each intermediate word must exist in the word list
*For example,
*Given:
*beginWord = &quot;hit&quot;
*endWord = &quot;cog&quot;
*wordList = [&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;lot&quot;,&quot;log&quot;]
*As one shortest transformation is &quot;hit&quot; -&gt; &quot;hot&quot; -&gt; &quot;dot&quot; -&gt; &quot;dog&quot; -&gt; &quot;cog&quot;,
*return its length 5.
*Note:
*Return 0 if there is no such transformation sequence.
*All words have the same length.
*All words contain only lowercase alphabetic characters.
*
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord == endWord) return 0;
        unordered_map<string,int> len;
        len[beginWord] = 1;
        queue<string> ladder;
        ladder.push(beginWord);
        while(!ladder.empty()){
            string word = ladder.front();
            ladder.pop();
            int step = len[word] + 1;
            for(int i = 0; i < word.length(); ++i) {
                for(int c = 'a'; c <= 'z'; ++c) {
                    if(word[i] != c) {
                        char tem = word[i];
                        word[i] = c;
                        if(word == endWord)
                                return step;
                        if((wordDict.find(word) != wordDict.end()) && (len.find(word) == len.end())){
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