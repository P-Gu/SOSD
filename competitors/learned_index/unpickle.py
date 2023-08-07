import os
import hashlib
import pickle

f = open("prefix", 'rb')
pickled_f = pickle.load(f)
out_f = open("prefix_processed", "w+")
count = 0
line_list = []
tmp = []
line_list.append(tmp)
tmp = []
line_list.append(tmp)
for line in pickled_f:
    line_list[count] = line
    count += 1
for i in range(len(line_list[0])):
    out_f.write(str(line_list[0][i]) + ",")
    out_f.write(str(line_list[1][i]) + "\n")