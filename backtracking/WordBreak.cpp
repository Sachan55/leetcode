Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
https://leetcode.com/problems/word-break/


simple backtracking problem but using memoization converted it to dynamic programming.
there will be many instances when we will backtrack and calculate again.(when multiple prefix exists in dictionary ex word aaaaaaaaaa , dict : [a,aa,aaa,aaaa])
so to avoid recalculating just save if a word can be splited at any perticiular index or not.
there are always two choice either you split for curr index or not so complexity will be o(2^n)
but if we memoize we can reduce it to o(n2)
class Solution {
public:
    unordered_set<string> st;
    bool ans = false;
    map<int,bool> mp;
    bool backtrac(string s, string curr, string temp,int start,int end)
    {
		//these strings are reducdant we can compare size with i also so temp and curr can be removed
        if(s.size() == curr.size())
        {
            return true;
        }
        if(mp.find(start) != mp.end())
            return mp[start];
        if((curr+temp).size() > s.size())
            return false;
        bool res = false;
        for(int i = start ; i <= end ; i++)
        {
            temp = temp + s[i];
            if(st.find(temp)!=st.end())
            {
                if(backtrac(s,curr+temp,"",i+1,end) == true)
                {
                    res = true;
                    break;
                }
            }
        }
        mp[start] = res;
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0 ; i < wordDict.size() ; i++)
        {
            st.insert(wordDict[i]);
        }
        return backtrac(s,"","",0,s.size()-1);
    }
};