#include <iostream>

using namespace std;

int main ()
{
	// deklarasi variabel
	int x;
	int *px;
	
	// bagian badan program
	px=&x;
	x=10;
	
	cout << "\nVariabel x berada di alamat : " << px;
	cout << "\nNilai variabel x diakses melalui pointer : " << *px;
	cout << "Nilai variabel x diakses secara langsung : " << x;
	
	return 0;
}

// 1. Perbedaan baris 15 dan 17 adalah, baris 15 mencetak langsung variabel tanpa menggunakan pointer (langsung)
// sedangkan baris 17 adalah mencetak nilai variabel x dengan mengalamatkan terlebih dahulu ke px lalu mencetak dengan variabel pointer px
// 2. Cara mengakses isi variabel pointer adalah dengan mengalamatkan nilai variabel tertentu dengan menggunakan simbol &
// 3. Cara mengakses data yang alamatnya disimpan oleh variabel pointer dengan menyamakan sesuai dengan deklarasi yang telah
// dibuat dengan penanda (*) sebagai tanda pointer
// 4. Yang terjadi ketika memindahkan baris 16 dan 17 ke baris 12 adalah program yang dieksekusi mengalami stop working atau not respond
// karena pointer px tidak memiliki alamat variabel lain / tidak ada variabel yang disimpan dan dialamatkan
// 5. Jika baris 16 dan 17 di sisipkan diantara baris 12 dan 13 adalah px (alamat) akan default di alamatkan di 0x28ff08 dan nilai *px 
// menjadi 8, karena ??
// 6. tanda (*) pada deklarasi variabel seperti kita memanggil pointer yang dinamaka px
// sedangkan tanda (*) pada badan program adalah untuk memanggil atau mengakses nilai yang telah di alamatkan ke px
