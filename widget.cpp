#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QBitmap>
#include<QPainter>
#include<QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){

        QString  str= QFileDialog::getOpenFileName(this,"biaoti","D://") ;
        ui->label->setPixmap(QBitmap(str));

    });
    //在pixmap画图
  QPixmap pix(300,300);//纸的大小
  pix.fill(Qt::red);
  QPainter p(&pix);
  p.drawRect(10,10,280,280);
  p.setPen(QPen(Qt::green,10));
  p.drawEllipse(150,150,50,50);
  pix.save("C:\\sad.png");

  //在Qimage 画图
  //指定绘图设备两种方式1.构造函数中(参数是绘图设备)
                   //2.//begin（参数是绘图设备）
  //end（）；
QImage img(300,300,QImage::Format_RGB32);//纸的大小
img.fill(Qt::red);
p.begin(&img);//重新指定绘图设备
p.drawRect(10,10,280,280);
p.setPen(QPen(Qt::green,10));
p.drawEllipse(150,150,50,50);
p.end();
img.save("C:\\1213.png");

//在Qpicture 画图
//1.保持的是绘图步骤---画家类的绘图步骤
//2.pictu不是图片就是普通的二进制图片（save文件）
//3.不依赖于平台

QPicture pic;//纸的大小
p.begin(&pic);//重新指定绘图设备
p.drawRect(10,10,280,280);
p.setPen(QPen(Qt::green,10));
p.drawEllipse(150,150,50,50);
p.end();
pic.save("C:\\02.png");

}
//可作为绘图设备  Qpixmap   Qimage  Qpicture  QBitmap（黑白图片）
//QBitmap 父类 Qpixmap
//Qpixmap  --图片类，主义用来显示，它针对于显示做了优化，依赖于平台的，只能在主线程使用（ui线程））
//Qimage--图片类 ，不依赖于平台(图片传输，可以在多线程中对其进行操作）
Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
 QPainter p(this);
 QPicture pic;
 pic.load("C:\\02.png");
 p.drawPicture(100,100,pic);


}
