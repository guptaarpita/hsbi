
class Solution {
public:
    int findDaysOfYear(string date, vector<int>& cumMonthDays) {
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3, 2));

        return cumMonthDays[month - 1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31
        };
        vector<int> cumMonthDays(12, 0);
        for (int i = 1; i < 12; i++) {
            cumMonthDays[i] = cumMonthDays[i - 1] + monthDays[i - 1];
        }
        int arriveAliceDay = findDaysOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay = findDaysOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay = findDaysOfYear(arriveBob, cumMonthDays);
        int leaveBobDay = findDaysOfYear(leaveBob, cumMonthDays);

        int overlapDays = min(leaveAliceDay, leaveBobDay)- max(arriveAliceDay, arriveBobDay) + 1;
        return max(0, overlapDays);
    }
};
