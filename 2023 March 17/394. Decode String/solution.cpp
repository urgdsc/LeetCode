class Solution {
public:
    string decodeString(string s) {
        return decode(s).first;
    }
    
    pair<string, int> decode(string s) {
        string res = "";
        string num = "0";
        
        for(int i=0; i<s.size(); i++) {
            
            if( isdigit(s[i]) )
                num += s[i];
            
            else if( s[i] == '[' ) {
                pair <string, int> tmp = decode(s.substr(i+1));
                i += tmp.second+1;
                int tmp_num = stoi(num);
                while(tmp_num--)
                    res += tmp.first;
                num = "0";
            }
            
            else if( s[i] == ']' )
                return {res, i};
            
            else
                res += s[i];
        }
        return {res, 0};
    }
};
