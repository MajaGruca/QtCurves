#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.spinScale->setValue(ui.renderArea->getScale());
    ui.spinInterval->setValue(ui.renderArea->getIntervalLength());
    ui.spinStep->setValue(ui.renderArea->getStepCount());
}

MainWindow::~MainWindow() {}

void MainWindow::on_btnAstroid_clicked()
{
    update_ui(RenderArea::ShapeType::Astroid);
}

void MainWindow::on_btnCycloid_clicked()
{
    update_ui(RenderArea::ShapeType::Cycloid);
}

void MainWindow::on_btnHuygens_clicked()
{
    update_ui(RenderArea::ShapeType::HuygensCycloid);
}

void MainWindow::on_btnHypo_clicked()
{
    update_ui(RenderArea::ShapeType::HypoCycloid);
}

void MainWindow::on_btnLine_clicked()
{
    update_ui(RenderArea::ShapeType::Line);
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    ui.renderArea->setScale(scale);
    ui.renderArea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    ui.renderArea->setIntervalLength(interval);
    ui.renderArea->repaint();
}

void MainWindow::on_spinStep_valueChanged(int step)
{
    ui.renderArea->setStepCount(step);
    ui.renderArea->repaint();
}

void MainWindow::update_ui(RenderArea::ShapeType shapeType)
{
    ui.renderArea->setShape(shapeType);
    ui.renderArea->repaint();
    ui.spinScale->setValue(ui.renderArea->getScale());
    ui.spinInterval->setValue(ui.renderArea->getIntervalLength());
    ui.spinStep->setValue(ui.renderArea->getStepCount());
}
