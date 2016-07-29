#include "ProgressBar.hpp"
#include "WaitingBar.hpp"

#include <iostream>

using namespace std;


int main(int argc, char **argv) {
    ProgressBar pb;

    cout << "default progress bar " << endl;
    for (int i = 0; i < 30; i++) {
        cout << "test   =>  ";
        pb.ShowProgress((float) (i+1)/30, i+1 , 30);
        sleep(1);
    }
    cout << endl;

    cout  << "pacman -Syu " << endl;
    ProgressBar  b('#','~'); 
    cout << "default progress bar " << endl;
    for (int i = 0; i < 30; i++) {
        b.ShowProgress((float) (i+1)/30, i+1 , 30);
        sleep(1);
    }
    cout << endl;

    WaitingBar p('=', 0.2,10); 
    for (int i = 0; i < 30; i++) {


    p.Clear(); 
    cout << "MDR" << endl;
    p.Show();
        sleep(1);
    }

    cout << endl;
}
