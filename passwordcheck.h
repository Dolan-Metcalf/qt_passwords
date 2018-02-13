#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

class PasswordCheck: public QWidget
{
    Q_OBJECT
    public:
        PasswordCheck();

    public slots:
        void setValidation();

    private:        
        QLineEdit* enterPassword;        
        QCheckBox* rule1;
        QCheckBox* rule2;
        QCheckBox* rule3;
        QPushButton *enter;
        QLabel *output;

        QRegExp validation1_1;
        QRegExp validation1_2;
        QRegExp validation2;
        QRegExp validation3;

        void setGUI();
};
#endif
