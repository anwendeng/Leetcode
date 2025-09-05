class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
    //    if (num2==0) return popcount(unsigned(num1));
        long long x=num1;
        for(int k=1; k<61; k++){
            x-=num2;
        //    cout<<"k="<<k<<" x="<<x<<" bitcount(x)="<<popcount((unsigned long long)(x))<<endl;
            if (x<k) return -1;
            if (k>=popcount((unsigned long long)(x))) return k;
        }
        return -1;
    }
};