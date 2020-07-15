//
// Created by eleonora on 14/07/20.
//

#include "View.h"

View::View(FileLoader *s) : subject(s) {
    attach();

    // set dimensions for the MainWindow
    setFixedSize(800, 400);
    setWindowTitle("File loader");

    // set the button
    button = new QPushButton("Start loading resources", this);
    button->setGeometry(QRect(QPoint(300, 150), QSize(200, 30)));

    // set the progressBar
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(100, 190), QSize(600, 30)));
    progressBar -> setRange(0,100);
    progressBar->setValue(0);


    label = new QLabel(this);
    label -> setWordWrap(true);
    label->setAlignment(Qt::AlignCenter);

    errorMessage = new QErrorMessage(this);

    connect(button, SIGNAL(released()), this, SLOT(startLoadingFiles()));

}

void View::startLoadingFiles() {
    std::list <const char*> files;
    files.push_back("Text.txt");
    files.push_back("Text2.txt");
    files.push_back("Image.svg");
    subject->loadFiles(files);
    if(progressBar->value() == 99)
        progressBar->setValue(100);

}

View::~View() {
    detach();
}

void View::attach() {
    subject -> addObserver(this);
}

void View::detach() {
    subject -> removeObserver(this);
}

void View::update() {
    if(subject->isLoaded1()) {
        progressBar->setValue(progressBar->value() + ((1.0 / subject->getNumFiles()) * 100));
        label->setGeometry(QRect(QPoint(325, 230), QSize(150, 100)));
        label->setStyleSheet("QLabel { background-color : green; color : white; }");
        label->setText(label->text() + "\nFile loaded");
    } else
        errorMessage -> showMessage("Cannot load file");
}
