/**
*Given numRows, generate the first numRows of Pascal's triangle.

*For example, given numRows = 5,
*Return
    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > re;

		for(int i = 0;i < numRows;i++){
			vector<int> pa;
			if(numRows == 1)
				pa.push_back(1);
			else{
				for(int j = 0; j <= i; j++){
					if(j == 0 || j == i)
						pa.push_back(1);
					else
						pa.push_back(re[i - 1][j - 1] + re[i - 1][j]);
				}
			}
			re.push_back(pa);
		}
		return re;
		}
};
