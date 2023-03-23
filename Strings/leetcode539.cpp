class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;
        // converting it into minutes
        for (int i = 0; i < timePoints.size(); i++)
        {
            string curr = timePoints[i];

            int hours = stoi(curr.substr(0, 2));
            int min = stoi(curr.substr(3, 2));
            int totalMinutes = (hours * 60) + min;
            minutes.push_back(totalMinutes);
        }

        // sorting
        sort(minutes.begin(), minutes.end());

        // difference and minimum calculation
        int mini = INT_MAX;
        for (int j = 0; j < minutes.size() - 1; j++)
        {
            int diff = minutes[j + 1] - minutes[j];
            mini = min(mini, diff);
        }

        // THIS IS THE GAME
        int lastDiff1 = (minutes[0] + 1440) - minutes[minutes.size() - 1];
        int lastDiff2 = minutes[minutes.size() - 1] - minutes[0];
        int lastDiff = min(lastDiff1, lastDiff2);
        mini = min(mini, lastDiff);

        return mini;
    }
};