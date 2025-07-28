class Solution {
public:
    bool checkPowersOfThree(int n) {
        int res;
        int div;
        while(n>0){
            res=n%3;
            if(res>1)
                return false;
            n=n/3;
        }
        return true;
    }
};