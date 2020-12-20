#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(a, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    a->show();
}

bool MainWindow::isSoNguyen(QString str)
{
    if(str.length() == 0)
    {
        return false;
    }
    if((str.at(0) < '0' || str.at(0) > '9') && str.at(0) != '-')
    {
        return false;
    }
    if(str.at(0) == '-' && str.length() == 1)
    {
        return false;
    }
    for(int i = 1;i < str.length(); i++)
    {
        if(str.at(i) < '0' || str.at(i) > '9')
        {
            return false;
        }
    }
    return true;
}

void MainWindow::receiveData(QString str)
{
    if(isSoNguyen(str))
    {
        daySo += str;
        daySo += " ";
        ui->lineEdit_nhap->setText(daySo);
        tong += str.toInt();
        if(str.toInt() % 2 == 0)
        {
            tongChan += str.toInt();
        } else
        {
            tongLe += str.toInt();
        }
    } else
    {
        QMessageBox a;
        a.setWindowTitle("Close");
        a.setText("KHONG PHAI SO NGUYEN???!!!");
        a.setInformativeText("Nhan Yes de close");
        a.setStandardButtons(QMessageBox::Yes);
        a.setDefaultButton(QMessageBox::Yes);
        a.setIcon(QMessageBox::Warning);
        int ketQua = a.exec();
        switch (ketQua)
            case QMessageBox::Yes:
            close();

        }
    ui->lineEdit_tong->setText(QString::number(tong));
    ui->lineEdit_tongChan->setText(QString::number(tongChan));
    ui->lineEdit_tongLe->setText(QString::number(tongLe));
    }

void MainWindow::on_pushButton_reset_clicked()
{
    tong = 0;
    tongChan = 0;
    tongLe = 0;
    daySo = "";
    ui->lineEdit_nhap->setText("");
    ui->lineEdit_tong->setText("");
    ui->lineEdit_tongChan->setText("");
    ui->lineEdit_tongLe->setText("");
}

void MainWindow::on_pushButton_thoat_clicked()
{
    QMessageBox a;
    a.setWindowTitle("Close");
    a.setText("Ban co muon close khong?");
    a.setInformativeText("Nhan Yes de close");
    a.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    a.setDefaultButton(QMessageBox::No);
    a.setIcon(QMessageBox::Warning);
    int ketQua = a.exec();
    switch (ketQua) {
        case QMessageBox::Yes:
        close();
        break;
    case QMessageBox::No:
        break;
    }
}
