#include <iostream>
#include <stdlib.h> //(WAJIB ADA)

using namespace std;

int main (){
	//deklarasi pointer
	float *pjari, *pluas;
	
	//memesan slot memori untuk membuat variabel jari dan luas. Simpan alamatnya pada pointer
	pjari = (float*)malloc(sizeof(float));
	pluas = (float*)malloc(sizeof(float));
	
	//if (pjari != NULL && pluas != NULL){ //loker diuji berhasil dibuat atau tidak (WAJIB ADA)
		//jika berhasil memesan memori, gunakn variabel jari dan luas melalui pointer
		*pjari = 7;
		*pluas = 3.14 * *pjari * *pjari;
		cout << "lingkaran dengan jari jari : " << *pjari;
		cout << "\nluasnya : " << *pluas;
	
		//menghapus atau melepaskan slot memoru yang dtinjuk oleh pjari dan pluas
		free(pjari);
		free(pluas);
	//}
	return 0;
}
