from os import listdir
from os.path import isfile, join
from collections import OrderedDict

onlyfiles = [f for f in listdir(".") if isfile(join(".", f))]
solvedProblems = OrderedDict()

readme='''
# Leetcode Solutions
My accepted leetcode solutions in C++

|NO|Title|Solution|
|---|-----|--------|
'''
for i in onlyfiles:
    namesplit = i.split('.')
    if len(namesplit)==3:        
        solvedProblems[int(namesplit[0])] =   [" ".join(namesplit[1].split("-")),"https://leetcode.com/problems/"+namesplit[1],i, namesplit[-1]]

for key, value in solvedProblems.items():
    if value[-1] == "cpp":
        readme+="|{}|[{}]({})|[C++]({})|\n".format(key,value[0],value[1],value[2])
    elif value[-1] == "py":
        readme+="|{}|[{}]({})|[Python3]({})|\n".format(key,value[0],value[1],value[2])

# print(readme)
f = open("README.md", 'r+')
f.seek(0)
f.write(readme)
f.truncate()
f.close()

import glob
import os

list_of_files = glob.glob('*.cpp') # * means all if need specific format then *.csv
latest_file = max(list_of_files, key=os.path.getmtime)

os.system("git add .")
os.system("git commit -m \"Solved "+latest_file.split('.')[1]+"\"")
os.system("git push")