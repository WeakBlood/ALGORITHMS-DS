#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int K) {
        deque<int> q;
        int N = nums.size();
        vector<int> answers;
        for(int i = 0; i < K; i++)
        {
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        answers.push_back(nums[q.front()]);
        for(int i = K; i < N; i++)
        {
            while(!q.empty() && q.front() <= i - K) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            answers.push_back(nums[q.front()]);
        }
        return answers;
    }
};