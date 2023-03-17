class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> dict1, dict2;
        for(int i = 0; i < s.size(); i++) {
            if(dict1.find(s[i]) == dict1.end() && dict2.find(t[i]) == dict2.end()) {
                dict1[ s[i] ] = t[i];
                dict2[ t[i] ] = s[i];
            }
            s[i] = dict1[s[i]];
        }
        return s == t;
    }
};
