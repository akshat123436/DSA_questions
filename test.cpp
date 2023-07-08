int noOfPairs(vector<string> box)
{
    int count = 0;
    int n = box.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string concat_string = box[i] + box[j];
            map<char, int> char_freq;
            for (char c : concat_string)
            {
                char_freq[c] = char_freq.count(c) ? char_freq[c] + 1 : 1;
            }
            int odd_count = 0;
            for (auto it : char_freq)
            {
                if (it.second % 2 != 0)
                {
                    odd_count++;
                }
            }
            if (odd_count <= 1)
            {
                count++;
            }
        }
    }
    return count;
}