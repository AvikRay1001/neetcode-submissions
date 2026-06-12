/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> start(n), end(n);

        for (int i = 0; i < n; i++) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0;
        int startIn = 0;
        int endIn = 0;
        int maxRooms = 0;

        while (startIn < n && endIn < n) {
            if (start[startIn] < end[endIn]) {
                rooms++;
                startIn++;
            } else {
                rooms--;
                endIn++;
            }
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};