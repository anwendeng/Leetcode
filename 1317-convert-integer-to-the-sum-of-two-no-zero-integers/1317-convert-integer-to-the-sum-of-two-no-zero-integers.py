class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        a, b, tens=0, 0, 1
        while n>0:
            n, d=divmod(n, 10)
            if d==0:
                a+=5*tens
                b+=5*tens
                n-=1
            elif d==1 and n>=1:
                a+=6*tens
                b+=5*tens
                n-=1
            else:
                a+=(d-d//2)*tens
                b+=(d//2)*tens
            tens*=10

        return [a, b]
        