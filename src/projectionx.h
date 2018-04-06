#ifndef PROJECTIONX_H
#define PROJECTIONX_H

#include <QWidget>
#include <QGLWidget>
#include "model.h"

namespace Ui{
    class ProjectionX;
}

/// defines the projectionX for the current design to be displayed using the model class
class ProjectionX :  public QGLWidget
{
    Q_OBJECT

public:
    explicit ProjectionX (QWidget *parent = 0);
    ~ProjectionX();
    /// the 3d model that describes a xy projection view
    Model *model;
    /// the wireframe is either enabled or disabled for the projection
    bool wireframe;


protected:
//    float r1 ; float r2; float r3;
    /// sets up the OpenGL resources and state. Gets called once before the first time resizeGL() or paintGL() is called
    void initializeGL();
    /// renders the OpenGL scene. Gets called whenever the widget needs to be updated
    void paintGL();
    /// sets up the OpenGL viewport, projection, etc. Gets called whenever the widget has been resized (and also when it is shown for the first time because all newly created widgets get a resize event automatically).
    void resizeGL(int width, int height);

//    QSize minimumSizeHint() const;
    /// to provide a reasonable default size for the widget
    QSize sizeHint() const;


public slots:
    /// decide the numerical scale factor for viewing the object
    void setScale(int factor);
    /// set the wrireframe property of the model
    void setWireframe(bool b);
    /// the update function just updates the model view based on its currently set parameters/fields
    void update();
    /// sets the current model to the specified argument
    void setModel(Model* m);

private:
    /// the scale factor to draw the design
    int scl;
    /// creates the current model design
    void draw();

};

#endif // PROJECTIONX_H
