// Insert Delete GetRandom O(1)

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> map;
    vector<int> vect;
    
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end()) {
            return false;
        } else {
            map[val] = vect.size();
            vect.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = map.find(val);
        if(it == map.end()) {
            return false;
        } else {
            int index = it -> second;
            map[vect.back()] = index;
            vect[index] = vect[vect.size() - 1];
            vect.pop_back();
            map.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vect[rand() % vect.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */