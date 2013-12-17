#!/usr/bin/python

import timeit, gzip, cPickle
import numpy as np

setup_string = """
import numpy as np
import matmult_cython as cymm
import matmult_f2py as fpmm

N = 500
M = 500
L = 500
x = np.random.randn(N, L)
y = np.random.randn(L, M)
"""
result = []
index = 0
#test_strings = ["np.dot(x, y)", "cymm.matmultp(x, y)",
test_strings = ["np.dot(x, y)",
        "cymm.matmult1(x, y)", "cymm.matmult2(x, y)", "cymm.matmult3(x, y)",
        "cymm.matmult3_1(x, y)", "cymm.matmult3_2(x,y)", "cymm.matmult4(x, y)", "cymm.matmult5(x, y)", "cymm.matmult6(x, y)",
        "fpmm.matmult_f(x, y)", "fpmm.matmult_c(x, y)"]

n_retry_default = 1
for test_string in test_strings:
    n_retry = n_retry_default
    if "matmultp" in test_string:
        n_retry = n_retry_default / 1000
    test_time = timeit.Timer(test_string, setup_string).timeit(n_retry)
    #print "%20s used %12.5e s"%(test_string, test_time / n_retry )
    result.append( tuple([index,
                          test_string,
                          test_time / n_retry ]) )
    index += 1

dt={'names':('index','name','speed'),'formats':('|i8','|S20',float)}
result = np.array(result, dtype=dt)
with gzip.open('result.dump.gz','w') as outfile:
    cPickle.dump(result,outfile,2)
