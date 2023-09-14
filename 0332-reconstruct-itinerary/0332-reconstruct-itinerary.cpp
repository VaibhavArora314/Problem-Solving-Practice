class Solution {
    unordered_map<string,vector<string>> m;
    vector<string> ans;
    string start = "JFK";

    bool helper(string cur,int ticketCount) {
        ans.push_back(cur);

        if (ticketCount == 0) return true;

        if (!m[cur].empty()) {
            for (int i=0;i<m[cur].size();i++) {
                if (m[cur][i].length() < 3) continue;

                string x = m[cur][i];
                m[cur][i] = "-1";

                if (helper(x,ticketCount-1))
                    return true;

                m[cur][i] = x;
            }
        }

        ans.pop_back();

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ans.clear();

        for (auto ticket:tickets)
            m[ticket[0]].push_back(ticket[1]);

        for (auto itr = m.begin(); itr != m.end(); itr++) 
            sort(itr->second.begin(), itr->second.end());


        if (helper(start,tickets.size()))
            return ans;
        
        return {};
    }
};