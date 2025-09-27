class Solution {
public:
    using int2 = pair<short, short>;

    static int cross(const int2& O, const int2& P, const int2& Q){
        const auto& [a0, a1]=O; 
        const auto& [b0, b1]=P; 
        const auto& [c0, c1]=Q; 
        return (b0-a0)*(c1-a1)-(b1-a1)*(c0-a0);
    }

    static double maxArea(const vector<int2>& P, int n){
        double maxA=0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    double area=abs(cross(P[i],P[j],P[k]));
                    maxA=max(maxA, area);
                }
            }
        }
        return 0.5*maxA;
    }

    static double largestTriangleArea(vector<vector<int>>& points) {
        const int n=points.size();
        vector<int2> P(n);
        for(int i=0; i<n; i++) P[i]={points[i][0], points[i][1]};
        sort(P.begin(), P.end());

        vector<int2> Hull(2*n);
        int k=0;
        // lower hull
        for(int i=0; i<n; i++){
            while(k>=2 && cross(Hull[k-2], Hull[k-1], P[i])<=0)
                k--;
            Hull[k++]=P[i];
        }
        // upper hull
        for(int i=n-1, t=k+1; i>=0; i--){
            while(k>=t && cross(Hull[k-2], Hull[k-1], P[i])<=0) 
                k--;
            Hull[k++]=P[i];
        }
        // remove duplicate start point
        return maxArea(Hull, k-1);
    }
};

