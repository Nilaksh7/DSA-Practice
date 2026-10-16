class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();

        sort(temp.begin(),temp.end());

        unordered_map<int,int> rank;//arr[i] , its rank
        int rnk = 1;
        for(int i = 0 ; i < n ; i++){
            if(rank.find(temp[i]) == rank.end())
                rank[temp[i]] = rnk++;
        }

        for(int i = 0 ; i < n ; i++){
            arr[i] = rank[arr[i]];//replace arr[i] with its rank.
        }

        return arr;
    }
};