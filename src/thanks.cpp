#include "thanks.h"
#include "ui_thanks.h"

THANKS::THANKS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::THANKS)
{
    ui->setupUi(this);
}

THANKS::~THANKS()
{
    delete ui;
}

