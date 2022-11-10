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

	enum class ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid };

	void setBackgroundColor(QColor color) { mBackgroundColor = color; }
	QColor getBackgroundColor() const { return mBackgroundColor; }

	void setShapeColor(QColor color) { mShapeColor = color; }
	QColor getShapeColor() const { return mShapeColor; }

	void setShape(ShapeType shape) { mShape = shape; }
	ShapeType getShape() const { return mShape; }

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
	Ui::RenderAreaClass ui;
	QColor mBackgroundColor;
	QColor mShapeColor;
	ShapeType mShape;
};
