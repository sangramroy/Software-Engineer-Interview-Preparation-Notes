// Online C++ compiler to run C++ program online
/*
sum in a matrixone
sum in a matrixtwo
search target in matrix (sorted row wise and next row element> max of prev row)
spiral traversal one
spiral traversal two (Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.)
Delete Greatest Value in Each Row
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void matrixSum(vector<vector<int>>& nums) {
    cout<<"\nfinding max from each row and iterate till end to get max value: "<<endl;
    //7,6,6,3->7 now removing 7,6,6,3 from their rows, add 7 to ans
    //2,4,5,2->5 now removing 2,4,5,2 from their rows, add 5 to ans 
    //1,2,3,1->3 now removing 1,2,3,1 from their rows, add 3 to ans
    int row=nums.size();
    int col=nums[0].size();
    int maxval=0;
    int ans=0;
    for(int i=0;i<row;i++)
    {
        sort(nums[i].begin(),nums[i].end());
    }
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
         {
           maxval=max(maxval,nums[j][i]);
         }
        ans+=maxval;
    }
   cout<<"sum aggregated after finding max element from each row is: "<<ans<<endl<<endl; 
}

void binarysearch(vector<vector<int>>& matrix,int target,int row)
  {
     int n=matrix[0].size();
     int s=0,e=n-1;
     while(s<=e)
     {
      int mid=(s+e)>>1;
      if(matrix[row][mid]==target) 
      {
           cout<<"target "<<target<<" found in matrix at pos matrix["<<row<<"]["<<mid<<"]"<<endl<<endl;
           return;
      }
      else if(matrix[row][mid]>target) e=mid-1; 
      else s=mid+1;
     }
    cout<<"element not found in matrix "<<endl<<endl;
  }
  
void searchMatrixone(vector<vector<int>>& matrix, int target) {
  cout<<"finding element in searchMatrixone "<<endl;
  // logic identify first row as per binary search then find element in matrix[row][col]
  //where 0<=col<=matrix[0].size();
  int m=matrix.size();
  int n=matrix[0].size();
  int startrow=0;
  int endrow=m-1;;
  while(startrow<=endrow)
  {
      int mid=startrow+(endrow-startrow)/2;
      if(matrix[mid][0]<=target && matrix[mid][n-1]>=target)
      {
         return binarysearch(matrix,target,mid) ;
      }
      else if(matrix[mid][0]<target) startrow=mid+1;
      else  endrow=mid-1;
  }
}

void searchMatrixtwo(vector<vector<int>>& matrix, int target) {
    cout<<"finding element in searchMatrixtwo "<<endl;
  // logic start from tog right cell as there is pattern element before it is smaller and below it greater
     int m=matrix.size();
     int n=matrix[0].size();
     int r=0,c=n-1;
     while(r<m && c>=0)
     {
      if(target==matrix[r][c])
      {
       cout<<"target "<<target<<" found in matrix at pos matrix["<<r<<"]["<<c<<"]"<<endl<<endl;
       return;
      }
      else if(target<matrix[r][c]) c--;
      else r++;
     }
    cout<<"element not found in matrix "<<endl<<endl;
}

void spiralOrderOne(vector<vector<int>> matrix) {
      cout<<"spiral traversal matrix "<<endl<<endl;
      //logic first take 4 pointers and find its start to end point and it should continue till when
      ////top left to right
      ////top to bottom
      ////bottom right to left
      ////bottom to top 
      int row=matrix.size();
      int col=matrix[0].size();
      int srow=0,erow=row-1,scol=0,ecol=col-1;
      vector<int> ans;
      while(srow<=erow && scol<=ecol)
      {
         //top left to right
         for(int i=scol;i<=ecol;i++) ans.push_back(matrix[srow][i]);
         //top to bottom
         for(int i=srow+1;i<=erow;i++) ans.push_back(matrix[i][ecol]);
         //bottom right to left
         for(int i=ecol-1;i>=scol;i--) 
         {
             if(srow==erow) break;
             ans.push_back(matrix[erow][i]);
         }
         //bottom to top 
         for(int i=erow-1;i>=srow+1;i--) 
         {
             if(scol==ecol) break;
           ans.push_back(matrix[i][scol]);
         }
          srow++,scol++,erow--,ecol--;
      } 
        for (auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl<<endl;
}

void spiralOrderOne(int n) {
      cout<<"spiral traversal matrix two "<<endl<<endl;
      // modify spiral order while traversing
      vector<vector<int>> ans(n, vector<int>(n, 0));
      int row=ans.size();
      int col=ans[0].size();
      int srow=0,erow=row-1,scol=0,ecol=col-1;
      int j=1;
      while(srow<=erow && scol<=ecol)
      {
         //top left to right
         for(int i=scol;i<=ecol;i++) ans[srow][i]=j++;
         //top to bottom
         for(int i=srow+1;i<=erow;i++) ans[i][ecol]=j++;
         //bottom right to left
         for(int i=ecol-1;i>=scol;i--) 
         {
             if(srow==erow) break;
             ans[erow][i]=j++;
         }
         //bottom to top 
         for(int i=erow-1;i>=srow+1;i--) 
         {
             if(scol==ecol) break;
           ans[i][scol]=j++;
         }
          srow++,scol++,erow--,ecol--;
      } 
      cout<<"\n now ans matrix is:"<<endl;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
              {
                  cout<<ans[i][j]<<" ";
              }
              cout<<endl;
        }
        cout<<endl<<endl;
}

 void setZeroes(vector<vector<int>>& matrix) {
  
        cout<<"\n setting entire row n column zero if element at mat[i][j] 0 initially\n";
     
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> x;  // stores row indices to be zeroed
        vector<int> y;  // stores column indices to be zeroed
        
        
        cout<<"now matrix before setting zero:\n";
         for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
              {
                  cout<<matrix[i][j]<<" ";
              }
              cout<<endl;
        }
        cout<<endl<<endl;
        
        
       

        // Step 1: Collect row and column indices that have a 0
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        // Step 2: Zero out the collected rows
        for(int i = 0; i < x.size(); i++) {
            int idx = x[i];
            for(int j = 0; j < c; j++) {
                matrix[idx][j] = 0;
            }
        }

        // Step 3: Zero out the collected columns
        for(int i = 0; i < y.size(); i++) {
            int idx = y[i];
            for(int j = 0; j < r; j++) {
                matrix[j][idx] = 0;
            }
        }
        
        cout<<"now matrix after setting zero:\n";
         for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
              {
                  cout<<matrix[i][j]<<" ";
              }
              cout<<endl;
        }
        cout<<endl<<endl;
    }
    
  void deleteGreatestValue(vector<vector<int>>& grid) {
      
      cout<<"\nfinding max from each row and iterate till end to get max value: "<<endl;
      //{{1,2,4}-->  1,2,4--->1,2-->1             ans= 4+3+1=8
      //{3,3,1}}-->  1,3,3--->1,3-->1
      //sort and then traverse column wise
        int r=grid.size();
        int c=grid[0].size();
        int maxi=0,ans=0;
        for(int i=0;i<r;i++)
        {
            sort(grid[i].begin(),grid[i].end());
        }

        for(int j=c-1;j>=0;j--)
        {
             for(int i=0;i<r;i++)
            {
              maxi=max(maxi,grid[i][j]);
            }
            ans+=maxi;
            maxi=0;
        }
        cout<<"sum aggregated after finding max element from each row is: "<<ans<<endl<<endl;
    }


int main() {
 vector<vector<int>> nums={{7,2,1},{6,4,2},{6,5,3},{3,2,1}};
 vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
 vector<vector<int>> array = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
 int target = 3;
 vector<vector<int>> matrixone = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
 vector<vector<int>>grid = {{1,2,4},{3,3,1}};
 matrixSum(nums);
 searchMatrixone(matrix,target);
 searchMatrixtwo(array,target);
 spiralOrderOne(matrix);
 spiralOrderOne(3);
 setZeroes(matrixone);
 deleteGreatestValue(grid);
return 0;
}


