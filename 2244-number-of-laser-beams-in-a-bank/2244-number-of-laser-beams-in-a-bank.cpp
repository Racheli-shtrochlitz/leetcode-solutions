class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastLine=0;
        int total=0;
        for(int i=0; i<bank.size(); i++){
            string line=bank[i];
            int count=0;
            for(char c :line){
                if( c== '1') count++;
            }
            if (count == 0) continue;
            total+=lastLine* count;
            lastLine=count;
        }
        return total;
    }
};