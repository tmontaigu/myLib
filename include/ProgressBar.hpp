#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

/*
 *  ProgressBar class, this class is used to display a progress bar in the command line.
 *  Best to be used in a loop / recursion
 *
 *  When it reaches 100% or when you want to display something else
 *  don't forget to use std::cout << endl;
 */

class ProgressBar {

	/* Members */
	private:
		char progressSign;
		char barHead;
        int barWidth;

	/* constructors & Destructors*/
	public:
        /*
         * Creates a progress bar with the default parameters:
         * barWidth : 70
         * barHead : '>'
         * progressSign : '='
         * the bar will look like this: [======>     ]
         *
         */
		ProgressBar();
        /*
         * Creates a progress bar with the look that you want it to have.
         * barWidth is optionnal.
         *
         * Examples : ProgressBar('#','~'); -> [#######~     ]
         *            ProgressBar('#','#'); -> [########     ]
         *
         */
		ProgressBar(char progressSign, char barHead, int barWidth = 70);
		~ProgressBar();

    /* Methods */
    public:
        /*
         * Shows the progress on the command line with the given progress,
         * it also prints the percentage.
         *
         * /!\  progress is a float : 0 < progress < 1  /!\
         *
         * Example:
         *    progressBar.ShowProgress(0.5) -> [===>   ] (50%)
         */
        void ShowProgress(float progress);
        /*
         * Shows the progress on the command line with th given progess,
         * it also prints the percentage.
         * currentTask : number of the current iteration, task, etc
         * max: maximum number of tasks, iterations, task
         *
         * The idea is  that currentTask/max == 100%
         *
         * /!\  progress is a float : 0 < progress < 1  /!\
         *
         * Example : 
         * for (int i = 0; i < 100; i++) {
         *   progressBar.showProgress( (float) i/100, (i+1), 100)
         * }
         *  given (i = 50) -> [===>   ] (50%) ( 50/100) 
         *
         */ 
        void ShowProgress(float progress, int currentTask, int max);
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

};
#endif
