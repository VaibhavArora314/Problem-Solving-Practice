class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> last;
        map<char,int>::iterator itr;
        
        for (int i=0;i<s.size();i++) {
            itr = last.find(s[i]);
            if (itr == last.end()) {
                last.insert({s[i],i});
            } else {
                itr->second = i; 
            }
        }
        
        vector<int> partition,track;
        int max = 0;
        for (int i=0;i<s.size();i++) {
            itr = last.find(s[i]);
            if (itr->second > max) max = itr->second;
            if (i == max) {
                partition.push_back(max-(track.size() > 0 ? track[track.size()-1] : -1));
                track.push_back(max);
            }
        }
        
        return partition;
    }
};