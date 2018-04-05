#include <iostream>
#include <conio.h>
using namespace std;
int jumlahByValue(int nilai) {
 return nilai += nilai;
}
int jumlahByReference(int &referensi) {
 return referensi += referensi;
}

int main()
{
 int x = 3, z = 5;
 cout << "x = " << x << " sebelum jumlahByValue\n";
 cout << "Nilai yang dikembalikan oleh jumlahByValue: " << jumlahByValue(x) << "\n";
 cout << "x = " << x << " setelah jumlahByValue\n\n";

 cout << "z = " << z << " sebelum jumlahByReference \n";
 cout << "Nilai yang dikembalikan oleh jumlahByReference: " << jumlahByReference(z) << "\n";
 cout << "z = " << z << " setelah jumlahByReference \n\n";


 return 0;
}
