#!/bin/python3

import re

if re.search(r'[aeiouy]{2,}|(.)\1+', input()): print("No");
else: print("Yes")
