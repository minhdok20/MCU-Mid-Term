#include <iostream>
#include <string>
using namespace std;

string classify(int number) {
	if (number % 3 == 0)
		number = number / 3 - 1;
	else
		number /= 3;
	switch (number) {
	case 0:
		return "";
		break;
	case 1:
		return " Kilo";
		break;
	case 2:
		return " Mega";
		break;
	case 3:
		return " Giga";
		break;
	case 4:
		return " Tera";
		break;
	case 5:
		return " Peta";
		break;
	case 6:
		return " Exa";
		break;
	case 7:
		return " Zetta";
		break;
	case 8:
		return " Yotta";
		break;
	case 9:
		return " Bronto";
		break;
	case 10:
		return " Geop";
		break;
	default:
		break;
	}
	return "";
}

int findDot(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.')
			return i;
	}
	return -1;
}

string suffixWithUnit(double number) { 
	string sInteger = to_string((int)number); //lay chuoi phan nguyen cua bien number
	string sDouble = to_string(number); //lay nguyen chuoi so thuc cua bien number

	int posDot = findDot(sDouble); //tim vi tri dau cham dong

	if(posDot)
		sDouble.erase(sDouble.begin() + posDot); //xoa dau cham dong neu tim thay

	posDot = sInteger.length()%3; //vi tri moi cua dau cham dong
	posDot = posDot ? posDot : 3; //neu vi tri moi = 0, set vi tri moi = 3
	sDouble.insert(posDot, "."); //them dau cham dong vao
	while (sDouble[sDouble.length() - 1] == '0' || sDouble[sDouble.length() - 1] == '.')
		sDouble.pop_back(); //check ky tu cuoi cung, neu la '0' hoac '.' thi xoa
	return sDouble + classify(sInteger.length()); //in ket qua kem theo don vi quy doi
}

int main() {
	cout << suffixWithUnit((double)1000000);
	return 0;
}