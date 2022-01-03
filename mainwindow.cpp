#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createdChromosomeAmount = 0;
    createdGeneAmount = 0;
    chromosomeAmount = 0;
    geneAmount = 0;

    int val;

    //connecting chromosom amount
    connect(ui->hsChromosomeAmount, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbChromosomeAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbChromosomeAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsChromosomeAmount, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsChromosomeAmount->setValue(100);
    ui->sbChromosomeAmount->setValue(100);


    //connecting gene amount
    connect(ui->hsGeneAmount, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbGeneAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbGeneAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsGeneAmount, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsGeneAmount->setValue(30);
    ui->sbGeneAmount->setValue(30);

    //
    val = ui->hsGeneAmount->value();
    MainWindow::on_hsGeneAmount_valueChanged(val);

    //
    val = ui->hsBadGenesPercent->value();
    MainWindow::on_hsBadGenesPercent_valueChanged(val);
    ui->hsChromosomeAmount->setValue(100);

    //connecting
    connect(ui->rbOnePointMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbOnePointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setEnabled));
    connect(ui->rbOnePointMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbMultyPointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));

    //connecting
    connect(ui->rbMultyPointMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbOnePointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    connect(ui->rbMultyPointMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbMultyPointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setEnabled));

    //connecting
    connect(ui->rbUniformMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbOnePointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    connect(ui->rbUniformMethod, static_cast<void(QRadioButton::*)(bool)>(&QRadioButton::clicked),
            ui->gbMultyPointMethod, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    ui->rbUniformMethod->setChecked(true);
    ui->gbOnePointMethod->setDisabled(true);
    ui->gbMultyPointMethod->setDisabled(true);

    //connecting
    connect(ui->cbCrossoverPlaceWithRandomOPM, static_cast<void(QCheckBox::*)(bool)>(&QCheckBox::clicked),
            ui->gbCrossoverPlaceWithoutRandomOPM, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    ui->cbCrossoverPlaceWithRandomOPM->setChecked(true);
    ui->gbCrossoverPlaceWithoutRandomOPM->setDisabled(true);

    //connecting crossover place for one point method
    connect(ui->hsCrossoverPlaceOPM, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbCrossoverPlaceOPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbCrossoverPlaceOPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsCrossoverPlaceOPM, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsCrossoverPlaceOPM->setValue(0);

    //connecting
    connect(ui->cbCrossoverAmountWithRandomMPM, static_cast<void(QCheckBox::*)(bool)>(&QCheckBox::clicked),
            ui->gbCrossoverAmountWithoutRandomMPM, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    ui->cbCrossoverAmountWithRandomMPM->setChecked(true);
    ui->gbCrossoverAmountWithoutRandomMPM->setDisabled(true);

    //connecting crossover amount for multy point method
    connect(ui->hsCrossoverAmountMPM, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbCrossoverAmountMPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbCrossoverAmountMPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsCrossoverAmountMPM, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsCrossoverAmountMPM->setValue(0);
    ui->sbCrossoverAmountMPM->setValue(0);

    //connecting
    connect(ui->cbCrossoverPlaceWithRandomMPM, static_cast<void(QCheckBox::*)(bool)>(&QCheckBox::clicked),
            ui->gbCrossoverPlaceWithoutRandomMPM, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setDisabled));
    ui->cbCrossoverPlaceWithRandomMPM->setChecked(true);
    ui->gbCrossoverPlaceWithoutRandomMPM->setDisabled(true);

    //connecting crossover place for multy point method
    connect(ui->hsCrossoverPlaceMPM, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbCrossoverPlaceMPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbCrossoverPlaceMPM, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsCrossoverPlaceMPM, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsCrossoverPlaceMPM->setValue(0);
    ui->sbCrossoverPlaceMPM->setValue(0);

    connect(ui->cbUseMutation, static_cast<void(QCheckBox::*)(bool)>(&QCheckBox::clicked),
            ui->gbMutation, static_cast<void(QGroupBox::*)(bool)>(&QGroupBox::setEnabled));
    ui->cbUseMutation->setChecked(false);
    ui->gbMutation->setEnabled(false);

    //connecting mutation chance percent
    connect(ui->hsMutationChancePercent, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbMutationChancePercent, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbMutationChancePercent, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsMutationChancePercent, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsMutationChancePercent->setValue(1);

    //connecting generation mount
    connect(ui->hsGenerationAmount, static_cast<void(QSlider::*)(int)>(&QSlider::valueChanged),
            ui->sbGenerationAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::setValue));
    connect(ui->sbGenerationAmount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->hsGenerationAmount, static_cast<void(QSlider::*)(int)>(&QSlider::setValue));
    ui->hsGenerationAmount->setValue(0);

    srand(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hsGeneAmount_valueChanged(int value)
{
    ui->sbGeneAmount->setValue(value);
    int percentOfbadGenes = ui->lPercentOfBadGenes->text().toInt();
    ui->lBadGenesAmount->setText(QString::number(percentOfbadGenes * value / 100));
    ui->lGoodGenesAmount->setText(QString::number((100 - percentOfbadGenes) * value / 100));
    ui->hsCrossoverPlaceOPM->setMaximum(value);
    if(ui->cbCrossoverPlaceWithRandomMPM->isChecked())
        ui->hsCrossoverAmountMPM->setMaximum(value);
    ui->hsCrossoverPlaceMPM->setMaximum(value);
}

void MainWindow::on_hsBadGenesPercent_valueChanged(int value)
{
    ui->lPercentOfBadGenes->setText(QString::number(value));
    ui->lPercentOfGoodGenes->setText(QString::number(100-value));
    int genesAmount = ui->sbGeneAmount->value();
    int badGenesAmount = value * genesAmount / 100;
    int goodGenesAmount = genesAmount - badGenesAmount;
    ui->lBadGenesAmount->setText(QString::number(badGenesAmount));
    ui->lGoodGenesAmount->setText(QString::number(goodGenesAmount));
    if(badGenesAmount > goodGenesAmount)
        ui->lComparisson->setText(" > ");
    else if(badGenesAmount == goodGenesAmount)
        ui->lComparisson->setText(" == ");
    else if(badGenesAmount < goodGenesAmount)
        ui->lComparisson->setText(" < ");
    else
        ui->lComparisson->setText(" ? ");
}

void MainWindow::on_pbCreateFirstGeneration_clicked()
{
    createdChromosomeAmount = ui->sbChromosomeAmount->value();
    createdGeneAmount = ui->sbGeneAmount->value();
    int goodGenesAmount = ui->lGoodGenesAmount->text().toInt();
    createdGeneration = new bool*[createdChromosomeAmount];
    bool temp;
    int firstRandNum, secondRandNum;
    for(int i = 0; i < createdChromosomeAmount; i++){
        createdGeneration[i] = new bool[createdGeneAmount];
        for(int j = 0 ; j < goodGenesAmount; j++)
            createdGeneration[i][j] = true;
        for(int j = goodGenesAmount; j < createdGeneAmount; j++)
            createdGeneration[i][j] = false;
        for(int j = 0; j < createdGeneAmount; j++)
            firstRandNum = rand() % createdGeneAmount,
            temp = createdGeneration[i][firstRandNum],
            secondRandNum = rand() % createdGeneAmount,
            createdGeneration[i][firstRandNum] = createdGeneration[i][secondRandNum],
            createdGeneration[i][secondRandNum] = temp;

    }

    QStringListModel *stringListModel = new QStringListModel(this);

    QStringList stringList;
    QString chromosomString;
    for(int i = 0; i < createdChromosomeAmount; i++){
        chromosomString = QString::number(i + 1) + ". ";
        for(int j = 0; j < createdGeneAmount; j++)
            chromosomString += createdGeneration[i][j] ? "1" : "0";
        stringList << chromosomString;
        chromosomString = "";
    }
    stringListModel->setStringList(stringList);
    ui->lvFirstGenerationList->setModel(stringListModel);
    ui->lvFirstGenerationList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_pbAddCrossoverPlaceMPM_clicked()
{
    int crossoverPlace = ui->sbCrossoverPlaceMPM->value();
    bool check = true;
    for(int i = 0; i < crossoverPlacesList.length(); i++)
        if(crossoverPlacesList[i] == crossoverPlace){
            check = false;
            break;
        }
        else if(crossoverPlacesList[i] > crossoverPlace){
            check = false;
            crossoverPlacesList.insert(i, crossoverPlace);
            break;
        }
    if(check)
        crossoverPlacesList.push_back(crossoverPlace);

    QStringListModel *stringListModel = new QStringListModel(this);
    QStringList stringList;
    for(int i = 0; i < crossoverPlacesList.length(); i++)
        stringList << QString::number(crossoverPlacesList.at(i));
    stringListModel->setStringList(stringList);
    ui->lvCrossoverPlacesListMPM->setModel(stringListModel);
    ui->lvCrossoverPlacesListMPM->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->hsCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
    ui->sbCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
}
void MainWindow::on_pbRemoveAllCrossoverPlacesMPM_clicked()
{
    int length = crossoverPlacesList.length();
    for(int i = 0 ; i < length; i++)
        crossoverPlacesList.removeFirst();
    QStringListModel *stringListModel = new QStringListModel(this);
    QStringList stringList;
    stringListModel->setStringList(stringList);
    ui->lvCrossoverPlacesListMPM->setModel(stringListModel);


    ui->hsCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
    ui->sbCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
}

void MainWindow::on_pbRemoveSelectedCrossoverPlaceMPM_clicked()
{
    int selectedCrossoverPlace = ui->lvCrossoverPlacesListMPM->currentIndex().row();
    crossoverPlacesList.removeAt(selectedCrossoverPlace);
    QStringListModel *stringListModel = new QStringListModel(this);
    QStringList stringList;
    for(int i = 0; i < crossoverPlacesList.length(); i++)
        stringList << QString::number(crossoverPlacesList.at(i));
    stringListModel->setStringList(stringList);
    ui->lvCrossoverPlacesListMPM->setModel(stringListModel);
    ui->lvCrossoverPlacesListMPM->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->hsCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
    ui->sbCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
}

void MainWindow::on_pbStartProcess_clicked()
{

    //checking
    if(createdChromosomeAmount == 0 || createdGeneAmount == 0)
        return;


    if(!ui->cbContinueProcess->isChecked() || chromosomeAmount == 0 || geneAmount == 0){
        chromosomeAmount = createdChromosomeAmount;
        geneAmount = createdGeneAmount;
        firstGeneration = new bool*[chromosomeAmount];
        for(int i = 0; i < chromosomeAmount; i++){
            firstGeneration[i] = new bool[geneAmount];
            for(int j = 0; j < geneAmount; j++)
                firstGeneration[i][j] = (bool)createdGeneration[i][j];
        }
        averageFitnessesList.clear();
        maximumFitnessesList.clear();
    }
    //init
    //show
    QStringListModel *firstGenStrListModel = new QStringListModel(this);
    QStringList firstGenStrList;
    QString firstGenChromosomString;
    //show
    QStringListModel *secondGenStrListModel = new QStringListModel(this);
    QStringList secondGenStrList;
    QString secondGenChromosomString;
    //show
    QStringListModel *lastGenStrListModel = new QStringListModel(this);
    QStringList lastGenStrList;
    QString lastGenChromosomString;

    int generationAmount = ui->sbGenerationAmount->value();

    secondGeneration = new bool*[chromosomeAmount];

    //show in statusbar percent of processed generations
    ui->statusBar->showMessage("Processed: " + QString::number(0) + " %");
    //change cursor
    this->setCursor(Qt::WaitCursor);

    bool check;
    //all generations
    for(int g = 0; g < generationAmount; g++){
        int fatherChromosome, motherChromosome;
        //creating second generation
        for(int j = 0; j < chromosomeAmount; j++){
            fatherChromosome = rand() % chromosomeAmount;
            secondGeneration[j] = new bool[geneAmount];
            motherChromosome = rand() % chromosomeAmount;

            if(ui->rbOnePointMethod->isChecked())
                OnePointMethod(secondGeneration[j], firstGeneration[motherChromosome], firstGeneration[fatherChromosome]);
            else if(ui->rbMultyPointMethod->isChecked())
                MultyPointMethod(secondGeneration[j], firstGeneration[motherChromosome], firstGeneration[fatherChromosome]);
            else
                UniformMethod(secondGeneration[j], firstGeneration[motherChromosome], firstGeneration[fatherChromosome]);
        }

        //mutation
        if(ui->cbUseMutation->isChecked()){
            int mutationChancePercent = ui->sbMutationChancePercent->value();
            for(int i = 0; i < chromosomeAmount; i++)
                for(int j = 0; j < geneAmount; j++)
                    if(rand() % 100 < mutationChancePercent)
                        secondGeneration[i][j] = !secondGeneration[i][j];
        }

        //show
        for(int i = 0; i < chromosomeAmount; i++){
            firstGenChromosomString = QString::number(i + 1) + ". ";
            for(int j = 0; j < geneAmount; j++)
                firstGenChromosomString += firstGeneration[i][j] ? "1" : "0";
            firstGenStrList << firstGenChromosomString;
            firstGenChromosomString = "";
        }
        //show
        for(int i = 0; i < chromosomeAmount; i++){
            secondGenChromosomString = QString::number(i + 1) + ". ";
            for(int j = 0; j < geneAmount; j++)
                secondGenChromosomString += secondGeneration[i][j] ? "1" : "0";
            secondGenStrList << secondGenChromosomString;
            secondGenChromosomString = "";
        }

        //sorting the best chromosomes in first generation
        bool* temp = new bool[geneAmount];
        for(int i = 0; i < 2 * chromosomeAmount; i++){
            check = true;
            for(int j = 1; j < 2 * chromosomeAmount; j++){
                if(j < chromosomeAmount && fitness(firstGeneration[j]) > fitness(firstGeneration[j - 1])){
                    temp = firstGeneration[j];
                    firstGeneration[j] = firstGeneration[j - 1];
                    firstGeneration[j - 1] = temp;
                    check = false;
                }
                else if(j == chromosomeAmount && fitness(secondGeneration[j % chromosomeAmount]) > fitness(firstGeneration[j - 1])){
                    temp = secondGeneration[j % chromosomeAmount];
                    secondGeneration[j % chromosomeAmount] = firstGeneration[j - 1];
                    firstGeneration[j - 1] = temp;
                    check = false;
                }
                else if(j > chromosomeAmount && fitness(secondGeneration[j % chromosomeAmount]) > fitness(secondGeneration[(j - 1) % chromosomeAmount])){
                    temp = secondGeneration[j % chromosomeAmount];
                    secondGeneration[j % chromosomeAmount] = secondGeneration[(j - 1) % chromosomeAmount];
                    secondGeneration[(j - 1) % chromosomeAmount] = temp;
                    check = false;
                }
            }
            if(check)
                break;
        }

        //if we want to give a chance for losers
        if(ui->cbGiveAChance->isChecked()){
            //calculate fitness sum
            int fitnessSumInFirstGeneation = 0;
            for(int i = 0; i < chromosomeAmount; i++)
                fitnessSumInFirstGeneation += fitness(firstGeneration[i]);
            int fitnessSumInSecondGeneration = 0;
            for(int i = 0; i < chromosomeAmount; i++)
                    fitnessSumInSecondGeneration += fitness(secondGeneration[i]);
            int fitnessSum = fitnessSumInFirstGeneation + fitnessSumInSecondGeneration;

            QList<bool*> chanseForLosers;
            for(int i = 0; i < chromosomeAmount; i++)
                chanseForLosers.push_back(firstGeneration[i]);
            for(int i = 0; i < chromosomeAmount; i++)
                chanseForLosers.push_back(secondGeneration[i]);

            //mask of used chromosomes
//            bool* usedChromosomes = new bool[2 * chromosomeAmount];
//            for(int i = 0; i < 2 * chromosomeAmount; i++)
//                usedChromosomes[i] = false;

            for(int i = 0; i < chromosomeAmount; i++){
                int randChromosome = rand() % fitnessSum;
                int counter = 0;
                for(int j = 0; j < 2 * chromosomeAmount; j++){
                    if(j < chromosomeAmount)
                        counter += fitness(firstGeneration[j]);
                    else if(j >= chromosomeAmount)
                        counter += fitness(secondGeneration[j % chromosomeAmount]);
                    if(counter > randChromosome){
//                        if(usedChromosomes[j]){
//                            i--;
//                            break;
//                        }
                        firstGeneration[i] = chanseForLosers[j];
//                        usedChromosomes[j] = true;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < chromosomeAmount; i++){
            check = true;
            for(int j = 1; j < chromosomeAmount; j++)
                if(fitness(firstGeneration[j]) > fitness(firstGeneration[j - 1])){
                    temp = firstGeneration[j];
                    firstGeneration[j] = firstGeneration[j - 1];
                    firstGeneration[j - 1] = temp;
                    check = false;
                }
            if(check)
                break;
        }

        double averageFitness = 0;
        for(int i = 0; i < chromosomeAmount; i++)
            averageFitness += (double)fitness(firstGeneration[i]) / (double)chromosomeAmount;
        averageFitnessesList.push_back(averageFitness);
        maximumFitnessesList.push_back((double)fitness(firstGeneration[0]));

        //show in statusbar percent of processed generations
        ui->statusBar->showMessage("Processed: " + QString::number((g * 100 + 1) / generationAmount) + " %");
    }


    double maximumFitness = 0;
    for(int i = 0; i < maximumFitnessesList.length(); i++)
        if((double)maximumFitnessesList.at(i) > maximumFitness)
            maximumFitness = (double)maximumFitnessesList.at(i);
    QVector<double> x;
    for(int i = 0; i < averageFitnessesList.length(); i++)
        x.push_back((double)i);

    ui->cpGraph->clearGraphs();
    ui->cpGraph->addGraph();
    ui->cpGraph->graph(0)->setData(x, averageFitnessesList);
    ui->cpGraph->graph(0)->setPen(QColor(255,0,0,255));
    ui->cpGraph->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->cpGraph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    ui->cpGraph->addGraph();
    ui->cpGraph->graph(1)->setData(x, maximumFitnessesList);
    ui->cpGraph->graph(1)->setPen(QColor(0,225,0,255));
    ui->cpGraph->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->cpGraph->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 5));
    ui->cpGraph->xAxis->setLabel("Generation");
    ui->cpGraph->yAxis->setLabel("fitness");
    ui->cpGraph->xAxis->setRange(0, x.length() + 1);//Для оси Ox
    ui->cpGraph->yAxis->setRange(0, maximumFitness + 1);//Для оси Oy
    ui->cpGraph->replot();

    //show
    for(int i = 0; i < chromosomeAmount; i++){
        lastGenChromosomString = QString::number(i + 1) + ". ";
        for(int j = 0; j < geneAmount; j++)
            lastGenChromosomString += firstGeneration[i][j] ? "1" : "0";
        lastGenStrList << lastGenChromosomString;
        lastGenChromosomString = "";
    }

    firstGenStrListModel->setStringList(firstGenStrList);
    ui->lvLastParents->setModel(firstGenStrListModel);
    ui->lvLastParents->setEditTriggers(QAbstractItemView::NoEditTriggers);

    secondGenStrListModel->setStringList(secondGenStrList);
    ui->lvLastChilds->setModel(secondGenStrListModel);
    ui->lvLastChilds->setEditTriggers(QAbstractItemView::NoEditTriggers);

    lastGenStrListModel->setStringList(lastGenStrList);
    ui->lvLastGeneration->setModel(lastGenStrListModel);
    ui->lvLastGeneration->setEditTriggers(QAbstractItemView::NoEditTriggers);


    this->setCursor(Qt::ArrowCursor);
    ui->statusBar->showMessage("");
}

void MainWindow::OnePointMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome){
    bool isCrossoverPlaceWithRandom = ui->cbCrossoverPlaceWithRandomOPM->isChecked();
    int crossoverPlace;
    if(isCrossoverPlaceWithRandom)
        crossoverPlace = rand() % (geneAmount + 1);
    else
        crossoverPlace = ui->sbCrossoverPlaceOPM->value();
    for(int k = 0 ; k < geneAmount; k++){
        if(k < crossoverPlace)
            childChromosome[k] = fatherChromosome[k];
        else
            childChromosome[k] = motherChromosome[k];
    }
}

void MainWindow::MultyPointMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome){
    bool isCrossoverAmountWithRandom = ui->cbCrossoverAmountWithRandomMPM->isChecked();
    bool isCrossoverPlaceWithRandom = ui->cbCrossoverPlaceWithRandomMPM->isChecked();
    int crossoverAmount;
    QList<int> localCrossoverPlacesList;

    //take crossover amount variable
    if(isCrossoverAmountWithRandom)
        crossoverAmount = rand() % geneAmount;
    else
        crossoverAmount = ui->sbCrossoverAmountMPM->value();

    //if check box crossoverAmountWithRandom or crossoverPlaceWithRandom is checked so we will generate new crossover places list
    if(isCrossoverAmountWithRandom || isCrossoverPlaceWithRandom){
        int crossoverPlace;
        for(int i = 0 ; i < crossoverAmount; i++){
            crossoverPlace = rand() % (crossoverAmount + 1);
            bool check = true;
            for(int i = 0; i < localCrossoverPlacesList.length(); i++)
                //if we have the same place so pass it and try again
                if(localCrossoverPlacesList[i] == crossoverPlace){
                    check = false;
                    i--;
                    break;
                }
                else if(localCrossoverPlacesList[i] > crossoverPlace){
                    check = false;
                    localCrossoverPlacesList.insert(i, crossoverPlace);
                    break;
                }
            if(check)
                localCrossoverPlacesList.push_back(crossoverPlace);
        }
    }
    else{
        for(int i = 0; i < crossoverAmount; i++)
            localCrossoverPlacesList.push_back(crossoverPlacesList.at(i));
    }

    //child creating
    bool* thisChromosome = fatherChromosome;
    bool isThisFatherChromosome = true;
    //go throught all genes
    for(int k = 0; k < geneAmount; k++){
        for(int l = 0; l < localCrossoverPlacesList.length(); l++)
            //if we have the place in out list so we change parent
            if(k == localCrossoverPlacesList.at(l)){
                if(isThisFatherChromosome){
                    thisChromosome = motherChromosome;
                    isThisFatherChromosome = false;
                }
                else{
                    thisChromosome = fatherChromosome;
                    isThisFatherChromosome = true;
                }
                break;
            }
         childChromosome[k] = thisChromosome[k];
    }
}

void MainWindow::UniformMethod(bool* childChromosome, bool* fatherChromosome, bool* motherChromosome){
    for(int k = 0 ; k < geneAmount; k++){
        int rnd = rand() % 2;
        if(rnd)
            childChromosome[k] = fatherChromosome[k];
        else
            childChromosome[k] = motherChromosome[k];
    }
}


int MainWindow::fitness(bool* mass){
    int result = 0;
    for(int i = 0; i < geneAmount; i++)
        if(mass[i] == true)
            result++;
    return result;
}

void MainWindow::on_cbCrossoverPlaceWithRandomMPM_clicked(bool checked)
{
    if(checked){
        ui->hsCrossoverAmountMPM->setMaximum(ui->sbGeneAmount->value());
        ui->sbCrossoverAmountMPM->setMaximum(ui->hsGeneAmount->value());
    }
    else{
        ui->hsCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
        ui->sbCrossoverAmountMPM->setMaximum(crossoverPlacesList.length());
    }
}

void MainWindow::on_cbContinueProcess_clicked(bool checked)
{
    if(checked)
        ui->pbStartProcess->setText("Continue process");
    else
        ui->pbStartProcess->setText("Start process");
}
