class Solution {
  public:
    bool isKSortedArray(vector<int>& arr, int k) {
        // code here.
        vector<int> temp = arr;
        unordered_map<int, int>mp;
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++){
            mp[temp[i]] = i;
        }
        
        for (int i=0; i<arr.size(); i++){
            if ( abs(i - mp[arr[i]]) > k){
                return false;
            }
        }
        return true;
    }
};
