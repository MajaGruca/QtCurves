#include "StyleSheetGenerator.h"

const QString StyleSheetGenerator::mainWindowStyle(QColor color)
{
    const int btnSaturation = color.hsvSaturation() * 0.15;
    const int btnValue = color.value() < 120 ? color.value() * 2 : 240;
    QColor backgroundColor = QColor::fromHsv(color.hsvHue(), 5, 240);
    QColor textColor = color.value() < 70 ? Qt::white : Qt::black;
    QColor btnColor = QColor::fromHsv(color.hsvHue(), btnSaturation, btnValue);
    QColor pressedBtnColor = color.value() < 70 ? QColor::fromHsv(btnColor.hsvHue(), btnColor.hsvSaturation(), btnColor.value() + 50) : btnColor.darker(120);

    return "QMainWindow { background-color: " + backgroundColor.name() + "; } "
           "QPushButton { background-color: " + btnColor.name() + "; color: " + textColor.name() + "; font-family: Arial; font-size: 9pt; } "
           "QPushButton:pressed { background-color: " + pressedBtnColor.name() + "; } "
           "QSlider::handle { background-color: " + color.name() + "; }";
}
