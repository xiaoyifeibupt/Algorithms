/**
*Given a dictionary, find all of the longest words in the dictionary.
*Example*
*Given *
*{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
*
*the longest words are(is) *["internationalization"]*.*
*Given*
*{
  "like",
  "love",
  "hate",
  "yes"
}
*
*the longest words are *["like", "love", "hate"]*.*

*Challenge*
*It's easy to solve it in two passes, can you do it in one pass?*
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> result;
        int len = 0;
        for (string word : dictionary) {
            if (word.length() > len) {
                result.clear();
                len = word.length();
                result.push_back(word);
            } else if (word.length() == len)
                result.push_back(word);
        }
        return result;
    }
};
