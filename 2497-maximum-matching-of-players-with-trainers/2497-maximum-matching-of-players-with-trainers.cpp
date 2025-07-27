class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n1=players.size();
        int n2=trainers.size();
        int c=0;

        int p=0,t=0;
        while(p<n1 && t<n2){
            if(players[p]<=trainers[t])
            {
                c++;
                p++;
                t++;
                continue;
            }

            else{
                t++;
            }
        }

        return c;

    }
};