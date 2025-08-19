class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        return (Len:=0) or sum( Len:=Len+1 & -(x==0) for x in nums )
          