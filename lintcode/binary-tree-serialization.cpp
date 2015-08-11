/**
*Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
*Example*
*An example of testdata: Binary tree *{3,9,20,#,#,15,7}*,  denote the following structure:*
*  3
 / \
9  20
  /  \
 15   7
*
*Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.*
*You can use other method to do serializaiton and deserialization.*
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string output;
        serializeHelper(root, output);
        return output;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        TreeNode *root = nullptr;
        int start = 0;
        deserializeHelper(data, start, root);
        return root;
    }
    
private:
    bool getNumber(const string &data, int &start, int &num) {
        if (data[start] == '#') {
            start += 2;
            return false;
        }

        num = 0;
        while (data[start] != ' ') {
            num = num * 10 + data[start++] - '0';
        }

        start++;
        return true;
    }

    void deserializeHelper(string data, int &start,  TreeNode *&root) {
        int num;
        if (!getNumber(data, start, num)) {
            root = nullptr;
            return;
        }
        else {
            root = new TreeNode(num);
            deserializeHelper(data, start, root->left);
            deserializeHelper(data, start, root->right);
        }
    }

    void serializeHelper(TreeNode *root, string &prev) {
        if (!root)  {
            prev += "# ";
        } else {
            stringstream buffer;
            buffer << root->val << " ";
            prev += buffer.str();
            serializeHelper(root->left, prev);
            serializeHelper(root->right, prev);
        }
    }
};

