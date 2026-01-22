class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] < b[1]; //sort - if the starts are equal, check the ends
                 return a[0] < b[0];
             });

        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start < prevEnd) {
                // overlap: remove one interval
                removed++;
                // keep the interval with the smaller end
                prevEnd = min(prevEnd, end);
            } else {
                // no overlap: keep it
                prevEnd = end;
            }
        }
        return removed;
    }
};
