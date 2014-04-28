import QtQuick 2.1
import QtQuick.Particles 2.0

Item {
    ParticleSystem{ id: bubbles; running: visible }
    ImageParticle{
        id: fireball
        system: bubbles
        source: "qrc:/images/bubble.png"
        opacity: 0.7
    }
    Emitter{
        system: bubbles
        anchors.bottom: parent.bottom
        anchors.margins: 4
        anchors.bottomMargin: -4
        anchors.left: parent.left
        anchors.right: parent.right
        size: 4
        sizeVariation: 4
        acceleration: PointDirection{ y: -6; xVariation: 3 }
        emitRate: 2
        lifeSpan: 3000
    }
}
