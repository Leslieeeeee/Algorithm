#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 15 15:19:05 2017

@author: leslieeeeee
"""

#快速排序的python实现

def Quicksort(a, x, l, r):
    i = l
    j = r
    k = x[i]
    x[0] = k
    
    while 1:
        wait = a[i]
        if a[j] < k:
            a[i] = a[j]
       
        if a[i] > k:
            a[j] = wait   
        
        if i == j:
            a[i] = k
            break
        i += 1
        j += 1

def partition(a, x, k, i, j):
    k = x[i]
    Quicksort(a, k, i, x.index(k) - 1)
    Quicksort(a, k, x.index(k) + 1, j)