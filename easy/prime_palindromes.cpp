/** ===========================================================================================
* Name : prime_palindromes.cpp
* Author: taikido
* Description: Find next prime palindrome after a given number
* Source: http://www.codechef.com/problems/PRPALIN/
* Date: Sun.Dec.22.2013
*=============================================================================================**/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


/*All the prime palindromes
 * {2, 3, 5, 7, 11, 101, 131, 151, 181, 191, 313, 353, 373,
 *  383, 727, 757, 787, 797, 919, 929, 10301, 10501, 10601, 11311, 11411,
 *  12421, 12721, 12821, 13331, 13831, 13931, 14341, 14741, 15451, 15551, 16061, 16361,
 *  16561, 16661, 17471, 17971, 18181, 18481, 19391, 19891, 19991, 30103, 30203, 30403, 30703,
 *  30803, 31013, 31513, 32323, 32423, 33533, 34543, 34843, 35053, 35153, 35353, 35753, 36263,
 *  36563, 37273, 37573, 38083, 38183, 38783, 39293, 70207, 70507, 70607, 71317, 71917, 72227,
 *  72727, 73037, 73237, 73637, 74047, 74747, 75557, 76367, 76667, 77377, 77477, 77977,
 *  78487, 78787, 78887, 79397, 79697, 79997, 90709, 91019, 93139, 93239, 93739, 94049, 94349, 94649, 94849,
 *  94949, 95959, 96269, 96469, 96769, 97379, 97579, 97879, 98389, 98689, 1003001};
 */

/*
 * Key is to realize that N >=1 & <= 10^6, so if N = 10^6 then the next prime will be
 * 1003001, so you need to make max_num bigger or search until the next prime
 * palindrome is found
 */
#define max_num 1005001

bool is_prime[max_num];

void build_primes(){

	for(int i=0; i<max_num; i++) is_prime[i] = true;

	for(int i=2; i<max_num; i++){
		if (is_prime[i]){
			int j=2;
			while (i*j < max_num){
				is_prime[i*j] = false;
				j++;
			}
		}
	}
}

inline string int2str(int num){
	stringstream ss;
	ss << num;
	return ss.str();
}

bool is_palindrome(int n){

	string s1 = int2str(n);
	string s2(s1);
	reverse(s2.begin(), s2.end());
	return s1.compare(s2) == 0;

}

void print_prime_palindromes(){

	for (int i=2; i<max_num; i++){
		//printf("[%d] -- (%d, %d) \n", i, is_prime[i],is_palindrome(i));
		if (is_prime[i] && is_palindrome(i)){
			printf("%d\t", i);
		}
	}
}

void find_next_prime_palindrome(int n){

	for (int i=n; i<max_num; i++){
		if (is_prime[i] && is_palindrome(i)){
			printf("%d\n", i);
			break;
		}
	}
}


int main(){
	build_primes();
	int n;
	scanf("%d", &n);
	find_next_prime_palindrome(n);
	return 0;
}
