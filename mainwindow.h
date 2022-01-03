#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <random>
#include <QStringList>
#include <QStringListModel>
#include <QList>
#include <QModelIndexList>
#include <QModelIndex>
#include <malloc.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_hsGeneAmount_valueChanged(int value);

    void on_hsBadGenesPercent_valueChanged(int value);

    void on_pbCreateFirstGeneration_clicked();

    void on_pbAddCrossoverPlaceMPM_clicked();

    void on_pbRemoveAllCrossoverPlacesMPM_clicked();

    void on_pbRemoveSelectedCrossoverPlaceMPM_clicked();

    void on_pbStartProcess_clicked();

    void on_cbCrossoverPlaceWithRandomMPM_clicked(bool checked);

    void on_cbContinueProcess_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int createdChromosomeAmount;
    int createdGeneAmount;
    int chromosomeAmount;
    int geneAmount;
    bool **createdGeneration;
    bool **firstGeneration;
    bool **secondGeneration;
    QList<int> crossoverPlacesList;
    QVector<double> averageFitnessesList;
    QVector<double> maximumFitnessesList;
    void OnePointMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome);
    void MultyPointMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome);
    void UniformMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome);
    int fitness(bool* mass);
};

#endif // MAINWINDOW_H
