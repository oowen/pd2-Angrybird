#ifndef THANKS_H
#define THANKS_H

#include <QWidget>

namespace Ui {
class THANKS;
}

class THANKS : public QWidget
{
    Q_OBJECT

public:
    explicit THANKS(QWidget *parent = 0);
    ~THANKS();

private:
    Ui::THANKS *ui;
};

#endif // THANKS_H
