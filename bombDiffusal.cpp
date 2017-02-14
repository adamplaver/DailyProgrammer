#include <iostream>
using namespace std;

/* Code for r/DailyProgrammer Challenge 293.
If you cut a white cable you can't cut white or black cable.
If you cut a red cable you have to cut a green one
If you cut a black cable it is not allowed to cut a white, green or orange one
If you cut a orange cable you should cut a red or black one
If you cut a green one you have to cut a orange or white one
If you cut a purple cable you can't cut a purple, green, orange or white cable
*/

int colorToNumber(string color){
	// Converts the colors to intergers.
	// White = 1, Red = 2, Black = 3, Orange = 4,
	// Green = 5, Purple = 6.
	int colorN;
	if(color == "White" || "white"){
		colorN = 1;
	} else if(color == "Red" || "red"){
		colorN = 2;
	} else if(color == "Black" || "black"){
		colorN = 3;
	} else if(color == "Orange" || "orange"){
		colorN = 4;
	} else if(color == "Green" || "green"){
		colorN = 5;
	} else if(color == "Purple" || "purple"){
		colorN = 6;
	}
	return colorN;
}

int rules(int current, int next){ //Decides if the next move is correct.
	int missionStatus;
	switch(current){
		case 1: // White
			if(next == 1 || 3){
				missionStatus = 0;
			} else{
				missionStatus = 1;
			};
			break;
		case 2: // Red
			if(next != 5){
				missionStatus = 0;
			} else{
				missionStatus = 1;
			};
			break;
		case 3: // Black
			if(next == 1 || 4 || 5){
				missionStatus = 0;
			} else {
				missionStatus = 1;
			};
			break;
		case 4: // Orange
			if(next != 2 || 3){
				missionStatus = 0;
			} else{
				missionStatus = 1;
			};
			break;
		case 5: // Green
			if(next != 4 || 1){
				missionStatus = 0;
			} else{
				missionStatus = 1;
			};
			break;
		case 6: // Purple
			if(next == 6 || 5 || 4 || 1){
				missionStatus = 0;
			} else{
				missionStatus = 1;
			};
			break;
	};
	return missionStatus;
}

int main(){
	int c1,c2,missionStatus;
	int x = 1;
	string color = "";
	string missionFailed = "Terrorists Win.";
	string missionCompleted = "Counter-Terrorists Win.";
	cout << "Bomb Defusal\n" << "Type what color wire to cut on each line\n";
	cin >> color;
	c1 = colorToNumber(color);
	do{
		cin >> color;
		c2 = colorToNumber(color);
		missionStatus = rules(c1,c2);
		c2 = c1;
		x++;
	}while(missionStatus != 0 || x < 4);
	if(missionStatus == 1){
		cout << missionCompleted << endl;
	} else {
		cout << missionFailed << endl;
	}
	return 0;
}