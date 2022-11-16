#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();
    void on_btnCycloid_clicked();
    void on_btnHuygens_clicked();
    void on_btnHypo_clicked();
    void on_btnLine_clicked();

private:
    Ui::MainWindowClass ui;
};
