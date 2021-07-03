#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include "matrix.h"
#include<QColormap>
#include<QLabel>
#include <QVBoxLayout>
#include<QtCore>
#include<QtGui>
#include <QPushButton>
#include<QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PushButton_1_clicked();
    void on_PushButton_2_clicked();
    void on_PushButton_3_clicked();
    void on_PushButton_4_clicked();
    void on_PushButton_5_clicked();
    void on_PushButton_6_clicked();
    void on_PushButton_7_clicked();
    void on_PushButton_8_clicked();
    void on_PushButton_9_clicked();
    void on_table_cellClicked(int row, int column);
    void on_actionColor_triggered();

    void on_actionColor_Buttons_triggered();

    void on_actionHow_to_play_triggered();

    void on_solve_clicked();

    void on_actionNew_game_triggered();

    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    int Colum, Row;
    void ClickOnButton(int num);
};

#endif // MAINWINDOW_H
