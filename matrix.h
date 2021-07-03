#ifndef _MATRIX
	#include "rdarray.h"
	
	#define _MATRIX
#endif

namespace sudoku{
	class matrix{
		public:
        matrix(int (*mat)[10]);
        matrix();
        void WriteNumber(int i, int j, int val);
        int ReadNumber(int i, int j);
        int Output(int (*mat)[10]);
        int Input(int (*mat)[10]);
        void NewPuzzle();
        void SolvePuzzle();
        void Reset();
        bool YouWon();

		private:
		int obj[10][10];
		int row[10];
		int col[10];
		int block[5][5];
        int N[10][10];
        sudoku::rdarray R;
        int FoundSolve(int ni, int nj);
        void Empty();
        void Init();
	};
}
