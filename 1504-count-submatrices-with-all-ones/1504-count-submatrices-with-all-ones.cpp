int st[150], top=-1;// mono stack
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
        
        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++)
                if(mat[i][j]>0)
                    mat[i][j]+=mat[i-1][j];// height for mat[i][j]
        }  
        int ans=0;
        for (int i=0; i<r; i++){
            top=-1;// reset mono stack
            int count=0;
            auto& row=mat[i];
            for(int j=0; j<c; j++){
                while(top>-1 && row[st[top]]> row[j]){
                    int s=st[top--];// pop stack
                    int t=(top>-1)?st[top]:-1;
                    count-=(row[s]-row[j])*(s-t);// modify
                }
                count+=row[j];
                ans+=count;
                st[++top]=j;// push j to stack
            }
        }
        return ans;
    }
};