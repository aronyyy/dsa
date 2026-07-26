// class Solution {
//   public:
//     int minPlatform(vector<int>& arr, vector<int>& dep) {
//         // code here
//         sort(arr.begin(), arr.end());
//         sort(dep.begin(), dep.end());
//         int i=0;
//         int j=0;
//         int cnt=0;
//         int ans=0;
//         while(i<arr.size()){
//             if (arr[i] < dep[j]){
//                 i++;
//                 cnt++;
//             }
//             else {
//                 j++;
//                 cnt--;
//             }
//             ans = max(cnt, ans);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;

        while (i < arr.size()) {

            if (arr[i] <= dep[j]) {
                cnt++;
                ans = max(ans, cnt);
                i++;
            }
            else {
                cnt--;
                j++;
            }
        }

        return ans;
    }
};