#ifndef __EDITOR_BODY_CONTROL_H__
#define __EDITOR_BODY_CONTROL_H__

#include "DAVAEngine.h"
#include "CameraController.h"
#include "PropertyPanel.h"
#include "EditMatrixControl.h"
#include "../GameScene.h"

using namespace DAVA;

class BeastManager;
class EditorBodyControl : public UIControl, public UIHierarchyDelegate
{
    enum eConst
    {
        SCENE_OFFSET = 10, 
        LEFT_SIDE_WIDTH = 200,
        RIGHT_SIDE_WIDTH = 200,
        CELL_HEIGHT = 20,
        MATRIX_HEIGHT = 100,
        BUTTON_HEIGHT = 20,
    };
    
public:
    EditorBodyControl(const Rect & rect);
    virtual ~EditorBodyControl();
    
    virtual void WillAppear();
	virtual void Update(float32 timeElapsed);
    virtual void Input(UIEvent * touch);

    void OpenScene(const String &pathToFile);
    
    void ShowProperties(bool show);
    bool PropertiesAreShown();

    void ShowSceneGraph(bool show);
    bool SceneGraphAreShown();

    void UpdateLibraryState(bool isShown, int32 width);

	void BeastProcessScene();
    
protected:

    void CreateScene();
    void ReleaseScene();
    
    void CreatePropertyPanel();
    void ReleasePropertyPanel();
    
    
    virtual bool IsNodeExpandable(UIHierarchy *forHierarchy, void *forNode);
    virtual int32 ChildrenCount(UIHierarchy *forHierarchy, void *forParent);
    virtual void *ChildAtIndex(UIHierarchy *forHierarchy, void *forParent, int32 index);
    virtual UIHierarchyCell *CellForNode(UIHierarchy *forHierarchy, void *node);
    virtual void OnCellSelected(UIHierarchy *forHierarchy, UIHierarchyCell *selectedCell);
    
    
    UIHierarchy * sceneTree;
    
    //scene controls
    GameScene * scene;
	Camera * activeCamera;
    UI3DView * scene3dView;
    WASDCameraController * cameraController;
    
    // Node preview information
    SceneNode * selectedNode;
    PropertyPanel * activePropertyPanel;
    EditMatrixControl * localMatrixControl;
    EditMatrixControl * worldMatrixControl;
    void OnLocalTransformChanged(BaseObject * object, void * userData, void * callerData);
    
    
    UIStaticText * nodeName;
    UIStaticText * nodeCenter;
    UIStaticText * nodeBoundingBoxMin;
    UIStaticText * nodeBoundingBoxMax;
    UIButton * lookAtButton;
    UIButton * removeNodeButton;
    UIButton * enableDebugFlagsButton;
    
    void OnLookAtButtonPressed(BaseObject * obj, void *, void *);
    void OnRemoveNodeButtonPressed(BaseObject * obj, void *, void *);
    void OnEnableDebugFlagsPressed(BaseObject * obj, void *, void *);
    
    // touch
    float32 currentTankAngle;
	bool inTouch;
	Vector2 touchStart;
	Vector2 touchCurrent;
	float32 touchTankAngle;
	float32 rotationSpeed;
	
	float32 startRotationInSec;

	//beast
	BeastManager * beastManager;
};



#endif // __EDITOR_BODY_CONTROL_H__