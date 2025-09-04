impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let d:i32=x*x-y*y-2*z*(x-y);
        (d!=0) as i32*(1+(d>0) as i32)
    }
}