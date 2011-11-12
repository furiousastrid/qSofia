#include "browser.h"
#include <QFile>
#include <QtGui/QToolBar>

Browser::Browser(const QUrl& url)
{
    view = new QWebView(this);
        view->load(url);
        connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
        connect(view, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
        connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustTitle()));
        setCentralWidget(view);

    addressLine = new QLineEdit(this);
        addressLine->setSizePolicy(QSizePolicy::Expanding, addressLine->sizePolicy().verticalPolicy());
        connect(addressLine, SIGNAL(returnPressed()), SLOT(changeLocation()));

    QToolBar *toolBar = addToolBar(tr("Navigation"));
        toolBar->addAction(view->pageAction(QWebPage::Back));
        toolBar->addAction(view->pageAction(QWebPage::Forward));
        toolBar->addAction(view->pageAction(QWebPage::Reload));
        toolBar->addAction(view->pageAction(QWebPage::Stop));
        toolBar->addWidget(addressLine);
}

void Browser::adjustLocation()
{
    addressLine->setText(view->url().toString());
}

void Browser::changeLocation()
{
    QUrl url = QUrl(addressLine->text());
    view->load(url);
    view->setFocus();
}

void Browser::adjustTitle()
{
    setWindowTitle(view->title());
}

Browser::~Browser()
{

}
