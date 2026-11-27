import sys
def add(T): # T = testcase
	for i in range(T):
		a, b = sys.stdin.readline().split()
		print( int(a) + int(b))

a = sys.stdin.readline().split() # input Testcase
add(int(a[0]))
