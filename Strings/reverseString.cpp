/*

Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

        A sequence of non-space characters constitutes a word.
        Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
        If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

#include <bits/stdc++.h>
using namespace std;

void reverseString(string &A)
{

    reverse(A.begin(), A.end());
    int idx = 0;
    for (auto i = 0; i < A.size(); i++)
    {
        if (A[i] != ' ')
        {
            if (idx != 0)
                A[idx++] = ' ';

            int j = i;

            while (j < A.size() && A[j] != ' ')
                A[idx++] = A[j++];

            reverse(A.begin() + idx - (j - i), A.begin() + idx);
            i = j;
        }
    }
    A.erase(A.begin() + idx, A.end());
}

int main(){
    // call function
    string A = "the sky is blue";
    reverseString(A);
    cout << A << "\n";
    return 0;
}