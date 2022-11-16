#include "RenderArea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
	QWidget(parent),
	mBackgroundColor(Qt::red),
	mShapeColor(Qt::black),
	mShape(ShapeType::Astroid),
	mIntervalLength(2 * M_PI),
	mScale(60.f),
	mStepCount(256)
{
	ui.setupUi(this);
}

RenderArea::~RenderArea() {}

void RenderArea::on_shape_changed()
{
	switch (mShape) {
	case ShapeType::Astroid:
		mScale = 60.f;
		mIntervalLength = 2 * M_PI;
		mStepCount = 256;
		break;

	case ShapeType::Cycloid:
		mScale = 5.f;
		mIntervalLength = 6 * M_PI;
		mStepCount = 128;
		break;

	case ShapeType::HuygensCycloid:
		mScale = 8.f;
		mIntervalLength = 4 * M_PI;
		mStepCount = 256;
		break;

	case ShapeType::HypoCycloid:
		mScale = 40.f;
		mIntervalLength = 2 * M_PI;
		mStepCount = 256;
		break;

	case ShapeType::Line:
		mScale = 100.f;
		mIntervalLength = 3;
		mStepCount = 128;
		break;

	default:
		break;
	}
}

QPointF RenderArea::compute(float t)
{
	switch (mShape) {
	case ShapeType::Astroid:
		return compute_astroid(t);

	case ShapeType::Cycloid:
		return compute_cycloid(t);

	case ShapeType::HuygensCycloid:
		return compute_huygens(t);

	case ShapeType::HypoCycloid:
		return compute_hypo(t);

	case ShapeType::Line:
		return compute_line(t);

	default:
		break;
	}

	return QPointF(0.f, 0.f);
}

QPointF RenderArea::compute_astroid(float t)
{
	float cos_t = cos(t);
	float sin_t = sin(t);
	float x = 2 * pow(cos_t, 3);
	float y = 2 * pow(sin_t, 3);
	return QPointF(x, y);
}

QPointF RenderArea::compute_cycloid(float t)
{
	return QPointF(1.5 * (1 - cos(t)),
				   1.5 * (t - sin(t)));
}

QPointF RenderArea::compute_huygens(float t)
{
	return QPointF(4 * (3 * cos(t) - cos(3 * t)),
				   4 * (3 * sin(t) - sin(3 * t)));
}

QPointF RenderArea::compute_hypo(float t)
{
	return QPointF(1.5 * (2 * cos(t) + cos(2 * t)),
				   1.5 * (2 * sin(t) - sin(2 * t)));
}

QPointF RenderArea::compute_line(float t)
{
	return QPointF(t - 1.5, t - 1.5);
}

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

	painter.setBrush(mBackgroundColor);
	painter.setPen(mShapeColor);

	painter.drawRect(this->rect());

	QPoint center = this->rect().center();

	float step = mIntervalLength / mStepCount;

	QPointF startPoint = compute(0);
	QPoint prevPixel;
	prevPixel.setX(startPoint.x() * mScale + center.x());
	prevPixel.setY(startPoint.y() * mScale + center.y());
	
	for (float t = step; t < mIntervalLength; t += step)
	{
		QPointF point = compute(t);

		QPoint pixel;
		pixel.setX(point.x() * mScale + center.x());
		pixel.setY(point.y() * mScale + center.y());

		painter.drawLine(pixel, prevPixel);
		prevPixel = pixel;
	}
}
