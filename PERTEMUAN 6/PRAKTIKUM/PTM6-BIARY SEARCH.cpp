#include <iostream>
#include <algorithm>

using namespace std;

const int n = 100;
int nim[n];

int binarySearch (int x, int i, int r) {
	if (r >= i) {
		int mid = 1 + (r - 1) / 2;
		if (nim[mid] == x)
		return mid;
		if (nim[mid] > x)
		return binarySearch (x, i, mid - 1);
		return binarySearch (x, mid + 1, r);
	}
	return -1;
}

int main () {
	int n;
	cout << "Masukkan jumlah mahasiswa : ";
	cin >> n;
	
	cout << "Masukkan NIM Masiswa : "<< endl;
	for (int i = 0; i < n; i++) {
		cin >> nim[i];
	}
	sort (nim, nim + n);
	
	int x;
	cout << "masukkan NIM yang dicari : ";w
	cin >> x;
	
	int hasil = binarySearch (x, 0, n - 1);
	if (hasil == -1)
	cout << "NIM tidak di temukan" << endl;
	else 
	cout << "NIM ditemukan pada indeks " << hasil << endl;
	return 0;
}
