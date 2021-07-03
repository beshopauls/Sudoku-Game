#include "mainwindow.h"
#include "ui_mainwindow.h"

sudoku::matrix matx;
//Constractor;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sudoku");
    matx.NewPuzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.ReadNumber(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.ReadNumber(i, j))
            {
                QColor c(158, 163, 255);
                Cell->setBackgroundColor(c);
            }
        }
    }
    ui->label->setText("Row & Colum");
}
//This for Color tableWidget;
void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
               QTableWidgetItem*co= ui->table->item(i,j);
               co->setBackgroundColor(color);
            }
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.ReadNumber(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.ReadNumber(i, j))
            {
                QColor c(158, 163, 255);
                Cell->setBackgroundColor(c);
            }
        }
    }
}
//This for Color Button;
void MainWindow::on_actionColor_Buttons_triggered()
{
    //Group color;
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    QPalette pal;
    //Button 1;
    pal= ui->PushButton_1->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_1->setAutoFillBackground(true);
    ui->PushButton_1->setPalette(pal);
    ui->PushButton_1->update();
    //Button 2;
    pal= ui->PushButton_2->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_2->setAutoFillBackground(true);
    ui->PushButton_2->setPalette(pal);
    ui->PushButton_2->update();
    //Button 3;
    pal= ui->PushButton_3->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_3->setAutoFillBackground(true);
    ui->PushButton_3->setPalette(pal);
    ui->PushButton_3->update();
    //Butto 4;
    pal= ui->PushButton_4->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_4->setAutoFillBackground(true);
    ui->PushButton_4->setPalette(pal);
    ui->PushButton_4->update();
    //Button 5;
    pal= ui->PushButton_5->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_5->setAutoFillBackground(true);
    ui->PushButton_5->setPalette(pal);
    ui->PushButton_5->update();
    //Button 6;
    pal= ui->PushButton_6->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_6->setAutoFillBackground(true);
    ui->PushButton_6->setPalette(pal);
    ui->PushButton_6->update();
    //Button 7;
    pal= ui->PushButton_7->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_7->setAutoFillBackground(true);
    ui->PushButton_7->setPalette(pal);
    ui->PushButton_7->update();
    //Button 8;
    pal= ui->PushButton_8->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_8->setAutoFillBackground(true);
    ui->PushButton_8->setPalette(pal);
    ui->PushButton_8->update();
    //Button 9;
    pal= ui->PushButton_9->palette();
    pal.setColor(QPalette::Button, QColor(color));
    ui->PushButton_9->setAutoFillBackground(true);
    ui->PushButton_9->setPalette(pal);
    ui->PushButton_9->update();
}
//This is for Help Window;
void MainWindow::on_actionHow_to_play_triggered()
{
    QMessageBox::about(this,"Help","  How to solve the puzzle, you must first read a lot about this puzzle and"
                                   "you can read from this link\n"
                                   "https://en.wikipedia.org/wiki/Sudoku, In the event that it is difficult to reach a specific part of the puzzle,\n"
                                   "you can use the solve button."
                                   "In the event that you want to start over, you can press the reste button, but in the event that you want to change the puzzle,\n"
                                   "you can go to the menu and choose the new game."
                                   "I wish you success in solving the puzzle Beshoy Pauls !");

}
//This for write Row and Colum ;
void MainWindow::on_table_cellClicked(int row, int colum)
{
    Row = row;
    Colum = colum;
    QString str = "";
    str += '0' + row;
    str += ',';
    str += '0' + colum;
    const QString cstr = str;
    ui->label->setText(cstr);
}
void MainWindow::ClickOnButton(int num)
{
    QTableWidgetItem* Cell = ui->table->item(Row, Colum);
    matx.WriteNumber(Row, Colum, num);
    QString str = "";
    str += '0' + matx.ReadNumber(Row, Colum);
    const QString cstr = str;
    Cell->setText(cstr);
    if (matx.YouWon())
    {
         QMessageBox::about(this,"Cogratulations","Amazing You Won\n"
                                                  "Thanks For You\n");
    }
}
//This for click Button 1;
void MainWindow::on_PushButton_1_clicked()
{
   ClickOnButton(1);
}
//This for click Button 2;
void MainWindow::on_PushButton_2_clicked()
{
    ClickOnButton(2);
}
//This for click Button 3;
void MainWindow::on_PushButton_3_clicked()
{
    ClickOnButton(3);
}
//This for click Button 4;
void MainWindow::on_PushButton_4_clicked()
{
    ClickOnButton(4);
}
//This for click Button 5;
void MainWindow::on_PushButton_5_clicked()
{
    ClickOnButton(5);
}
//This for click Button 6;
void MainWindow::on_PushButton_6_clicked()
{
    ClickOnButton(6);
}
//This for click Button 7;
void MainWindow::on_PushButton_7_clicked()
{
    ClickOnButton(7);
}
//This for click Button 8;
void MainWindow::on_PushButton_8_clicked()
{
    ClickOnButton(8);
}
//This for click Button 9;
void MainWindow::on_PushButton_9_clicked()
{
    ClickOnButton(9);
}
//this for Button Solve if user needed Hint;
void MainWindow::on_solve_clicked()
{
    matx.Reset();
    matx.SolvePuzzle();
    for (int i = 0; i < 9; ++i)
	{
        for (int j = 0; j < 9; ++j)
		{
			QTableWidgetItem* Cell = ui->table->item(i, j);
			QString str = "";
            str += '0' + matx.ReadNumber(i,j);
			const QString cstr = str;
			Cell->setText(cstr);
		}
	}
}
//This for New Game if user want play again ;
void MainWindow::on_actionNew_game_triggered()
{
    matx.NewPuzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.ReadNumber(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.ReadNumber(i, j))
            {
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        QTableWidgetItem* Cell = ui->table->item(i, j);
                        QString str = "";
                        str += '0' + matx.ReadNumber(i, j);
                        const QString cstr = str;
                        Cell->setText(cstr);
                        if (matx.ReadNumber(i, j))
                        {
                            QColor c(158, 163, 255);
                            Cell->setBackgroundColor(c);
                        }
                    }
                }

            }
            else
            {
                for (int i = 0; i < 9; ++i)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        QTableWidgetItem* Cell = ui->table->item(i, j);
                        QString str = "";
                        str += '0' + matx.ReadNumber(i, j);
                        const QString cstr = str;
                        Cell->setText(cstr);
                        if (matx.ReadNumber(i, j))
                        {
                            QColor c(158, 163, 255);
                            Cell->setBackgroundColor(c);
                        }
                    }
                }
            }
        }
    }
}
//This for Button Reset;
void MainWindow::on_pushButton_clicked()
{
    matx.Reset();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.ReadNumber(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}

//Distractor;
MainWindow::~MainWindow()
{
    delete ui;
}
