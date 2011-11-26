#pragma once

#include <QtGui/QMainWindow>
#include <QtWebKit/QWebView>
#include <QtGui/QLineEdit>

class Browser : public QMainWindow
{
    Q_OBJECT

public:
    Browser(const QUrl& url);
    ~Browser();

protected slots:
    void adjustLocation();
    void changeLocation();
    void adjustTitle();

private:
    QWebView *view;
    QLineEdit *addressLine;
};
