class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int leftpointer = 0;
        int rightpointer = nums.size() - 1;

        vector<int> res(nums.size());

        int position = nums.size() - 1;

        while (leftpointer <= rightpointer)
        {
            if (abs(nums[leftpointer]) > abs(nums[rightpointer]))
            {

                res[position] = nums[leftpointer] * nums[leftpointer];
                leftpointer += 1;  
            }
            else
            {
                res[position] = nums[rightpointer] * nums[rightpointer];
                rightpointer -= 1;  
            }
            position -= 1; 
        }

        return res;
    }
};
