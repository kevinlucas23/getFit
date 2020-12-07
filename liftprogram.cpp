#include "liftprogram.h"
#include "ui_liftprogram.h"
#include "rpe.h"
#include "maxes.h"
#include "string"

LiftProgram::LiftProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LiftProgram)
{
    ui->setupUi(this);
    QPixmap pic1("../getFit/tsa.png");
    int w = ui->logo->width();
    int h = ui->logo->height();
    ui->logo->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
    QPalette p1;
    p1.setColor(QPalette::Base,Qt::red);
    ui->day1->setPalette(p1);
    ui->day2->setPalette(p1);
    ui->day3->setPalette(p1);
    ui->day4->setPalette(p1);
    p1.setColor(QPalette::Base,Qt::gray);
    ui->f1->setPalette(p1);
    ui->f2->setPalette(p1);
    ui->f3->setPalette(p1);
    ui->f4->setPalette(p1);
    ui->f4_2->setPalette(p1);
    ui->f5->setPalette(p1);
    ui->f6->setPalette(p1);
    ui->f7->setPalette(p1);
    ui->cgHeader->setPalette(p1);
    ui->f9->setPalette(p1);
    ui->f10->setPalette(p1);
    ui->f11->setPalette(p1);
    ui->f12->setPalette(p1);
    ui->f13->setPalette(p1);
    ui->f14->setPalette(p1);
    ui->f15->setPalette(p1);


}

LiftProgram::~LiftProgram()
{
    delete ui;
}

void LiftProgram::changeWeek(){
    setWeights();
}

void LiftProgram::setWeights(){
    int squat = getSquatMax(currentUser);
    int bench = getBenchMax(currentUser);
    int deadlift = getDeadliftMax(currentUser);
    /*qDebug() << "**AFTER GETTING MAXES**";
    qDebug() << squat;
    qDebug() << bench;
    qDebug() << deadlift;
    */
    int week = getWeek();
    switch(week){
        case(1):
            ui->cgHeader->setText("Close-Grip BP");
            ui->sq1->setText(QString::number(int(squat * .8)));
            ui->sq1Reps->setText("1x3");
            ui->sq2->setText(QString::number(int(squat * .69)));
            ui->sq2Reps->setText("3x8");
            ui->b1->setText(QString::number(int(bench * .69)));
            ui->b1Reps->setText("3x8");
            ui->cg->setText("RPE 7");
            ui->cgReps->setText("3x6");
            ui->dbRow->setText("RPE 7");
            ui->dbRowReps->setText("4x10");

            ui->dl->setText(QString::number(int(deadlift * .74)));
            ui->dlReps->setText("4x5");
            ui->bp2->setText(QString::number(int(bench * .72)));
            ui->bp2Reps->setText("5x4");
            ui->pendlay->setText("RPE 7.5");
            ui->PendlayReps->setText("3x7");

            ui->sq3->setText(QString::number(int(squat * .73)));
            ui->sq3Reps->setText("6x4");
            ui->ohp->setText("RPE 7");
            ui->ohpReps->setText("3x8");
            ui->goblet->setText("RPE 7.5");
            ui->gobletReps->setText("3x10");
            ui->dbRow2->setText("RPE 8");
            ui->dbRow2Reps->setText("3x10");

            ui->bp3->setText("RPE 7");
            ui->bp3Reps->setText("x1");
            ui->bp4->setText(QString::number(int(bench * .77)));
            ui->bp4Reps->setText("3x5");
            ui->pausedDl->setText(QString::number(int(deadlift * .67)));
            ui->pausedDLReps->setText("4x4");
            ui->larson->setText("RPE 7");
            ui->larsenReps->setText("3x6");
            ui->lat->setText("RPE 8");
            ui->latReps->setText("3x8");
            break;
    case(2):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText(QString::number(int(squat * .82)));
        ui->sq1Reps->setText("1x3");
        ui->sq2->setText(QString::number(int(squat * .71)));
        ui->sq2Reps->setText("3x8");
        ui->b1->setText(QString::number(int(bench * .71)));
        ui->b1Reps->setText("3x8");
        ui->cg->setText("RPE 7.5");
        ui->cgReps->setText("3x6");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText(QString::number(int(deadlift * .75)));
        ui->dlReps->setText("5x5");
        ui->bp2->setText(QString::number(int(bench * .74)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x7");

        ui->sq3->setText(QString::number(int(squat * .75)));
        ui->sq3Reps->setText("6x4");
        ui->ohp->setText("RPE 7");
        ui->ohpReps->setText("3x8");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x10");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x10");

        ui->bp3->setText("RPE 7.5");
        ui->bp3Reps->setText("x1");
        ui->bp4->setText(QString::number(int(bench * .79)));
        ui->bp4Reps->setText("3x5");
        ui->pausedDl->setText(QString::number(int(deadlift * .69)));
        ui->pausedDLReps->setText("4x4");
        ui->larson->setText("RPE 7.5");
        ui->larsenReps->setText("3x6");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(3):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText(QString::number(int(squat * .84)));
        ui->sq1Reps->setText("1x3");
        ui->sq2->setText(QString::number(int(squat * .73)));
        ui->sq2Reps->setText("3x7");
        ui->b1->setText(QString::number(int(bench * .73)));
        ui->b1Reps->setText("3x8");
        ui->cg->setText("RPE 8");
        ui->cgReps->setText("3x6");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText(QString::number(int(deadlift * .79)));
        ui->dlReps->setText("5x4");
        ui->bp2->setText(QString::number(int(bench * .76)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x7");

        ui->sq3->setText(QString::number(int(squat * .77)));
        ui->sq3Reps->setText("6x4");
        ui->ohp->setText("RPE 8");
        ui->ohpReps->setText("3x8");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x10");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x10");

        ui->bp3->setText("RPE 8");
        ui->bp3Reps->setText("x1");
        ui->bp4->setText(QString::number(int(bench * .81)));
        ui->bp4Reps->setText("3x5");
        ui->pausedDl->setText(QString::number(int(deadlift * .71)));
        ui->pausedDLReps->setText("4x4");
        ui->larson->setText("RPE 8");
        ui->larsenReps->setText("3x6");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(4):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText(QString::number(int(squat * .86)));
        ui->sq1Reps->setText("1x3");
        ui->sq2->setText(QString::number(int(squat * .75)));
        ui->sq2Reps->setText("3x7");
        ui->b1->setText(QString::number(int(bench * .75)));
        ui->b1Reps->setText("4x7");
        ui->cg->setText("RPE 8.5");
        ui->cgReps->setText("3x6");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText(QString::number(int(deadlift * .81)));
        ui->dlReps->setText("6x4");
        ui->bp2->setText(QString::number(int(bench * .78)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x7");

        ui->sq3->setText(QString::number(int(squat * .79)));
        ui->sq3Reps->setText("6x4");
        ui->ohp->setText("RPE 8");
        ui->ohpReps->setText("3x8");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x10");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x10");

        ui->bp3->setText("RPE 8.5");
        ui->bp3Reps->setText("x1");
        ui->bp4->setText(QString::number(int(bench * .84)));
        ui->bp4Reps->setText("3x5");
        ui->pausedDl->setText(QString::number(int(deadlift * .73)));
        ui->pausedDLReps->setText("4x4");
        ui->larson->setText("RPE 8.5");
        ui->larsenReps->setText("3x6");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(5):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText(QString::number(int(squat * .73)));
        ui->sq1Reps->setText("3x5");
        ui->sq2->setText("");
        ui->sq2Reps->setText("");
        ui->b1->setText(QString::number(int(bench * .73)));
        ui->b1Reps->setText("3x6");
        ui->cg->setText("RPE 7");
        ui->cgReps->setText("2x5");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText(QString::number(int(deadlift * .79)));
        ui->dlReps->setText("4x3");
        ui->bp2->setText(QString::number(int(bench * .78)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x4");

        ui->sq3->setText(QString::number(int(squat * .75)));
        ui->sq3Reps->setText("5x4");
        ui->ohp->setText("RPE 7");
        ui->ohpReps->setText("3x6");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x6");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x8");

        ui->bp3->setText(QString::number(int(deadlift * .78)));
        ui->bp3Reps->setText("3x4");
        ui->bp4->setText("");
        ui->bp4Reps->setText("");
        ui->pausedDl->setText(QString::number(int(deadlift * .72)));
        ui->pausedDLReps->setText("4x3");
        ui->larson->setText("RPE 8.5");
        ui->larsenReps->setText("2x5");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(6):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText("RPE 6.5");
        ui->sq1Reps->setText("x1");
        ui->sq2->setText(QString::number(int(squat * .85)));
        ui->sq2Reps->setText("5x3");
        ui->b1->setText(QString::number(int(bench * .75)));
        ui->b1Reps->setText("4x6");
        ui->cg->setText("RPE 7");
        ui->cgReps->setText("3x5");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText("RPE 7");
        ui->dlReps->setText("1x2");
        ui->dl2->setText(QString::number(int(deadlift * .82)));
        ui->dlReps2->setText("4x5");
        ui->bp2->setText(QString::number(int(bench * .80)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x6");

        ui->sq3->setText(QString::number(int(squat * .76)));
        ui->sq3Reps->setText("5x4");
        ui->ohp->setText("RPE 7");
        ui->ohpReps->setText("3x8");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x8");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x8");

        ui->bp3->setText("RPE 7");
        ui->bp3Reps->setText("2x1");
        ui->bp4->setText(QString::number(int(bench * .81)));
        ui->bp4Reps->setText("3x4");
        ui->pausedDl->setText(QString::number(int(deadlift * .74)));
        ui->pausedDLReps->setText("5x3");
        ui->larson->setText("RPE 7");
        ui->larsenReps->setText("3x5");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(7):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText("RPE 7.5");
        ui->sq1Reps->setText("x1");
        ui->sq2->setText(QString::number(int(squat * .87)));
        ui->sq2Reps->setText("5x3");
        ui->b1->setText(QString::number(int(bench * .77)));
        ui->b1Reps->setText("4x6");
        ui->cg->setText("RPE 7");
        ui->cgReps->setText("3x5");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x10");

        ui->dl->setText("RPE 8");
        ui->dlReps->setText("x1");
        ui->dl2->setText(QString::number(int(deadlift * .84)));
        ui->dlReps2->setText("5x2");
        ui->bp2->setText(QString::number(int(bench * .82)));
        ui->bp2Reps->setText("5x4");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x6");

        ui->sq3->setText(QString::number(int(squat * .78)));
        ui->sq3Reps->setText("5x3");
        ui->ohp->setText("RPE 7");
        ui->ohpReps->setText("3x6");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x8");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x8");

        ui->bp3->setText("RPE 8");
        ui->bp3Reps->setText("2x1");
        ui->bp4->setText(QString::number(int(bench * .84)));
        ui->bp4Reps->setText("3x4");
        ui->pausedDl->setText(QString::number(int(deadlift * .76)));
        ui->pausedDLReps->setText("5x3");
        ui->larson->setText("RPE 7.5");
        ui->larsenReps->setText("3x5");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(8):
        ui->cgHeader->setText("Close-Grip BP");
        ui->sq1->setText("RPE 8.5");
        ui->sq1Reps->setText("x1");
        ui->sq2->setText(QString::number(int(squat * .89)));
        ui->sq2Reps->setText("5x2");
        ui->b1->setText(QString::number(int(bench * .79)));
        ui->b1Reps->setText("4x5");
        ui->cg->setText("RPE 7");
        ui->cgReps->setText("3x5");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x8");

        ui->dl->setText("RPE 8.5");
        ui->dlReps->setText("x1");
        ui->dl2->setText(QString::number(int(deadlift * .86)));
        ui->dlReps2->setText("4x2");
        ui->bp2->setText(QString::number(int(bench * .84)));
        ui->bp2Reps->setText("5x3");
        ui->pendlay->setText("RPE 7.5");
        ui->PendlayReps->setText("3x4");

        ui->sq3->setText(QString::number(int(squat * .8)));
        ui->sq3Reps->setText("5x3");
        ui->ohp->setText("RPE 7");
        ui->ohpReps->setText("3x4");
        ui->goblet->setText("RPE 7.5");
        ui->gobletReps->setText("3x6");
        ui->dbRow2->setText("RPE 8");
        ui->dbRow2Reps->setText("3x8");

        ui->bp3->setText("RPE 9");
        ui->bp3Reps->setText("1x1");
        ui->bp4->setText(QString::number(int(bench * .86)));
        ui->bp4Reps->setText("4x3");
        ui->pausedDl->setText(QString::number(int(deadlift * .78)));
        ui->pausedDLReps->setText("5x2");
        ui->larson->setText("RPE 8");
        ui->larsenReps->setText("3x5");
        ui->lat->setText("RPE 8.5");
        ui->latReps->setText("3x8");
        break;
    case(9):
        ui->cgHeader->setText("Deadlift");
        ui->sq1->setText(QString::number(int(squat * .8)));
        ui->sq1Reps->setText("5x2");
        ui->sq2->setText("");
        ui->sq2Reps->setText("");
        ui->b1->setText(QString::number(int(bench * .81)));
        ui->b1Reps->setText("5x4");
        ui->cg->setText(QString::number(int(deadlift * .75)));
        ui->cgReps->setText("5x1");
        ui->dbRow->setText("RPE 7");
        ui->dbRowReps->setText("4x8");

        ui->dl->setText("");
        ui->dlReps->setText("");
        ui->dl2->setText("");
        ui->dlReps2->setText("");
        ui->bp2->setText(QString::number(int(bench * .86)));
        ui->bp2Reps->setText("x1");
        ui->pendlay->setText("");
        ui->PendlayReps->setText("");

        ui->sq3->setText("");
        ui->sq3Reps->setText("");
        ui->ohp->setText("");
        ui->ohpReps->setText("");
        ui->goblet->setText("");
        ui->gobletReps->setText("");
        ui->dbRow2->setText("");
        ui->dbRow2Reps->setText("");

        ui->bp3->setText("");
        ui->bp3Reps->setText("");
        ui->bp4->setText("");
        ui->bp4Reps->setText("");
        ui->pausedDl->setText("");
        ui->pausedDLReps->setText("");
        ui->larson->setText("");
        ui->larsenReps->setText("");
        ui->lat->setText("");
        ui->latReps->setText("");
        break;




    default:
        break;
    }
}

int LiftProgram::getWeek(){
    QString week = ui->programWeek->currentText();
    if(week == "Week 1 Intro/Acclimation"){
        return 1;
    }
    else if(week == "Week 2 Progress 1"){
        return 2;
    }
    else if(week == "Week 3 Progress 2"){
        return 3;
    }
    else if (week == "Week 4 Progress 3"){
        return 4;
    }
    else if (week == "Week 5 Deload/Intensity Prep"){
        return 5;
    }
    else if (week == "Week 6 Intensify/Peak 1"){
        return 6;
    }
    else if (week == "Week 7 Intensify/Peak 2"){
        return 7;
    }
    else if (week == "Week 8 Intensify/Peak 3"){
        return 8;
    }
    else if (week == "Week 9 Test/Compete"){
        return 9;
    }

   return 1;

}

void LiftProgram::setCurrentUser(QString user){
    currentUser = user;
    setWeights();
}

void LiftProgram::rpe(){
    this->hide();
    Rpe *r = new Rpe();
    r->setCurrentUser(currentUser);
    r->show();
}

void LiftProgram::updateMaxes(){
    this->hide();
    Maxes *max = new Maxes();
    max->setCurrentUser(currentUser);
    max->show();
}
