/* Alexa is Amazon's virtual AI assistant. It makes it east to set up your Alexa-enabled devices, listen to music, get weather updates, and much more. The team is working on a new feature that evaluates the aggregate temperature change for a period based on the changes in temperature of previous and upcoming days.

	Taking the change in temperature data of n days, the aggregate temperature change evaluated on the i'th day is the maximum of the sum of the changes in temperatures until the i'th day, and the sum of the change in temperatures in the next (n-i) days, with the i'th day temperature change included in both.
	
	Given the temperature data of n days, find the maximum aggregate temperature change evaluated among all the days.
	
	Example
	
	tempChange = [6,-2,5]
	
	The aggregate temperature change on each day is evaluated as:
	
	For day 1, there are no perceding days information, but the day itself included in the calculation.
	Temperature changes = [6] for the before period.
	For succeeding days, there are values [6,-2,5] and 6+(-2)+5 = 9. Again the change for day 1 is included.
	The maximum of 6 and 9 is 9.
	For day 2, consider [6,-2]-> 6+(-2)=4, and [-2,5]-> (-2)+5=3. The maximum of 3 and 4 is 4.
	For day 3, condider [6,-2,5] -> 6+(-2)+5=9, and [5]. The maximum of 9 and 5 is 9.
	The maximum aggregate temperature change is max(9,4,9)=9.
	
	Function Description
	
	Complete the function getMaxAggregateTemperatureChange in the editor below.
	
	getMaxAggregateTemperatureChange has the following parameter:
		int tempChange[n]: the temperature change data of n days
		
	Returns
		long: the maximum aggregate temperature change
		
	Constraints
	
		1 <= n <= 10^5
		-10^9 <= tempChange[i] <= 10^9 where, 1 <= i <= n.
*/

#include <bits/stdc++.h>

long getMaxAggregateTemperatureChange(std :: vector<int> tempChange) {
	long n = tempChange.size() , maxi = INT_MIN , past , pres ;
	long prefix[n] ;
	prefix[0] = tempChange[0] ;
	for (int i = 1 ; i < n ; i ++) {
		prefix[i] = prefix[i-1] + tempChange[i] ;
	} for (int i = 0 ; i < n ; i ++) {
		past = prefix[i] ;
		if (i == 0) pres = prefix[n-1] ;
		else pres = prefix[n-1] - prefix[i-1] ;
		maxi = std :: max(maxi, std :: max(past, pres)) ;
	} return maxi ;
}

int main() {
	int n ;
	std :: cin >> n ;
	std :: vector<int> nums(n) ;
	for (int i = 0 ; i < n ; i ++) std :: cin >> nums[i] ;
	std :: cout << getMaxAggregateTemperatureChange(nums) ;
	return 0 ;
}
	
