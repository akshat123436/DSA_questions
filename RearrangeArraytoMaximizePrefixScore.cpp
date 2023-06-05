class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        int count = 0;

        for (auto a : nums)
        {
            if (a > 0)
                count++;
        }
        return count;
    }
};