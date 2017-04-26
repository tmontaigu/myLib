#include "ProgressBar.hpp"

#include <iostream>

using namespace std;

//----------------------------------------------------------------------------------------------------
ProgressBar::ProgressBar() {
    this->progressSign = '=';
    this->barHead = '>';
    this->barWidth = 70;
}
//----------------------------------------------------------------------------------------------------
ProgressBar::ProgressBar(char progressSign, char barHead, int barWidth) {
    this->progressSign = progressSign;
    this->barHead = barHead;
    this->barWidth = barWidth;
}
//----------------------------------------------------------------------------------------------------
ProgressBar::~ProgressBar() {

}
//----------------------------------------------------------------------------------------------------
void ProgressBar::ShowProgress(float progress) {

    cout << "[";
    int pos = (int) (this->barWidth * progress);
    for (int i = 0; i < this->barWidth; ++i) {
        if( i < pos) cout << this->progressSign;
        else if (i == pos) cout << this->barHead;
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << "%" << "\r";
    cout.flush();
}
//----------------------------------------------------------------------------------------------------
void ProgressBar::ShowProgress(float progress, int min, int max) {

    cout << "[";
    int pos = (int) (this->barWidth * progress);
    for (int i = 0; i < this->barWidth; ++i) {
        if( i < pos) cout << this->progressSign;
        else if (i == pos) cout << this->barHead;
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << "%" << " ";
    cout << "( " << min << "/" << max << " )" << "\r";
    cout.flush();
}
//----------------------------------------------------------------------------------------------------
void ProgressBar::Clear() {
    // + 2 because of the '[' and ']' char that are not counted in the width
    for (int i = 0; i < this->barWidth + 2; i++) {
        cout  << " ";
    }
    cout << "\r" ;
}
