#!/usr/bin/env python3

import os, sys
import re
import subprocess
import statistics

NB_RUNS = int(sys.argv[1])
SRC_FILE = sys.argv[2]
RUN_ARGS = ' '.join(sys.argv[3:])

exe_file = SRC_FILE.replace(".cpp",".exe")
compile_cmd = "rm -f {} && g++ -std=c++17 -O3 -march=native {} -o {}".format(exe_file,SRC_FILE,exe_file)
run_cmd = "./{} {}".format(exe_file,RUN_ARGS)

# Utility fonction

def run(cmd):
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, shell=True, executable='bash', universal_newlines=True, check=True)
    return proc.stdout.rstrip().split('\n')

# Compile & first run

expr_times = re.compile("^\((.*) time: (.*) us\)$")

times = {}

os.system(compile_cmd)
for line in run(run_cmd):
    match = expr_times.match(line)
    if expr_times.match(line):
        times[match.groups()[0]] = []
    else:
        print(line)

# Repeat timig

for irun in range(NB_RUNS):
    for line in run(run_cmd):
        match = expr_times.match(line)
        if expr_times.match(line):
            times[match.groups()[0]].append(int(match.groups()[1]))

# Display mean times

for ktime in times:
    print("({} mean time: {})".format(ktime,int(statistics.mean(times[ktime]))))
