#include "WaitingBar.hpp"

#include <iostream>
#include <cmath>


using namespace std;

WaitingBar::WaitingBar() {
    this->barWidth = 70;
    this->progressSign = '=';
    this->movingBarWidth = 3;
    this->currentProgress = (float) movingBarWidth/barWidth ;
    this->speed = 0.1;
    this->direction = Forward;
}
//----------------------------------------------------------------------------------------------------
WaitingBar::WaitingBar(char progressSign, float speed, int movingBarWidth, int barWidth) {
    this-> barWidth = barWidth;
    this->progressSign = progressSign;
    this->movingBarWidth = movingBarWidth;
    this->speed = speed;
    this->direction = Forward;
    this->currentProgress = (float) movingBarWidth/barWidth ;

}
//----------------------------------------------------------------------------------------------------
WaitingBar::~WaitingBar() {
}

//----------------------------------------------------------------------------------------------------
void WaitingBar::Show() {

    cout << "[";
    int pos = (int) (this->barWidth * this->currentProgress);
    float distanceToEdge;

    for (int i = 0; i < this->barWidth; ++i) {
        if( i >= (pos-movingBarWidth)  && i <= pos ) cout << this->progressSign;
        else cout << " ";
    }


    if (direction == Forward ) distanceToEdge = 1.0 - currentProgress;
    else if (direction == Backward) distanceToEdge = fabs(0.0 - currentProgress);
    if(speed > distanceToEdge) {
        if (direction == Forward )
            currentProgress += distanceToEdge;
        else if (direction == Backward) {
            distanceToEdge -= (float) movingBarWidth/barWidth;
            currentProgress -= distanceToEdge;
        }
    }
    else {
        if (direction == Forward)
            currentProgress += speed;
        else if (direction == Backward)
            currentProgress -= speed;
    }
    if ( distanceToEdge < 0.001 ){
        this->ChangeDirection();
    }
    cout << "] " << "\r";
    cout.flush();
}
//----------------------------------------------------------------------------------------------------
void WaitingBar::ChangeDirection() {
    if (this->direction == Forward)
        this->direction = Backward;
    else if (this->direction == Backward)
        this->direction = Forward;
}
//----------------------------------------------------------------------------------------------------
void WaitingBar::Clear() {
    // + 2 because of the '[' and ']' char that are not counted in the width
    for (int i = 0; i < this->barWidth + 2; i++) {
        cout  << " ";
    }
    cout << "\r" ;
}
