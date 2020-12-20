#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void receiveData(QString);
    void on_pushButton_reset_clicked();

    void on_pushButton_thoat_clicked();

private:
    Ui::MainWindow *ui;
    Form *a = new Form();

    bool isSoNguyen(QString);

    int tong = 0;
    int tongChan = 0;
    int tongLe = 0;
    QString daySo;
};
#endif // MAINWINDOW_H
