#include <iostream>
#include <string>
using namespace std;

string lang[52] = { "ok", //a
"Ok", //b
"oK", //c
"OK", //d
"ook", //e
"Ook", //f
"oOk", //g
"OOk", //h
"ooK", //i
"OoK", //j
"oOK", //k
"OOK", //l
"oook", //m
"Oook", //n
"oOok", //o
"OOok", //p
"ooOk", //q
"OoOk", //r
"oOOk", //s
"OOOk", //t
"oooK", //u
"OooK", //v
"oOoK", //w
"OOoK", //x
"ooOK", //y
"OoOK", //z
"oOOK", //A
"OOOK", //B
"ooook", //C
"Ooook", //D
"oOook", //E
"OOook", //F
"ooOok", //G
"OoOok", //H
"oOOok", //I
"OOOok", //J
"oooOk", //K
"OooOk", //L
"oOoOk", //M
"OOoOk", //N
"ooOOk", //O
"OoOOk", //P
"oOOOk", //Q
"OOOOk", //R
"ooooK", //S
"OoooK", //T
"oOooK", //U
"OOooK", //V
"ooOoK", //W
"OoOoK", //X
"oOOoK", //Y
"OOOoK", //Z
};
char translation[52] = { 'a',
'b',
'c',
'd',
'e',
'f',
'g',
'h',
'i',
'j',
'k',
'l',
'm',
'n',
'o',
'p',
'q',
'r',
's',
't',
'u',
'v',
'w',
'x',
'y',
'z',
'A',
'B',
'C',
'D',
'E',
'F',
'G',
'H',
'I',
'J',
'K',
'L',
'M',
'N',
'O',
'P',
'Q',
'R',
'S',
'T',
'U',
'V',
'W',
'X',
'Y',
'Z'
};
string inputText = "";


void okTrans(string inputText) {
	string fullText = "", lowerinput = "", sublower = "";
	int start = 0, length = tolower(inputText.find('k'));

	for (int i = 0; i < inputText.length(); i++)
		lowerinput += tolower(inputText.at(i));

	do {
		for (int i = 0; i < 52; i++) {
			sublower = lowerinput.substr(start);
			length = sublower.find('k') + 1;
			if (sublower.at(0) == ' ') {
				fullText += ' ';
				start++;
			}
			if (lang[i] == inputText.substr(start, length)) {
				fullText += translation[i];
				start += length;
				break;
			}
		}
	} while (start < lowerinput.length());
	cout << fullText << endl;
}

void engTrans(string inputText) {
	string fullText = "";
	for (int i = 0; i < inputText.length(); i++) {
		if (inputText.at(i) == ' ') {
			fullText += ' ';
			continue;
		}
		for (int j = 0; j < 52; j++) {
			if (translation[j] == inputText.at(i)) {
				fullText += lang[j];
				break;
			}
		}
	}
	cout << fullText << endl;
}

string textInput() {
	cout << "What is the text you want to translate?\n";
	cin.ignore(100, '\n');
	getline(cin, inputText);
	return inputText;
}

int main() {
	int x;
	do {
		cout << "Do you want to translate to english or to ok? (1 for engish, 2 for ok and 0 to end the program)\n";
		cin >> x;
		if (x == 1) {
			textInput();
			okTrans(inputText);
		}
		else if (x == 2) {
			textInput();
			engTrans(inputText);
		}
		else
			break;
	} while (1);
}