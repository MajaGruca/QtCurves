#pragma once

#include <QWidget>
#include <QColor>
#include "ui_RenderArea.h"

class RenderArea : public QWidget
{
	Q_OBJECT

public:
	RenderArea(QWidget *parent = nullptr);
	~RenderArea();

	QSize minimumSizeHint() const Q_DECL_OVERRIDE;
	QSize sizeHint() const Q_DECL_OVERRIDE;

	enum class ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line };

	void setBackgroundColor(QColor color) { mBackgroundColor = color; }
	QColor getBackgroundColor() const { return mBackgroundColor; }

	void setShapeColor(QColor color) { mShapeColor = color; }
	QColor getShapeColor() const { return mShapeColor; }

	void setShape(ShapeType shape) { mShape = shape; on_shape_changed(); }
	ShapeType getShape() const { return mShape; }

	void setScale(float scale) { mScale = scale; }
	float getScale() const { return mScale; }

	void setIntervalLength(float interval) { mIntervalLength = interval; }
	float getIntervalLength() const { return mIntervalLength; }

	void setStepCount(int step) { mStepCount = step; }
	int getStepCount() const { return mStepCount; }

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	Ui::RenderAreaClass ui;
	QColor mBackgroundColor;
	QColor mShapeColor;
	ShapeType mShape;

	float mIntervalLength;
	float mScale;
	int mStepCount;

	void on_shape_changed();
	QPointF compute(float t);
	QPointF compute_astroid(float t);
	QPointF compute_cycloid(float t);
	QPointF compute_huygens(float t);
	QPointF compute_hypo(float t);
	QPointF compute_line(float t);
};
