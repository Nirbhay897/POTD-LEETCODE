// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.



class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minocc(26,INT_MAX);
        vector<string> ans;

        for (auto& it : words) {
            vector<int> temp(26,0);
            for (auto& ch : it) {
               temp[ch-'a']++;
            }
            for(int i=0; i<26; i++){
                    minocc[i] = min(minocc[i], temp[i]);
            }
        }

        for(int i=0; i<26; i++){
            string out (1,i+'a');
            for(int j=1; j<=minocc[i]; j++){
              ans.push_back(out);
            }

        }

        return ans;

    }
};