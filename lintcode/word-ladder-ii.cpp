/**
*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

*Example*
*
Given:*
*start* = *"hit"*
*end* = *"cog"*
*dict* = *["hot","dot","dog","lot","log"]*
*
*
Return*
*
*  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*

*Note*
*All words have the same length.*All words contain only lowercase alphabetic characters.*
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_map<string, unordered_set<string>> trace;

        // BFS, each round is a level
        unordered_set<string> levels[2];
        int cur_level = 0;

        levels[cur_level].insert(start);
        while (dict.size() > 0 && levels[cur_level % 2].size() > 0) {
            // end is in current level, stop
            if (trace.count(end) == 1) {
                ++cur_level;
                break;
            }

            // clear words from the dictionary to avoid it' apear in future level again
            for (auto& word : levels[cur_level % 2]) {
                dict.erase(word);
            }

            levels[(cur_level + 1) % 2].clear();
            for (auto& from : levels[cur_level % 2]) {
                string new_word = from;
                for (int i = 0; i < new_word.length(); ++i) {
                    char orig_c = from[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        new_word[i] = c;
                        if (dict.count(new_word) == 1) {
                            trace[new_word].insert(from);
                            levels[(cur_level + 1) % 2].insert(new_word);
                        }
                    }
                    new_word[i] = orig_c;
                }
            }

            ++cur_level;
        }

        vector<vector<string>> result;
        vector<string> temp;
        traceBack(trace, temp, end, result);
        return result;
    }

    void traceBack(
                   unordered_map<string, unordered_set<string>> &trace,
                   vector<string> &temp,
                   string end,
                   vector<vector<string>> &result) {
        temp.emplace_back(end);
        if (trace.count(end) != 1) {
            vector<string> path = temp;
            reverse(path.begin(), path.end());
            result.emplace_back(move(path));
        }
        else {
            for (auto& word: trace[end]) {
                traceBack(trace, temp, word, result);
            }
        }
        temp.pop_back();
    }
};
