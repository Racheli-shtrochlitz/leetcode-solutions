class Solution {
public:
    int smallestNumber(int n) {
        int bits=(int)floor(log2(n))+1; //מספר הסיביות במספר
        if((n+1) & n == 0) return n;
        return (1u <<((int)floor(log2(n))+1)) -1;
    }
};