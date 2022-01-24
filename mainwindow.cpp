#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // totKalkulasi = 0;
    // tempNilai = 0;
    // iter = 0;

    // tempNilai.resize(iter + 1);

    divClick = false;
    multClick = false;
    addClick = false;
    minClick = false;
    modClick = false;

    ui->hasilBar->setText(QString::number(valButton));
    //inisialisasi nilai awal = 0
    // tempNilai[iter] = 0;

    QPushButton *numButtons[10];

    // Cycle through locating the buttons
    for (int i = 0; i < 10; ++i)
    {
        QString butName = "Button" + QString::number(i);

        // Get the buttons by name and add to array
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);

        // When the button is released call num_pressed()
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(numPressed()));
    }

    // connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::clearButton_isClicked);
    // connect(ui->pushButton_Erase, &QPushButton::clicked, this, &MainWindow::eraseButton_isClicked);
    // connect(ui->pushButton_eqTo, &QPushButton::clicked, this, &MainWindow::eqToButton_isClicked);
    connect(ui->pushButton_Plus, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->pushButton_Min, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->pushButton_Mult, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->pushButton_Div, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->pushButton_Modulo, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui->pushButton_eqTo, SIGNAL(released()), this,
            SLOT(eqToButton_isClicked()));

    connect(ui->pushButton_plusMin, SIGNAL(released()), this,
            SLOT(ChangeNumSign()));

    //angka
    // connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::angka0);
    // connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::angka1);
    // connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::angka2);
    // connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::angka3);
    // connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::angka4);
    // connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::angka5);
    // connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::angka6);
    // connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::angka7);
    // connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::angka8);
    // connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::angka9);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearButton_isClicked()
{
    ui->hasilBar->setText("0");
    // tempNilai.at(iter) = 0;
}

void MainWindow::eraseButton_isClicked()
{
}

// void MainWindow::moduloButton_isClicked()
// {
// }

// void MainWindow::plusButton_isClicked()
// {
//     QMatOperator = "+";
//     ui->hasilBar->setText(QMatOperator);

//     matOperator = QMatOperator.toStdString();

//     totKalkulasi = tempNilai[iter] + tempNilai[iter + 1];
// }

void MainWindow::numPressed()
{

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    QString displayVal = ui->hasilBar->text();

    if ((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0))
    {

        // calcVal = butVal.toDouble();
        ui->hasilBar->setText(butVal);
    }
    else
    {
        // Put the new number to the right of whats there
        QString newVal = displayVal + butVal;

        // Double version of number
        double dblNewVal = newVal.toDouble();

        // calcVal = newVal.toDouble();

        // Set value in display and allow up to 16
        // digits before using exponents
        ui->hasilBar->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void MainWindow::mathOperator()
{
    divClick = false;
    multClick = false;
    addClick = false;
    minClick = false;
    modClick = false;

    QString displayVal = ui->hasilBar->text();
    valButton = displayVal.toDouble();

    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if (QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
    {
        divClick = true;
    }
    else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
    {
        multClick = true;
    }
    else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
    {
        addClick = true;
    }
    else if (QString::compare(butVal, "-", Qt::CaseInsensitive) == 0)
    {
        minClick = true;
    }
    else if (QString::compare(butVal, "%", Qt::CaseInsensitive) == 0)
    {
        modClick = true;
    }

    ui->hasilBar->setText("");
}

void MainWindow::eqToButton_isClicked()
{
    double solution = 0.0;

    // Get value in display
    QString displayVal = ui->hasilBar->text();
    double dblDisplayVal = displayVal.toDouble();

    if (addClick || minClick || multClick || divClick || modClick)
    {
        if (addClick)
        {
            solution = valButton + dblDisplayVal;
        }
        else if (minClick)
        {
            solution = valButton - dblDisplayVal;
        }
        else if (multClick)
        {
            solution = valButton * dblDisplayVal;
        }
        else if (divClick)
        {
            solution = valButton / dblDisplayVal;
        }
        else if (modClick)
        {
            solution = int(valButton) % int(dblDisplayVal);
        }
    }

    ui->hasilBar->setText(QString::number(solution));
}

void MainWindow::changeNumSign()
{
    QString displayVal = ui->hasilBar->text();

    // Regular expression checks if it is a number
    // plus sign
    QRegExp reg("[-+]?[0-9.]*");

    // If it is a number change the sign
    if (reg.exactMatch(displayVal))
    {
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        ui->hasilBar->setText(QString::number(dblDisplayValSign));
    }
}

// void MainWindow::angka0()
// {
//     ui->hasilBar->setText("0");
//     iter++;
//     tempNilai[iter] = 0;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka1()
// {
//     ui->hasilBar->setText("1");
//     iter++;
//     tempNilai[iter] = 1;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka2()
// {
//     ui->hasilBar->setText("2");
//     iter++;
//     tempNilai[iter] = 2;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka3()
// {
//     ui->hasilBar->setText("3");
//     iter++;
//     tempNilai[iter] = 3;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka4()
// {
//     ui->hasilBar->setText("4");
//     iter++;
//     tempNilai[iter] = 4;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka5()
// {
//     ui->hasilBar->setText("5");
//     iter++;
//     tempNilai[iter] = 5;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka6()
// {
//     ui->hasilBar->setText("6");
//     iter++;
//     tempNilai[iter] = 6;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka7()
// {
//     ui->hasilBar->setText("7");
//     iter++;
//     tempNilai[iter] = 7;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka8()
// {
//     ui->hasilBar->setText("8");
//     iter++;
//     tempNilai[iter] = 8;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }

// void MainWindow::angka9()
// {
//     ui->hasilBar->setText("9");
//     iter++;
//     tempNilai[iter] = 9;
//     // cout << "HASIL ITER: " << iter << endl;
//     // cout << "HASIL TEMP NILAI: " << tempNilai[iter] << endl;
// }