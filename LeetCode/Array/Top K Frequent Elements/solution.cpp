class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using unordered_map
        // Map structure: { Element (key) : Frequency (value) }
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Define Min-Heap using greater<pair<int, int>>
        // Heap pair structure: { Frequency, Element }
        // C++ compares pair.first (Frequency) to maintain the Min-Heap ordering.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 3: Push map entries into the Min-Heap
        for (auto &x : mp) {
            int ele = x.first;   // Map key = Element
            int freq = x.second; // Map value = Frequency

            // Push {freq, ele} so heap sorts by frequency automatically
            pq.push({freq, ele});

            // Keep only the top 'k' most frequent elements in the heap
            if (pq.size() > k) {
                pq.pop(); // Removes the element with the smallest frequency
            }
        }

        // Step 4: Extract the top k elements from the heap
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second); // .second contains the Element
            pq.pop();
        }

        return ans;
    }
};