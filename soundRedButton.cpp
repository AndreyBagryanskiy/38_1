#include "soundRedButton.h"



SoundRedButton::SoundRedButton(QWidget *parent){
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("../soundRedButton/img/buttonDown.png");
    mButtonDownPixmap = QPixmap("../soundRedButton/img/buttonUp.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &SoundRedButton::setDown);

    player = new QMediaPlayer();
    clickSound = QUrl("../soundRedButton/sound/click.mp3");
    player->setMedia(clickSound);
    player->setVolume(100);
}

void SoundRedButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize SoundRedButton::sizeHint() const{
    return QSize(100,100);
}

QSize SoundRedButton::minimumSizeHint() const{
    return sizeHint();
}

void  SoundRedButton::keyPressEvent(QKeyEvent *e){
    setDown();
}

void SoundRedButton::setDown(){
    player->stop();
    player->play();


    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &SoundRedButton::setUp);
}

void SoundRedButton::setUp(){
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}
