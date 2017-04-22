#include "test.h"
#include "qhexedit.h"

Test::Test(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
  ui.setupUi(this);

  m_hexedit = new QHexEdit();
  m_HexEditByteArray.append("Hello, c'est un début de chaine en hexa");
  m_hexEditData = QHexEditData::fromMemory(m_HexEditByteArray);
  m_hexedit->setData(m_hexEditData);

  QHexEditDataWriter *writer = new QHexEditDataWriter(m_hexEditData);

  m_hexedit->commentRange(3, 12, "commentaire");


  ui.layout->addWidget(m_hexedit);

 writer->append("\nEncore un HELLO");
 writer->insert(0, "DOUDOU");

}

Test::~Test()
{

}
