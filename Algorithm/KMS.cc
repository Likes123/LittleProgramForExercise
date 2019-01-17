#include <iostream>
#include <string>
#include <vector>
using namespace std;
//O(N)
void GetMaxPrefixAndSuffix(string &s, vector<int> &result)
{
    result.push_back(-1);
    if (s.size() == 1)
        return;
    result.push_back(0);
    for (int i = 2; i < s.size(); i++)
    {
        if (s[result[i - 1]] == s[i - 1])
            result.push_back(result[i - 1] + 1);
        else
            result.push_back(0);
    }
}

int KMS(string &s1, string &s2)
{
    if (s2.size() > s1.size() || s2.size() == 0)
        return -1;

    vector<int> max_pre_suffix;
    GetMaxPrefixAndSuffix(s2, max_pre_suffix);

    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (s1[i] == s2[j])
        {
            ++i;
            ++j;
            if (j == s2.size()) //matching
                return i - s2.size();
        }
        else
        {
            if (max_pre_suffix[j] == -1 || 0)
            {
                j = 0;
                ++i;
            }
            else
                j = max_pre_suffix[j];
        }
    }

    return -1;
}

int main()
{
    string s1("asdasbalaisdalailsdasdfsafdalailiasdfasdfsaasdlailifdsa");
    string s2("asdlaili");
    //vector<int> temp;
    // GetMaxPrefixAndSuffix(s1, temp);
    // for (auto &n : temp)
    //     cout << n << ",";
    cout << KMS(s1, s2) << endl;
    cout << s1.substr(KMS(s1,s2)) << endl;
    return 0;
}
