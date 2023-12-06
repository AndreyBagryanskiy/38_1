#include "soundRedButton.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SoundRedButton redButton(nullptr);

    redButton.setFixedSize(100, 100);
    redButton.move(1000,400);

    QObject::connect(&redButton, &QPushButton::clicked, [](){std::cout <<"clicked" << std::endl;});

    redButton.show();

    return a.exec();
}
