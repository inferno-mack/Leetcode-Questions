class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end()); 
        vector<vector<int>> ans;  
        set<vector<int>> store;   
		
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n ; j++){
                long new_target  = (long)target - nums[i] - nums[j];
                int front = j+1 , back = n-1;
                while(front < back){
                    int sum = nums[front] + nums[back];
                    if(sum > new_target) back--;
                    else if(sum < new_target ) front++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[front] , nums[back]});
                        front++;
                        back--;
                    };
                }
            }
        }
        for(auto i : store){
            ans.push_back(i);
        }
        return ans;
    }
};