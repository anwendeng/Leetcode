class Solution:
    def totalMoney(self, n: int) -> int:
        return 28*(q:=n//7)+7*q*(q-1)//2+(2*q+(r:=n%7)+1)*r//2
        