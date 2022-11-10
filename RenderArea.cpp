#include "RenderArea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
	QWidget(parent),
	mBackgroundColor(Qt::black),
	mShapeColor(Qt::white),
	mShape(ShapeType::Astroid)
{
	ui.setupUi(this);
}

RenderArea::~RenderArea() {}

QSize RenderArea::minimumSizeHint() const
{
	return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
	return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);

	switch (mShape) {
	case ShapeType::Astroid:
		mBackgroundColor = Qt::red;
		break;

	case ShapeType::Cycloid:
		mBackgroundColor = Qt::green;
		break;

	case ShapeType::HuygensCycloid:
		mBackgroundColor = Qt::blue;
		break;

	case ShapeType::HypoCycloid:
		mBackgroundColor = Qt::yellow;
		break;

	default:
		break;
	}

	painter.setBrush(mBackgroundColor);
	painter.setPen(mShapeColor);

	painter.drawRect(this->rect());
	painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
