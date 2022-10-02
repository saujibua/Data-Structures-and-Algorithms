/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14

Input : "XX"
Output : 20

*/

#include <bits/stdc++.h>
using namespace std;

int numericalValue(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;

    return -1;
}

int romanToInt(string A)
{

    int answer = 0;

    for (auto i = 0; i < A.size(); i++)
    {
        int s1 = numericalValue(A[i]);

        if (i + 1 < A.length())
        {
            int s2 = numericalValue(A[i + 1]);
            if (s1 >= s2)
                answer += s1;
            else
            {
                answer += (s2 - s1);
                i++;
            }
        }
        else
        {
            answer += s1;
            i++;
        }
    }

    return answer;
}

int main()
{
    string roman = "XIII";
    cout << romanToInt(roman) << "\n";
    return 0;
}