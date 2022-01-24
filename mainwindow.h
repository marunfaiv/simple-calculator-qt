#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include <QDebug>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    string getString(string);

public slots:
    // tombol operator
    void clearButton_isClicked();
    void eraseButton_isClicked();
    // void moduloButton_isClicked();
    // void plusButton_isClicked();
    // void minButton_isClicked();
    // void divButton_isClicked();
    // void multButton_isClicked();
    void eqToButton_isClicked();
    // void plusMinButton_isClicked();
    void mathOperator();
    void changeNumSign();

    //tombol angka
    void numPressed();

private:
    Ui::MainWindow *ui;
    // vector<int> tempNilai;
    // int totKalkulasi;
    // int iter;
    double valButton = 0.0;

    bool divClick, multClick, addClick, minClick, modClick;

    // QString QMatOperator;
    // string matOperator;
};
#endif // MAINWINDOW_H