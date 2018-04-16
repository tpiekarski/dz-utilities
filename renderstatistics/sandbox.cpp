#include "sandbox.h"

#include "dzapp.h"
#include "dzscene.h"
#include "dznode.h"
#include "dzobject.h"
#include "dzdefaultmaterial.h"
#include "dzshape.h"
#include "dzmaterial.h"

#include "QtCore\qobject.h"

Sandbox::Sandbox() {

  int numNodes = dzScene->getNumSelectedNodes();

  for (int i = 0; i < numNodes; ++i) {

    DzShape* pShape = dzScene->getNode(i)->getObject()->getShape(0);
    int numMaterials = pShape->getNumMaterials();

    QObjectList qObjectList = pShape->getAllMaterials();
    dzApp->log(QString("Objects inside qObjectList: %1").arg(QString::number(qObjectList.count())));

    QList<DzDefaultMaterial*> materialList;

    for (int n = 0; n < qObjectList.count(); n++) {
      DzDefaultMaterial* currentMaterial = dynamic_cast<DzDefaultMaterial*>(materialList.at(n));

      if (currentMaterial != NULL) {
        dzApp->log(QString("Material #%1 is not null, appending to material list.").arg(n));
        materialList.append(currentMaterial);
      }
      
    }

    dzApp->log(QString("Materials inside materialList: %1").arg(QString::number(materialList.count())));
  }
 
}

