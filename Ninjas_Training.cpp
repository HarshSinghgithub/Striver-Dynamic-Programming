int solve(int day, int prev_day, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int max_points = 0;

        for(int i=0; i<3; i++){
            if(i != prev_day){
                max_points = max(max_points, points[day][i]);
            }
        }

        return max_points;
    }

    if(dp[day][prev_day] != -1) return dp[day][prev_day];

    int max_points = 0;

    for(int i=0; i<3; i++){
        if(i != prev_day){
            max_points = max(max_points, points[day][i] + solve(day-1, i, points, dp));
        }
    }

    return dp[day][prev_day] = max_points;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));
    int maxPoints = 0;

    for (int i = 0; i < 3; i++) {
        maxPoints = max(maxPoints, points[n - 1][i] + solve(n - 2, i, points, dp));
    }

    return maxPoints;
}