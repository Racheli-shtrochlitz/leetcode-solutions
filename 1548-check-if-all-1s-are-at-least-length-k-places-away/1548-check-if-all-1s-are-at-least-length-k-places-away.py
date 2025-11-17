class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        temp=0
        for i in nums:
            if i==1:
                if temp>0:
                    return False
                else:
                    temp=k
            else:
                temp-=1
        return True