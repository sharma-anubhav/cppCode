int minSubArrayLen(int target, vector<int> &n)
{
    int i = 0;
    int j = 0;

    int cur_sum = 0;
    int mini = INT_MAX;
    int flag = 0;

    while (j <= n.size() - 1)
    {
        cur_sum = cur_sum + n[j];
        j++;

        while (cur_sum > target and i < j)
        {
            cur_sum = cur_sum - n[i];
            i++;
        }

        if (cur_sum == target)
        {
            flag = 1;
            mini = min(mini, j - i);
        }
    }

    if (flag == 0)
        return 0;
    return mini;
}