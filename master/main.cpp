#include"dialog.h"
#include"master.h"
#include<QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Dialog dialog;
    dialog.show();

    return app.exec();
}
