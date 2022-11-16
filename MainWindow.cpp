#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow() {}

void MainWindow::on_btnAstroid_clicked()
{
    ui.renderArea->setShape(RenderArea::ShapeType::Astroid);
    ui.renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    ui.renderArea->setShape(RenderArea::ShapeType::Cycloid);
    ui.renderArea->repaint();
}

void MainWindow::on_btnHuygens_clicked()
{
    ui.renderArea->setShape(RenderArea::ShapeType::HuygensCycloid);
    ui.renderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    ui.renderArea->setShape(RenderArea::ShapeType::HypoCycloid);
    ui.renderArea->repaint();
}

void MainWindow::on_btnLine_clicked()
{
    ui.renderArea->setShape(RenderArea::ShapeType::Line);
    ui.renderArea->repaint();
}