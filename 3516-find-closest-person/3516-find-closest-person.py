class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        return -(abs(x-z)!=abs(y-z)) & (1+(abs(x-z)>abs(y-z)))
        