#include "passwordcheck.h"
#include <QRegExp>
#include <QButtonGroup>
#include <QVBoxLayout>

PasswordCheck::PasswordCheck()
{
    setGUI();
    validation1_1.setPattern(".{5,}");
    validation1_2.setPattern("\\s");
    validation2.setPattern("..[0-9a-fA-F]..");
    validation3.setPattern("[1-9][0-9]{3,5}");
    connect(enter, SIGNAL(clicked()), this, SLOT(setValidation()));
}

void PasswordCheck::setGUI()
{
    QVBoxLayout* layout=new QVBoxLayout;

    QLabel* password = new QLabel("Enter the password");
    enterPassword=new QLineEdit;
    enterPassword->setMaxLength(20);
    QLabel* validation=new QLabel("Select the Validation rule:");

    QStringList strings = QStringList()<< "Validation 1 [min 5 characters and no spaces]"
                      << "Validation 2 [5 characters, 3rd character digit or (a-fA-F)]"
                      << "Validation 3 [Minimum 4 and maximum 6 digits, the first digit non zero]";

    QButtonGroup* group = new QButtonGroup();
    rule1 = new QCheckBox(strings.at(0));
    rule2 = new QCheckBox(strings.at(1));
    rule3 = new QCheckBox(strings.at(2));
    group->addButton(rule1);
    group->addButton(rule2);
    group->addButton(rule3);
    group->setExclusive(true);
    rule1->setChecked(true);

    enter = new QPushButton("Validate");
    output = new QLabel(" ");

    layout->addWidget(password);
    layout->addWidget(enterPassword);
    layout->addWidget(validation);
    layout->addWidget(rule1);
    layout->addWidget(rule2);
    layout->addWidget(rule3);
    layout->addWidget(enter);
    layout->addWidget(output);

    setLayout(layout);
}

void PasswordCheck::setValidation()
{
    bool flag = false;

    if(rule1->isChecked())
       if((validation1_1.exactMatch(enterPassword->text()))&& ((validation1_2.indexIn(enterPassword->text()))==-1))
           flag = true;

    if(rule2->isChecked())
       if(validation2.exactMatch(enterPassword->text()))
          flag = true;

    if(rule3->isChecked())
        if(validation3.exactMatch(enterPassword->text()))
            flag = true;

    if (flag)
           output->setText("Password Valid");
        else
           output->setText("Password Invalid");
    enterPassword->setFocus();
}

