//
// Created by eleonora on 14/07/20.
//

#include "View.h"

View::View(FileLoader *s) : subject(s) {
    attach();

    // set dimensions for the MainWindow
    setFixedSize(800, 400);
    setWindowTitle("File loader");

    // set button
    button = new QPushButton("Start loading resources", this);
    button->setGeometry(QRect(QPoint(300, 150), QSize(200, 30)));

    // set progressBar
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(100, 190), QSize(600, 30)));
    progressBar -> setRange(0,100);
    progressBar->setValue(0);


    label = new QLabel(this);
    label -> setWordWrap(true);
    label->setAlignment(Qt::AlignCenter);

    errorMessage = new QErrorMessage(this);

    //set the description of the program
    description = new QLabel(" Program that loads resources",this);
    description->setGeometry(QRect(QPoint(250,90),QSize(300,30)));
    description->setStyleSheet("QLabel { border-radius : 5px; background-color : #369CDD; color : white; }");
    description->setAlignment(Qt::AlignCenter);

    connect(button, SIGNAL(released()), this, SLOT(startLoadingFiles()));

}

void View::startLoadingFiles() {
    std::list <std::string> files;
    files.emplace_back("Text.txt");
    files.emplace_back("Text2.txt");
    files.emplace_back("Image.svg");
    try {
        subject->loadFiles(files);
        progressBar->setValue(100);
    } catch(std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }

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
        label->setGeometry(QRect(QPoint(310, 230), QSize(180, subject->getNumFiles()*30)));
        label->setStyleSheet("QLabel { border-radius : 5px; background-color : green; color : white; }");
        label->setText(label->text() + "File " + subject->getFileName() + " loaded\n");
        progressBar->setValue(std::ceil(progressBar->value() + ((1.0 / subject->getNumFiles()) * 100)));
    } else
        errorMessage -> showMessage("Cannot load file " + subject->getFileName());
}
