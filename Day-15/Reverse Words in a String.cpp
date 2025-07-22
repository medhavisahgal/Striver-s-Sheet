#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (!word.empty())
                {
                    v.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += s[i];
            }
        }
        if (!word.empty())
        {
            v.push_back(word);
        }
        string res = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            res += v[i];
            if (i != 0)
                res += " ";
        }
        return res;
    }
};