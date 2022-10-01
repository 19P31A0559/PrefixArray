/*  The interns at Amazon were asked to review the company's stock value over a period. Given the stock prices of n months, the net price change for the i'th month is defined as the absolute difference between the average of stock prices for the first i months and for the remaining (n-i) months where 1 <= i < n. Note that these averages are rounded down to an integer.

	Given an array of stock prices, find the month at which the net price change is minimum. If there are several such months, return the earliest month.
	
	Note: The average of a set of integers here is defined as the sum of integers divided by the number of integers, rounded down to the nearest integer. For example, the average of [1,2,3,4] is the floor of (1+2+3+4)/4 = 2.5 and the floor of 2.5 is 2.
	
	Example,
	 
	stcokPrice = [1,3,2,3]
	
	The minimum net price change is 0, and it occurs in the 2nd month. Return 2.
	
	Function Description
	Complete the function findEarliestMonth the editor below.
	
	findEarliestMonth has the following parameter:
		int stockPrice[n]: the stock prices
	
	Returns
	    int: the earliest month in which the net price change is minimum
	    
	Constraints
	
		2 <= n <= 10^5
		1 <= stockPrice[i] <= 10^9
		
*/

#include <bits/stdc++.h>

int findEarliestMonth(std :: vector<int> stockPrice) {
	long long int n = stockPrice.size() , mini = INT_MAX , net_price ;
	long long int prefix[n] , past_avg , pres_avg , month ;
	prefix[0] = stockPrice[0] ;
	for (int i = 1 ; i < n ; i ++) {
		prefix[i] = prefix[i-1] + stockPrice[i] ;
	} for (int i = 1 ; i < n ; i ++) {
		past_avg = prefix[i-1] / i ;
		pres_avg = (prefix[n-1] - prefix[i-1]) / (n - i) ;
		net_price = abs(past_avg - pres_avg) ;
		if (net_price < mini) {
			mini = net_price , month = i ;
		}
	} return month ;
}

int main() {
	int n ;
	std :: cin >> n ;
	std :: vector<int> nums(n) ;
	for (int i = 0 ; i < n ; i ++) std :: cin >> nums[i] ;
	std :: cout << findEarliestMonth(nums) ;
	return 0 ;
}

