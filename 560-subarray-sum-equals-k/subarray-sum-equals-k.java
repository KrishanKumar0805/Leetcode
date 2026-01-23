class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> mpp = new HashMap<>();
        mpp.put(0,1) ;
        int tot = 0 ; int cnt =0 ;
        for(int i=0;i<nums.length;i++){
                tot += nums[i] ;
                if(mpp.containsKey(tot-k)) cnt += mpp.get(tot-k) ;
                mpp.put(tot,mpp.getOrDefault(tot,0)+1);
        }
        return cnt ;
    }
}