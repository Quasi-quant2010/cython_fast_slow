#!/usr/bin/python

import timeit
import gzip, cPickle
import numpy as np
import matplotlib.pyplot as plt

f = gzip.open('result.dump.gz','r')
data = cPickle.load(f)
f.close()

names = [ element[:len(element)-6] 
          for element in data['name'] ]
ax = plt.subplot(111)
bins = map(lambda x: x,range(1,len(data)+1))
ax.bar(bins,data['speed'])
ax.set_xticks(map(lambda x: x, range(1,len(data)+1)))
ax.set_xticklabels(names,rotation=45, rotation_mode="anchor", ha="right")
plt.ylabel('Calculate Time[s]')
plt.savefig('speed_with_pure_python.png')
plt.close()
