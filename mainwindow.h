#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QImage>
#include<QLabel>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QComboBox>
#include<QSpinBox>
#include<QToolBar>
#include<QFontComboBox>
#include<QToolButton>
#include<QTextCharFormat>
#include<QApplication>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QPainter>
#include "showwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;//各项菜单项
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;


    QImage img;
    QString filename;
    ShowWidget *showWidget;

    QAction *openFileAction;//文件菜单项
    QAction *newFileAction;
    QAction *printTextAction;
    QAction *printImageAction;
    QAction *exitAction;

    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;

    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;

    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;

    QAction *undoAction;
    QAction *redoAction;

    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;

    QToolBar *doToolBar;

protected slots:
    void ShowNewFile();
    void ShowOpenFile();
    void ShowPrintText();
    void ShowPrintImage();
    void ShowZoomIn();
    void ShowZoomOut();
    void ShowRotate90();
    void ShowRotate180();
    void ShowRotate270();
    void ShowMirrorVertical();
    void ShowMirrorHorizonal();
};

#endif // MAINWINDOW_H
