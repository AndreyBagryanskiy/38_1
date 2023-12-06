#ifndef SOUNDREDBUTTON_H
#define SOUNDREDBUTTON_H

#include <QMainWindow>

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include <QMediaPlayer>
#include <QMediaContent>


class SoundRedButton : public QPushButton{
    Q_OBJECT

public:
    SoundRedButton() = default;
    SoundRedButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    QMediaPlayer *player;
    QMediaContent clickSound;
    bool isDown = false;
};
#endif // SOUNDREDBUTTON_H
