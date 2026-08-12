class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            mp[ch]++;
            // If any character appears more than half the time, impossible!
            if (mp[ch] > (n + 1) / 2) return "";
        }

        // Step 2: Max-Heap storing pair<freq, char>
        // Automatic sorting on .first (freq) from highest to lowest
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Step 3: Build answer string by picking top 2 characters
        string res = "";

        while (pq.size() >= 2) {
            // Pop top 2 most frequent characters
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();

            // Append characters to result
            res += p1.second;
            res += p2.second;

            // Decrement remaining frequencies
            p1.first--;
            p2.first--;

            // Push back if characters are still left
            if (p1.first > 0) pq.push(p1);
            if (p2.first > 0) pq.push(p2);
        }

        // Step 4: Handle leftover single character (if string length was odd)
        if (!pq.empty()) {
            res += pq.top().second;
        }

        return res;
    }
};