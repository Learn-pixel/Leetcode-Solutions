class Solution {
public:
    vector<vector<int>> Combine(vector<vector<int>>& left, vector<vector<int>>& right) {
        vector<vector<int>> ans;

        int i = 0, j = 0;
        int h1 = 0, h2 = 0;

        while(i < left.size() && j < right.size()) {
            int x;

            if(left[i][0] < right[j][0]) {
                x = left[i][0];
                h1 = left[i][1];
                i++;
            }
            else if(left[i][0] > right[j][0]) {
                x = right[j][0];
                h2 = right[j][1];
                j++;
            }
            else {
                x = left[i][0];
                h1 = left[i][1];
                h2 = right[j][1];
                i++;
                j++;
            }

            int curr = max(h1, h2);

            if(ans.empty() || ans.back()[1] != curr)
                ans.push_back({x, curr});
        }

        while(i < left.size()) {
            if(ans.empty() || ans.back()[1] != left[i][1])
                ans.push_back(left[i]);
            i++;
        }

        while(j < right.size()) {
            if(ans.empty() || ans.back()[1] != right[j][1])
                ans.push_back(right[j]);
            j++;
        }

        return ans;
    }
 
    vector<vector<int>> divide(vector<vector<int>>& buildings, int left, int right){
        vector<vector<int>> b;
        if(left==right) return {{buildings[left][0],buildings[left][2]},{buildings[left][1],0}};
        int mid = (left+right)/2;
        vector<vector<int>> leftSky = divide(buildings, left, mid);
        vector<vector<int>> rightSky = divide(buildings, mid+1, right);
        vector<vector<int>> midSky = Combine(leftSky, rightSky);
        return midSky;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return divide(buildings, 0, buildings.size()-1);
    }
};