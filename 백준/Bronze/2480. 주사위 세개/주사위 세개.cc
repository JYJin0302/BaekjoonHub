#include <iostream>
using namespace std;

int main()
{
 int a,b,c;
 cin >> a >> b >>c;

if(1<=a&&a<=6&&1<=b&&b<=6&&1<=c&&c<=6)
{
   if(a==b&&c==b)
 {
   cout << (10000)+a*1000 << "\n";
 }
 else if(a==b||c==b||a==c)
  {
     if(a == c) cout << 1000 + c*100;
  else cout << (1000)+b*100 << "\n";
  } 
 else if(b<c&&a<c)
 {
   cout << c*100 << "\n";
 }
 else if(c<a&&b<a)
 {
   cout << a*100 << "\n";
 }
 else
 {
   cout << b*100 << "\n";
  }
}
}