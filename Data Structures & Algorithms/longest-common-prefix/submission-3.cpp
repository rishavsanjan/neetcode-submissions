class Solution {
public:
    void prefixCheck(string &prefix, string obj){
        cout<<prefix<<endl;
        for(int i = 0; i<obj.size(); i++){
            if(obj[i] != prefix[i]){
                string newPrefix = prefix.substr(0, i);
                prefix = newPrefix;
                return;
            }
        }
        prefix = obj;
        return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(string s : strs){
            if(s.length() == 0){
                return "";
            }
            prefixCheck(prefix, s);
        }

        return prefix;
        
    }
};