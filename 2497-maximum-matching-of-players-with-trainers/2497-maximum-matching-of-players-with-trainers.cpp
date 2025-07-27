class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int p = 0, t = 0, count = 0;
        while (p < players.size() && t < trainers.size()) {
            if (players[p] <= trainers[t]) {
                count++;
                p++;
            }
            t++;
        }

        return count;
    }
};
