
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = word1.length();
        if(word2.length()!=n){
            return false;
        }
        int fre[26]; 
        memset(fre, 0, sizeof(fre));
        int fre2[26];
        memset(fre2, 0, sizeof(fre2));

        for(int i=0;i<n;i++){
            fre[word1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            fre2[word2[i]-'a']++;
        }
        vector<int>v1,v2;
        for(int i=0;i<26;i++){
            if(fre[i]!=fre2[i]){
                if(fre[i]==0 || fre2[i]==0){
                    return false;
                }
            }
            if(fre[i]!=fre2[i]){
                v1.push_back(fre[i]);
                v2.push_back(fre2[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int m = v1.size();
        for(int i=0;i<m;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};