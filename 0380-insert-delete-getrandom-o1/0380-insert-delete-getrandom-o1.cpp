class RandomizedSet {
    vector<int> vals;
    unordered_map<int,int> m;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        
        vals.push_back(val);
        m[val] = vals.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) 
            return false;

        int index = m[val];
        if (index != vals.size()-1) {
            swap(vals[index],vals[vals.size()-1]);
            m[vals[index]] = index;
        }
        vals.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % vals.size();
        return vals[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */