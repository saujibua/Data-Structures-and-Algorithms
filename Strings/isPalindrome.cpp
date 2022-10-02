/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A)
{
    int i = 0, j = A.size() - 1;

    while (j > i)
    {
        if (!isalnum(A[i]))
            i++;

        else if (!isalnum(A[j]))
            j--;

        else
        {
            if (tolower(A[i++]) != tolower(A[j--]))
                return 0;
        }
    }

    return 1;
}

int main()
{
    // call the function here
    string A = "HELLLLEH";
    if (isPalindrome(A))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}