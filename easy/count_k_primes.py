"""===========================================================================================
* Name : count_k_primes.py
* Author: taikido
* Description: Count K-Primes
* Source: http://www.codechef.com/problems/KPRIME
* Date: Fri.Dec.21.2013
*============================================================================================="""

import sys
max_num = 100001


def count_primes(num_lines):
    is_prime = [1] * max_num
    counts = [0] * max_num
    
    #print "is_prime: ", is_prime

    for p in range(2, max_num):
        if is_prime[p]:
            counts[p] = 1
            j = 2
            while p * j < max_num:
                #print "p: {0}, j: {1}".format(p, j)
                is_prime[p*j] = 0
                counts[p*j] += 1
                j += 1
                
    kp = [[0 for i in range(6)] for j in range(max_num)]
    
    #print "counts: ", counts
    
    #Create running sum of the counts for the unique prime factors in each num from 2 -> max_num
    for i in range(2, max_num):
        for j in range(1, 6):
            kp[i][j] = kp[i-1][j] + (1 if counts[i] == j else 0)
    
    #print "kp: ", kp      
    for i in range(num_lines):
        a, b, k = map(int, sys.stdin.readline().strip().split())
        print kp[b][k] - kp[a-1][k]   


    

s = raw_input()
num_lines = map(int, s.split())[0]            
count_primes(num_lines)
 




