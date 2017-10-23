#include "speed.h"
#include "ui_speed.h"

Speed::Speed() : QWidget(0), ui(new Ui::Speed) {
    ui->setupUi(this);
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SIGNAL(speedChanged(int)));
}

SpeedQML::SpeedQML(QObject *parent) : QObject(parent) {
    m_speed.setVisible(true);
    m_speedData = 0;
    connect(&m_speed, SIGNAL(speedChanged(int)), this, SLOT(updateSpeed(int)));
}

int SpeedQML::speed() const {
    return m_speedData;
}

void SpeedQML::updateSpeed(int value){
    m_speedData = value;
    emit speedChanged();
}
