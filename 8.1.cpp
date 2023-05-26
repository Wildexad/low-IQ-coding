#include <iostream>
#include <cmath>
using namespace std;
 
int ext_gcd(int a, int b, int& x, int& y){
   int q, r, x1, x2, y1, y2,d;
   if (b == 0) {
      d = a, x = 1, y = 0;
      return d;
   }
   x2 = 1, x1 = 0, y2 = 0, y1 = 1;
   while (b > 0) {
      q = a / b, r = a - q * b;
      x = x2 - q * x1, y = y2 - q * y1;
      a = b, b = r;
      x2 = x1, x1 = x, y2 = y1, y1 = y;
   }
   d = a, x = x2, y = y2;
   return fabs(d);
}
 
int main(){
 
        int a, b, x, y;
        char flag='y';
        cout << "Eta programma nahod NOD\n";
        while(flag=='y'||flag == 'Y'){
                cout << "Vvedite dannie\na = ";
                cin >> a;
                cout <<"b = ";
                cin >> b;
                cout << "NOD(" << a << "," << b << ")=" <<ext_gcd(a,b,x,y) << " (rashirenniy algoritm Evklida)"<<endl;
                cout << "Najmite [y] dlya povtora\n";
                cin >> flag;
        }
        return 0;
}
