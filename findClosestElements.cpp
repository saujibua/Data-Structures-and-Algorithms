class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> answer;
        auto pos = upper_bound(arr.begin(), arr.end(), x)-1;
        int idx = distance(arr.begin(), pos);
        int start = idx;
        int end = idx+1;
        
        while ((end-start) <= k) {
            int d1, d2;
            if (start >= 0 && end < arr.size()) {
                d1 = abs(x-arr[start]);
                d2 = abs(x-arr[end]);
                if (d1<=d2) {
                    answer.push_back(arr[start--]);
                } else {
                    answer.push_back(arr[end++]);
                }
            } else if (end < arr.size()) {
                answer.push_back(arr[end++]);
            } else {
                answer.push_back(arr[start--]);
            }
        }
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
