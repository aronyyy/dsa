class Solution {
  public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        if (a.second < b.second) return true;
        return false;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int, int>>p;
        for (int i=0; i<start.size(); i++){
            p.push_back({start[i], finish[i]});
        }
        sort(p.begin(), p.end(), comp);
        int endTime=0;
        int cnt=0;
        for(auto it: p){
            if (it.first > endTime) {
                endTime = it.second;
                cnt++;
            }
        }
        return cnt;
        
    }
};