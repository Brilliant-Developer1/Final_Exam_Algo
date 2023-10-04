#include <iostream>
#include <vector>

using namespace std;

bool canDivideChocolates(int N, vector<int> &chocolates)
{
    int totalChocolates = 0;

    // Calculate the total number of chocolates in all boxes
    for (int i = 0; i < N; i++)
    {
        totalChocolates += chocolates[i];
    }

    // Check if the total number of chocolates is even
    if (totalChocolates % 2 != 0)
    {
        return false;
    }

    int targetChocolates = totalChocolates / 2;

    vector<bool> dp(targetChocolates + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = targetChocolates; j >= chocolates[i]; j--)
        {
            dp[j] = dp[j] || dp[j - chocolates[i]];
        }
    }

    return dp[targetChocolates];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> chocolates(N);

        for (int i = 0; i < N; i++)
        {
            cin >> chocolates[i];
        }

        if (canDivideChocolates(N, chocolates))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

/*
check my code and modiefy it according to solve this problem.
my code :

please slove this using knapsack in cpp
Problem Statement

Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to carry all of his equipment with him.

The treasure hunter had a backpack with a limited weight capacity, and he could only carry a certain amount of equipment with him. Each piece of equipment had its own weight and value, and the treasure hunter needed to choose which items to bring to maximize the total value while keeping the total weight under the limit.

Help the treasure hunter to choose which items to bring in his backpack to maximize their total value while keeping the total weight of his backpack under a certain limit. Each item can only be included once.

Input Format

First line will contain T, the number of test cases.
The first line of each test case will contain N(Number of items) and W(Total weight of backpack).
Second line of each test case will contain an array w containing the weights of all items.
Third line of each test case will contain an array v containting the values of all items.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= W <= 1000
0 <= w[i] <= 1000; Here 0 <= i < N
0 <= v[i] <= 1000; Here 0 <= i < N
Output Format

Output the maximum total value you can obtain in the backpack for each test case.

Sample Input 0:
2
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8
.
Sample Output 0 :
13
28

still for this input :
3
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
6 900
10 20 30 40 50 60
.
my expected output is :
YES
NO
YES

but I'm getting this output :
NO
NO
NO

*/