class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int l=0;
        int h = n-1;
        for(int i=0; i<n-1; i++){
            if (arr[i] > arr[i+1]){
                l = i+1;
                h = i;
                break;
            }
        }
        
        while(l!=h){
            if (arr[l] + arr[h] == target){
                return true;
            }
            else if (arr[l] + arr[h] < target){
                l = (l + 1)%n;
            }
            else{
                h = h - 1;
                if (h == -1) {
                    h = n-1;
                }
            }
        }
        return false;
    }
};