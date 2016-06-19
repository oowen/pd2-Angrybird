#include "resultwindow.h"
#include "ui_resultwindow.h"

resultwindow::resultwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultwindow)
{
    ui->setupUi(this);
}

resultwindow::~resultwindow()
{
    delete ui;
}
