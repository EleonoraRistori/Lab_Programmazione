#include <QApplication>
#include "View.h"
#include "FileLoader.h"


int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    FileLoader loader;
    View window(&loader);
    window.show();
    return app.exec();
}
