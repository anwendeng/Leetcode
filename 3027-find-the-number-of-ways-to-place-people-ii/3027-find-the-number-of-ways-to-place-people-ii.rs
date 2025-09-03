impl Solution {
    pub fn number_of_pairs(mut P: Vec<Vec<i32>>) -> i32 {
        P.sort_by_key(|p|(-p[0], p[1]));
        let n=P.len();
        let mut ans=0;
        for i in 0..n-1{
            let mut y:i32=i32::MAX;
            let yi=P[i][1];
            for j in i+1..n{
                let yj=P[j][1];
                if y>yj && yj>=yi {
                    ans+=1;
                    y=yj;
                    if yi==yj {break;}
                }
            }
        }
        ans
    }
}