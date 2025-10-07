#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
string minWindow(string s, string t) {
        vector<int> map(128,0); //ASCII arrray
        for(auto c: t) map[c]++;//store t
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0; //counter for t
        while(end<s.size()){//move end to find a valid window
            if(map[s[end++]]-->0) counter--; //if found a char in t, decrease counter
            while(counter==0){ //valid window, move begin to find smaller window
                if(end-begin<d)  d=end-(head=begin);//update d(min length) and head(start index)
                if(map[s[begin++]]++==0) counter++;  //if a char in t is removed from the window, increase counter
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
    string minWindowSubstring(string s, string t)
    {
        if (s.empty() || t.empty() || t.size() > s.size())
            return "";

        // hash map to store t and count of each char in t
        unordered_map<char, int> track;
        // hash map to store window chars and their counts found within window
        unordered_map<char, int> window;

        // store t chars in hashmap track
        for (auto c : t)
            track[c]++;

        // have: no of complete chars in t found in window (no. currently statisfied)
        // need: no. of characters in t(no. of distinct requirements)
        int have = 0, need = static_cast<int>(track.size());
        int bestL = 0, bestLen = INT_MAX;

        // start of window
        int l = 0;
        // from start of window to end of s
        for (int r = 0; r < (int)s.size(); ++r)
        {
            // char at the end of window (r)
            char c = s[r];
            // add or increment character in window map
            auto it = track.find(c);
            if (it != track.end())
            {
                int &wc = window[c]; // inserts 0 on first use
                wc++;
                if (wc == it->second)// if count of char in window matches count in t
                    ++have;// we have one more char satisfied
            }

            // continue to shrink window until what we have is no longer(less than) what we need
            while (have == need)
            {
                // if size of curr window is less than curr best length
                if (r - l + 1 < bestLen)
                {
                    // set new best length and best start to substring since substring is start+ length
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char cl = s[l];
                auto is = track.find(cl);
                if (is != track.end())
                {
                    int &wl = window[cl];
                    wl--;
                    if (wl < is->second)
                        --have; 
                }
                // shrink window(move left pointer)
                ++l;
            }
        }

        return bestLen != INT_MAX ? s.substr(bestL, bestLen) : "";
    }
};