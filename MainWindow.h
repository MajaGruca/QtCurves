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
    void on_sliderScale_valueChanged(int scale);
    void on_spinInterval_valueChanged(double interval);
    void on_sliderStep_valueChanged(int step);

private:
    Ui::MainWindowClass ui;

    void update_ui(RenderArea::ShapeType shapeType);
};
