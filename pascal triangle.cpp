//https://www.codingninjas.com/codestudio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/*
	Time Complexity: O(N^2)
	Space complexity: O(N^2)
	
	Where N denotes the number of Rows.
*/

#include<vector>

vector < vector < long long int >> printPascal(int n) {
    vector < vector < long long int >> triangle;
    vector < long long int > temp;

    temp.push_back(1);
    triangle.push_back(temp);
    for (int i = 1; i < n; i++) {
        temp.clear();
        for (int j = 0; j <= i; j++) {
            if (j == i || j == 0) {
                temp.push_back(1);
            } else {
                temp.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
        }
        triangle.push_back(temp);
    }
    return triangle;
}


/*
	Time Complexity: O(N^2)
	Space complexity: O(1)
	
	Where N denotes the number of Rows.
*/

#include<vector>

vector < vector < long long int >> printPascal(int n) {
    vector < vector < long long int >> triangle;
    vector < long long int > temp;

    for (int i = 1; i <= n; i++) {
        long long int rCe = 1;
        temp.clear();
        for (int j = 1; j <= i; j++) {
            temp.push_back(rCe);
            rCe = rCe * (i - j) / j;
        }

        triangle.push_back(temp);
    }
    return triangle;
}

//direct update less space
 vector<vector<int>> generate(int numRows) {
       vector<vector<int>> m(numRows);// creating 2-D vector with rows=numRows
        
            for(int i=0;i<numRows;i++)
            {
                m[i].resize(i + 1);    //to increase column size as level increases
                m[i][0] = m[i][i] = 1; //first and last element of every row is 1 always so

                //loop to calculate sum of remaining elements from previous row  
                for (int j = 1; j < i; j++)
                   m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
        
            }
        return m;
    }