class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += removePairs(s, 'a', 'b', x);
            total += removePairs(s, 'b', 'a', y);
        } else {
            total += removePairs(s, 'b', 'a', y);
            total += removePairs(s, 'a', 'b', x);
        }

        return total;
    }

    int removePairs(string& s, char first, char second, int value) {
        string stack;
        int count = 0;

        for (char c : s) {
            if (!stack.empty() && stack.back() == first && c == second) {
                stack.pop_back(); // הסר את הצמד
                count++;
            } else {
                stack.push_back(c);
            }
        }

        s = stack; // המחרוזת החדשה לאחר הסרה
        return count * value;
    }
};
