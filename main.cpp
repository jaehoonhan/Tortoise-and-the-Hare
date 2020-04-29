//
//  main.cpp
//  Tortoise_and_Hare
//  Copyright © 2020 Jae Hoon Han. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <time.h>
//#include <windows.h>

using namespace std;

int FINISH_LINE = 70;

void TortoiseRun(int *);
void HareRun(int *);
void Positions(int, int);

int main()
{
int T = 1;
int H = 1;


int * TPtr = &T;
int * HPtr = &H;

srand((unsigned int)time(0)); //set random seed to time


cout << "BANG ! ! ! ! !" << "\n";
cout << "AND THEY'RE OFF ! ! ! ! !" << endl;



while (T != FINISH_LINE && H != FINISH_LINE)
{
TortoiseRun(TPtr); //function to determine tortoise's next  step
HareRun(HPtr);     // function to determine hare's next step
Positions(T, H);   // display positions after steps have been recorded
chrono::milliseconds dura( 50);
this_thread::sleep_for( dura );
    //Sleep(1000); // Pause "while" loop for 1000 milliseconds (1second)
}



if (T > H)
cout << "TORTOISE WINS ! ! ! ! YAY ! ! !" << endl;
if (H > T)
cout << "Hare wins." << endl;
return 0;
}



void TortoiseRun(int * Tortoise) {
int RT = 1 + rand() % 10;


if (RT >= 1 && RT <= 5) // Fast plod, +3
*Tortoise += 3;
else if (RT >= 6 && RT <= 7) // Slip, -6
*Tortoise -= 6;
else if (RT >= 8 && RT <= 10) // Slow plod, +1
++(*Tortoise);



if (*Tortoise < 1) // move tortoise back to 1 if below starting pt
*Tortoise = 1;


else if (*Tortoise > FINISH_LINE) // if tortoise passes finish line(70), move him to finish line
*Tortoise = FINISH_LINE;
}



void HareRun(int * Hare) {
int RH = 1 + rand() % 10;

if (RH >= 3 && RH <= 4) //Big Hop, +9
*Hare += 9;
else if (RH == 5) //Big slip, -12
*Hare -= 12;
else if (RH >= 6 && RH <= 8) //Small hop, +1
*Hare += 1;
else if (RH >= 9 && RH <= 10) // Small slip, -2
*Hare -= 2;



if (*Hare < 1)  //move hare back to "1" if before starting pt
*Hare = 1;
if (*Hare > FINISH_LINE) // if tortoise passes finish line(70), move him to finish line
*Hare = FINISH_LINE;



}



void Positions(int Tortoise, int Hare)
{
if (Tortoise < Hare)
{                    //if tortoise is behind hare
for (int a = 0; a < Tortoise; a++) {   // output each "-" before tortoise position
cout << "-";
}
cout << "T";                            // output Tortoise position
for (int b = Tortoise + 1; b < Hare; b++) { // start at Tort + 1 (must account for "T" output) and continue "-" until Hare position
cout << "-";
}
cout << "H";                            // output Hare position
for (int c = Hare + 1; c <= FINISH_LINE; c++)    // start 1 space after "H" and continue "-" until finish line (70)
cout << "-";
cout << endl;
}



else if (Hare < Tortoise)
{           // same thing if hare is behind tortoise
for (int d = 0; d < Hare; d++) {
cout << "-";
}
cout << "H";
for (int e = Hare + 1; e < Tortoise; e++) {
cout << "-";
}
cout << "T";
for (int f = Tortoise + 1; f <= FINISH_LINE; f++)
cout << "-";
cout << endl;
}
else if (Tortoise == Hare) // if tortoise and hare collide
{
for (int g = 0; g < Tortoise; g++) { // output "-" until reach animals
cout << "-";
}
cout << "Ouch!";                     // "Ouch!"
for (int f = Tortoise + 5; f <= FINISH_LINE; f++) // Starting at tortoise + 5 continue "-" until finish line
cout << "-";                                  // **skip 5 spaces bcuz "ouch!" has more characters**
cout << endl;
}
}

