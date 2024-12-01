#include <QApplication>
#include "MainWindow.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Initialize the Qt application

    MainWindow MW;         // Create an instance of MainWindow
    MW.show();// Show the main window

    return app.exec();             // Enter the Qt event loop
}