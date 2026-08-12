// Custom Comparator
struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        // 1. Min-Heap on frequency (smaller frequency stays at top to be popped first)
        if (a.second != b.second) {
            return a.second > b.second;
        }
        // 2. Max-Heap on word (alphabetically larger word stays at top to be popped first)
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (const auto& w : words) {
            mp[w]++;
        }

        // Min-Heap storing pair<word, frequency>
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

        for (const auto& x : mp) {
            pq.push({x.first, x.second});
            if (pq.size() > k) {
                pq.pop(); // Drops lower frequency or alphabetically larger words
            }
        }

        vector<string> v;
        while (!pq.empty()) {
            v.push_back(pq.top().first); // Extract word
            pq.pop();                    // Remove from heap
        }

        // Reverse because Min-Heap extracts smallest-to-largest
        reverse(v.begin(), v.end());

        return v;
    }
};