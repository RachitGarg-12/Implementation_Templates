//https://leetcode.com/problems/set-matrix-zeroes/

//brute force extra space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool> row(m,true);
        vector<bool> col(n,true);
        for(int i=0;i<m;i++){
           
            for(int j=0;j<n;j++){
               
                if(matrix[i][j]==0){
                    row[i]=false;col[j]=false;
                }}
            } 
        
        for(int i=0;i<m;i++){
            if(row[i]==false){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
                cout<<matrix[i][j];
            }}
            else{
                for(int j=0;j<n;j++){
                    if(col[j]==false){matrix[i][j]=0;
                cout<<matrix[i][j];}
                    else{cout<<matrix[i][j];}
            }}
        }
    }
};


//optimized o(1) space

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0 =1;
        
        for(int i=0;i<m;i++){
           if(matrix[i][0]==0){col0=0;}
            for(int j=1;j<n;j++){
               
                if(matrix[i][j]==0){
                    matrix[i][0]=0;matrix[0][j]=0;
                }}
            } 
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){matrix[i][j]=0;}
            }
            if(col0==0){matrix[i][0]=0;}
        }
        for(int i=0;i<m;i++){
           
            for(int j=0;j<n;j++){
                cout<<matrix[i][j];}}
        
        
    }
};