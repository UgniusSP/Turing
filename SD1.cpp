#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

struct strukt {
	string bus, nbus;
	char symb, nsymb, symb2, nsymb2;
	char krypt, krypt2;
};

int main() {
	int jsk, pos, pos2, count;
	string juost, juost2, x = "0", filename;
	vector <strukt> a;
	strukt temp;

	cout << "Jeigu ciklas yra amzinas(niekada nesibaigia), paspauskite esc noredami is jo iseti." << endl << endl;

	cout << "Iveskite failo pavadinima: ";
	cin >> filename;

	ifstream is(filename);

	if (!is) {
		cout << "Tokio failo nera.";
	}
	else {
		is >> jsk;
		if (jsk == 1) {
			is >> juost >> pos;

			while (!is.fail()) {
				is >> temp.bus >> temp.symb >> temp.nsymb >> temp.krypt >> temp.nbus;
				a.push_back(temp);
			}

			bool exit = false;

			while (exit == false) {
				count = 0;
				for (int i = 0; i < a.size(); i++) {
					if (a[i].bus == x) {
						count++;
						if (a[i].symb == juost[pos - 1]) {
							juost[pos - 1] = a[i].nsymb; // naujas
							if (a[i].krypt == 'R') { //desine
								pos++;
							}
							else if (a[i].krypt == 'L') { // kaire
								pos--;
							}
							x = a[i].nbus;
						}
					}
				}
				if (count > 0) {
					cout << juost << endl;
					//Sleep(50);
				}
				else {
					cout << endl << "UTM sustojo del neapibreztos busenos " << x << "!" << endl;
					break;
				}
				if (GetAsyncKeyState(VK_ESCAPE)) {
					exit = true;
					cout << endl << "Ciklas sustabdytas!" << endl;
				}
			}
		}
		else if (jsk == 2) {
			is >> juost >> juost2 >> pos >> pos2;

			while (!is.fail()) {
				is >> temp.bus >> temp.symb >> temp.symb2 >> temp.nsymb >> temp.nsymb2 >> temp.krypt >> temp.krypt2 >> temp.nbus;
				a.push_back(temp);
			}

			bool exit = false;

			while (exit == false) {
				count = 0;
				for (int i = 0; i < a.size(); i++) {
					if (a[i].bus == x) {
						count++;
						if (a[i].symb == juost[pos - 1] && a[i].symb2 == juost2[pos - 1]) {
							juost[pos - 1] = a[i].nsymb; // naujas
							juost2[pos - 1] = a[i].nsymb2;
							if (a[i].krypt == 'R') { //desine
								pos++;
							}
							else if (a[i].krypt == 'L') { // kaire
								pos--;
							}
							if (a[i].krypt2 == 'R') { //desine
								pos2++;
							}
							else if (a[i].krypt2 == 'L') { // kaire
								pos2--;
							}
							x = a[i].nbus;
						}
					}
				}
				if (count > 0) {
					cout << juost << " " << juost2 << endl;
					//Sleep(50);
				}
				else {
					cout << endl << "UTM sustojo del neapibreztos busenos " << x << "!" << endl;
					break;
				}
				if (GetAsyncKeyState(VK_ESCAPE)) {
					exit = true;
					cout << endl << "Ciklas sustabdytas!" << endl;
				}
			}
		}
		
	}
	
	return 0;
}