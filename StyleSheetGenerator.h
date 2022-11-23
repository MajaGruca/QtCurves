#pragma once

#include <QColor>

class StyleSheetGenerator final
{
public:
	static const QString mainWindowStyle(QColor color);

private:
	StyleSheetGenerator() {}
};

