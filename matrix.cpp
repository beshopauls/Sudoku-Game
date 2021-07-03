#include "matrix.h"
sudoku::matrix::matrix(int (*mat)[10]):R()
{
    Input(mat);
}

sudoku::matrix::matrix()
{
    for (int i = 0; i < 9; ++i)
    {
        this->row[i] = this->col[i] = 0;
        this->block[i/3][i%3] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            this->obj[i][j] = 0;
        }
    }
}
//this function for calculate closed places and inseder numbers in this palces ;
void sudoku::matrix::Init()
{
	for (int i = 0; i < 9; ++i)
	{
		this->row[i] = this->col[i] = 0;
		this->block[i/3][i%3] = 0;
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if(this->obj[i][j])
			{
				int sig = (1 << (obj[i][j] - 1));
				this->row[i] |= sig;
				this->col[j] |= sig;
				this->block[i/3][j/3] |= sig;
                this->N[i][j] = 1;
			}
            else this->N[i][j] = 0;
		}
	}
}
int sudoku::matrix::Input(int (*mat)[10])
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			this->obj[i][j] = mat[i][j];
		}
	}
    return 1;
}


//This function for solve the puzzel and it to help user in geting hint;
int sudoku::matrix::FoundSolve(int ni, int nj)
{
	if (this->obj[ni][nj])
	{
		if (nj+1 < 9)
            return FoundSolve(ni, nj+1);
		else if (ni+1 < 9)
            return FoundSolve(ni+1, 0);
		else
			return 1;
    }
    else
	{
		int sig = this->row[ni] | this->col[nj] | this->block[ni/3][nj/3];
        this->R.narray();
		for (int i = 0; i < 9; ++i)
		{
            int ri = this->R.Read(i);
			int sign = (1<<(ri-1));
			if (!(sig & sign))
			{
                this->obj[ni][nj] = ri;
				this->row[ni] |= sign;
				this->col[nj] |= sign;
				this->block[ni/3][nj/3] |= sign;
				if (nj+1 < 9)
				{
                    if (FoundSolve(ni, nj+1) > 0)
						return 1;
				}
				else if (ni+1 < 9)
				{
                    if (FoundSolve(ni+1, 0) > 0)
						return 1;
				}
				else
				{
					return 1;
				}
				this->obj[ni][nj] = 0;
				this->row[ni] ^= sign;
				this->col[nj] ^= sign;
				this->block[ni/3][nj/3] ^= sign;
			}
		}
		return -1;
	}
}

void sudoku::matrix::SolvePuzzle()
{
    Init();
    FoundSolve(0, 0);
}

int sudoku::matrix::Output(int (*mat)[10])
{
	int res = 1;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			mat[i][j] = this->obj[i][j];
			res = res && mat[i][j];
		}
	}
	return res;
}
//this function for write answer in table ;
void sudoku::matrix::WriteNumber(int i, int j, int val)
{
    if (N[i][j])
		return;
	this->obj[i][j] = val;
}

int sudoku::matrix::ReadNumber(int i, int j)
{
    return this->obj[i][j];
}

void sudoku::matrix::Empty()
{
    for (int i = 0; i < 9; ++i)
    {
        this->row[i] = this->col[i] = 0;
        this->block[i/3][i%3] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            this->obj[i][j] = 0;
        }
    }
}
//this function for check all answer user if all answer correct it is meening he won;
bool sudoku::matrix::YouWon()
{
	for (int i = 0; i < 9; ++i)
	{
		row[i] = 0;
		col[i] = 0;
		block[i/3][i%3] = 0;
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int sig = row[i] | col[j] | block[i/3][j/3];
            int sgn = (1 << (obj[i][j] - 1));
			if (!(sig&sgn))
			{
				row[i] |= sgn;
				col[j] |= sgn;
				block[i/3][j/3] |= sgn;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
//This function for set new numbers in other palces by function random;
//it is meening add new round;
void sudoku::matrix::NewPuzzle()
{
    Empty();
    SolvePuzzle();
    int rdbox = rand()%10 + 40;
	for (int k = 0; k < rdbox; ++k)
	{
		int i = rand()%9;
		int j = rand()%9;
		while(!obj[i][j])
		{
			i = rand()%9;
			j = rand()%9;
		}
		obj[i][j] = 0;
	}
    Init();
}
//this function for delete all number user writed;
void sudoku::matrix::Reset()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (!N[i][j])
                obj[i][j] = 0;
        }
    }
}
