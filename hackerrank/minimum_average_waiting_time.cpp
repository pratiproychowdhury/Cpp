/*
Tieu owns a pizza restaurant and he manages it in his own way. While in a normal restaurant, a customer is served by following the first-come, first-served rule, Tieu simply minimizes the average waiting time of his customers. So he gets to decide who is served first, regardless of how sooner or later a person comes.

Different kinds of pizzas take different amounts of time to cook. Also, once he starts cooking a pizza, he cannot cook another pizza until the first pizza is completely cooked. Let's say we have three customers who come at time t=0, t=1, & t=2 respectively, and the time needed to cook their pizzas is 3, 9, & 6 respectively. If Tieu applies first-come, first-served rule, then the waiting time of three customers is 3, 11, & 16 respectively. The average waiting time in this case is (3 + 11 + 16) / 3 = 10. This is not an optimized solution. After serving the first customer at time t=3, Tieu can choose to serve the third customer. In that case, the waiting time will be 3, 7, & 17 respectively. Hence the average waiting time is (3 + 7 + 17) / 3 = 9.

Help Tieu achieve the minimum average waiting time. For the sake of simplicity, just find the integer part of the minimum average waiting time.

Input Format

    The first line contains an integer N, which is the number of customers.

    In the next N lines, the ith line contains two space separated numbers Ti and Li. Ti is the time when ith customer order a pizza, and Li is the time required to cook that pizza.

    The 

customer is not the customer arriving at the

    arrival time.

Output Format

    Display the integer part of the minimum average waiting time.

Constraints

    1 ≤ N ≤ 105
    0 ≤ Ti ≤ 109
    1 ≤ Li ≤ 109

Note

    The waiting time is calculated as the difference between the time a customer orders pizza (the time at which they enter the shop) and the time she is served.

    Cook does not know about the future orders.

Sample Input #00

3
0 3
1 9
2 6

Sample Output #00

9

Sample Input #01

3
0 3
1 9
2 5

Sample Output #01

8

Explanation #01

Let's call the person ordering at time = 0 as A, time = 1 as B and time = 2 as C. By delivering pizza for A, C and B we get the minimum average wait time to be

(3 + 6 + 16)/3 = 25/3 = 8.33 

the integer part is 8 and hence the answer.
*/

#include <bits/stdc++.h>

using namespace std;

long long minimumAverage(vector<vector<int>> customers) {

    multimap<long long,long long> timetocust;
    long long totalCustomers = customers.size();

    for (vector<int> a : customers)
        timetocust.emplace(a[1],a[0]);

    long time = 0;
    long long totalwaitingtime = 0;
    multimap<long long,long long>::iterator thisCust = timetocust.begin();

    do {
        if (thisCust == timetocust.end()) {
            thisCust = timetocust.begin();
            // find earliest arrival time
            long long earliest = numeric_limits<long long>::max();
            for (pair<long long,long long> a : timetocust)
                earliest = min(earliest, a.second);
            time = earliest;
        }

        if (thisCust->second <= time) {
            // serve this customer
            totalwaitingtime += (thisCust->first+time) - thisCust->second;
            time += thisCust->first;
            timetocust.erase(thisCust);
            thisCust = timetocust.begin();
        }
        else
            thisCust++;

    } while (!timetocust.empty());

    return totalwaitingtime/totalCustomers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> customers(n);
    for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++) {
        customers[customers_row_itr].resize(2);

        for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++) {
            cin >> customers[customers_row_itr][customers_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}
