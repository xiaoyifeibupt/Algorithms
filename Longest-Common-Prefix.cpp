/*
*Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(int x = 1; x < strs.size(); x++){
            int i = 0,j = 0;
			while(i < prefix.length() && i < strs[x].length()){
				if(prefix[i] != strs[x][i]){
					break;
				}
				i++;
			}
			prefix = prefix.substr(0,i);
        }
	return prefix;
    }
};
