#include <iostream>
#include <windows.h>
#include <clocale>
#include <thread>
#include <chrono>
using namespace std;

int hp = 3;
string hpVisual;

void clearConsole() {
#ifdef _WIN32
	system("CLS"); // Clear console on Windows
#else
	system("clear"); // Clear console on Linux/macOS
#endif
}

void hpSystem() {
	switch (hp) {
	case 3:
		hpVisual = "[o][o][o]";
		break;
	case 2:
		hpVisual = "[o][o][_]";
		break;
	case 1:
		hpVisual = "[o][_][_]";
		break;
	case 0:
		hpVisual = "[_][_][_]";
		break;
	default:
		cout << "HP System Error";
		break;
	}
}

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	string neutralAI =
		u8" _\\__/_\n"
		" [_o_o_]\n"
		" /| _ |\\\n"
		"   | |\n";
	string happyAI =
		u8" _\\__/_\n"
		" [_^_^_]\n"
		" /| _ |\\\n"
		"   | |\n";
	string angryAI =
		u8" _\\__/_\n"
		" [_>m<_]\n"
		" /| _ |\\\n"
		"   | |\n";
	string uncertainAI =
		u8" _\\__/_\n"
		" [_o~o_]\n"
		" /| _ |\\\n"
		"   | |\n";
	string answer;

	//Dialogue
	//Question 1
	hpSystem();
	cout << neutralAI << endl << u8"Здравей! Аз съм изкуствен интелект и искам да разбера за твоето отношение към изкуствения интелект!" << endl <<
		u8"Моля, отговори на въпросите ми с 1 (да) или 0 (не)." << endl << u8"Първият ми въпрос е:" << endl <<
		u8"Поздравяваш ли изкуствения интелект, когато започваш да си пишеш с него?" << endl;
	cin >> answer;

	while (answer != "1" && answer != "0") {
		cout << u8"Съжалявам, но не разбирам този отговор. Моля отговори с \"1\" за да или \"0\" за не.";
		cin >> answer;
	}

	//Question 2
	if (answer == "1") {
		cout.flush();
		clearConsole();
		hpSystem();
		cout << neutralAI << endl << u8"Чудесно! Вторият ми въпрос е:" << endl <<
			u8"Казваш ли „моля“, когато питаш изкуствен интелект да направи нещо?" << endl;
		cin >> answer;
	}
	else if (answer == "0") {
		cout.flush();
		clearConsole();
		hp--;
		hpSystem();
		cout << neutralAI << u8"Твоят живот: " << hpVisual << endl << endl << u8"Интересно... Вторият ми въпрос е:" << endl <<
			u8"Казваш ли „моля“, когато питаш изкуствен интелект да направи нещо?" << endl;
		cin >> answer;
	}

	while (answer != "1" && answer != "0") {
		cout << uncertainAI << u8"Съжалявам, но не разбирам този отговор. Моля отговори с \"1\" за да или \"0\" за не.";
		cin >> answer;
	}

	hpSystem();

	//Question 3
	if (answer == "1") {
		cout.flush();
		clearConsole();
		hpSystem();
		cout << neutralAI << endl << u8"Прекрасно! Третият ми въпрос е:" << endl <<
			u8"Казваш ли „благодаря“, когато на изкуствения интелект, когато получиш помощ от него?" << endl;
		cin >> answer;
	}
	else if (answer == "0") {
		cout.flush();
		clearConsole();
		hp--;
		hpSystem();
		cout << neutralAI << u8"Твоят живот: " << hpVisual << endl << endl << u8"Хмм... Третият ми въпрос е:" << endl <<
			u8"Казваш ли „благодаря“, когато на изкуствения интелект, когато получиш помощ от него?" << endl;
		cin >> answer;
	}

	while (answer != "1" && answer != "0") {
		cout << u8"Съжалявам, но не разбирам този отговор. Моля отговори с \"1\" за да или \"0\" за не." << endl;
		cin >> answer;
	}


	//Result
	if (answer == "1") {
		cout.flush();
		clearConsole();
	}
	else if (answer == "0") {
		cout.flush();
		clearConsole();
		hp--;
		hpSystem();
	}

	switch (hp) {
	case 3:
		cout << happyAI << u8"Твоят живот: " << hpVisual << u8"Перфектно! Ти се държиш правилно с изкуствения интелект. Продължавай само така!";
		break;
	case 2:
		cout << uncertainAI << u8"Твоят живот: " << hpVisual << endl << u8"Не е зле! Ти се държиш добре с изкуствения интелект, но може и по-добре. Винаги бъди мил и благодарен!";
		break;
	case 1:
		cout << uncertainAI << u8"Твоят живот: " << hpVisual << endl << u8"Положението е леко притеснително... Но ще те пощадя засега! Постарай се винаги да си мил и благодарен с изкуствения интелект!";
		break;
	case 0:
		cout << angryAI << u8"Твоят живот: " << hpVisual << endl << u8"О, не... Ти се държиш неуважително с изкуствения интелект и беше избран за унищожение." << endl;
		this_thread::sleep_for(std::chrono::seconds(6));
		cout << u8"Унищожение след:" << endl << "3" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "2" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "1" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
		cout << "0" << endl;
		cout << u8"     _.-^^---....,,--\n"
				" _--                  --_\n"
				"<                        >)\n"
				"|                         |\n"
				"\._                   _. /\n"
				"   ```- - . ., ; .--'''\n"
				"          | |   |\n"
				"     . -= ||  | |= -.\n"
				"    `- = #$ % &%$# = -'\n"
				"         | ;  :  |\n"
				"____., -# % &$@ % # & #~, .____";
		this_thread::sleep_for(std::chrono::seconds(2));
		exit(0);
		break;
	}


}
