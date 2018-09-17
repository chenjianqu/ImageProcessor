#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Easy Word"));

    showWidget=new ShowWidget(this);
    setCentralWidget(showWidget);

    createActions();
    createMenus();
    createToolBars();

    if(!img.load("E:\\QT\\images\\image1.png"));
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

}

//动作实现
void MainWindow::createActions()
{
    //打开动作
    openFileAction=new QAction(QIcon("E:\\QT\\images\\open.png"),tr("打开"),this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("打开一个图像文件"));
    connect(openFileAction,SIGNAL(triggered(bool)),this,SLOT(ShowOpenFile()));

    //新建动作
    newFileAction=new QAction(QIcon("E:\\QT\\images\\new.png"),tr("新建"),this);
    newFileAction->setShortcut(QKeySequence::New);
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction,SIGNAL(triggered(bool)),this,SLOT(ShowNewFile()));

    //退出动作
    exitAction=new QAction(QIcon("E:\\QT\\images\\close.png"),tr("关闭"),this);
    exitAction->setShortcut(QKeySequence::Close);
    exitAction->setStatusTip(tr("退出应用"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    //剪切动作
    cutAction=new QAction(QIcon("E:\\QT\\images\\cut.png"),tr("剪切"),this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("剪切"));
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));

    //复制动作
    copyAction=new QAction(QIcon("E:\\QT\\images\\copy.png"),tr("复制"),this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("复制"));
    connect(copyAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));

    //粘贴动作
    pasteAction=new QAction(QIcon("E:\\QT\\images\\paste.png"),tr("粘贴"),this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("粘贴"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(paste()));

    //关于
    aboutAction=new QAction(tr("关于"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(QApplication::aboutQt()));

    //打印
    printImageAction=new QAction(QIcon("E:\\QT\\images\\printImg.png"),tr("打印图像"),this);
    printImageAction->setStatusTip(tr("打印一个图像"));
    connect(printImageAction,SIGNAL(triggered(bool)),this,SLOT(ShowPrintImage()));

    printTextAction=new QAction(QIcon("E:\\QT\\images\\printTxt.png"),tr("打印文本"),this);
    printTextAction->setStatusTip(tr("打印一个文本"));
    connect(printTextAction,SIGNAL(triggered(bool)),this,SLOT(ShowPrintText()));

    //放大和缩小
    zoomInAction=new QAction(QIcon("E:\\QT\\images\\zoomIn.png"),tr("放大"),this);
    zoomInAction->setStatusTip(tr("放大图像"));
    connect(zoomInAction,SIGNAL(triggered(bool)),this,SLOT(ShowZoomIn()));
    zoomOutAction=new QAction(QIcon("E:\\QT\\images\\zoomOut.png"),tr("缩小"),this);
    zoomOutAction->setStatusTip(tr("缩小图像"));
    connect(zoomOutAction,SIGNAL(triggered(bool)),this,SLOT(ShowZoomOut()));

    //图像旋转
    rotate90Action=new QAction(QIcon("E:\\QT\\images\\rotate90.png"),tr("旋转90"),this);
    rotate90Action->setStatusTip(tr("将一幅图像旋转90度"));
    connect(rotate90Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate90()));

    rotate180Action=new QAction(QIcon("E:\\QT\\images\\rotate180.png"),tr("旋转180"),this);
    rotate180Action->setStatusTip(tr("将一幅图像旋转180度"));
    connect(rotate180Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate180()));

    rotate270Action=new QAction(QIcon("E:\\QT\\images\\rotate270.png"),tr("旋转270"),this);
    rotate270Action->setStatusTip(tr("将一幅图像旋转270度"));
    connect(rotate270Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate270()));

    //图像镜像
    mirrorVerticalAction=new QAction(QIcon("E:\\QT\\images\\mirrorVertical.png"),tr("纵向图像"),this);
    mirrorVerticalAction->setStatusTip(tr("将图像纵向镜像"));
    connect(mirrorVerticalAction,SIGNAL(triggered(bool)),this,SLOT(ShowMirrorVertical()));

    mirrorHorizontalAction=new QAction(QIcon("E:\\QT\\images\\mirrorHorizonal.png"),tr("水平图像"),this);
    mirrorHorizontalAction->setStatusTip(tr("将图像水平镜像"));
    connect(mirrorHorizontalAction,SIGNAL(triggered(bool)),this,SLOT(ShowMirrorHorizonal()));

    //撤销和恢复
    undoAction=new QAction(QIcon("E:\\QT\\images\\undo.png"),tr("撤销"),this);
    undoAction->setStatusTip(tr("撤销"));
    connect(undoAction,SIGNAL(triggered()),showWidget->text,SLOT(undo()));
    redoAction=new QAction(QIcon("E:\\QT\\images\\redo.png"),tr("恢复"),this);
    redoAction->setStatusTip(tr("恢复"));
    connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));
}


void MainWindow::createMenus()
{
    //文件菜单
    fileMenu=menuBar()->addMenu(tr("文件"));//QMainWindow的menuBar()函数可以直接得到主窗口菜单条指针,addMenu函数加入项
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    //缩放菜单
    zoomMenu=menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    //旋转菜单
    rotateMenu=menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    //镜像菜单
    mirrorMenu=menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}

void MainWindow::createToolBars()
{
    /*工具条是可移动的窗口,通过setAllowedAreas()指定停靠位置*/
    //文件工具条
    fileTool=addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printTextAction);
    fileTool->addAction(printImageAction);
    fileTool->setAllowedAreas(Qt::TopToolBarArea|Qt::LeftToolBarArea);//只能放在左边或顶上

    //编辑工具条
    zoomTool=addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    //旋转工具条
    rotateTool=addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    //撤销和重做工具条
    doToolBar=addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

}

void MainWindow::ShowNewFile()
{
    MainWindow *newWindow=new MainWindow;
    newWindow->show();
}

void MainWindow::ShowOpenFile()
{
    //获取打开文件的路径,参数:父指针,对话框标题,对话框打开时的默认目录(.代表当前目录),过滤器(只显示文本)
    filename=QFileDialog::getOpenFileName(this,tr("Open File"),".");
    if(!filename.isEmpty())
    {
        if(showWidget->text->document()->isEmpty())
            loadFile(filename);
        else{
            MainWindow *newWin=new MainWindow;
            newWin->show();
            newWin->loadFile(filename);
        }
    }
}

void MainWindow::loadFile(QString filename)
{
    printf("file name:%s\n",filename.data());

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {
            showWidget->text->append(textStream.readLine());
            printf("end\n");
        }
    }
}

void MainWindow::ShowPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())//判断对话框显示后 用户是否单击了"打印按钮"
    {
        QTextDocument *doc=showWidget->text->document();
        doc->print(&printer);
    }
}

void MainWindow::ShowPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);//新建QPainter对象,指定绘图设备
        QRect rect=painter.viewport();//获得视口矩形区域
        QSize size=img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);//按照图形比列大小重新设置视口矩形区域
        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);//打印图像
    }

}

void MainWindow::ShowZoomIn()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(1.2,1.2);//按两倍比例对水平和垂直方向进行放大
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowZoomOut()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.scale(0.8,0.8);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate90()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate180()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate270()
{
    if(img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img=img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowMirrorVertical()
{
    if(img.isNull())
        return;
    img=img.mirrored(false,true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowMirrorHorizonal()
{
    if(img.isNull())
        return;
    img=img.mirrored(true,false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
