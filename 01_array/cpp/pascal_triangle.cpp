/*
1. Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

----
2. Given an index k, return the kth row of the Pascal's triangle.
(where does the index start? 0 or 1)

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/



class Solution {
public:

	// fast solution, using the rolling array, 
	// avoid declaring the vector repetively.
	// only O(k) storage
	// question 1
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows < 1) {
        	return result;
        }

        // instantiating a vector with 1 element
        vector<int> row(1, 1);
        result.push_back(row);

        for (int i = 2; i <= numRows; i++) {
        	int prev = 1;

        	for (int j = 1; j < i-1; j++) {
        		int temp = row[j];
        		row[j] += prev;
        		prev = temp;
        	}

        	row.push_back(1);
        	res.push_back(row);
        } 

        return res;
    }

    // question 2
        vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1,1);
        for(int i=1; i<=rowIndex; i++) {
            int prev = 1;
            for(int j=1; j<i; j++) {
                int temp = row[j];
                row[j] += prev;
                prev = temp;
            }
        }
        return row;
    }


    // question 1, normal, but slow solution
    public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (numRows==0){return res;}
        vector<int> r;
        r.push_back(1);
        res.push_back(r);
        if (numRows==1){return res;}
        r.push_back(1);
        res.push_back(r);
        if (numRows==2){return res;}
         
        for (int i=2;i<numRows;i++){
            vector<int> c(i+1,1);
            for (int j=1;j<i;j++){
                c[j]= res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(c);
        }
        return res;
    }

     // question 2:
     //http://yucoding.blogspot.com/2013/04/leetcode-question-65-pascals-triangle-ii.html
};