#include <QtWidgets>
#include "passwordcheck.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswordCheck pwd;
    pwd.show();
    return a.exec();
}
