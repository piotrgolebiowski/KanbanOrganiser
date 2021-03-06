#include "windowmain.h"

#include <QApplication>

#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	QFile f(":/themes/resources/theme/output/dark.css");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		a.setStyleSheet(ts.readAll());
	}

	WindowMain w;
	w.show();
	return a.exec();
}
