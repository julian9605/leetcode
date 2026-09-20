class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        // e.g. [1,2,3,4]
        // front = 2, answer = [1,1,2,6]
        // back = 24, answer = [24,12,8,6]

        // have 2 ints, front, back
        // front = product of elements before answer[i]
        // back = product of elements after answer[i]
        int front = 1, back = 1;

        for (int i = 1; i < nums.size(); i++) {
            answer[i] = nums[i-1] * front;
            front = answer[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= back;
            back *= nums[i];
        }
        return answer;
    }
};