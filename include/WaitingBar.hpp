#ifndef WAITING_BAR_H
#define WAITING_BAR_H

enum Directions {
    Forward, //To the left
    Backward, //To the right
};
/*
 * Class that is used to display a waiting bar int the command line
 * ( a bar that goes forward and backwards until the task is finished )
 *
 * example :
 * [===        ]
 * [    ===    ]
 * [        ===]
 * [    ===    ]
 * [===        ]
 * etc...
 *
 *  When the program has finished its task or you want to display something else
 *  don't forget to use std::cout << endl;
 */

class WaitingBar {
    /* Members */
    private:
        int barWidth;
        int movingBarWidth;
        char progressSign;
        float currentProgress;
        float speed;
        Directions direction;
    
    /* Constructors */
    public:

        /*
         * Creates a waiting Bar with the default parameters.
         * barWidth 70 (the space in which the actual bar will move
         * progressSign: '='
         * movingBarWidth : 3 the bar will be 3 * '=' -> '==='
         * speed : 0.3 The speed represents how many space the bar will travel
         *             between calls. It must be 0.0 < speed < 1.0
         *             as it is a percentage of the space where the bar can move 
         *             (ie barWidth)
         * default look: [ === ] 
         *
         */
        WaitingBar();
        /*
         * Creates a waiting Bar with the default parameters.
         * progressSign: look of the bar
         * speed : The speed represents how many space the bar will travel
         *         between calls. It must be 0.0 < speed < 1.0
         *         as it is a percentage of the space where the bar can move 
         *         (ie barWidth)
         * movingBarWidth : The size of the bar that moves 
         * barWidth  optionnal (the space in which the actual bar will move
         * 
         * Example:
         *       WaitingBar('#',0.2,3) -> [ ###   ]
         *       WaitingBar('$',0.2,4) -> [ $$$$  ]
         */
        WaitingBar(char progressSign, float speed, int movingBarWidth, int barWidth = 70);
        ~WaitingBar();

    public:
        /*
         * Shows the bar
         * Call this function (for instance in a loop) continuously to animate the bar.
         *
         */
        void Show();
        /*
         * Clears the bar so that it is not displayed anymore.
         * Can be used to output things while still having the bar display at
         * the bottom of the commanc line
         *
         * Ex:
         *  WaitingBar p('=', 0.2,10); 
         *  for (int i = 0; i < 30; i++) {
         *     p.Clear(); 
         *     cout << i << " seconds elapsed" << endl;
         *     p.Show();
         *     sleep(1);
         *  }
         */
        void Clear();

    private:
        void ChangeDirection();
    
};
#endif
