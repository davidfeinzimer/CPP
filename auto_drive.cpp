//David Feinzimer
//05/17/16

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

string FOV[10];

string DM = "Active";
string STS = "Healthy";

int detected = 0;

void SetDetected();

int main()
{

    for(int x = 0; x < 2; x++)
    {

        SetDetected();

        const time_t ctt = time(0);

        cout << asctime(localtime(&ctt));
        cout << "Drive Mode:    " << DM << endl;
        cout << "System Status: " << STS << endl;
        cout << "Objects Detected: " << detected << endl;
        for(int P = 0; P < 10; P++)
        {
            cout << FOV[P];
        }
        cout << endl << endl;

        x = x-1;
        detected = 0;

        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
    }

    return 0;
}

void SetDetected()
{

    FOV[0] = " | ";
    detected ++;
    FOV[1] = " PED ";
    detected ++;
    FOV[2] = " BIK ";
    detected ++;
    FOV[3] = " VEH ";
    detected ++;
    FOV[4] = " | ";
    detected ++;
    FOV[5] = " | ";
    detected ++;
    FOV[6] = " VEH ";
    detected ++;
    FOV[7] = " _ ";
    detected ++;
    FOV[8] = " BIK ";
    detected ++;
    FOV[9] = " | ";
    detected ++;

    for(int x = 0; x < 10; x++)
    {

        if(FOV[x] == " _ ")
        {
            detected -= 1;
        }
        if(FOV[x] == " | ")
        {
            detected -= 1;
        }

    }

}
