leap = 0
year = int(input())
if year % 4 == 0 and year % 100 != 0:
    leap = 1
elif year % 400 == 0:
    leap = 1
print(leap)