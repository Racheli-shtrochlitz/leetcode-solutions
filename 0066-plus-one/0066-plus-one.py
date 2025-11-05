class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n= len(digits)

        if digits[n-1]<9:
            digits[n-1]+=1
            return digits
        
        i=n-1
        while i>=0 and digits[i]==9:
            digits[i]=0
            i-=1
        if i==-1:
            digits.insert(0,1)
            return digits
        
        digits[i]+=1
        return digits
        