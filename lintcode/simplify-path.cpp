/**
*Given an absolute path for a file (Unix-style), simplify it.
*Example*
*"/home/"*, => *"/home"*
*"/a/./b/../../c/"*, => *"/c"*

*Challenge*
*
*
*Did you consider the case where path = *"/../"*?*
*In this case, you should return *"/"*.*
*
*
*Another corner case is the path might contain multiple slashes *'/'* together, such as *"/home//foo/"*.*
*In this case, you should ignore redundant slashes and return *"/home/foo"*.*
*
*
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        vector<string> dirs;
        for (auto i = path.begin(); i != path.end();) {
            ++i;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                } else
                    dirs.push_back(dir);
            }
            i = j;
        }
        stringstream ss;
        if (dirs.empty())
            ss << "/";
        else {
            for (auto dir : dirs)
                ss << "/" << dir;
        }
        return ss.str();
    }
};
