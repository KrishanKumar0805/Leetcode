class Solution {
    public int[] rotateElements(int[] nums, int k) {
        int t=0 ; 
        for(int i=0;i<nums.length;i++) if(nums[i] >= 0)t++;
         if (t == 0) return nums;
        int [] res  = new int[t];
        t=0; int n = nums.length;
        for(int i=0;i<nums.length;i++) if(nums[i] >= 0) res[t++] = nums[i];
        int[] ans = new int[t];
        k = k % t;
        for(int i=0;i<t;i++){
            int idx = ((i-k)+t)%t;
            ans[idx] = res[i];
        }  t=0;
        for(int i=0;i<n;i++){
            if(nums[i] >= 0) nums[i] = ans[t++];
        }
        return nums;
    }
}