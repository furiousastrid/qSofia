#include <QtGui/QApplication>
#include "browser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Browser myBrowser(QUrl("http://www.google.com"));
    myBrowser.show();

    return a.exec();
}
