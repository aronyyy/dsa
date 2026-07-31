class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> pse(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            if (st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(arr[i]);
        }
        return pse;
    }
};