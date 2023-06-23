//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        s1 = s1 + s1;
        return kmp(s1, s2);
    }

    vector<int> createlps(string s)
    {
        int i = 0, j = 1, n = s.length();
        vector<int> a(n);
        a[0] = 0;

        while (j < n)
        {
            if (s[i] != s[j])
            {
                i = 0;
                a[j] = i;
            }
            else
            {
                i++;
                a[j] = i;
            }
            j++;
        }

        return a;
    }

    bool kmp(string s1, string s2)
    {
        vector<int> lps = createlps(s2);
        int i = 0, j = 0;
        int n = s1.length(), m = s2.length();
        int count = 0;
        while (i < n)
        {
            if (j == m)
            {
                return true;
            }
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                {
                    i++;
                    continue;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        if (j == m)
        {
            return true;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areRotations(s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
