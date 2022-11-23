#include "MainWindow.h"
#include <QColorDialog>
#include "StyleSheetGenerator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.sliderScale->setValue(ui.renderArea->getScale() * 10.f);
    ui.spinInterval->setValue(ui.renderArea->getIntervalLength());
    setMinimumSize(570, 300);
    setStyleSheet(StyleSheetGenerator::mainWindowStyle(ui.renderArea->getBackgroundColor()));
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

void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui.renderArea->getShapeColor(), this, "Select line color");
    if (color.isValid())
    {
        ui.renderArea->setShapeColor(color);
        ui.renderArea->repaint();
    }
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui.renderArea->getBackgroundColor(), this, "Select background color");
    if (color.isValid())
    {
        ui.renderArea->setBackgroundColor(color);
        setStyleSheet(StyleSheetGenerator::mainWindowStyle(color));
        ui.renderArea->repaint();
    }
}

void MainWindow::on_sliderScale_valueChanged(int scale)
{
    ui.renderArea->setScale(scale / 10.f);
    ui.renderArea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    ui.renderArea->setIntervalLength(interval);
    ui.renderArea->repaint();
}

void MainWindow::on_sliderStep_valueChanged(int step)
{
    ui.renderArea->setStepCount(step);
    ui.renderArea->repaint();
}

void MainWindow::update_ui(RenderArea::ShapeType shapeType)
{
    ui.renderArea->setShape(shapeType);
    ui.renderArea->repaint();
    ui.sliderScale->setValue(ui.renderArea->getScale() * 10.f);
    ui.spinInterval->setValue(ui.renderArea->getIntervalLength());
    ui.sliderStep->setValue(ui.renderArea->getStepCount());
}
